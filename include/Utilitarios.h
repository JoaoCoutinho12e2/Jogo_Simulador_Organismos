// Includes e pragma
#pragma once      // Evita múltiplas inclusões
#include <random> // std::default_random_engine, std::uniform_real_distribution, std::uniform_int_distribution

// Namespace Utilitarios invés de classe para funções utilitárias
namespace Utilitarios
{
    double numeroAleatorioDouble(double min, double max); // Retorna um número aleatório entre min e max
    int numeroAleatorioInt(int min, int max);             // Retorna um número inteiro aleatório entre min e max
    void inicializarAleatorio();                          // Inicializa o gerador de números aleatórios
    double calcularAptidao(const class Organismo &org);   // Calcula a aptidão de um organismo
}