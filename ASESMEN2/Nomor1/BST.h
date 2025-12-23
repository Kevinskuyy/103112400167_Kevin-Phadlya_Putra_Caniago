#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* insertNodeHelper(Node* node, string nama, float berat, string tier);
    void inOrderHelper(Node* node);
    Node* searchByBeratBadanHelper(Node* node, float berat);
    Node* findParent(Node* root, Node* child);
    void printNodeInfo(Node* node);
    
public:
    BST();
    void createTree();
    void insertNode(string nama, float berat, string tier);
    void inOrder();
    void mostLeft();
    void mostRight();
    void searchByBeratBadan(float berat);
    Node* getRoot();
};

#endif