#include <iostream>
#include <string>

using namespace std;

// Struktur untuk setiap node dalam tree
struct Node {
    int tinggi; // Kunci untuk BST
    string nama;
    Node* left;
    Node* right;

    // Constructor untuk memudahkan pembuatan node baru
    Node(int t, string n) {
        tinggi = t;
        nama = n;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk menambahkan node baru ke BST secara rekursif
Node* insert(Node* root, int tinggi, string nama) {
    // Jika tree kosong, buat node baru sebagai root
    if (!root) {
        return new Node(tinggi, nama);
    }

    // Jika tinggi lebih kecil, masukkan ke sub-pohon kiri
    if (tinggi < root->tinggi) {
        root->left = insert(root->left, tinggi, nama);
    } 
    // Jika tinggi lebih besar, masukkan ke sub-pohon kanan
    else if (tinggi > root->tinggi) {
        root->right = insert(root->right, tinggi, nama);
    }
    // (Untuk kesederhanaan, tinggi badan yang sama tidak diizinkan)

    return root;
}

// Fungsi untuk menampilkan data secara Inorder (terurut dari terpendek ke tertinggi)
void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << "- " << root->nama << " (" << root->tinggi << " cm)\n";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int pilihan;
    int tinggi;
    string nama;

    do {
        cout << "\n===== Program Data Tinggi Badan (BST) =====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Semua Data (Terurut)\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan nama: ";
            cin.ignore(); // Membersihkan buffer sebelum getline
            getline(cin, nama);
            cout << "Masukkan tinggi (cm): ";
            cin >> tinggi;
            root = insert(root, tinggi, nama);
            cout << "Data berhasil ditambahkan.\n";
        } else if (pilihan == 2) {
            if (!root) {
                cout << "Data masih kosong.\n";
            } else {
                cout << "\n--- Data Tinggi Badan (Urut Terpendek ke Tertinggi) ---\n";
                inorder(root);
            }
        } else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan program ini.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 3);

    return 0;
}
