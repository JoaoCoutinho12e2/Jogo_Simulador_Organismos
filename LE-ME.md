# Simulador de Evolução de Organismos

## Como Compilar e Executar(manual)

1. **Abre um terminal** e navega até o diretório do projeto onde está o arquivo `CMakeLists.txt`:

   ```sh
   cd /c:/Users/11PI08/Downloads/TLP/Jogo_Simulador_Organismos
   ```

2. **Cria um diretório de compilação** (se ainda não existir) e navega para este:

   ```sh
   mkdir build
   cd build
   ```

3. **Configura o projeto com CMake**:

   ```sh
   cmake ..
   ```

4. **Compila o projeto**:

   Para Windows (Visual Studio e VS Code):

   ```sh
   cmake --build . --config Release
   ```

   Para Linux/Mac:

   ```sh
   cmake --build .
   ```

5. **Executa o programa**:

   Windows:

   ```sh
   .\Release\SimuladorOrganismos.exe
   ```

   Linux/Mac:

   ```sh
   ./SimuladorOrganismos
   ```

## Como Compilar e Executar(por script)

1. **Abre o bat se usares windows ou sh se usares Linux/unix**

   Linux/Mac

   ```sh
       cd /c/Users/11PI08/Downloads/Jogo_Simulador_Organismos
   ```

    Windows

   ```bat
       cd C:\Users\11PI08\Downloads\Jogo_Simulador_Organismos
   ```

   Muda o 11PI08 para o nome do teu utilizador

2. **Dá permissão para executar o script**
    - Linux/Unix:

        ```sh
            chmod +x instalar_linux_unix.sh
        ```

3. **Corre o script**
    - Linux/Unix:

        ```sh
            ./instalar_linux_unix.sh
        ```

    - Windows:

        ```cmd
            instalar_windows.bat
        ```

## Estrutura do Projeto

- `src/`: Código fonte
- `include/`: Arquivos de cabeçalho
- `data/`: Arquivos de salvar o jogo
- `build/`: Arquivos de compilação

## Controles do Jogo

1. Coletar Energia: Opção 1
2. Ver Estatísticas: Opção 2
3. Ver Fase Atual: Opção 3
4. Salvar Jogo: Opção 4
5. Carregar Jogo: Opção 5
6. Sair: Opção 0

## Fases da Evolução

1. Fase Microbiana - Fase inicial
2. Fase Evolução
3. Fase Multicelular
4. Fase Consciência
5. Fase Humana
6. Fase Cibernética - Fase final

## Necessidades do Sistema

- CMake 3.10 ou superior
- Compilador C++ com suporte a C++17
- Visual Studio (Windows) ou GCC/Clang (Linux/Mac)

## Notas

- Os dados do jogo são salvos automaticamente em `./data/saved_data.txt`.
- O jogo criará o diretório `data` automaticamente, se necessário.
- Usa Enter para confirmar as escolhas no menu.
