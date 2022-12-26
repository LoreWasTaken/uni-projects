#include "aux114862.h"
using namespace std;

/*
// Estrutura das estatisticas
struct Stats_S {
    int ngolos;
    int namarelos;
};

// Estrutura do jogador
struct Jogador_S {
    string nome;
    int numero;
    Stats_S stats;
};
*/

// Função para inserir um jogador novo
void insertPlayer(vector<Jogador_S> &players) {
    Jogador_S player;

    cout << "Nome do jogador: ";
    getline(cin, player.nome);

    // Pedir ao utilizador para inserir o número do jogador com verificação do número ser entre 1 e 99
    do {
        cout << "Número do jogador: ";
        cin >> player.numero;
        cin.ignore(); // Ignorar o caracter da nova linha no input buffer
    } while (player.numero < 1 || player.numero > 100);

// Condições iniciais para todos os jogadores criados
    player.stats.ngolos = 0;
    player.stats.namarelos = 0;

// Guardar o jogador criado num vetor com os jogadores
    players.push_back(player);
}

// Função para imprimir os dados dos jogadores
void printPlayers(const vector<Jogador_S> &players) {
    if (players.empty()) {
        cout << "Não foram inseridos jogadores!" << endl;
        return;
    }

    cout << left << setw(10) << "Nome" << setw(10) << "Numero" << setw(10) << "Golos" << setw(10) << "Amarelos" << endl;
    for (const Jogador_S &player : players) {
        cout << left << setw(10) << player.nome << setw(10) << player.numero << setw(10) << player.stats.ngolos << setw(10) << player.stats.namarelos << endl;
    }
}

// Função para importar jogadores de um ficheiro
void importPlayers(vector<Jogador_S> &players) {
    // Perguntar ao utilizador o nome do ficheiro
    string filename;
    cout << "Nome do ficheiro: ";
    getline(cin, filename);

    // Se não encontrar o ficheiro, dá erro
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }

    // Se encontrar, importa os jogadores do ficheiro de texto do nome que o utilizador inseriu
    while (!file.eof()) {
        Jogador_S player;
        file >> player.nome >> player.numero >> player.stats.ngolos >> player.stats.namarelos;
        players.push_back(player);
    }
    // Fechar o ficheiro de depois de terminar
    file.close();
}

// Função para exportar jogadores para um ficheiro
void exportPlayers(const vector<Jogador_S> &players) {
    // Perguntar ao utilizador o nome do ficheiro
    string filename;
    cout << "Nome do ficheiro: ";
    getline(cin, filename);

    // Se não encontrar o ficheiro, dá erro
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o ficheiro!" << endl;
        return;
    }

    // Se encontrar o ficheiro, exporta os jogadores para um ficheiro de texto com o nome que o utilizador inseriu
    for (const Jogador_S &player : players) {
        file << player.nome << " " << player.numero << " " << player.stats.ngolos << " " << player.stats.namarelos << endl;
    }
    // Fechar o ficheiro de depois de terminar
    file.close();
}

// Função para registar um golo ou cartão amarelo
void registerGoalYellow(vector<Jogador_S> &players) {
    // Perguntar o número do jogador ao utilizador
    int playerNumber;
    cout << "Numero do Jogador?: ";
    cin >> playerNumber;

    // Procurar pelo jogador com o número dado
    Jogador_S *player = nullptr;
    for (Jogador_S &p : players) {
        if (p.numero == playerNumber) {
            player = &p;
            break;
        }
    }

    // Dá erro se o jogador não for encontrado
    if (player == nullptr) {
        cout << "Jogador não encontrado!" << endl;
        return;
    }

    int choice;
    cout << "Insira 1 para registar GOLO, ou 2 para registar CARTÃO: ";
    cin >> choice;

    // Adiciona um golo ou um amarelo dependendo do que o utilizador escolher
    if (choice == 1) {
        player->stats.ngolos++;
    } else if (choice == 2) {
        player->stats.namarelos++;
    } else {
        cout << "Opcão incorreta!" << endl;
    }
}

// Função para gerar as estatísticas da equipa
void generateStats(const vector<Jogador_S> &players) {
    // Inicializar as variáveis
    int totalGoals = 0;
    int totalYellowCards = 0;
    int maxGoals = 0;
    string maxGoalsPlayer;
    int maxYellowCards = 0;
    string maxYellowCardsPlayer;

    // Procurar pelo jogar que teve mais golos e o jogador que teve mais amarelos
    for (const Jogador_S &player : players) {
        totalGoals += player.stats.ngolos;
        totalYellowCards += player.stats.namarelos;

        if (player.stats.ngolos > maxGoals) {
            maxGoals = player.stats.ngolos;
            maxGoalsPlayer = player.nome;
        }

        if (player.stats.namarelos > maxYellowCards) {
            maxYellowCards = player.stats.namarelos;
            maxYellowCardsPlayer = player.nome;
        }
    }

    // Imprimir o resultado
    cout << "A equipa marcou um total de " << totalGoals << " golos" << endl;
    cout << "A equipa levou um total de " << totalYellowCards << " cartões amarelos" << endl;
    cout << "O maior goleador é o " << maxGoalsPlayer << " com " << maxGoals << " golos" << endl;
    cout << "O jogador mais amarelado é o " << maxYellowCardsPlayer << " com " << maxYellowCards << " cartões amarelos" << endl;
}