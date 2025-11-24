# <h1 align="center">Laporan Praktikum Modul 7 - QUEUE </h1>
<p align="center">Kevin Phadlya Putra Caniago - 103112400167</p>

## Dasar Teori
Struktur data adalah cara untuk mengatur, menyimpan, dan mengelola data di dalam komputer agar data mudah diakses, diproses, dan diubah. Dengan struktur data, data bisa dikelola dengan lebih baik dan program berjalan lebih cepat dalam memproses informasi. Struktur data juga membantu memahami bagaimana data saling terhubung, sehingga memudahkan pencarian dan pengubahan data sesuai kebutuhan aplikasi. Menggunakan struktur data yang tepat akan membantu programmer meningkatkan kinerja aplikasi dan menghadapi masalah data yang rumit [1].

### A. QUEUE
Queue merupakan struktur data yang dapat diumpamakan seperti sebuah antrean,Jadi prinsip dasar dalam Queue adalah FIFO (First in Fisrt out), proses yang pertama masuk akan diakses terlebih dahulu. Dalam pengimplementasian struktur Queue dalam C dapat menggunakan tipe data array dan linked list.


## Guided 

### 1. 

file main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah updateQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchQueue(Q, 4);
    searchQueue(Q, 9);

    return 0;
}
```

file queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchQueue(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    int dataAngka;
    address next;
};

struct queue {
    address head;
    address tail;
};
bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi (int angka);
void dealokasi (queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchQueue(queue Q, int data);
#endif
```

penjelasan singkat guided 1
Program tersebut mengimplementasikan struktur data Queue (antrian) menggunakan linked list. Setiap elemen queue disimpan dalam node yang berisi data angka dan pointer ke node berikutnya. Queue memiliki dua pointer utama, yaitu head untuk menunjuk elemen paling depan dan tail untuk menunjuk elemen paling belakang. Program menyediakan fungsi dasar seperti createQueue untuk inisialisasi, isEmpty untuk mengecek apakah queue kosong, alokasi dan dealokasi untuk membuat serta menghapus node, enqueue untuk menambahkan elemen ke bagian belakang queue, dan dequeue untuk menghapus elemen dari bagian depan queue. Selain itu, terdapat fitur tambahan seperti updateQueue yang memungkinkan pengguna mengganti nilai node tertentu berdasarkan posisi, viewQueue untuk menampilkan seluruh isi queue, dan searchData untuk mencari apakah suatu nilai terdapat dalam queue. Pada fungsi main, program membuat lima node (1 - 5), menambahkannya ke queue, menampilkan antrian, menghapus dua node terdepan, mengupdate beberapa posisi, dan melakukan pencarian data.


### 2. Guided
file main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" <<  endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```

file queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

penjelasan singkat guided 2
Program tersebut mengimplementasikan Circular Queue menggunakan array berukuran tetap (MAX_QUEUE = 5). Struktur queue menyimpan tiga informasi penting: indeks head sebagai posisi elemen depan, tail sebagai posisi elemen belakang berikutnya, serta count sebagai jumlah elemen yang sedang tersimpan. Fungsi createQueue menginisialisasi queue agar kosong, sementara isEmpty dan isFull digunakan untuk mengecek kondisi queue. Operasi enqueue menambahkan data ke posisi tail, lalu memutar indeks menggunakan operasi modulus agar bersifat circular. Sebaliknya, dequeue mengambil elemen dari head dan menggeser posisi kepala secara circular. Fungsi printInfo menampilkan seluruh isi queue sesuai jumlah elemen yang tersimpan. Pada fungsi main, program mendemonstrasikan cara kerja circular queue dengan menambah beberapa elemen, menghapus elemen dari depan, menambah elemen lagi setelah terjadi perputaran indeks, dan menampilkan isi queue setiap kali ada perubahan.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”: Type infotype: integer Type Queue: < info : array [5] of infotype {index array dalam C++ dimulai dari 0} head, tail : integer
procedure CreateQueue (input/output Q: Queue) function isEmptyQueue (Q: Queue) → boolean function isFullQueue (Q: Queue) → boolean procedure enqueue (input/output Q: Queue, input x: infotype) function dequeue (input/output Q: Queue) → infotype procedure printInfo (input Q: Queue) Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
int main() { cout << "Hello World" << endl; Queue Q; createQueue(Q); cout<<"----------------------"<<endl; cout<<" H - T \t | Queue info"<<endl; cout<<"----------------------"<<endl; printInfo(Q); enqueue(Q,5); printInfo(Q); enqueue(Q,2); printInfo(Q); enqueue(Q,7); printInfo(Q); dequeue(Q); printInfo(Q); enqueue(Q,4); printInfo(Q); dequeue(Q); printInfo(Q); dequeue(Q); printInfo(Q); return 0; }

file queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MaxEl 5     
#define Nil -1      

typedef int infotype;

