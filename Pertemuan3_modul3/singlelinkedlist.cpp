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