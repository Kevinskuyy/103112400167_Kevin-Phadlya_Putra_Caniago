# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Kevin Phadlya Putra Caniago - 103112400167</p>

## Dasar Teori
Bahasa pemrograman C++ merupakan salah satu bahasa pemrograman tingkat menengah yang dikembangkan oleh Bjarne Stroustrup pada tahun 1983. Bahasa ini merupakan pengembangan dari bahasa C dengan menambahkan konsep pemrograman berorientasi objek (Object-Oriented Programming), sehingga lebih fleksibel untuk membangun perangkat lunak berskala kecil maupun besar [1]. C++ banyak digunakan dalam pembuatan aplikasi desktop, sistem operasi, game development, serta perangkat lunak berbasis kinerja tinggi [2].

### A. Operator Aritmatika <br/>
Operator aritmetika merupakan simbol atau tanda yang digunakan dalam bahasa pemrograman C++ untuk melakukan operasi perhitungan matematika pada nilai numerik. Operator ini berfungsi untuk memproses dua atau lebih operand (nilai atau variabel) sehingga menghasilkan suatu nilai baru sesuai dengan jenis operasi yang dilakukan [1].

### B. Perulangan <br/>
Perulangan (looping) merupakan salah satu struktur kontrol dalam bahasa pemrograman C++ yang digunakan untuk mengeksekusi suatu blok perintah secara berulang selama kondisi tertentu terpenuhi [1]. Konsep ini sangat penting dalam pemrograman karena dapat menghemat penulisan kode dan memungkinkan program menjalankan tugas yang bersifat repetitif tanpa perlu menulis instruksi yang sama berulang kali.

## Guided 

### 1. ...

```C++
source code guided 1
#include <iostream>
using namespace std;

int main(){
    float angka1, angka2;
    cout << "Masukkan angka 1 : ";
    cin >> angka1;
    cout << "Masukkan angka 2 : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian  : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    return 0;
}
penjelasan singkat guided 1
Program ini berfungsi untuk menerima dua bilangan dari pengguna (tipe data float), lalu menampilkan hasil operasi aritmetika dasar:


```C++
source code guided 2
#include <iostream>
using namespace std;

int main(){
    int angka;
    cout << "Masukan angka (0-100) : " ; 
    cin >> angka;

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (angka == 0) cout << "0 : nol ";
    else if (angka == 10 ) cout << "10 : sepuluh ";
    else if (angka == 11) cout << "11 : sebelas ";
    else if (angka < 10) cout << angka << " : " << satuan[angka] << " ";
    else if (angka < 20) cout << angka << " : " << satuan[angka - 10] << " belas ";
    else if (angka < 100){
        int puluhan = angka / 10;
        int sisa = angka % 10;
        cout << angka << " : " << satuan[puluhan] << " puluh ";
        if (sisa != 0) cout << satuan[sisa] << " ";
    }
    else if (angka == 100) cout << "100 : seratus ";
    else cout << "Angka di luar jangkauan" << endl;
    return 0;
}
penjelasan singkat guided 2
Program ini berfungsi untuk mengubah angka (0-100) menjadi tulisan dalam Bahasa Indonesia

```C++
source code guided 3
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "input : ";
    cin >> n;

    cout << "Output:\n";
    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < n - i; s++) cout << "  ";
        if (i > 0) {
            for (int j = i; j >= 1; j--) cout << j << " ";
            cout << "* ";
            for (int j = 1; j <= i; j++) cout << j << " ";
        } else {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}

penjelasan singkat guided 3
Program diatas digunakan untuk mencetak pola segitiga simetris dengan angka dan tanda bintang (*) ditengah


### 1. Soal Unguided 1
Buat program C++ yang menerima input 2 bilangan float, lalu tampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian dari kedua bilangan tersebut.

```C++
source code unguided 1
#include <iostream>
using namespace std;

int main(){
    float angka1, angka2;
    cout << "Masukkan angka 1 : ";
    cin >> angka1;
    cout << "Masukkan angka 2 : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian  : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    return 0;
}
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/4d7b258b8084c13a94d77b1d4cfd50461e312e80/Pertemuan1_modul1/Output-Unguided1-modul1.png) 

penjelasan unguided 1 

Program ini berfungsi untuk menerima dua bilangan dari pengguna (tipe data float), lalu menampilkan hasil operasi aritmetika dasar

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
source code unguided 2 
#include <iostream>
using namespace std;

int main(){
    int angka;
    cout << "Masukan angka (0-100) : " ; 
    cin >> angka;

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (angka == 0) cout << "0 : nol ";
    else if (angka == 10 ) cout << "10 : sepuluh ";
    else if (angka == 11) cout << "11 : sebelas ";
    else if (angka < 10) cout << angka << " : " << satuan[angka] << " ";
    else if (angka < 20) cout << angka << " : " << satuan[angka - 10] << " belas ";
    else if (angka < 100){
        int puluhan = angka / 10;
        int sisa = angka % 10;
        cout << angka << " : " << satuan[puluhan] << " puluh ";
        if (sisa != 0) cout << satuan[sisa] << " ";
    }
    else if (angka == 100) cout << "100 : seratus ";
    else cout << "Angka di luar jangkauan" << endl;
    return 0;
}
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/4d7b258b8084c13a94d77b1d4cfd50461e312e80/Pertemuan1_modul1/Output-Unguided2-Modul1.png)


penjelasan unguided 2
Program ini berfungsi untuk mengubah angka (0-100) menjadi tulisan dalam Bahasa Indonesia

### 3. Buatlah sebuah program yang memberikan input dan output...

```C++
source code unguided 3
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "input : ";
    cin >> n;

    cout << "Output:\n";
    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < n - i; s++) cout << "  ";
        if (i > 0) {
            for (int j = i; j >= 1; j--) cout << j << " ";
            cout << "* ";
            for (int j = 1; j <= i; j++) cout << j << " ";
        } else {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}

### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 1_2](https://github.com/Kevinskuyy/103112400167_Kevin-Phadlya_Putra_Caniago/blob/4d7b258b8084c13a94d77b1d4cfd50461e312e80/Pertemuan1_modul1/Output-Unguided3-modul1.png)

penjelasan unguided 3
Program diatas digunakan untuk mencetak pola segitiga simetris dengan angka dan tanda bintang (*) ditengah


## Kesimpulan
Modul 1 mengenalkan penggunaan Code::Blocks IDE serta konsep dasar bahasa C++, mencakup tipe data, operator aritmetika, mekanisme input-output, percabangan, dan perulangan. Melalui latihan guided dan unguided, mahasiswa dapat menerapkan teori tersebut ke dalam program nyata, seperti pembuatan kalkulator sederhana, konversi angka menjadi teks, dan pembuatan pola angka. Pemahaman materi ini menjadi dasar penting untuk mempelajari konsep pemrograman C++ yang lebih lanjut pada modul-modul berikutnya.

## Referensi
[1] Pemrograman C++ Bab 05 Operator, Academia.edu, 2017. [Online]. Tersedia di: https://www.academia.edu/35361996/Pemograman_C_Bab_05_Operator_pdf, 
[2] Dasar Pemrograman Modul 4 – Perulangan (Looping), Universitas Negeri Malang (UM), 2016. [Online]. Tersedia di: https://elektro.um.ac.id/wp-content/uploads/2016/04/Dasar-Pemrograman-Modul-4-Perulangan.pdf
