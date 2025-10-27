#include <iostream>
#include <string>

using namespace std;

const int SIZE = 10;
string table[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = "";
    }
}

int hashFunction(string name) {
    int sum = 0;
    for (char ch : name) {
        sum += ch;
    }
    return sum % SIZE;
}

void insert(string name) {
    int index = hashFunction(name);
    int startIndex = index; 
    bool tableFull = false;

    while (table[index] != "" && table[index] != name) {
        index = (index + 1) % SIZE; 

        if (index == startIndex) {
            tableFull = true;
            break;
        }
    }

    if (tableFull) {
        cout << "Gagal memasukkan " << name << ". Tabel penuh." << endl;
    } else if (table[index] == "") {
        table[index] = name;
        cout << "Berhasil memasukkan " << name << " di index " << index << endl;
    } else if (table[index] == name) {
        cout << "Nama " << name << " sudah ada di index " << index << endl;
    }
}

bool search(string name) {
    int index = hashFunction(name);
    int startIndex = index;

    while (table[index] != "") {
        if (table[index] == name) {
            cout << "Nama " << name << " ditemukan di index " << index << endl;
            return true;
        }

        index = (index + 1) % SIZE;

        if (index == startIndex) {
            break;
        }
    }

    cout << "Nama " << name << " tidak ditemukan." << endl;
    return false;
}

void display() {
    cout << "\n--- Isi Hash Table ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        if (table[i] == "") {
            cout << "[KOSONG]" << endl;
        } else {
            cout << table[i] << endl;
        }
    }
    cout << "----------------------" << endl;
}

int main() {
    initTable();

    insert("Budi");
    insert("Andi");
    insert("Siti");
    insert("Eka");
    insert("Joko");

    display();

    search("Siti");
    search("Joko");
    search("Rani");
    
    return 0;
}
