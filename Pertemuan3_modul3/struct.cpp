#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai1;
    float nilai2;
};

void inputMHS(Mahasiswa &m) {
    cout << "input nama:";
    cin >> m.nama;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}
float rata2(Mahasiswa m) {
    return float (m.nilai1 + m.nilai2) / 2;
}

int main(){
    Mahasiswa mhs; // Pemanggil struct (ADT)
    inputMHS(mhs); // Pemanggil prosedur
    cout << "Rata - rata: " << rata2(mhs) << endl; // Pemanggil function
    return 0;

}