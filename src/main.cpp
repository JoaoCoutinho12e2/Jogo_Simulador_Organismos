// Includes
#include "Jogo.h"        // Jogo
#include "Utilitarios.h" // Utilitarios
#include <iostream>      // std::cerr
#include <filesystem>    // std::filesystem

// Função principal
int main()
{
    try
    {
        // Inicializar console para suporte UTF-8
        InterfaceUtilizador::inicializarConsola();

        // 1. Criar diretório data se não existir
        std::filesystem::create_directories("./data");

        // 2. Inicializar utilitários
        Utilitarios::inicializarAleatorio();

        // 3. Criar e iniciar jogo
        Jogo jogo;
        jogo.iniciar();

        // 4. Capturar exceções
    }
    catch (const std::exception &e)
    {

        // 5. Mostrar erro
        std::cerr << "Erro: " << e.what() << std::endl;

        // 6. Pausar
        return 1;
    }

    // 7. Sair
    return 0;
}