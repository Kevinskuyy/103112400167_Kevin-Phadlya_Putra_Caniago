#include <iostream>
using namespace std;

int main(){
    int angka;
    cout << "Masukan angka (0-100) : " ; 
    cin >> angka;

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (angka == 0) cout << "0 : nol ";
    else if (angka == 10 ) cout << "10 : sepuluh ";
    else if (angka == 11) cout << "11 : sebelas ";
    else if (angka < 10) cout << angka << " : " << satuan[angka] << " ";
    else if (angka < 20) cout << angka << " : " << satuan[angka - 10] << " belas ";
    else if (angka < 100){
        int puluhan = angka / 10;
        int sisa = angka % 10;
        cout << angka << " : " << satuan[puluhan] << " puluh ";
        if (sisa != 0) cout << satuan[sisa] << " ";
    }
    else if (angka == 100) cout << "100 : seratus ";
    else cout << "Angka di luar jangkauan" << endl;
    return 0;
}