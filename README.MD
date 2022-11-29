# COMPILANDO

g++ -o servicos.exe resetar-jboss.cpp
g++ -o inicia.exe executar-programa.cpp

## REQUERIMENTOS
Você vai precisar das bibliotecas: <br /> 
libgcc_s_seh-1.dll
libstdc++-6.dll
libwinpthread-1.dll
<br /> 

## DESCRIÇÃO
Basta rodar o programa inicia.exe que a cada 3 horas ele vai reiniciar o JBOSS.
<br /> 
Lembrar-se de que o serviços JBOSS deve se chamar JBOSS em services.msc