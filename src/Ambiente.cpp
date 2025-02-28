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

    // Calcula o consumo total de recursos com limite de segurança
    for (auto organismo : organismos)
    {
        // Limita o consumo individual para evitar overflow
        double consumoIndividual = std::min(organismo->getConsumoEnergia(), recursos * 0.1);
        consumoTotal += consumoIndividual;
    }

    // Limita o consumo total aos recursos disponíveis
    consumoTotal = std::min(consumoTotal, recursos);
    
    // Atualiza os recursos disponíveis
    recursos -= consumoTotal;

    // Adiciona uma pequena regeneração de recursos
    recursos += 50.0; // Valor base de regeneração
    
    // Garante que os recursos fiquem dentro de limites razoáveis
    recursos = std::min(std::max(0.0, recursos), 10000.0);
}