// Includes
#include "Ambiente.h"  // Ambiente
#include "Organismo.h" // Organismo
#include <algorithm>   // std::max

// Construtor Ambiente
Ambiente::Ambiente(double temp, double rec)

    // Inicializar temperatura e recursos
    : temperatura(temp), recursos(rec)
{
}

// Destrutor Ambiente
Ambiente::~Ambiente()
{

    // Iterar sobre os organismos
    for (auto organismo : organismos)
    {

        // Apagar organismo
        delete organismo;
    }

    // Limpar vetor de organismos
    organismos.clear();
}

// Adicionar organismo
void Ambiente::adicionarOrganismo(Organismo *org)
{

    // Adicionar organismo ao vetor
    if (org != nullptr)
    {

        // Adicionar organismo ao vetor
        organismos.push_back(org);
    }
}

// Remover organismo
void Ambiente::removerOrganismo(int indice)
{

    // Remover organismo do vetor
    if (indice >= 0 && indice < organismos.size())
    {
        delete organismos[indice];                     // Apagar organismo
        organismos.erase(organismos.begin() + indice); // Remover organismo do vetor
    }
}

// Atualizar temperatura
void Ambiente::atualizarRecursos()
{

    // Inicializar consumo total
    double consumoTotal = 0.0;

    // Calcula o consumo total de recursos
    for (auto organismo : organismos)
    {

        // Adiciona o consumo de energia do organismo ao consumo total
        consumoTotal += organismo->getConsumoEnergia();
    }

    // Atualiza os recursos disponíveis
    recursos -= consumoTotal;

    // Garante que os recursos não fiquem negativos
    recursos = std::max(0.0, recursos);
}