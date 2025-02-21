// Includes e pragma
#pragma once           // Evita múltiplas inclusões
#include <vector>      // std::vector
#include "Organismo.h" // Header do Organismo

// Classe que representa o ambiente da simulação
class Ambiente
{

private:
    double temperatura;                  // Temperatura do ambiente
    double recursos;                     // Recursos disponíveis
    std::vector<Organismo *> organismos; // Vetor de organismos vivos

public:
    Ambiente(
        double temperatura = 20.0, // Temperatura inicial = 20°C
        double recursos = 1000.0   // Recursos iniciais = 1000
    );
    ~Ambiente(); // Destrutor(necessário para libertar memória dos organismos)

    void adicionarOrganismo(Organismo *org); // Adiciona um organismo ao ambiente
    void removerOrganismo(int indice);       // Remove um organismo do ambiente
    void atualizarRecursos();                // Atualiza os recursos disponíveis

    // Getters e Setters
    double getTemperatura() const { return temperatura; }                        // Retorna a temperatura do ambiente
    void setTemperatura(double temp) { temperatura = temp; }                     // Define a temperatura do ambiente
    double getRecursos() const { return recursos; }                              // Retorna os recursos disponíveis
    void setRecursos(double rec) { recursos = rec; }                             // Define os recursos disponíveis
    std::vector<Organismo *> &getOrganismos() { return organismos; }             // Retorna o vetor de organismos
    const std::vector<Organismo *> &getOrganismos() const { return organismos; } // Retorna o vetor de organismos (const)
};