#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST gym;
    cout << "   SISTEM KEANGGOTAAN GYM - BST" << endl;
    cout << "\n1) createTree()" << endl;
    gym.createTree();
    cout << "\n2) insertNode()" << endl;
    gym.insertNode("Ahmad Azizah", 60, "Basic");
    gym.insertNode("Hakan Ismail", 50, "Bronze");
    gym.insertNode("Olivia Saevali", 65, "Silver");
    gym.insertNode("Felix Pedrosa", 47, "Gold");
    gym.insertNode("Gamat Al Ghifari", 56, "Platinum");
    gym.insertNode("Hanif Al Faiz", 70, "Basic");
    gym.insertNode("Mutiara Fauziah", 68, "Bronze");
    gym.insertNode("Davi Ilyas", 68, "Silver");
    gym.insertNode("Abdad Mubarok", 81, "Gold");
    cout << "\n3) inOrder()" << endl;
    gym.inOrder();
    cout << "\n4) mostLeft() dan mostRight()" << endl;
    gym.mostLeft();
    gym.mostRight();
    cout << "\n5) searchByBeratBadan(70)" << endl;
    gym.searchByBeratBadan(70);
    cout << "PROGRAM SELESAI" << endl;
    
    return 0;
}