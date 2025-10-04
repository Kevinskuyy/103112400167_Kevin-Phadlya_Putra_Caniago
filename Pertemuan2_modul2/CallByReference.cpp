#include <iostream>
using namespace std;

void ubahNilai(int& ref){
    ref = 20; // mengubah nilai yang direferensikan
}

int main(){
    int x = 10;
    cout << "nilai sebelum diubah: " << x << endl;

    ubahNilai(x); // mengirim reference ke x
    cout << "nilai setelah diubah: " << x << endl;

    return 0;
}