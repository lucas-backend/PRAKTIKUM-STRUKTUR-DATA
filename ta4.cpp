#include <iostream>
using namespace std;

const int KAPASITAS_MAKSIMAL = 5;

string antrianLab[KAPASITAS_MAKSIMAL]; // Tipe data diubah dari int ke string
int front = -1;
int rear = -1;

bool isFull() {
    // Penuh jika posisi 'rear' berikutnya adalah posisi 'front'
    return (rear + 1) % KAPASITAS_MAKSIMAL == front;
}

bool isEmpty() {
    return front == -1;
}

void tambahMahasiswa(string nama) { // Tipe data parameter diubah ke string
    if (isFull()) {
        cout << "Antrian sudah penuh, mohon tunggu sebentar.\n";
        return;
    }
    if (isEmpty()) {
        // Jika ini mahasiswa pertama, set front dan rear ke 0
        front = 0;
        rear = 0;
    } else {
        // Jika tidak, geser posisi rear secara sirkular
        rear = (rear + 1) % KAPASITAS_MAKSIMAL;
        /* Biar gak lupa :>
        Tujuannya biar setelah penunjuk rear mencapai akhir array
        (indeks terakhir), ia bisa secara otomatis kembali ke awal array (indeks 0) untuk
        mengisi slot yang mungkin sudah kosong. Operasi modulo (%) memastikan hal ini terjadi,
        jika rear + 1 sama dengan KAPASITAS_MAKSIMAL, hasilnya akan menjadi 0, sehingga rear
        akan kembali ke awal. Ini membuat penggunaan ruang pada array menjadi jauh
        lebih efisien. Gitu.
        */
    }
    // Masukkan nama ke posisi rear
    antrianLab[rear] = nama;
    cout << "Mahasiswa dengan nama " << nama << " berhasil ditambahkan ke antrian.\n";
}

// Fungsi untuk memanggil mahasiswa dari antrian (Dequeue)
void panggilMahasiswa() {
    if (isEmpty()) {
        cout << "Tidak ada mahasiswa dalam antrian.\n";
        return;
    }
    
    cout << "--> Memanggil mahasiswa dengan nama " << antrianLab[front] << " untuk asistensi.\n";

    if (front == rear) {
        // Jika hanya ada satu mahasiswa, reset antrian menjadi kosong
        front = -1;
        rear = -1;
    } else {
        // Jika tidak, geser posisi front secara sirkular
        front = (front + 1) % KAPASITAS_MAKSIMAL;
    }
}

// Fungsi untuk menampilkan seluruh mahasiswa dalam antrian
void tampilkanAntrian() {
    if (isEmpty()) {
        cout << "Antrian saat ini kosong.\n";
        return;
    }
    cout << "\n=== Daftar Antrian Asistensi ===\n";
    cout << "Depan -> ";
    int i = front;
    while (true) {
        cout << antrianLab[i] << " ";
        if (i == rear) {
            break;
        }
        i = (i + 1) % KAPASITAS_MAKSIMAL;
    }
    cout << "<- Belakang\n";
}

int main() {
    int pilihan;
    string nama; // Tipe data diubah ke string
    cout << "Sistem Antrian Asistensi Laboratorium\n";

    do {
        cout << "\nMenu\n";
        cout << "1. Tambah Mahasiswa ke Antrian\n";
        cout << "2. Panggil Mahasiswa Berikutnya\n";
        cout << "3. Tampilkan Semua Antrian\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan nama Mahasiswa: ";
            cin >> nama;
            tambahMahasiswa(nama);
        } else if (pilihan == 2) {
            panggilMahasiswa();
        } else if (pilihan == 3) {
            tampilkanAntrian();
        } else if (pilihan == 4) {
            cout << "Terima kasih, program ditutup.\n";
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }

    } while (pilihan != 4);

    return 0;
}
