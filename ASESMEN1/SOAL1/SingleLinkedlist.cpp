#include <iostream>
using namespace std;

struct Node {
    string name;  
    Node* next;   
};

class SinglyLinkedList {
private:
    Node* head; 

public:

    SinglyLinkedList() {
        head = nullptr;
    }

    void insertLast(string name) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;  
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  
            }
            temp->next = newNode;  
        }
    }

    void deleteFirst(string name) {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }

        Node* temp = head;
        if (head->name == name) {
            head = head->next; 
            delete temp;
            return;
        }

        while (temp->next != nullptr && temp->next->name != name) {
            temp = temp->next;  
        }

        if (temp->next == nullptr) {
            cout << "Nama tidak ditemukan." << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;  
        delete toDelete;
    }

    void viewList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << endl;  
            temp = temp->next;
        }
    }

    void jumlahNamaPanjangGenap() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name.length() % 2 == 0) {
                count++;  
            }
            temp = temp->next;
        }
        cout << "Jumlah nama dengan huruf genap: " << count << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int pilihan;
    string nama;

    while (true) {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 0) break;  

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama untuk insert: ";
                cin >> nama;
                list.insertLast(nama);  
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                cin >> nama;
                list.deleteFirst(nama);  
                break;

            case 3:
                list.viewList();  
                break;

            case 4:
                list.jumlahNamaPanjangGenap();  
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
