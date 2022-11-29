# COMPILANDO
Primeiro vamos compilar o programa que reinicia os serviços: <br /> 
g++ -o servicos.exe resetar-jboss.cpp <br /> 
Em seguida, compilamos o programa que executa o programa que vai reiniciar os serviços: <br /> 
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