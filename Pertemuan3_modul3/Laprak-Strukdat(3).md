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

// Struktur Node
struct Node {
    float info;
    Node* next;
};

// Deklarasi List
typedef Node* List;

// Membuat Node baru
Node* createNode(float X) {
    Node* p = new Node;
    p->info = X;
    p->next = NULL;
    return p;
}

// Menambah elemen di akhir list
void insertLast(List &L, Node* p) {
    if (L == NULL) {
        L = p;
    } else {
        Node* last = L;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p; 
    }
}

// Mencari nilai X di list
bool searchX(List L, float X) {
    Node* p = L;
    while (p != NULL) {
        if (p->info == X)
            return true;
        p = p->next;
    }
    return false;
}

// Menghapus elemen sesuai kondisi soal
void deleteElement(List &L, float X) {
    if (L == NULL) {
        cout << "List kosong" << endl;
        return;
    }

    // Cek apakah X ada
    if (!searchX(L, X)) {
        cout << "Tidak ada elemen bernilai " << X << endl;
        return;
    }

    // Jika X di awal list
    if (L->info == X) {
        Node* del = L;
        L = L->next;
        delete del;
        cout << "Elemen awal bernilai X dihapus" << endl;
        return;
    }

    Node* p = L;
    Node* prev = NULL;

    // Cari node dengan nilai X
    while (p != NULL && p->info != X) {
        prev = p;
        p = p->next;
    }

    // Jika X ditemukan dan bukan di akhir list
    if (p != NULL && p->next != NULL) {
        Node* del = p->next;
        p->next = del->next;
        cout << "Elemen setelah " << X << " dihapus" << endl;
        delete del;
        return;
    }

    // Jika X di akhir list
    prev->next = NULL;
    delete p;
    cout << "Elemen " << X << " di akhir list dihapus" << endl;
}

// Menampilkan list
void printList(List L) {
    Node* p = L;
    while (p != NULL) {
        cout << p->info << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Program utama
int main() {
    List L = NULL;
    float X;

    // Membuat list awal
    insertLast(L, createNode(15));
    insertLast(L, createNode(30));
    insertLast(L, createNode(40));
    insertLast(L, createNode(50));

    cout << "List awal: ";
    printList(L);

    cout << "Masukkan nilai X: ";
    cin >> X;

    deleteElement(L, X);

    cout << "List setelah penghapusan: ";
    printList(L);

    return 0;
}

penjelasan singkat guided 2
Program ini membuat **linked list** berisi angka, lalu meminta input nilai **X** dan **menghapus elemen tertentu** sesuai posisi X:

* Jika X di awal → hapus elemen pertama.
* Jika X di tengah → hapus elemen setelah X.
* Jika X di akhir → hapus elemen terakhir.
Kemudian program menampilkan list sebelum dan sesudah penghapusan.


### 3. ...

```C++
source code guided 3

penjelasan singkat guided 3
Program ini menunjukkan dua cara mengakses elemen array di C++, yaitu menggunakan pointer dan indeks.


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
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/main/Pertemuan2_modul2/output%20no1.png)

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

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1] 
penjelasan unguided 2
...

## Kesimpulan
...

## Referensi
...