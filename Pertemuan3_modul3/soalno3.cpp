#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void tukarElemen(int arr1[3][3], int arr2[3][3], int i, int j) {
    int temp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = temp;
}

void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;

    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    tukarElemen(A, B, 1, 1);
    cout << "Setelah tukar A[1][1] dan B[1][1]:" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    cout << "Sebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(p1, p2);
    cout << "Setelah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}
