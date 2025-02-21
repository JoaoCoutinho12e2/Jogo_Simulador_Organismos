// Includes e pragma
#pragma once                // Evita múltiplas inclusões
#include "Ambiente.h"       // Ambiente
#include "EvolucaoArvore.h" // EvolucaoArvore
#include <fstream>          // std::fstream

// Classe que representa a simulação
class Simulacao
{

private:
    Ambiente *ambiente;               // Ambiente da simulação
    EvolucaoArvore arvoreEvolucao;    // Nova instância de EvolucaoArvore
    int contagemGeracoes;             // Contador de gerações
    std::fstream arquivoEstatisticas; // Ficheiro de estatísticas
    int faseAtual;                    // 0: Microbiana, 1: Evolução, 2: Multicelular, 3: Consciência, 4: Humana, 5: Cibernética

public:
    Simulacao(int organismosIniciais = 10,     // Construtor
              double recursosIniciais = 1000,  // Recursos iniciais
              double temperaturaInicial = 20); // Temperatura inicial
    ~Simulacao();                              // Destrutor

    void executarGeracao();                              // Executa uma geração da simulação
    void imprimirEstatisticas();                         // Imprime as estatísticas da simulação
    void salvarEstado(const std::string &nomeArquivo);   // Guarda o estado da simulação num ficheiro
    void carregarEstado(const std::string &nomeArquivo); // Carrega o estado da simulação de um ficheiro

    // Métodos para progressão de fases
    void atualizarFase();                                                                   // Atualiza a fase da simulação
    EvolucaoArvore::Fase getFaseAtual() const { return arvoreEvolucao.getFaseAtual(); }     // Retorna a fase atual
    std::string getDescricaoFaseAtual() const { return arvoreEvolucao.getDescricaoFase(); } // Retorna a descrição da fase atual

    // Getter para acesso ao ambiente
    const Ambiente *getAmbiente() const { return ambiente; }
};