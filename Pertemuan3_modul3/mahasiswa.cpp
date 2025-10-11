#include <iostream>
#include "mahasiswa.h"

using namespace std;

//relasi dari fungsi inputMhs
void inputMHS(Mahasiswa &m) {
    cout << "input NIM:";
    cin >> m.nim;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}

//relasi dari fungsi rata2
float rata2(Mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2;

}