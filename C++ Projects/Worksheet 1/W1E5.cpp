#include "iostream"
#include "iomanip"
using namespace std;

int main()
{
    cout << setw(9) << "Last Name" << setw(15) << "First Name" << setw(14) << "Town" << setw(15) << "Country" << endl;
    cout << setw(15) << "----------------------------------------------------------" << endl;
    cout << setw(14) << left << "Silva" << setw(20) << "Joao" << setw(12) << "Aveiro" << setw(15) << "Portugal" << endl;
    cout << setw(14) << left << "Almeida" << setw(20) << "Maria" << setw(12) << "Madrid" << setw(15) << "Spain" << endl;
    cout << setw(14) << left << "Santos" << setw(20) << "Miguel" << setw(12) << "Moscow" << setw(15) << "Russia" << endl;

    return 0;
}

