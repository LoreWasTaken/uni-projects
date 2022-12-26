// denis: Desafio 2 de programação utilizando strings, estruturas, memória dinâmica e operação sobre ficheiros de texto
 
#include "aux114862.h"
using namespace std;

int main(int argc, char* argv[])
{
    // Vetor para guardar os jogadores criados
    vector<Jogador_S> players;

    // Se um nome de ficheiro for passado como argumento, importa jogadores do ficheiro
    if (argc > 1) {
        importPlayers(players);
    }

    while (true) {
        cout << "1 - Inserir jogador" << endl;
        cout << "2 - Listar Equipa" << endl;
        cout << "3 - Importar Equipa" << endl;
        cout << "4 - Exportar Equipa" << endl;
        cout << "5 - Registar Golo/Cartão" << endl;
        cout << "6 - Gerar estatísticas" << endl;
        cout << "0 - Finalizar o programa" << endl;

        int choice;
        cin >> choice;
        cin.ignore(); // Ignorar o caracter da nova linha no input buffer

        // Dispatch the appropriate function based on the user's choice
        switch (choice)
        {
            case 1:
                insertPlayer(players);
                break;
            case 2:
                printPlayers(players);
                break;
            case 3:
                 importPlayers(players);
                break;
            case 4:
                 exportPlayers(players);
                break;
            case 5:
                 registerGoalYellow(players);
                break;
            case 6:
                 generateStats(players);
                break;
            case 0:
                cout << "Boas férias!" << endl;
                return 0;
            default:
                cout << "Escolha inválida!" << endl;
                break;
        }
    }
}