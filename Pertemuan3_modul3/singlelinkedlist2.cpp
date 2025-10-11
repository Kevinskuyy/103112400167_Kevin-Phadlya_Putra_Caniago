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
