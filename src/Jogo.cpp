// Includes
#include "Jogo.h"        // Jogo
#include "Utilitarios.h" // Utilitarios
#include <thread>        // std::this_thread::sleep_for
#include <chrono>        // std::chrono::milliseconds

// Construtor Jogo
Jogo::Jogo() : aExecutar(true)
{

    // Inicializar gerador de números aleatórios
    Utilitarios::inicializarAleatorio();
}

// Iniciar o jogo
void Jogo::iniciar()
{

    // Enquanto o jogo estiver em execução
    while (aExecutar)
    {

        // Limpar consola e mostrar menu
        InterfaceUtilizador::limparConsola();                      // Limpar consola
        InterfaceUtilizador::mostrarMenu();                        // Mostrar menu
        processarEntrada(InterfaceUtilizador::obterEscolhaMenu()); // Processar escolha
    }
}

// Processar escolha do utilizador
void Jogo::processarEntrada(int escolha)
{

    // Processar escolha do utilizador(usa-se swich case porque if else não é eficiente)
    switch (escolha)
    {

    // Sair
    case 0:
        aExecutar = false;
        break;

    // Coletar Energia
    case 1:
        coletarEnergia();
        break;

    // Ver Estatísticas
    case 2:
        InterfaceUtilizador::mostrarEstatisticas(simulacao);
        break;

    // Ver Fase Atual
    case 3:
        InterfaceUtilizador::mostrarFase(simulacao);
        break;

    // Salvar Jogo
    case 4:
        simulacao.salvarEstado("./data/saved_data.txt"); // Salvar estado
        std::cout << "Jogo salvo com sucesso!\n";        // Mostrar mensagem
        InterfaceUtilizador::pausar();                   // Pausar
        break;

    // Carregar Jogo
    case 5:
        simulacao.carregarEstado("./data/saved_data.txt"); // Carregar estado
        std::cout << "Jogo carregado com sucesso!\n";      // Mostrar mensagem
        InterfaceUtilizador::pausar();                     // Pausar
        break;
    }
}

// Coletor de energia
void Jogo::coletarEnergia()
{

    // 1. Coletar energia aleatória dos Utilitários
    double energiaColetada = Utilitarios::numeroAleatorioDouble(10.0, 50.0);

    // 2. Executar geração da simulação
    simulacao.executarGeracao();

    // 3. Mostrar energia coletada
    std::cout << "\nEnergia coletada: " << energiaColetada << "\n";

    // 4. Pausar
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}