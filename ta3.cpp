#include <iostream>
using namespace std;

int sequentialSearch(const string daftarNama[], int panjangDaftar, const string& namaDicari) {
    int lokasi = 0;
    bool ditemukan = false;
    while (lokasi < panjangDaftar && !ditemukan) {
        if (daftarNama[lokasi] == namaDicari) {
            ditemukan = true;
        } else {
            lokasi++;
        }
    }
    if (ditemukan) {
        return lokasi;
    } else {
        return -1;
    }
}

int main() {
    const int UKURAN_DAFTAR = 5;
    string namaMahasiswa[UKURAN_DAFTAR] = {"Dipa", "Yaza", "Regina", "Fathan", "Tanto"};
    string namaInput;

    cout << "DAFTAR MAHASISWA (" << UKURAN_DAFTAR << " elemen):" << endl;
    for (int i = 0; i < UKURAN_DAFTAR; ++i) {
        cout << i << ": " << namaMahasiswa[i] << endl;
    }

    cout << "Masukkan nama mahasiswa yang ingin dicari: ";
    // Menggunakan getline untuk memungkinkan nama dengan spasi
    getline(cin, namaInput);
    int hasilPencarian = sequentialSearch(namaMahasiswa, UKURAN_DAFTAR, namaInput);
    cout << "Hasil Pencarian untuk: " << namaInput << endl;

    if (hasilPencarian != -1) {
        cout << "HASIL: Ditemukan!" << endl;
        cout << namaInput << " berada di indeks: " << hasilPencarian << endl;
    } else {
        cout << "HASIL: Tidak ditemukan." << endl;
        cout << "Nama " << namaInput << " tidak ada dalam daftar." << endl;
    }
    return 0;
}
