// Includes e pragma
#pragma once
#include "Simulacao.h" // Simulacao
#include "UI.h"        // Interface do Utilizador
#include <iostream>    // std::cout, std::cin

// Classe que representa o jogo
class Jogo
{

private:
    Simulacao simulacao;                // Simulação do jogo
    bool aExecutar;                     // Indica se o jogo está em execução
    void processarEntrada(int escolha); // Processa a escolha do utilizador
    void coletarEnergia();              // Coleta energia

public:
    Jogo();         // Construtor
    void iniciar(); // Inicia o jogo
};