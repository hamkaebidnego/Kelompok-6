#include <iostream>
#include <string>
using namespace std;

const int MAX_MAHASISWA = 3;
string tumpukan[MAX_MAHASISWA][3];
int top = 0;
int maksimum_mahasiswa;

// cek apakah stack penuh 
bool isfull() {
    return top == maksimum_mahasiswa;
}

// cek apakah stack kosong
bool isempty() {
    return top == 0;
}

// push/input data dalam stack
void push(string data, string nim, string angkatan) {
    if (!isfull()) {
        tumpukan[top][0] = data;
        tumpukan[top][1] = nim;
        tumpukan[top][2] = angkatan;
        top++;
        cout << "\nNama " << data <<" dengan"; cout << " Nim " << nim << " dari";
		cout << " Angkatan " << angkatan << " hadir!!!" << endl << endl;
    } else {
        cout << "\nabsen telah penuh, maksimum mahasiswa yang dapat absen adalah " << maksimum_mahasiswa << " !!! " << endl << endl;
    }
}

// pop/hapus data ke dalam stack
void pop() {
    if (!isempty()) {
        for (int x = 0; x < 3; x++) {
            tumpukan[top - 1][x] = "";
        }
        top--;
        cout << "\nData telah dihapus" << endl;
        cout << "\n-----------------------------------------\n" << endl;
    }
}

// hapus semua data
void clear() {
    if (!isempty()) {
        for (int i = top - 1; i >= 0; i--) {
            for (int x = 0; x < 3; x++) {
                tumpukan[i][x] = "";
            }
        }
        top = 0;
        cout << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Semua data berhasil dihapus " << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
    }
}

// menampilkan semua data data
void print() {
    cout << "Isi absen :" << endl << endl;
    for (int i = top - 1; i >= 0; i--) {
        cout << "------------" << endl;
        if (tumpukan[i][0] == "") {
            cout << "Kosong" << endl;
        }
        for (int x = 0; x < 3; x++) {
            cout << tumpukan[i][x] << endl;
        }
    }
    cout << "------------" << endl;
    cout << endl;
}

int main() {
    cout << "\nMasukkan jumlah maksimum mahasiswa yang dapat didaftarkan: ";
    cin >> maksimum_mahasiswa;
    cin.ignore();

    int pil;
    string data, nim, angkatan;
    do {
        cout << "\n----------------------------------" << endl;
        cout << "|Selamat datang di aplikasi Absen| " << endl;
        cout << "----------------------------------" << endl;
        cout << "Menu:" << endl;
        cout << "1. Tambah mahasiswa ke dalam absen" << endl;
        cout << "2. Hapus mahasiswa dari absen" << endl;
        cout << "3. Tampilkan data absen" << endl;
        cout << "4. Hapus semua data absen)" << endl;
        cout << "5. Exit " << endl;
        cout << "\nMasukan pilihan : ";
        cin >> pil;
        cin.ignore(); // tambahkan cin.ignore() di sini
        cout << "-----------------------------------------" << endl;
        switch (pil) {
            case 1:
                cout << "Masukkan nama \t\t: ";
                getline(cin, data);
                cout << "Masukkan NIM \t\t: ";
                getline(cin, nim);
                cout << "Masukkan Angkatan \t: ";
                getline(cin, angkatan);
                push(data, nim, angkatan);
                break;
            case 2:
                pop();
                break;
            case 3 :
                print();
                break;
            case 4 :
                clear();
                break;
        }
    } while (pil != 5);

    cout << "Terima Kasih " << endl;
    cout << "-----------------------------------------" << endl;
    return 0;
}

