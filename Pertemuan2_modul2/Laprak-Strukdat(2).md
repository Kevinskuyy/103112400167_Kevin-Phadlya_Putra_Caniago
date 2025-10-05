# <h1 align="center">Laporan Praktikum Modul 1 - Array & Pointer Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Kevin Phadlya Putra Caniago - 103112400167</p>

## Dasar Teori
Menurut Pratama (2024), C++ merupakan bahasa pemrograman yang mendukung paradigma prosedural dan berorientasi objek, serta memiliki konsep dasar penting seperti array dan pointer. Array digunakan untuk menyimpan sekumpulan data bertipe sama secara berurutan di memori, sehingga mempermudah pengelolaan dan akses data melalui indeks. Sementara itu, pointer adalah variabel yang menyimpan alamat memori dari variabel lain, memungkinkan program mengakses dan memanipulasi data secara langsung. Dalam C++, pointer dan array memiliki hubungan erat karena nama array sebenarnya menunjukkan alamat elemen pertamanya, sehingga keduanya dapat saling digunakan untuk mengakses data [1]

### A. Array
Array di C++ adalah kumpulan elemen dengan tipe data yang sama, disimpan dalam urutan tertentu di memori, dan dapat diakses menggunakan indeks. Array digunakan ketika kita ingin menyimpan banyak data sejenis tanpa harus membuat banyak variabel.

### B. Pointer
Pointer dalam C++ adalah variabel yang menyimpan alamat memori dari variabel lain.
Artinya, pointer tidak menyimpan nilai secara langsung, tetapi menyimpan lokasi di mana nilai tersebut berada di memori.

## Guided 

### 1. 

```C++
source code guided 1
#include <iostream>
using namespace std;

void tampilkanhasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] ={
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] ={
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    // penjumlahan matrik 2x2
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanhasil(arrC);

    cout << endl;

    // perkalian matrik 2x2
    for (int i = 0; i < 2; i++){            // perulangan baris 
        for (int j = 0; j < 2; j++){        // perulangan kolom 
            for (int k = 0; k < 2; k++){    // perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanhasil(arrD);
    return 0;
}
penjelasan singkat guided 1
Program ini melakukan operasi penjumlahan dan perkalian matriks berukuran 2x2 menggunakan bahasa C++.

### 2. ...

```C++
source code guided 2
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "Total Jumlah : " << totalJumlah << endl;

    int totalkali = 1;
    for (int i = 0; i < ukuran; i++){
        totalkali *= arr[i];
    }
    cout << "Total Perkalian : " << totalkali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++){
        cout << "Masukan angka ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}

penjelasan singkat guided 2
Program ini berfungsi untuk mencari nilai terbesar dalam array, serta menghitung total penjumlahan dan total perkalian dari semua elemen array yang dimasukkan oleh pengguna.

### 3. ...

```C++
source code guided 3
#include <iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // pointer ke elemen pertama array

    // mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; ++i){
        cout << "Elemen ke-" << i+1 << " menggunakan pointer " << *(ptr + i) << endl;
    }

    // mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; ++i){
        cout << "Elemen ke-" << i+1 << " menggunakan indeks " << arr[i] << endl;
    }
    return 0;
}
penjelasan singkat guided 3
Program ini menunjukkan dua cara mengakses elemen array di C++, yaitu menggunakan pointer dan indeks.


## Unguided 

### 1. Diketahui 2 buah matriks 3x3 seperti dibawah ini : 

matriksA = 
[7 12 22
31 6 41
15 19 36]      
MatriksB = 
[11 34 7
3 25 41
5 18 33]     

Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian 
matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; 
jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan 
kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case 
seperti berikut ini : 
--- Menu Program Matriks --- 
1. Penjumlahan matriks 
2. Pengurangan matriks 
3. Perkalian matriks 
4. Keluar

```C++
source code unguided 1
#include <iostream>
using namespace std;
const int N = 3;

void tampilMatriks(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void kurangMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void kaliMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int A[N][N] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int B[N][N] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int C[N][N];
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---\n";
        cout << "1. Penjumlahan matriks\n";
        cout << "2. Pengurangan matriks\n";
        cout << "3. Perkalian matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahMatriks(A, B, C);
                cout << "\nHasil Penjumlahan Matriks:\n";
                tampilMatriks(C);
                break;
            case 2:
                kurangMatriks(A, B, C);
                cout << "\nHasil Pengurangan Matriks:\n";
                tampilMatriks(C);
                break;
            case 3:
                kaliMatriks(A, B, C);
                cout << "\nHasil Perkalian Matriks:\n";
                tampilMatriks(C);
                break;
            case 4:
                cout << "\nProgram selesai.\n";
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/main/Pertemuan2_modul2/output%20no1.png)

penjelasan unguided 1 
Program C++ ini berfungsi untuk menjalankan kalkulasi standar (penjumlahan, pengurangan, dan perkalian) pada dua matriks 3×3 yang datanya telah ditetapkan sebelumnya.



###2.Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan 
dan perubahan nilainya menggunakan pointer, seperti berikut: 
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan 
luas (beri nilai 0). 
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar 
yang menunjuk ke variabel lebar.  
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. 
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar. 
4) Cetak nilai luas ke layar. 
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui 
pointer ptrPanjang dan ptrLebar. 
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa 
nilainya telah berubah.

```C++
source code unguided 2

#include <iostream>
using namespace std;
int main() {
    int panjang = 10, lebar = 5, luas = 0, keliling = 0;
    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar  : " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang : " << luas << endl;
    cout << "Keliling Persegi Panjang : " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru : " << panjang << endl;
    cout << "Lebar Baru   : " << lebar << endl;
    cout << "Luas Baru    : " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/main/output%20no%202.png)

penjelasan unguided 2
Program ini digunakan untuk menghitung luas dan keliling persegi panjang menggunakan pointer, serta menunjukkan bagaimana perubahan nilai melalui pointer akan memengaruhi variabel aslinya.

## Kesimpulan
Dari hasil praktikum yang telah dilakukan, dapat disimpulkan bahwa array dan pointer adalah dua konsep penting dalam pemrograman C++. Array digunakan untuk menyimpan banyak data yang memiliki tipe sama secara berurutan, sehingga memudahkan kita dalam mengolah dan mengakses data menggunakan indeks. Sedangkan pointer berfungsi untuk menyimpan alamat memori dari suatu variabel, sehingga program bisa membaca dan mengubah nilai variabel tersebut secara langsung.

## Referensi
[1] Moenawar. (2018). Pointer dan Fungsi dalam C/C++. Diakses melalui https://moenawar.web.id/wp-content/uploads/2018/03/SD-Lab-5-6-pointer-dan-fungsi.pdf
[2] Sindar, Anita. (2019). Struktur Data dan Algoritma dengan C++. Medan: Universitas Negeri Medan