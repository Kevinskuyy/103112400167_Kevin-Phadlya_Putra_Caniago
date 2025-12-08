# <h1 align="center">Laporan Praktikum Modul 10 - TREE </h1>
<p align="center">Kevin Phadlya Putra Caniago - 103112400167</p>

## Dasar Teori
Tree adalah struktur data non-linear yang digunakan untuk merepresentasikan hubungan hierarkis antar elemen (node). Berbeda dengan array atau linked list yang bersifat linear, tree memiliki bentuk bercabang seperti pohon, di mana setiap node dapat memiliki lebih dari satu anak. Tree terdiri atas root sebagai node utama, node parent, node child, dan node leaf sebagai node tanpa anak. Struktur ini memungkinkan proses pencarian, penyisipan, serta pengelolaan data dilakukan dengan lebih efisien [1].
Secara umum, tree memiliki karakteristik berikut:
Root: node paling atas dalam struktur tree.
Edge: penghubung antara dua node.
Child: node yang berada di bawah node lain.
Parent: node yang memiliki child.
Leaf: node tanpa child.
Subtree: bagian tree yang merupakan tree baru di dalamnya.
Struktur data tree banyak digunakan dalam algoritma pencarian, pengurutan, representasi ekspresi matematika, hingga struktur file sistem operasi karena kemampuannya mengelola data terstruktur secara hierarkis [2].


### A. tree
Tree merupakan bentuk struktur data yang membentuk hierarki melalui hubungan antar simpul (node) yang terhubung oleh jalur (edge). Dimulai dari simpul utama yang disebut root, setiap node bisa memiliki satu atau lebih node turunan (child), sedangkan node yang tidak memiliki turunan disebut sebagai daun (leaf) [2].

## Guided 

### 1. 

file main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```

file bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

file bst.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data interger
typedef struct Node* address; //alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan(integer)
    address left; // pointer left
    address right; // pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); //function untuk memasukkan node kedalam BST

//traversal
void preOrder(address root); //function traversal tree secara pre-order (tengah - kiri - kanan atau root - childkiri - childkanan)
void inOrder(address root); //function traversal tree secara in-order (kiri - tengah - kanan atau childkiri - root - childkanan)
void postOrder(address root); //function traversal tree secara post-order (kiri - kanan - tengah atau childkiri - childkanan - root)

//utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

#endif
```

penjelasan singkat guided 1
Program ini mengimplementasikan Binary Search Tree (BST) dalam C++ dengan operasi dasar seperti penambahan node, traversal, dan penghitungan jumlah node serta kedalaman tree. Di main.cpp, tree dibuat dan node ditambahkan menggunakan fungsi insertNode. Hasil traversal tree ditampilkan dengan metode InOrder, PreOrder, dan PostOrder, serta menghitung jumlah node dan kedalaman dengan fungsi countNodes dan treeDepth. Di bst.cpp, terdapat fungsi untuk memeriksa apakah tree kosong (isEmpty), membuat tree baru (createTree), dan menambahkan node (insertNode). Fungsi traversal seperti preOrder, inOrder, dan postOrder digunakan untuk mencetak elemen tree dalam urutan berbeda. Program ini menunjukkan cara mengelola BST, melakukan traversal, serta menganalisis ukuran dan kedalaman tree.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file
“bstree.h”

file bst.h

```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);
void preOrder(address root);
void postOrder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);


#endif

```

file bst.cpp 

```C++
#include "bst.h"


address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}


void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}


address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } 
    else if (x == root->info) {
        return root;
    } 
    else if (x < root->info) {
        return findNode(x, root->left);
    } 
    else {
        return findNode(x, root->right);
    }
}


void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) {
        return start;
    }
    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    return max(leftDepth, rightDepth);
}

void preOrder(address root) {
    if (root != NULL) {
        cout << root->info << " - ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " - ";
    }
}


```

file main.cpp 

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    cout << "In-Order   : ";
    InOrder(root);

    cout << "\nPre-Order  : ";
    preOrder(root);

    cout << "\nPost-Order : ";
    postOrder(root);

    cout << "\n";
    
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;


    return 0;
}


``` 


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/54667e4cabe791493e6d9ecff1e002b29d926367/Pertemuan10_modul10/unguided/Screenshot%202025-12-08%20181259.png)


penjelasan unguided 1 
Program ini berfungsi sebagai implementasi lengkap dari Binary Search Tree (BST) menggunakan bahasa C++. Program ini mampu melakukan berbagai operasi penting dalam struktur data BST, mulai dari pembuatan node, penyisipan data, pencarian, penghapusan, traversal, hingga perhitungan informasi statistik mengenai tree.

## Kesimpulan
Multi Linked List merupakan struktur data yang terdiri dari beberapa kelompok Linked List terpisah namun tetap dapat diakses sekaligus, sehingga memudahkan pengelompokan data secara rapi dan terorganisasi; sedangkan Tree adalah struktur data hierarkis yang menghubungkan node melalui hubungan parent–child, dimulai dari root hingga leaf, sehingga cocok untuk merepresentasikan data bertingkat; dan algoritma rekursif adalah teknik pemrograman di mana suatu fungsi memanggil dirinya sendiri dengan ruang masalah yang semakin kecil, sehingga sangat efektif digunakan pada proses yang memiliki pola berulang seperti traversal pada Tree. Dengan memahami ketiga konsep ini, kita dapat memilih dan menggunakan struktur data ataupun algoritma yang tepat sesuai kebutuhan aplikasi.

## Referensi
[1] Wibowo, F., & Sunaryo, A. (2020). Analisis Struktur Data Tree dalam Pengembangan Algoritma Pencarian. Jurnal Teknologi Informatika, 14(2), 45–52. [2] Putra, D. A., & Nugroho, R. (2019). Implementasi Struktur Data Tree pada Sistem Informasi Hierarki Organisasi. Jurnal Informatika dan Sistem Informasi, 5(1), 33–40.