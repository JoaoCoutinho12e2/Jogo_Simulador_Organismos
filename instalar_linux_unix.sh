#!/bin/bash

# Navega para a pasta do projeto
cd /c/Users/11PI08/Downloads/TLP/Jogo_Simulador_Organismos

# Cria uma pasta para o build e entra nesta
mkdir -p build
cd build

# Corre o Cmake para configurar o projecto
cmake ..

# Compila o projecto
cmake --build .

# Corre o programa (não é necessário sudo para correr o programa)
./SimuladorOrganismos