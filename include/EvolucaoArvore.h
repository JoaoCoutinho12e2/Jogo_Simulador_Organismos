// Includes e pragma
#pragma once      // Evita múltiplas inclusões
#include <vector> // std::vector
#include <string> // std::string

// Classe que representa a árvore da evolução
class EvolucaoArvore
{

public:
    // Enumeração para as fases da evolução
    enum Fase
    {
        Microbiana,   // Microbiana
        Evolucao,     // Evolução
        Multicelular, // Multiceular
        Consciencia,  // Consciência
        Humana,       // Humana
        Cibernetica   // Cibernética
    };
    EvolucaoArvore();                               // Construtor
    void avancarFase();                             // Avança para a próxima fase
    Fase getFaseAtual() const { return faseAtual; } // Retorna a fase atual
    std::string getDescricaoFase() const;           // Retorna a descrição da fase atual

private:
    Fase faseAtual;                          // Fase atual
    std::vector<std::string> descricaoFases; // Descrição das fases
};