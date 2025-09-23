#include <iostream>
using namespace std;
int main()
{
    int nilai[3][3] = {
        {85, 90, 78}, // Baris ke-0: Nilai mahasiswa 1
        {92, 88, 95}, // Baris ke-1: Nilai mahasiswa 2
        {76, 80, 82}  // Baris ke-2: Nilai mahasiswa 3
    };
    cout << "=== Menampilkan Isi Array 2D ===\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Nilai Mahasiswa ke-" << i + 1 << ": ";
        for (int j = 0; j < 3; j++)
        {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n=== Menghitung Rata-rata ===\n";
    for (int i = 0; i < 3; i++)
    {
        int total = 0;
        for (int j = 0; j < 3; j++)
        {
            total = total + nilai[i][j];
        }
        float rataRata = (float)total / 3.0;
        cout << "Rata-rata Mahasiswa ke-" << i + 1 << ": " << rataRata << endl;
    }
    return 0;
}

/*
=== Menampilkan Isi Array 2D ===
Nilai Mahasiswa ke-1: 85 90 78 
Nilai Mahasiswa ke-2: 92 88 95 
Nilai Mahasiswa ke-3: 76 80 82 

=== Menghitung Rata-rata ===
Rata-rata Mahasiswa ke-1: 84.3333
Rata-rata Mahasiswa ke-2: 91.6667
Rata-rata Mahasiswa ke-3: 79.3333
*/