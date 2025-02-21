# CMakeLists.txt

# Define a versão mínima do CMake necessária para compilar o projeto
cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(SimuladorOrganismos)

# Define qual versão do C++ será utilizada e se é obrigatório ter essa versão
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define o diretório onde estão os arquivos de cabeçalho
include_directories(${PROJECT_SOURCE_DIR}/include)

# Define os arquivos fonte do projeto
set(SOURCES
    src/main.cpp
    src/Jogo.cpp
    src/Simulacao.cpp
    src/Ambiente.cpp
    src/Organismo.cpp
    src/UI.cpp
    src/Utilitarios.cpp
    src/EvolucaoArvore.cpp
)

# Define o diretório onde será gerado o executável
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Define o nome do executável e os arquivos fonte que serão compilados
add_executable(${PROJECT_NAME} ${SOURCES})

# Define as bibliotecas que serão utilizadas
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(${PROJECT_NAME} stdc++fs)
endif()

# Define as opções de compilação
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()