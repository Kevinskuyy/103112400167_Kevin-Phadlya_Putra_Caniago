#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() {
    root = NULL;
}

void BST::createTree() {
    root = NULL;
    cout << "Binary Search Tree telah dibuat (kosong)" << endl;
}

Node* BST::insertNodeHelper(Node* node, string nama, float berat, string tier) {
    if (node == NULL) {
        Node* newNode = new Node();
        newNode->namaMember = nama;
        newNode->beratBadan = berat;
        newNode->tierMember = tier;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (berat < node->beratBadan) {
        node->left = insertNodeHelper(node->left, nama, berat, tier);
    }
    else if (berat > node->beratBadan) {
        node->right = insertNodeHelper(node->right, nama, berat, tier);
    }
    
    return node;
}

void BST::insertNode(string nama, float berat, string tier) {
    root = insertNodeHelper(root, nama, berat, tier);
    cout << "Data member " << nama << " berhasil ditambahkan" << endl;
}

void BST::inOrderHelper(Node* node) {
    if (node != NULL) {
        inOrderHelper(node->left);
        cout << node->beratBadan << " - ";
        inOrderHelper(node->right);
    }
}

void BST::inOrder() {
    cout << "\n=== Traversal InOrder ===" << endl;
    cout << "Urutan berat badan: ";
    inOrderHelper(root);
    cout << endl;
}

void BST::mostLeft() {
    cout << "\n=== Most Left (Node Terkecil) ===" << endl;
    if (root == NULL) {
        cout << "Tree kosong!" << endl;
        return;
    }
    
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    
    cout << "Node MostLeft : " << current->beratBadan << endl;
    cout << "Nama Member   : " << current->namaMember << endl;
    cout << "Tier Member   : " << current->tierMember << endl;
}

void BST::mostRight() {
    cout << "\n=== Most Right (Node Terbesar) ===" << endl;
    if (root == NULL) {
        cout << "Tree kosong!" << endl;
        return;
    }
    
    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    
    cout << "Node MostRight : " << current->beratBadan << endl;
    cout << "Nama Member    : " << current->namaMember << endl;
    cout << "Tier Member    : " << current->tierMember << endl;
}

Node* BST::searchByBeratBadanHelper(Node* node, float berat) {
    if (node == NULL || node->beratBadan == berat) {
        return node;
    }
    
    if (berat < node->beratBadan) {
        return searchByBeratBadanHelper(node->left, berat);
    }
    
    return searchByBeratBadanHelper(node->right, berat);
}

Node* BST::findParent(Node* root, Node* child) {
    if (root == NULL || root == child) {
        return NULL;
    }
    
    if (root->left == child || root->right == child) {
        return root;
    }
    
    if (child->beratBadan < root->beratBadan) {
        return findParent(root->left, child);
    } else {
        return findParent(root->right, child);
    }
}

void BST::searchByBeratBadan(float berat) {
    cout << "\n=== Search By Berat Badan ===" << endl;
    cout << "Mencari member dengan berat badan: " << berat << " kg" << endl;
    
    Node* found = searchByBeratBadanHelper(root, berat);
    
    if (found == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }
    
    cout << "\n--- Data Ditemukan ---" << endl;
    cout << "Nama Member  : " << found->namaMember << endl;
    cout << "Berat Badan  : " << found->beratBadan << endl;
    cout << "Tier Member  : " << found->tierMember << endl;
    
    Node* parent = findParent(root, found);
    if (parent != NULL) {
        cout << "\n--- Data Parent ---" << endl;
        cout << "Nama Member  : " << parent->namaMember << endl;
        cout << "Berat Badan  : " << parent->beratBadan << endl;
        cout << "Tier Member  : " << parent->tierMember << endl;
    } else {
        cout << "\n--- Tidak Memiliki Parent (Root Node) ---" << endl;
    }
    
    if (parent != NULL) {
        Node* sibling = NULL;
        if (parent->left == found) {
            sibling = parent->right;
        } else {
            sibling = parent->left;
        }
        
        if (sibling != NULL) {
            cout << "\n--- Data Sibling ---" << endl;
            cout << "Nama Member  : " << sibling->namaMember << endl;
            cout << "Berat Badan  : " << sibling->beratBadan << endl;
            cout << "Tier Member  : " << sibling->tierMember << endl;
        } else {
            cout << "\n--- Tidak Memiliki Sibling ---" << endl;
        }
    }
    
    if (found->left != NULL) {
        cout << "\n--- Data Child Kiri ---" << endl;
        cout << "Nama Member  : " << found->left->namaMember << endl;
        cout << "Berat Badan  : " << found->left->beratBadan << endl;
        cout << "Tier Member  : " << found->left->tierMember << endl;
    } else {
        cout << "\n--- Tidak Memiliki Child Kiri ---" << endl;
    }
    
    if (found->right != NULL) {
        cout << "\n--- Data Child Kanan ---" << endl;
        cout << "Nama Member  : " << found->right->namaMember << endl;
        cout << "Berat Badan  : " << found->right->beratBadan << endl;
        cout << "Tier Member  : " << found->right->tierMember << endl;
    } else {
        cout << "\n--- Tidak Memiliki Child Kanan ---" << endl;
    }
}

Node* BST::getRoot() {
    return root;
}