struct Queue {
    infotype info[MaxEl];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

file queue.cpp 

```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];

        if (Q.head == Q.tail) {
    
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head++;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t: ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}

```

file main.cpp 

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << "H - T | Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
``` 

### 2. Soal Unguided 2
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MaxEl 5     
#define Nil -1      

typedef int infotype;

struct Queue {
    infotype info[MaxEl];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

file queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
    
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++; 
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t: ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

file main.cpp 
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << "H - T | Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```

### 3. Soal Unguided 3
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar)

file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MaxEl 5     
#define Nil -1      

typedef int infotype;

struct Queue {
    infotype info[MaxEl];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

file queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    
    return (!isEmptyQueue(Q) && ((Q.tail + 1) % 5 == Q.head));
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % 5;   
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % 5;   
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t: ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % 5;
        }
        cout << endl;
    }
}
```

file main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << "H - T | Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/5d000ee127ac2c09eaabf10378b47edda02fad1c/Pertemuan8_modul8/unguided1/Screenshot%202025-11-24%20090120.png)

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/5d000ee127ac2c09eaabf10378b47edda02fad1c/Pertemuan8_modul8/unguided2/Screenshot%202025-11-24%20090357.png)

### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/5d000ee127ac2c09eaabf10378b47edda02fad1c/Pertemuan8_modul8/unguided3/Screenshot%202025-11-24%20090559.png)

penjelasan unguided 1 
Kode ini mendefinisikan struktur data antrean menggunakan array di C++. Fungsi-fungsi yang diimplementasikan antara lain untuk membuat antrean, memeriksa apakah antrean kosong atau penuh, menambah (enqueue) dan mengeluarkan (dequeue) elemen, serta menampilkan kondisi antrean. File utama menguji antrean dengan beberapa operasi seperti menambah dan mengeluarkan elemen, serta menampilkan kondisi antrean setelah setiap aksi.

penjelasan unguided 2
Program di atas mengimplementasikan struktur data queue (antrean) menggunakan array dalam bahasa C++. queue.h mendefinisikan struktur Queue dengan array info untuk menyimpan elemen, serta dua variabel integer head dan tail untuk menunjuk elemen pertama dan terakhir. Beberapa fungsi yang dideklarasikan antara lain: createQueue untuk menginisialisasi antrean, isEmptyQueue dan isFullQueue untuk mengecek kondisi antrean, enqueue untuk menambah elemen ke antrean, dequeue untuk mengeluarkan elemen, dan printInfo untuk menampilkan status antrean. Di queue.cpp, implementasi fungsi-fungsi tersebut dijelaskan dengan cara memanipulasi posisi head dan tail berdasarkan kondisi antrean (kosong atau penuh). Program utama di main.cpp menguji antrean dengan beberapa operasi, seperti menambahkan elemen (5, 2, 7, 4) dan mengeluarkannya, serta menampilkan status antrean setiap kali operasi dilakukan.

penjelasan unguided 3
Kode ini mengimplementasikan queue dengan teknik circular queue dalam C++. Struktur Queue memiliki array info untuk menyimpan elemen dan variabel head serta tail untuk menunjukkan posisi elemen. Fungsi-fungsinya meliputi: enqueue untuk menambah elemen, dequeue untuk mengeluarkan elemen, serta printInfo untuk menampilkan status antrean. Posisi head dan tail diatur secara sirkuler menggunakan modulus % 5 agar tetap berada dalam batas kapasitas. Di main.cpp, antrean diuji dengan beberapa operasi dan menampilkan status setelah setiap aksi.

## Kesimpulan
Struktur data merupakan komponen penting dalam pemrograman karena berfungsi untuk mengatur, menyimpan, dan mengelola data agar lebih mudah diakses dan diproses. Penggunaan struktur data yang tepat akan meningkatkan efisiensi kinerja program dan membantu menangani pengolahan data yang kompleks. Salah satu struktur data yang sering digunakan adalah queue, yang bekerja dengan prinsip FIFO (First In, First Out). Queue sangat bermanfaat dalam berbagai aplikasi seperti penjadwalan proses, pengelolaan antrean tugas, manajemen pesan, serta sistem yang membutuhkan pengolahan data secara berurutan. Selain itu, queue memiliki beberapa jenis yang dapat disesuaikan dengan kebutuhan, baik dari sisi implementasi seperti Linear Queue dan Circular Queue, maupun dari sisi penggunaan seperti Priority Queue dan Double-ended Queue. Dengan memahami jenis dan fungsi queue, programmer dapat memilih model antrean yang paling sesuai untuk menyelesaikan permasalahan secara lebih efisien.

## Referensi
[1] Anaraindyah, R. (2024). Struktur data: Pengertian, fungsi, dan penerapannya. Universitas Negeri Surabaya.https://share.google/kfvAZsEHXwWWO9ZVc
[2] Maulana, R. (2023). Struktur data queue: Pengertian, fungsi, dan jenisnya. Digoding.https://share.google/pxu2YAgcsMBzVlprm