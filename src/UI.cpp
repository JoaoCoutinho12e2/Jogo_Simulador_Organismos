// Includes
#include "UI.h"      // Interface do Utilizador
#include <iostream>  // std::cout, std::cin
#include <iomanip>   // std::setprecision
#include <algorithm> // std::max

// Suporte para UTF-8. Se for Windows, incluir headers específicos se não for, incluir cstdlib que contém a função system
#ifdef _WIN32
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#else
#include <cstdlib>
#endif

// Suporte para UTF-8
void InterfaceUtilizador::inicializarConsola()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);  // UTF-8
    SetConsoleCP(65001);        // UTF-8 input
#endif
}

// Limpa o ecrã
void InterfaceUtilizador::limparConsola()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux/Unix
#endif
}

// Mostra o menu principal
void InterfaceUtilizador::mostrarMenu()
{
    std::cout << "\n┌──────────────────────────────────┐\n";
    std::cout << "│     Simulador de Evolução v1.0    │\n";
    std::cout << "├──────────────────────────────────┤\n";
    std::cout << "│ 1. Coletar Energia               │\n";
    std::cout << "│ 2. Ver Estatísticas              │\n";
    std::cout << "│ 3. Ver Fase Atual                │\n";
    std::cout << "│ 4. Salvar Jogo                   │\n";
    std::cout << "│ 5. Carregar Jogo                 │\n";
    std::cout << "│ 0. Sair                          │\n";
    std::cout << "└──────────────────────────────────┘\n";
    std::cout << "\nEscolha uma opção: ";
}

// Obtém escolha do utilizador
int InterfaceUtilizador::obterEscolhaMenu()
{
    int escolha;         // Escolha do utilizador
    std::cin >> escolha; // Ler escolha
    return escolha;      // Retornar escolha
}

// Mostra estatísticas detalhadas
void InterfaceUtilizador::mostrarEstatisticas(const Simulacao &sim)
{

    // 1. Limpar consola
    limparConsola();

    // 2. Mostrar estatísticas
    std::cout << "\n┌─────────── Estatísticas da Simulação ───────────┐\n\n";

    // 3. Mostrar fase atual
    std::cout << "► Fase: " << sim.getDescricaoFaseAtual() << "\n\n";

    // 4. Mostrar detalhes do ambiente
    const Ambiente &amb = *sim.getAmbiente();
    std::cout << "▼ Ambiente:\n";
    std::cout << "  • Temperatura: " << std::fixed << std::setprecision(1) << amb.getTemperatura() << "°C\n";
    std::cout << "  • Recursos: " << std::setprecision(0) << amb.getRecursos() << "\n";
    std::cout << "  • População: " << amb.getOrganismos().size() << " organismos\n\n";

    // 5. Detalhes dos organismos
    std::cout << "▼ Detalhes dos Organismos:\n";
    const auto &organismos = amb.getOrganismos();

    // 6. Mostrar estatísticas dos organismos
    if (!organismos.empty())
    {
        int maxGeracao = 0;          // Inicializar geração máxima
        double mediaEnergia = 0;     // Inicializar médias
        double mediaVelocidade = 0;  // Inicializar médias
        double mediaResistencia = 0; // Inicializar médias

        // Iterar sobre os organismos
        for (const auto *org : organismos)
        {
            maxGeracao = std::max<int>(maxGeracao, org->getGeracao()); // Encontrar geração máxima
            mediaEnergia += org->getEnergia();                         // Adicionar energia
            mediaVelocidade += org->getVelocidade();                   // Adicionar velocidade
            mediaResistencia += org->getResistencia();                 // Adicionar resistência
        }

        // Calcular médias
        size_t total = organismos.size();

        // Mostrar estatísticas
        std::cout << "  • Geração Máxima: " << maxGeracao << "\n";
        std::cout << "  • Média de Energia: " << std::setprecision(1) << mediaEnergia / total << "\n";
        std::cout << "  • Média de Velocidade: " << mediaVelocidade / total << "\n";
        std::cout << "  • Média de Resistência: " << mediaResistencia / total << "\n";

        // 7. Mostrar mensagem se não houver organismos
    }

    // Se não houver organismos
    else
    {
        // Mostrar mensagem
        std::cout << "  • Nenhum organismo vivo\n";
    }

    std::cout << "└──────────────────────────────────────────────────┘\n";
    // 8. Pausar
    pausar();
}

