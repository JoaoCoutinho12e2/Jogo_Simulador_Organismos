// Includes
#include "Utilitarios.h" // Utilitarios
#include "Organismo.h"   // Organismo
#include <random>        // std::mt19937
#include <chrono>        // std::chrono::steady_clock

// Gerador de números aleatórios
static std::mt19937 geradorNumeros;

// Namespace Utilitarios
namespace Utilitarios
{

    // Inicializa o gerador de números aleatórios
    void inicializarAleatorio()
    {

        // Use unsigned long long for the seed to avoid conversion warnings
        auto seed = static_cast<unsigned long long>(std::chrono::steady_clock::now().time_since_epoch().count());

        // Inicializa o gerador de números aleatórios com a seed
        geradorNumeros.seed(seed);
    }

    // Retorna um número aleatório entre min e max
    double numeroAleatorioDouble(double minimo, double maximo)
    {

        // Troca os valores se o mínimo for maior que o máximo
        if (maximo < minimo)
        {

            // Troca os valores
            std::swap(minimo, maximo);
        }

        // Distribuição uniforme de números reais
        std::uniform_real_distribution<double> distribuicao(minimo, maximo);

        // Retorna um número aleatório
        return distribuicao(geradorNumeros);
    }

    // Retorna um número inteiro aleatório entre min e max
    int numeroAleatorioInt(int minimo, int maximo)
    {

        // Troca os valores se o mínimo for maior que o máximo
        if (maximo < minimo)
        {

            // Troca os valores
            std::swap(minimo, maximo);
        }

        // Distribuição uniforme de números inteiros
        std::uniform_int_distribution<int> distribuicao(minimo, maximo);

        // Retorna um número aleatório
        return distribuicao(geradorNumeros);
    }

    // Calcula a aptidão de um organismo
    double calcularAptidao(const ::Organismo &organismo)
    {

        // Calcula a aptidão baseada em múltiplos fatores
        double aptidao = 0.0;

        // Fatores positivos
        aptidao += organismo.getEnergia() * 0.4;     // Energia contribui 40%
        aptidao += organismo.getVelocidade() * 0.2;  // Velocidade contribui 20%
        aptidao += organismo.getResistencia() * 0.2; // Resistência contribui 20%
        aptidao += organismo.getGeracao() * 10.0;    // Bônus por geração

        // Fatores negativos
        aptidao -= organismo.getConsumoEnergia() * 0.1; // Penalidade por consumo de energia

        return std::max(0.0, aptidao); // Garante que a aptidão não seja negativa
    }
}