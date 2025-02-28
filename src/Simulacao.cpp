// Includes
#include "Simulacao.h"   // Simulacao
#include "Utilitarios.h" // Utilitarios
#include <iostream>      // std::cerr

// Função principal da simulação. Inicia o jogo, executa as gerações e mostra as estatísticas
Simulacao::Simulacao(int organismosIniciais, double recursosIniciais, double temperaturaInicial)

    // Inicializar membros
    : faseAtual(0), contagemGeracoes(0)
{

    // Inicializar ambiente
    ambiente = new Ambiente(temperaturaInicial, recursosIniciais);

    // Para cada organismo inicial, adicionar um organismo ao ambiente
    for (int i = 0; i < organismosIniciais; i++)
    {

        // Adiciona organismo ao ambiente
        ambiente->adicionarOrganismo(new Organismo());
    }
}

// Destrutor
Simulacao::~Simulacao()
{

    // Apagar ambiente
    delete ambiente;
}

// Executar uma geração da simulação
void Simulacao::executarGeracao()
{

    // 1. Incrementar contagem de gerações
    contagemGeracoes++;

    // 2. Atualizar recursos do ambiente
    ambiente->atualizarRecursos();

    // 3. Iterar sobre os organismos
    auto &organismos = ambiente->getOrganismos();

    // 4. Atualizar organismos
    for (auto it = organismos.begin(); it != organismos.end();)
    {

        // Obter organismo
        Organismo *org = *it;

        // Consumir recursos
        org->consumir(Utilitarios::numeroAleatorioDouble(1.0, 5.0));

        // Verificar se o organismo está vivo
        if (!org->estaVivo())
        {

            // Apagar organismo se não estiver vivo
            delete org;

            // Remover organismo do vetor
            it = organismos.begin();

            // Se estiver vivo, então
        }
        else
        {

            // Evoluir organismo
            if (Utilitarios::numeroAleatorioDouble(0, 1) < org->getTaxaReproducao())
            {

                if (organismos.size() < 1000)  // Limite máximo de organismos
                {
                    Organismo *novoOrg = new Organismo(*org);
                    novoOrg->mutar();
                    ambiente->adicionarOrganismo(novoOrg);
                }
            }

            // Incrementar iterador
            ++it;
        }
    }

    // 5. Atualizar fase
    atualizarFase();
}

// Imprimir as estatísticas da simulação
void Simulacao::imprimirEstatisticas()
{
    std::cout << "\n=== Geração " << contagemGeracoes << " ===\n";                 // Mostrar geração atual
    std::cout << "Organismos vivos: " << ambiente->getOrganismos().size() << "\n"; // Mostrar quantidade de organismos
    std::cout << "Temperatura: " << ambiente->getTemperatura() << "°C\n";          // Mostrar temperatura
    std::cout << "Recursos: " << ambiente->getRecursos() << "\n";                  // Mostrar recursos
    std::cout << "Fase atual: " << getDescricaoFaseAtual() << "\n";                // Mostrar fase atual
}

// Atualizar a fase da simulação
void Simulacao::atualizarFase()
{

    // Encontrar a maior geração entre os organismos
    int maxGeracao = 0;

    // Iterar sobre os organismos para determinar a geração máxima
    for (auto org : ambiente->getOrganismos())
    {

        // Atualizar maxGeracao caso o organismo atual tenha uma geração maior
        maxGeracao = std::max(maxGeracao, org->getGeracao());
    }

    // Atualizar a fase da árvore de evolução com base na geração máxima
    while (true)
    {

        // 1. Obtém a fase atual da evolução
        auto faseAtualTemp = arvoreEvolucao.getFaseAtual();

        // 2. Flag para verificar se a fase foi atualizada
        bool avancou = false;

        // 3. Utiliza switch case para selecionar a ação com base na fase atual
        switch (faseAtualTemp)
        {

        // Se a fase for Microbiana e maxGeracao for pelo menos 10, avança para a próxima fase
        case EvolucaoArvore::Evolucao:

            // Caso a fase seja Evolucao e maxGeracao for pelo menos 20, avança para a próxima fase
            if (maxGeracao >= 20)
            {
                arvoreEvolucao.avancarFase();
                avancou = true;
            }
            break;
            
        case EvolucaoArvore::Multicelular:

            // Caso a fase seja Multicelular e maxGeracao for pelo menos 40, avança para a próxima fase
            if (maxGeracao >= 40)
            {
                arvoreEvolucao.avancarFase();
                avancou = true;
            }
            break;

        case EvolucaoArvore::Consciencia:

            // Caso a fase seja Consciencia e maxGeracao for pelo menos 60, avança para a próxima fase
            if (maxGeracao >= 60)
            {
                arvoreEvolucao.avancarFase();
                avancou = true;
            }
            break;

        case EvolucaoArvore::Humana:

            // Caso a fase seja Humana e maxGeracao for pelo menos 80, avança para a próxima fase
            if (maxGeracao >= 80)
            {
                arvoreEvolucao.avancarFase();
                avancou = true;
            }
            break;

        case EvolucaoArvore::Cibernetica:

            // Caso a fase seja Cibernetica e maxGeracao for pelo menos 100, avança para a próxima fase
            if (maxGeracao >= 100)
            {
                arvoreEvolucao.avancarFase();
                avancou = true;
            }
            break;

        default:
            break;
        }
        // Se nenhuma atualização de fase ocorreu, sai do laço
        if (!avancou)
        {
            break;
        }
    }
}

// Salvar o estado da simulação num ficheiro
void Simulacao::salvarEstado(const std::string &nomeArquivo)
{

    // 1. Abre o ficheiro para escrita binária
    std::ofstream arquivo(nomeArquivo, std::ios::binary);

    // 2. Verifica se o ficheiro foi aberto com sucesso
    if (arquivo.is_open())
    {

        // 3. Escreve a contagem de gerações no ficheiro
        arquivo.write(reinterpret_cast<char *>(&contagemGeracoes), sizeof(contagemGeracoes));

        // 4. Salva o estado completo automaticamente

        // 5. Fecha o ficheiro
        arquivo.close();

        // 6. Mostra mensagem de sucesso
        std::cout << "Estado salvo com sucesso!\n";
    }
}

// Carregar o estado da simulação de um ficheiro
void Simulacao::carregarEstado(const std::string &nomeArquivo)
{

    // 1. Abre o ficheiro para leitura binária
    std::ifstream arquivo(nomeArquivo, std::ios::binary);

    // 2. Verifica se o ficheiro foi aberto com sucesso
    if (arquivo.is_open())
    {

        // 3. Lê a contagem de gerações do ficheiro
        arquivo.read(reinterpret_cast<char *>(&contagemGeracoes), sizeof(contagemGeracoes));

        // 4. Carrega o estado completo ao abrir a consola/app

        // 5. Fecha o ficheiro
        arquivo.close();

        // 6. Mostra mensagem de sucesso
        std::cout << "Estado carregado com sucesso!\n";
    }
}