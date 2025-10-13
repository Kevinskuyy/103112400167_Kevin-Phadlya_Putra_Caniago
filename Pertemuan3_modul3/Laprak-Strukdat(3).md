# <h1 align="center">Laporan Praktikum Modul 1 - ABSTRACT DATA TYPE (Bagian Kedua)</h1>
<p align="center">Kevin Phadlya Putra Caniago - 103112400167</p>

## Dasar Teori
Menurut Dale & Weems (2020), Abstract Data Type (ADT) adalah model logis dari suatu struktur data yang mendefinisikan apa yang dapat dilakukan oleh data, bukan bagaimana cara implementasinya. Dengan ADT, programmer dapat fokus pada operasi seperti menambah, menghapus, atau menelusuri data tanpa memikirkan detail penyimpanan di memori.
Contoh ADT yang sering digunakan antara lain List, Stack, Queue, dan Tree.

### A. Single linked list
Single Linked List dalam bahasa C adalah struktur data berantai satu arah, di mana setiap elemen (disebut node) berisi:
1.Data — nilai yang disimpan (misalnya angka atau karakter), dan
2.Pointer — alamat menuju node berikutnya.

### B. Pointer
Double Linked List (Doubly Linked List) adalah struktur data berantai dua arah, di mana setiap elemen (node) memiliki dua pointer:
1.prev → menunjuk ke node sebelumnya,
2.next → menunjuk ke node berikutnya,
3.serta data yang disimpan di tengahnya

## Guided 

### 1. 

```C++
source code guided 1
#include <iostream>
using namespace std;

struct node{
    float data;
    node* next;

}; 

struct list{
    node* first;

};

void buatList(list &L){
    L.first = NULL;
    
}

node* buatElemen(float X){
    node* elm = new node;
    elm -> data = X;
    elm -> next = NULL;
    return elm;
}
void insertAscending( list &L, node* elm){
    if (L.first == NULL || elm -> data < L.first -> data ){
        elm -> next = L.first;
        L.first = elm;

    }
    else{
        node* before = L.first;
        node* after = L.first -> next;
        while(after != NULL && elm -> data > after -> data){
            before = after;
            after = after -> next;
        }
        elm -> next = after;
        before -> next = elm;
    }
}

void tampilList(list L){
    node* p = L.first;
    while(p != NULL){
        cout << p -> data << " -> ";
        p = p -> next;
    }
    cout << "NULL " << endl;
}

int main(){
    list L;
    buatList(L);

    node* satu = buatElemen(10.5);
    node* dua = buatElemen(12.0);
    node* tiga =  buatElemen(20.9);
    node* empat = buatElemen(25.1);

    satu -> next = dua;
    dua -> next = tiga;
    tiga -> next = empat;

    L.first = satu;
    
    cout << "isi list : " << endl;
    tampilList(L);

    float X;
    cout << "Masukan nilai : ";
    cin >>  X;

    node* elm = buatElemen(X);
    insertAscending(L, elm );
    cout << "List setelah ditambah : " << endl;
    tampilList(L);
    return 0;
}
```
penjelasan singkat guided 1
Program ini membuat struktur data Linked List (daftar berantai) dengan tipe data float, lalu:

1.Membuat list awal berisi beberapa elemen.
2.Menampilkan isi list.
3.Meminta pengguna memasukkan angka baru.
4.Menyisipkan angka tersebut ke dalam list secara berurutan (ascending).
5.Menampilkan hasil akhir setelah penyisipan.

### 2. 

```C++
source code guided 2
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
```
penjelasan singkat guided 2
Program ini digunakan untuk menginput data mahasiswa (nama dan dua nilai), lalu menghitung rata-rata nilainya menggunakan fungsi dan struct (ADT).

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
source code unguided 1
#include <iostream>
using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    string nama, nim;
    float uts, uas, tugas;
    int n;

    cout << "Jumlah mahasiswa (maks 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNama: "; cin >> nama;
        cout << "NIM : "; cin >> nim;
        cout << "UTS : "; cin >> uts;
        cout << "UAS : "; cin >> uas;
        cout << "Tugas: "; cin >> tugas;

        cout << "Nilai Akhir: " << hitungNilaiAkhir(uts, uas, tugas) << endl;
    }
}

```
##### Output 1
![Screenshot Output Unguided 1_1] (https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/cfefbd105e10acacceb1f3b8e78e6ff0842e0439/Pertemuan3_modul3/output%20nomor%201%20pertemuan%203.png)

penjelasan unguided 1 
Program C++ ini berfungsi untuk menghitung nilai akhir beberapa mahasiswa 


###2.Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h" ... 

source code unguided 2

file main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);

    return 0;
}
```

file pelajaran.cpp
```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaPel;
    p.kodeMapel = kodePel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

file pelajaran.h
```C++ 
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};
pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(pelajaran pel);
#endif
```

### Output Unguided 2 :
![Screenshot Output Unguided 1_1] (https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/cfefbd105e10acacceb1f3b8e78e6ff0842e0439/Pertemuan3_modul3/output%20no2%20pertemuan%203.png)


penjelasan unguided 2
Program ini digunakan untuk menyimpan dan menampilkan data pelajaran (nama pelajaran dan kode pelajaran) menggunakan konsep modularisasi yaitu memisahkan kode menjadi beberapa file:
-main.cpp → program utama
-pelajaran.h → header (deklarasi struct & fungsi)
-pelajaran.cpp → implementasi fungsi


###3.Buatlah program dengan ketentuan:
-2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
-fungsi/prosedur yang menampilkan isi sebuah array integer 20
-fungsi/prosedur yang akan menukarkan isi dari 2 array integer 20 pada posisi tertentu
-fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

source code unguided 3
```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void tukarElemen(int arr1[3][3], int arr2[3][3], int i, int j) {
    int temp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = temp;
}

void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;

    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    tukarElemen(A, B, 1, 1);
    cout << "Setelah tukar A[1][1] dan B[1][1]:" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    cout << "Sebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(p1, p2);
    cout << "Setelah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}
```

### Output Unguided 3 :
![Screenshot Output Unguided 1_1] (https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/cfefbd105e10acacceb1f3b8e78e6ff0842e0439/Pertemuan3_modul3/output%20no3%20pertemuan%203.png)

## Kesimpulan
ADT membantu memisahkan antara logika data dan cara implementasinya, sehingga program lebih mudah dipahami, STRUCT digunakan untuk membuat tipe data baru seperti data mahasiswa dan pelajaran, LINKED LIST merupakan penerapan ADT yang menggunakan pointer untuk menghubungkan antar elemen data

## Referensi
[1] Deitel, P. J., & Deitel, H. M. (2017). C++ How to Program (10th Edition). Pearson Education.
[2] GeeksforGeeks. Abstract Data Types (ADT) in C++. https://www.geeksforgeeks.org/abstract-data-types/