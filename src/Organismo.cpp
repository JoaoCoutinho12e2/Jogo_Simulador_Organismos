// Includes
#include <iostream>    // std::cout, std::endl
#include "Organismo.h" // Organismo

// Construtor
Organismo::Organismo(double energia)

    // Inicializar membros
    : energia(energia), velocidade(1.0), resistencia(1.0),
      taxaReproducao(0.1), geracao(1)
{
}

// Organismo está vivo?
bool Organismo::estaVivo() const
{

    // Retorna verdadeiro se a energia for maior que zero
    return energia > 0;
}

// Consumir energia
void Organismo::consumir(double quantidade)
{

    // Reduzir energia ao consumir
    energia -= quantidade;
}

// Mutar organismo
void Organismo::mutar()
{

    // Adicionar variação aos atributos
    velocidade *= (0.9 + (rand() % 3) * 0.1);      // ±10% variação
    resistencia *= (0.9 + (rand() % 3) * 0.1);     // ±10% variação
    taxaReproducao *= (0.95 + (rand() % 2) * 0.1); // ±5% variação
}

// Obter consumo de energia
double Organismo::getConsumoEnergia() const
{

    // Consumo base + bônus por geração
    return 10.0 * geracao + (velocidade + resistencia) * 5.0;
}

// Evoluir organismo
void Organismo::evoluir()
{
    ++geracao;              // Incrementar geração
    energia += 20.0;        // Adicionar energia
    velocidade *= 1.1;      // Aumentar velocidade
    resistencia *= 1.1;     // Aumentar resistência
    taxaReproducao *= 1.05; // Aumentar taxa de reprodução
}

// Reproduzir organismo
void Organismo::reproduzir()
{

    // Gasta 30% de energia na reprodução
    energia *= 0.7;
}