// Includes e pragma
#pragma once           // Evita múltiplas inclusões
#include "Simulacao.h" // Simulacao
#include "Ambiente.h"  // Ambiente
#include <string>      // std::string

class InterfaceUtilizador
{
public:
    // Inicialização e controle da consola
    static void inicializarConsola(); // Configura UTF-8 e formatação
    static void limparConsola();      // Limpa a tela

    // Interface principal
    static void mostrarMenu();     // Mostra menu principal
    static int obterEscolhaMenu(); // Obtém escolha do usuário

    // Visualizações detalhadas
    static void mostrarEstatisticas(const Simulacao &sim); // Mostra estatísticas completas
    static void mostrarGeracao(const Ambiente &ambiente);  // Mostra estado atual
    static void mostrarFase(const Simulacao &sim);         // Mostra fase atual

    // Utilidades de interface
    static void mostrarMensagem(const std::string &msg, // Mostra mensagem ao usuário
                                bool erro = false);     // true para erro, false para sucesso
    static void pausar();                               // Aguarda input do usuário
};