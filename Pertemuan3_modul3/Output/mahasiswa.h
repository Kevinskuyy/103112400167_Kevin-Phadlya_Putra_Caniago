#ifndef MAHASISWA_H
#define MAHASISWA_H

// definisi tipe (struct) 
struct Mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

// deklarasi primitif (fungsi)
void inputMHS(Mahasiswa &m);
float rata2(Mahasiswa m);

#endif 