#ifndef PROGRAMACAO_AUX114862_H
#define PROGRAMACAO_AUX114862_H

// Definição das bibliotecas necessárias
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Estrutura das estatisticas
struct Stats_S {
    int ngolos;
    int namarelos;
};

// Estrutura do jogador
struct Jogador_S {
    std::string nome;
    int numero;
    Stats_S stats;
};

// Protótipo das funções
void insertPlayer(std::vector<Jogador_S> &players);
void printPlayers(const std::vector<Jogador_S> &players);
void importPlayers(std::vector<Jogador_S> &players);
void exportPlayers(const std::vector<Jogador_S> &players);
void registerGoalYellow(std::vector<Jogador_S> &players);
void generateStats(const std::vector<Jogador_S> &players);

#endif //PROGRAMACAO_AUX114862_H