#include "mergeSort.hpp"

MergeSort::MergeSort(){}

void MergeSort::jalankanSorting(){
    vector<string> namaLokasi;
    for(const auto& pasangan : data_peta_lengkap){
        namaLokasi.push_back(pasangan.first);
    }
    
    int n = namaLokasi.size();
    int pilihan;
    string mode;
    
    do{
        cout << "\nIngin mengurutkan berdasarkan" << endl;
        cout << "[1]. Rating" << endl;
        cout << "[2]. Poin Tiket Termurah" << endl;
    
        cout << "\nPilihan : "; cin >> pilihan;
        mode = pilihan == 1 ? "rating" : "poin";
    } while (pilihan < 1 || pilihan > 2);
    
    cout << "Mengurutkan berdasarakan " << mode << endl;
    devine(namaLokasi, 0, n - 1, mode);
    
    string judul = (mode == "rating") ? "Hasil Sorting (Rating Tertinggi)" : "Hasil Sorting (Poin Termurah)";
    printList(judul, namaLokasi);
}

bool MergeSort::compare(const string& a, const string& b, const string& mode){
    if (mode == "rating") {
        float ratingA = data_peta_lengkap.at(a).rating;
        float ratingB = data_peta_lengkap.at(b).rating;
        return ratingA > ratingB;
    }
    else if (mode == "poin") {
        int poinA = data_peta_lengkap.at(a).poin;
        int poinB = data_peta_lengkap.at(b).poin;
        return poinA < poinB;
    }
    
    return a < b;
}

void MergeSort::conquere(vector<string>& arr, int left, int mid, int right, const string& mode){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;   
    int j = 0;       
    int k = left;

    while (i < n1 && j < n2) {
        if (compare(L[i], R[j], mode)) {
            arr[k] = L[i];
            i++;
        } 
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort::devine(vector<string>& arr, int left, int right, const string& mode){
    if(left >= right) return;

    int mid = left + (right - left) / 2;
    devine(arr, left, mid, mode);
    devine(arr, mid + 1, right, mode);

    conquere(arr, left, mid, right, mode);
}

void MergeSort::printList(const string& judul, const vector<string>& namaDaftar){
    system("cls");
    string garis(130, '-');

    gotoxy(0, 0); cout << garis;
    gotoxy(40, 1); cout << "--- " << judul << " ---";
    gotoxy(0, 2); cout << garis;

    const int itemsPerColumn = 5;
    const int columnWidth = 35;
    const int itemHeight = 4;     // Tiap item butuh 4 baris (3 cetak + 1 spasi)
    const int startX = 0;
    const int startY = 4;

    int rank = 1;
    for(const string& nama : namaDaftar){
        const Lokasi& data = data_peta_lengkap.at(nama);
        string n(to_string(abs(rank)).length(), ' ');

        int col = (rank - 1) / itemsPerColumn;
        int row = (rank - 1) % itemsPerColumn;
        int currentX = startX + (col * columnWidth);
        int currentY_base = startY + (row * itemHeight);

        gotoxy(currentX, currentY_base); cout << rank << ". " << nama;
        gotoxy(currentX, currentY_base + 1); cout << n << "  Rating : " << data.rating;
        gotoxy(currentX, currentY_base + 2); cout << n << "  Poin   : " << data.poin;
        
        rank++;
    }
}