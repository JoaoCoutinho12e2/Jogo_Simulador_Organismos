// Includes e pragma
#pragma once      // Evita múltiplas inclusões
#include <string> // std::string

// Classe que representa um organismo
class Organismo
{

private:
    double energia;        // Energia do organismo
    double velocidade;     // Velocidade do organismo
    double resistencia;    // Resistência do organismo
    double taxaReproducao; // Taxa de reprodução do organismo
    int geracao;           // Geração do organismo

public:
    Organismo(double energia = 100.0); // Construtor
    bool estaVivo() const;             // Verifica se o organismo está vivo
    void consumir(double quantidade);  // O organismo consome recursos
    void reproduzir();                 // O organismo reproduz-se
    void mutar();                      // O organismo sofre mutação
    void evoluir();

    // Método para obter consumo de energia com base na geração
    double getConsumoEnergia() const;

    // Gets e sets dos atributos
    double getEnergia() const { return energia; }               // Retorna a energia do organismo
    double getVelocidade() const { return velocidade; }         // Retorna a velocidade do organismo
    double getResistencia() const { return resistencia; }       // Retorna a resistência do organismo
    double getTaxaReproducao() const { return taxaReproducao; } // Retorna a taxa de reprodução do organismo
    int getGeracao() const { return geracao; }                  // Retorna a geração do organismo
};