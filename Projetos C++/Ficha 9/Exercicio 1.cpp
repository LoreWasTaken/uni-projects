// denis: Programa não funciona como entendido, primeira tentativa de fazer o que é suposto
// denis: Exercicio 1.1 faz o que é pedido 

#include "fstream"
#include "iostream"
#include "cmath"
using namespace std;

double Average(int list[], int size){
    double average = 0.0;
    for (int i = 0; i < size; i++){
        average += list[i];
    }
    return average / size;
}

double StandardDeviation(int list[], int size){
    double average_deviation = 0;
    for (int i = 0; i < size; i++){
        double deviation = pow((float)list[i] - Average(list, size), 2);
        average_deviation += deviation;
    }
    return sqrt(average_deviation / size);
}
int main(){
    // Ask the user what name they want to use for file
    string fname;
    cout << "insira nome do ficheiro: ";
    getline(cin,fname);
    ifstream infile(fname);
    int tmp;

    while(infile.good()){
        infile >> tmp;
        //cout << tmp << endl;
    }
    int size = tmp;
    int *numbers = NULL;
    numbers = new int[size];
    double average = Average(numbers, size);

    for (int i = 0; i < size; i++){
        if (numbers[i] > average)
            cout << i << endl;
    }

    delete [] numbers;
    infile.close();
}
