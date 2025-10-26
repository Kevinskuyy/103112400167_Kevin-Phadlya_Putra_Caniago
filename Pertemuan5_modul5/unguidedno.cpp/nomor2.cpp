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

    // Membuat linked list (bisa minimal 3 elemen; di sini pakai 5 agar lebih representatif)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List yang dibuat: ";
    printList(head);

    // Pencarian pertama (nilai ada)
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

    // Pencarian kedua (nilai tidak ada)
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