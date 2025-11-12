#include "djikstraAlgorithm.hpp"
#include "mergeSort.hpp"

void tampilkanSemuaLokasi();
void inputLokasi();

vector<string> namaLokasi;
MergeSort sorting;
DjikstraAlgorithm djikstra;

int main(){
    int pilihanFitur;

    tampilkanSemuaLokasi();

    cout << "Pilihan fitur " << endl;
    cout << "[1]. Urutkan lokasi" << endl;
    cout << "[2]. Cari rute terpendek" << endl;

    do{
        cout << "\nPilih fitur (1-2) : "; cin >> pilihanFitur;

        if (pilihanFitur == 1){
            sorting.jalankanSorting();
        }
        else if(pilihanFitur == 2){
            inputLokasi();
        }
        
    } while (!validasiPilihan(1, 2, pilihanFitur));
}

void inputLokasi(){
    int posisiAwal, tujuan;
    do{
        cout << "\nMasukkan angka sesuai dengan nomor kota di atas" << endl;
        cout << "Masukkan posisi anda sekarang : "; cin >> posisiAwal;
        cout << "Masukkan lokasi tujuan anda   : "; cin >> tujuan;
        
    } while (!validasiPilihan(1, 20, posisiAwal) || !validasiPilihan(1, 20, tujuan));
    
    djikstra.cariRuteTerpendek(namaLokasi[posisiAwal - 1], namaLokasi[tujuan - 1]);
}

void tampilkanSemuaLokasi(){
    string garis(130, '-');

    gotoxy(0, 0); cout << garis;
    gotoxy(40, 1); cout << "--- Daftar Lokasi di Mikie Funland ---";
    gotoxy(0, 2); cout << garis;

    int i = 0, j = 1;
    int col = 0;
    int startY = 4;
    const int maxHeight = 5;
    const int maxWidth = 35;

    for(const auto& pasangan : data_peta_lengkap){
        gotoxy(col * maxWidth, i + startY);  cout << j << ". " << pasangan.first;
        namaLokasi.push_back(pasangan.first);

        if (i == maxHeight){
            i = -1;
            col++;
        }
        
        i++;
        j++;
    }
    gotoxy(0, maxHeight + 5); cout << endl;
}