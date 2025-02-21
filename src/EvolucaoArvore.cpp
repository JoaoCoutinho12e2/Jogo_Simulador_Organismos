// Include
#include "EvolucaoArvore.h" // EvolucaoArvore

// Construtor Evolução Arvore
EvolucaoArvore::EvolucaoArvore() : faseAtual(Microbiana)
{

    // Inicializar descrições das fases
    descricaoFases = {
        "Fase Microbiana: Organismos unicelulares simples",
        "Fase Evolução: Desenvolvimento de estruturas complexas",
        "Fase Multicelular: Organismos com múltiplas células",
        "Fase Consciência: Desenvolvimento de sistema nervoso",
        "Fase Humana: Desenvolvimento de inteligência avançada",
        "Fase Cibernética: Fusão com tecnologia"};
}

// Atualizar fase
void EvolucaoArvore::avancarFase()
{

    // Se a fase atual for menor que Cibernética
    if (faseAtual < Cibernetica)
    {

        // Avançar para a próxima fase
        faseAtual = static_cast<Fase>(static_cast<int>(faseAtual) + 1);
    }
}

// Obter descrição da fase
std::string EvolucaoArvore::getDescricaoFase() const
{

    // Retornar descrição da fase atual
    return descricaoFases[static_cast<int>(faseAtual)];
}