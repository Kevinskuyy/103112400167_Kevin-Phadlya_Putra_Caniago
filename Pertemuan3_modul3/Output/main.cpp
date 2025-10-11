#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    Mahasiswa mhs;

    inputMHS(mhs);
    cout << "Rata - rata nilai adalah : " << rata2(mhs) << endl;

    system("pause");
    return 0;
}