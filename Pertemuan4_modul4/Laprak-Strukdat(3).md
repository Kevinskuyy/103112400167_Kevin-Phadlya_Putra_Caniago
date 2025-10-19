# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (Bagian Pertama)</h1>
<p align="center">Kevin Phadlya Putra Caniago - 103112400167</p>

## Dasar Teori
Menurut Horowitz dan Sahni (1984), Singly Linked List merupakan struktur data linear yang terdiri dari sekumpulan elemen yang disebut node, di mana setiap node menyimpan data dan satu pointer yang menunjuk ke node berikutnya. Setiap node pada Singly Linked List memiliki dua bagian utama, yaitu bagian data untuk menyimpan nilai dan bagian pointer untuk menyimpan alamat node berikutnya (Lafore, 2002). Struktur ini bersifat dinamis karena memungkinkan penambahan dan penghapusan elemen tanpa perlu mengalokasikan ulang seluruh memori seperti pada array.

### A. SINGLY LINKED LIST
Singly linked list adalah struktur data linier di mana setiap elemen, yang disebut simpul (node), berisi data dan sebuah pointer yang hanya menunjuk ke simpul berikutnya dalam daftar. Karena hanya ada satu pointer, traversi atau penelusuran hanya bisa dilakukan dalam satu arah, yaitu dari awal (kepala) ke akhir (ekor). Simpul terakhir dalam daftar akan menunjuk ke NULL (atau nilai kosong), menandakan akhir dari daftar. 

## Guided 

### 1. 

file list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
file list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
file main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

penjelasan singkat guided 1
Program di atas merupakan implementasi Singly Linked List dalam bahasa C++ untuk menyimpan dan menampilkan data mahasiswa.

### 2. ...
file list.cpp
```C++
source code guided 2
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
file list.h
```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

file main.cpp
```C++
// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

penjelasan singkat guided 2
Program di atas merupakan implementasi lengkap dari Singly Linked List dalam bahasa C++ yang mencakup proses penambahan, penghapusan, penelusuran, dan penghapusan seluruh data.


## Unguided 

### 1. Soal Unguided 1...

file main.cpp
```C++
#include "Singlylist.h"

int main(){
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```

file singlylist.cpp
```C++
#include "Singlylist.h"

void CreateList(List &L){
    L.First = NULL;
}
address alokasi (infotype X){
    address P = new ElmList;
    if (P != NULL){
        P -> info = X;
        P -> next = NULL;
    }
    return P;
}
void dealokasi (address &P){
    delete P;
    P = NULL;
}
void printInfo(List L){
    address P = L.First;
    while(P != NULL){
        cout << P -> info << " ";
        P = P -> next;

    }
    cout << endl;
}
void insertFirst (List &L, address P){
    P -> next = L.First;
    L.First = P;
}
```

file singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infotype;
//typedef ElmList* address;

struct ElmList{
   infotype info;
   ElmList* next;
};
typedef ElmList* address;
struct List{
    address First;
};

void CreateList(List &L);
address alokasi (infotype X);
void dealokasi (address &P);
void printInfo (List L);
void insertFirst (List &L, address P);

#endif 
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/71f336217b9bb9e43eec2d8371c054b51c4bb65b/Pertemuan4_modul4/nomor1/UNGUIDED%201.png)

penjelasan unguided 1 
Program C++ ini berfungsi untuk menjalankan kalkulasi standar (penjumlahan, pengurangan, dan perkalian) pada dua matriks 3×3 yang datanya telah ditetapkan sebelumnya.



###2.Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 
2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan 
jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh 
node menggunakan deleteList(). 
Output yang diharapkan : 
12 0  
Jumlah node : 2 - List Berhasil Terhapus –  
Jumlah node : 0

file main.cpp
```C++

#include "singlylist.h"

int main(){
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L, P1);
    deleteLast(L,P5);

    address P;
    deleteAfter(L, P, P4);
    dealokasi(P);
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "List berhasil terhapus " << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
file singlylist.cpp
```C++
#include "singlylist.h"

void CreateList(List &L){
    L.First = NULL;
}
address alokasi (infotype X){
    address P = new ElmList;
    if (P != NULL){
        P -> info = X;
        P -> next = NULL;
    }
    return P;
}
void dealokasi (address &P){
    delete P;
    P = NULL;
}
void printInfo(List L){
    address P = L.First;
    while(P != NULL){
        cout << P -> info << " ";
        P = P -> next;

    }
    cout << endl;
}
void insertFirst (List &L, address P){
    P -> next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P){
    if (L.First != NULL){
        P = L.First;
        L.First = L.First -> next;
        P -> next = NULL;
    }else{
        P = NULL;
    }
}
void deleteLast(List &L, address &P){
    if (L.First != NULL){
        address Q = L.First;
        if(Q -> next == NULL){
            P = Q;
            L.First = NULL;
        }else{
            while (Q -> next -> next != NULL){
                Q = Q -> next;
            }
            P = Q -> next;
            Q -> next = NULL;


        }
    }else{
        P = NULL;
    }
}
void deleteAfter(List &L, address &P, address prec){
    if (prec != NULL && prec -> next != NULL){
        P = prec -> next;
        prec -> next = P -> next;
        P -> next = NULL;
    }else{
        P = NULL;
    }
}
int nbList(List L){
    int count = 0;
    address P = L.First;
    while (P != NULL){
        count++;
        P = P -> next;
    }
    return count;
}

void deleteList(List &L){
    address P;
    while (L.First != NULL){
        deleteFirst(L, P);
        //dealokasi(P);
    }
}
```
file singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infotype;
//typedef ElmList* address;

struct ElmList{
   infotype info;
   ElmList* next;
};

typedef ElmList* address;

struct List{
    address First;
};

void CreateList(List &L);
address alokasi (infotype X);
void dealokasi (address &P);
void printInfo (List L);
void insertFirst (List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address prec);
int nbList(List L);
void deleteList(List &L);

#endif 
```

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/71f336217b9bb9e43eec2d8371c054b51c4bb65b/Pertemuan4_modul4/nomor2/UNGUIDED%202.png)

penjelasan unguided 2
Program di atas merupakan implementasi Singly Linked List dalam bahasa C++ yang memiliki fungsi untuk menambah, menghapus, menampilkan, dan menghitung jumlah elemen (node) dalam list.

## Kesimpulan
...


## Referensi
...