// Mostra estado atual
void InterfaceUtilizador::mostrarGeracao(const Ambiente &amb)
{
    std::cout << "\n=== Estado Atual do Ambiente ===\n";               // Mostrar cabeçalho
    std::cout << "Temperatura: " << amb.getTemperatura() << "°C\n";    // Mostrar temperatura
    std::cout << "Recursos: " << amb.getRecursos() << "\n";            // Mostrar recursos
    std::cout << "Organismos: " << amb.getOrganismos().size() << "\n"; // Mostrar quantidade de organismos
    pausar();                                                          // Pausar
}

// Mostra fase atual com descrição
void InterfaceUtilizador::mostrarFase(const Simulacao &sim)
{

    // 1. Limpar consola
    limparConsola();

    // 2. Mostrar fase atual
    std::cout << "\n╔════════════════ Fase Atual ════════════════╗\n";
    std::cout << "║                                            ║\n";
    std::cout << "  " << sim.getDescricaoFaseAtual() << "\n";
    std::cout << "║                                            ║\n";
    std::cout << "╚════════════════════════════════════════════╝\n\n";

    // 3. Adicionar descrição detalhada da fase
    switch (sim.getFaseAtual())
    {

    // Se a fase for Microbiana. Mostrar descrição da fase Microbiana
    case EvolucaoArvore::Microbiana:
        std::cout << "Os primeiros organismos unicelulares começam\n";
        std::cout << "a se desenvolver em um ambiente primitivo.\n";
        break;

    // Se a fase for Evolução. Mostrar descrição da fase Evolução
    case EvolucaoArvore::Evolucao:
        std::cout << "Os organismos evoluem para formas mais\n";
        std::cout << "complexas e adaptadas ao ambiente.\n";
        break;

    // Se a fase for Multicelular. Mostrar descrição da fase Multicelular
    case EvolucaoArvore::Multicelular:
        std::cout << "Os organismos evoluem para formas multicelulares\n";
        std::cout << "com diferentes tipos de células especializadas.\n";
        break;

    // Se a fase for Consciência. Mostrar descrição da fase Consciência
    case EvolucaoArvore::Consciencia:
        std::cout << "Os organismos desenvolvem consciência e\n";
        std::cout << "capacidade de raciocínio.\n";
        break;

    // Se a fase for Humana. Mostrar descrição da fase Humana
    case EvolucaoArvore::Humana:
        std::cout << "Os organismos humanos desenvolvem tecnologia\n";
        std::cout << "e sociedades complexas.\n";
        break;

    // Se a fase for Cibernetica. Mostrar descrição da fase Cibernetica
    case EvolucaoArvore::Cibernetica:
        std::cout << "Os organismos cibernéticos fundem biologia\n";
        std::cout << "e tecnologia para criar formas de vida avançadas.\n";
        break;
    }

    // 4. Pausar
    pausar();
}

// Mostra mensagem
void InterfaceUtilizador::mostrarMensagem(const std::string &mensagem, bool erro)
{

    // Mostrar mensagem de erro ou sucesso
    if (erro)
    {
        std::cout << "\n❌ Erro: " << mensagem << "\n";

        // Mostrar mensagem de sucesso
    }
    else
    {
        std::cout << "\n✓ " << mensagem << "\n";
    }
}

// Aguarda input do utilizador
void InterfaceUtilizador::pausar()
{
    // 1. Limpar buffer de entrada(cache)
    std::cin.ignore(1000,'\n');

    // 2. Console
    limparConsola();

    // 3. Pausar até que o utilizador pressione Enter
    std::cout << "\nAperta Enter para continuar...";

    // 3. Aguardar input
    std::cin.get();
}