#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <winnt.h>
#include <winsvc.h>
#include <string>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

/*
Stop a windows Service with the name JBOSS and then start again after 45 seconds, if the service is already stopped, start it
*/

int main()
{
    SC_HANDLE schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (schSCManager == NULL) {
        cout << "OpenSCManager failed (" << GetLastError() << ")" << endl;
        return 1;
    }
    SC_HANDLE schService = OpenService(schSCManager, "JBOSS", SERVICE_ALL_ACCESS);
    if (schService == NULL) {
        cout << "OpenService failed (" << GetLastError() << ")" << endl;
        return 1;
    }
    SERVICE_STATUS_PROCESS ssp;
    DWORD dwBytesNeeded;
    if (!QueryServiceStatusEx(schService, SC_STATUS_PROCESS_INFO, (LPBYTE)&ssp, sizeof(SERVICE_STATUS_PROCESS), &dwBytesNeeded)) {
        cout << "QueryServiceStatusEx failed (" << GetLastError() << ")" << endl;
        return 1;
    }
    if (ssp.dwCurrentState == SERVICE_STOPPED) {
        cout << "Service is already stopped" << endl;
        // start the service
        if (!StartService(schService, 0, NULL)) {
            cout << "StartService failed (" << GetLastError() << ")" << endl;
            return 1;
        }
        cout << "Service started" << endl;
        return 0;
    }
    if (!ControlService(schService, SERVICE_CONTROL_STOP, (LPSERVICE_STATUS)&ssp)) {
        cout << "ControlService failed (" << GetLastError() << ")" << endl;
        return 1;
    }
    cout << "Service stopped" << endl;
    this_thread::sleep_for(chrono::seconds(45));
    if (!StartService(schService, 0, NULL)) {
        cout << "StartService failed (" << GetLastError() << ")" << endl;
        return 1;
    }
    cout << "Service started" << endl;
    return 0;
}