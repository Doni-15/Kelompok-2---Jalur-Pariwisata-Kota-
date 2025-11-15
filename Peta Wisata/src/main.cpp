#include "djikstraAlgorithm.hpp"
#include "mergeSort.hpp"
#include "searchingAlgorithm.hpp"

void tampilkanSemuaLokasi();
void inputLokasi();

vector<string> namaLokasi;

MergeSort sorting;
DjikstraAlgorithm djikstra;
SearchingAlgorithm searching;

int main(){
    string pilih;
    int pilihanFitur;

    do{
        clearScreen();
        tampilkanSemuaLokasi();

        cout << "Pilihan fitur " << endl;
        cout << "[1]. Urutkan lokasi" << endl;
        cout << "[2]. Mulai pencarian" << endl;
        cout << "[3]. Cari rute terpendek" << endl;

        do{
            cout << "\nPilih fitur (1-3) : "; cin >> pilihanFitur;

            if (pilihanFitur == 1){
                sorting.jalankanSorting();
            }
            else if(pilihanFitur == 2){
                searching.jalankanSearching();
            }
            else if(pilihanFitur == 3){
                inputLokasi();
            }
            
            cout << "\n\nKembali ke Utama?[Y/N] "; cin >> pilih;
        } while (!validasiPilihan(1, 3, pilihanFitur));
    } while (pilih == "Y" || pilih == "y");
}

void inputLokasi(){
    int posisiAwal, tujuan;
    do{
        cout << "\nMasukkan angka sesuai dengan nomor kota di atas" << endl;
        cout << "Masukkan posisi anda sekarang : "; cin >> posisiAwal;
        cout << "Masukkan lokasi tujuan anda   : "; cin >> tujuan;
        
    } while (!validasiPilihan(1, namaLokasi.size(), posisiAwal) || !validasiPilihan(1, namaLokasi.size(), tujuan));
    
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
    const int maxHeight = 14;
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