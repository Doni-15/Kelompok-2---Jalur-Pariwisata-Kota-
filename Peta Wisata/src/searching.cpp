#include "searchingAlgorithm.hpp"

SearchingAlgorithm::SearchingAlgorithm(){}

void SearchingAlgorithm::jalankanSearching(){
    clearScreen();
    int pilih;
    
    vector<string> mode = {
        "kategori", "rating", "poin"
    };
    
    vector<function<void()>> fungsiMode = {
        []() { kategori(); },
        []() { rating(); },
        []() { poin(); }
    };
    
    string pilihan;
    do{
        
        for (size_t i = 0; i < mode.size(); i++){
            cout << "[" << i + 1 << "]. Cari Berdasarkan " << mode.at(i) << endl;
        }
        
        cout << "\nPilih ingin mencari apa : "; cin >> pilih;
        fungsiMode.at(pilih - 1)();
        
        cout << "\nIngin mencari lagi?[Y/N] "; cin >> pilihan;

        if (pilihan == "Y" || pilihan == "y") {
            clearScreen();
        }
        
    } while ((validasiPilihan(1, mode.size(), pilih)) && (pilihan == "Y" || pilihan == "y"));
}

void SearchingAlgorithm::kategori(){
    cout << "\n";
    vector<string> types = {
        "Fasilitas", "Dream Zone", "Adventure Zone", "Atlantis Zone"
    };

    int pilihan, i = 1;
    do{
        cout << "Anda memilih Kategori " << endl;
        for (size_t i = 0; i < types.size(); i++){
            cout << "[" << i + 1 << "]. " << types.at(i) << endl;
        }

        cout << "\nMasukkan pilihan tipe nya (1-" << types.size() << ") : "; cin >> pilihan;
        cout << "\nTempat dengan tipe " << types.at(pilihan - 1) << endl;

        for(const auto& tipes : data_peta_lengkap){
            if(tipes.second.tipe == types.at(pilihan - 1)){

                string n(to_string(abs(i)).length(), ' ');
                cout << i << ". " << tipes.first << endl;
                
                for(const auto& koneksi : tipes.second.daftarTetangga){
                    cout << n << "  - Ke " << koneksi.namaTujuan 
                         << " (" << koneksi.jarak << " meter)" << endl;
                }
                cout << endl;
                i++;
            }
        }
        break;
    } while (validasiPilihan(1, types.size(), pilihan));

}

void SearchingAlgorithm::rating(){
    cout << "\n";
    
    vector<string> tampilPilihan = {
        "[1]. Cari dengan rating tertentu (misal: 4.5)",
        "[2]. Cari di atas rating tertentu (misal: > 4.5)",
        "[3]. Cari di bawah rating tertentu (misal: < 4.5)",
        "[4]. Cari di antara rating tertentu (misal: 4.0 - 4.5)",
    };

    aturOutput("rating", tampilPilihan);
}

void SearchingAlgorithm::poin(){
    cout << "\n";

    vector<string> tampilPilihan = {
        "[1]. Cari dengan poin tertentu (misal: 10)",
        "[2]. Cari di atas poin tertentu (misal: > 10)",
        "[3]. Cari di bawah poin tertentu (misal: < 10)",
        "[4]. Cari di antara poin tertentu (misal: 5 - 10)",
    };

    aturOutput("poin", tampilPilihan);
}

void SearchingAlgorithm::aturOutput(string mode, vector<string>& tampilPilihan){
    const float pembanding = 0.0001f;
    float rating1 = 0, rating2 = 0;
    int poin1 = 0, poin2 = 0;
    int i = 1;
    bool ditemukan = false;
    
    cout << "Anda memilih " << mode << endl;
    for(const auto& n : tampilPilihan){
        cout << n << endl;
    }

    int pilihan = 0;
    while(pilihan < 1 || pilihan > 4) {
        pilihan = bacaInputValid<int>("\nMasukkan pilihan pencarian (1-4) : ");
    }

    if (mode == "rating"){
        rating1 = bacaInputValid<float>("\nMasukkan rating : ");

        if(pilihan == 4) {
            rating2 = bacaInputValid<float>("Masukkan rating pembanding : ");
        }
    } 
    else if (mode == "poin"){
        poin1 = bacaInputValid<int>("\nMasukkan poin : ");

        if(pilihan == 4) {
            poin2 = bacaInputValid<int>("Masukkan poin pembanding : ");
        }
    }
    
    cout << "\n--- Hasil Pencarian ---" << endl;
    for(const auto& tipes : data_peta_lengkap){
        if (mode == "rating") {
            if(pilihan == 1){
                if(abs(tipes.second.rating - rating1) < pembanding){
                    cout << i << ". " << tipes.first << " (Rating " << tipes.second.rating << ")" << endl;
                    ditemukan = true; 
                    i++;
                }
            }
            else if(pilihan == 2){
                if(tipes.second.rating > rating1){
                    cout << i << ". " << tipes.first << " (Rating " << tipes.second.rating << ")" << endl;
                    ditemukan = true; i++;
                }
            }
            else if(pilihan == 3){
                if(tipes.second.rating < rating1){
                    cout << i << ". " << tipes.first << " (Rating " << tipes.second.rating << ")" << endl;
                    ditemukan = true; i++;
                }
            }
            else if(pilihan == 4){
                if((tipes.second.rating >= rating1 && tipes.second.rating <= rating2) || (tipes.second.rating <= rating1 && tipes.second.rating >= rating2)){
                    cout << i << ". " << tipes.first << " (Rating " << tipes.second.rating << ")" << endl;
                    ditemukan = true; i++;
                }
            }
        } 
        else if (mode == "poin") {
            if(pilihan == 1){
                if(tipes.second.poin == poin1){
                    cout << i << ". " << tipes.first << " (" << tipes.second.poin << " Poin)" << endl;
                    ditemukan = true; i++;
                }
            }
            else if(pilihan == 2){
                if(tipes.second.poin > poin1){
                    cout << i << ". " << tipes.first << " (" << tipes.second.poin << " Poin)" << endl;
                    ditemukan = true; i++;
                }
            }
            else if(pilihan == 3){
                if(tipes.second.poin < poin1){
                    cout << i << ". " << tipes.first << " (" << tipes.second.poin << " Poin)" << endl;
                    ditemukan = true; i++;
                }
            }
            else if(pilihan == 4){
                if(tipes.second.poin >= poin1 && tipes.second.poin <= poin2){
                    cout << i << ". " << tipes.first << " (" << tipes.second.poin << " Poin)" << endl;
                    ditemukan = true; 
                    i++;
                }
            }
        }
    }

    if(!ditemukan)cout << "Tidak ada lokasi yang ditemukan dengan kriteria tersebut." << endl;
    cout << "---------------------------\n" << endl;
}