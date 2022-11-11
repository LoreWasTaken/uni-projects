// Denis Sukhachev Nº Mec.: 114862
#include "iostream"
#include "iomanip"
using namespace std;

// Função para calcular a média pedido em e)
double calculaMedia(int array[], int array_size){
    double Media = array[0];
    for (int i = 0; i < array_size; i++){
        Media += array[i];
    }
    return Media / array_size;
}

// Função para calcular módulo pedido em f)
void calculaModulo(int *array, int array_size){
    for (int i = 0; i < array_size; i++){
            //cout << abs(array[i]) << " ";
            if(array[i] < 0)
                array[i] = abs(array[i]);
    }
    cout << endl;
}

// Função para comparar a média pedido em g)
void comparaMedia(int array[], int array_size){
    double media = calculaMedia(array, array_size);
    cout << left << "Valor" << "----" << right << "Posição" << endl
         << "----------------" << endl;
    for (int i = 0; i < array_size; i++)
        cout << array[i] << setfill('-') << setw(15) << ((array[i] < media) ? "inferior" : (array[i] > media) ? "maior" : "igual") << endl;
}

int main(){
    int N;
    // a) Imprimir Nome e NMec.

    cout << "a)" << endl;
    cout << "Denis Sukhachev, 114862" << endl;

    // b) Pedir ao utilizador um número inteiro no intervalo fechado [4, 16].
    // Validação do número introduzido pelo utilizador, pedindo um novo número caso o atual seja inválido.

    cout << "b)" << endl;
    do{
        cout << "Insira um valor entre 4 e 16: ";
        cin >> N;
    } while ( (N < 4) || (N > 16) );

    // c) Pedir ao utilizador para fornecer N números inteiros, sendo N o número lido na alínea anterior(b)),
    // e armazenar esses números num array de "inteiros" com N elementos.

    int array[N];
    cout << "c)" << endl;
    cout << "Insira " << N << " valores inteiros: ";
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    // d) Imprimir no ecrã todos os valores do array, numa única linha, separados por espaço

    cout << "d) O conteúdo do array é: " << endl;
    for (int i = 0; i < N; i++)
        cout << array[i] << " ";
    cout << endl;

    // e) Utilização da função para calcular e devolver a média dos elementos do array.
        cout << "e)" << endl;
        cout << "O valor da média é " << calculaMedia(array, N) << endl;

    // f) Esta função substitui os elementos negativos do array, pelo seu simétrico
        cout << "f)" << endl;
        cout << "O conteudo do array modificado é: " << endl;
        calculaModulo(array, N);
        cout << array << " " << endl;

    // g) Utilizar função para comparar cada um dos valores com a média

        cout << "g)" << endl;
        comparaMedia(array, N);

}

