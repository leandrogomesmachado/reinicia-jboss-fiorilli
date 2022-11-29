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

int main() {
    // Inicializa o programa servicos.exe a cada 3 horas
    while (true) {
        // Inicializa o programa servicos.exe
        system("servicos.exe");
        // Aguarda 3 horas
        this_thread::sleep_for(chrono::hours(3));
    }
}