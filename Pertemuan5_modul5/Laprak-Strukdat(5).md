# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (Bagian Kedua)</h1>
<p align="center">Kevin Phadlya Putra Caniago - 103112400167</p>

## Dasar Teori
Menurut Rosen [1], algoritma pencarian merupakan langkah-langkah sistematis yang digunakan untuk menemukan suatu elemen dalam kumpulan data. Algoritma ini memiliki peran penting dalam pengolahan data karena menentukan seberapa cepat dan efisien proses pencarian dapat dilakukan. Dua algoritma pencarian yang umum digunakan adalah Linear Search dan Binary Search.

### A. BINARY SEARCH
algoritma pencarian yang bekerja dengan memecah data yang sudah terurut secara berulang menjadi dua bagian hingga elemen yang dicari ditemukan.

### B. LINEAR SEARCH
algoritma pencarian sederhana yang mencari elemen target dengan memeriksa setiap item dalam daftar atau array satu per satu secara berurutan dari awal hingga akhir

## Guided 

### 1. 

file listbuah.cpp
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama
            << ", Jumlah : " << nodeBantu->isidata.jumlah
            << ", Harga : " << nodeBantu->isidata.harga << endl;
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
void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node "<< nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
file listbuah.h
```C++
    #ifndef LISTBUAH_H
    #define LISTBUAH_H

    #define Nil NULL
    #include <iostream>
    using namespace std;

    struct buah {
        string nama;
        int jumlah;
        float harga;
    };

    typedef buah dataBuah;
    typedef struct node *address;

    struct node {
        dataBuah isidata;
        address next;
    };

    struct linkedlist {
        address first;
    };

    // ==== DEKLARASI / PROTOTYPE ====
    bool isEmpty(linkedlist List);
    void createList(linkedlist &List);

    address alokasi(string nama, int jumlah, float harga);
    void dealokasi(address &node);

    void insertFirst(linkedlist &List, address nodeBaru);
    void insertAfter(linkedlist &List, address nodeBaru, address Prev);
    void insertLast(linkedlist &List, address nodeBaru);

    void delFirst(linkedlist &List);
    void delLast(linkedlist &List);
    void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

    void printList(linkedlist List);
    int nbList(linkedlist List);
    void deleteList(linkedlist &List);

    // === Fungsi update data ===
    void updateFirst(linkedlist List);
    void updateLast(linkedlist List);
    void updateAfter(linkedlist List, address nodePrev);

    #endif
```
file main.cpp
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

penjelasan singkat guided 1
Program ini membuat dan mengelola Linked List berisi data buah — setiap node menyimpan nama buah, jumlah, dan harga.
Program juga dapat menambah, menghapus, menampilkan, dan mengubah data buah dalam daftar.

### 2. ...
file binary.cpp
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```

file linear.cpp
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```

penjelasan singkat guided 2
binary.cpp → Melakukan pencarian biner (Binary Search) pada data yang sudah terurut di dalam linked list. Program menambahkan beberapa data, lalu mencari nilai tertentu (misalnya 40). Jika ditemukan, tampil “found”, jika tidak “not found”.
linear.cpp → Melakukan pencarian linear (Linear Search), yaitu memeriksa setiap elemen satu per satu dari awal sampai akhir linked list. Program menambahkan data, lalu mencari nilai tertentu (misalnya 20) dan menampilkan hasilnya (“found” atau “not found”).


## Unguided 

### 1. Soal Unguided 1...

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}


void displayList(Node* head) {
    cout << "Linked List yang dibuat: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


int getSize(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getNodeAt(Node* head, int index) {
    for (int i = 0; head && i < index; i++)
        head = head->next;
    return head;
}

Node* binarySearch(Node* head, int key) {
    cout << "\nMencari nilai: " << key << endl;
    cout << "\nProses Pencarian:" << endl;

    int left = 0;
    int right = getSize(head) - 1;
    int iterasi = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iterasi++ << ": Mid = " << midNode->data
        << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            if (midNode->next)
                cout << "Node berikutnya: " << midNode->next->data << endl;
            else
                cout << "Node berikutnya: (tidak ada, ini node terakhir)\n";
            return midNode;
        } else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan\n";
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri\n";
            right = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}


int main() {
    cout << "BINARY SEARCH PADA LINKED LIST\n";

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    displayList(head);

    binarySearch(head, 40);
    binarySearch(head, 25);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/761f874cd68a2c492ad15b9b52c06f67fd9795ee/Pertemuan5_modul5/unguidedno.cpp/OUTPUT%20BINERY.png)

penjelasan unguided 1 
Program ini menunjukkan cara menggunakan algoritma Binary Search pada linked list, lengkap dengan:
Proses iterasi pencarian.
Tampilan node tengah di setiap langkah.
Informasi node saat nilai ditemukan.


### 2. Soal Unguided 2...

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int idx = 1;

    cout << "\nProses Pencarian:\n";
    while (current != nullptr) {
        if (current->data == key) {
            cout << "Memeriksa node " << idx << ": " << current->data << " (SAMA) - DITEMUKAN!" << endl;
            return current;
        } else {
            cout << "Memeriksa node " << idx << ": " << current->data << " (TIDAK SAMA)" << endl;
        }
        current = current->next;
        idx++;
    }
    cout << "Tidak ada node lagi yang tersisa" << endl;
    return nullptr;
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n\n";

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List yang dibuat: ";
    printList(head);

    int key1 = 30;
    cout << "\nMencari nilai: " << key1 << endl;
    Node* res1 = linearSearch(head, key1);

    if (res1) {
        cout << "\nHasil: Nilai " << key1 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << res1 << endl;
        cout << "Data node: " << res1->data << endl;
        if (res1->next)
            cout << "Node berikutnya: " << res1->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "\nHasil: Nilai " << key1 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    int key2 = 25;
    cout << "\nMencari nilai: " << key2 << endl;
    Node* res2 = linearSearch(head, key2);

    if (res2) {
        cout << "\nHasil: Nilai " << key2 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << res2 << endl;
    } else {
        cout << "\nHasil: Nilai " << key2 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/761f874cd68a2c492ad15b9b52c06f67fd9795ee/Pertemuan5_modul5/unguidedno.cpp/OUTPUT%20LINEAR.png)

penjelasan unguided 2
Program ini digunakan untuk mencari nilai tertentu di dalam linked list menggunakan algoritma Linear Search, dengan menampilkan proses pencarian secara langkah demi langkah.

## Kesimpulan
Dari hasil praktikum dapat diketahui bahwa Singly Linked List adalah struktur data yang fleksibel dan efektif dalam pengelolaan data.
Algoritma Linear Search melakukan pencarian secara berurutan melalui setiap node, sedangkan Binary Search bekerja lebih cepat pada data terurut dengan prinsip pembagian dua bagian pencarian.
Keduanya memiliki perbedaan dalam mekanisme kerja, namun tetap memiliki nilai penting dalam penerapan algoritma pencarian pada struktur data.

## Referensi
[1] Rosen, K. H. (2012). Discrete Mathematics and Its Applications (7th ed.). New York: McGraw-Hill.