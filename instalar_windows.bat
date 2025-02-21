@echo off

REM Navega para a pasta do projeto
cd C:\Users\11PI08\Downloads\TLP\Jogo_Simulador_Organismos

REM Cria a pasta build se não existir
if not exist build mkdir build

REM Vai para a pasta build
cd build

REM Cmake para compilar o projeto
cmake ..

REM Compila o projeto como Release
cmake --build . --config Release

REM Executa o projeto
.\Release\SimuladorOrganismos.exe
pause