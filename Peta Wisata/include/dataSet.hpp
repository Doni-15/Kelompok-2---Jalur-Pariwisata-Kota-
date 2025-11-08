#ifndef DATASET_HPP
#define DATASET_HPP

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Koneksi {
    string namaTujuan;
    int jarak;
};

struct Lokasi {
    string tipe;
    float rating;
    int poin;
    vector<Koneksi> daftarTetangga;
};

inline map<string, Lokasi> data_peta_lengkap = {
    // --- Pintu Masuk & Fasilitas Utama ---
    {"Gerbang Masuk", {
        "Fasilitas", 4.0, 0, {
            {"Information", 15}, {"Simpang Dream Zone", 40}
        }
    }},
    {"Information", {
        "Fasilitas", 4.2, 0, {
            {"Gerbang Masuk", 15}, {"Toilet Utama", 10}, {"Simpang Dream Zone", 30}
        }
    }},
    {"Toilet Utama", {
        "Fasilitas", 3.8, 0, {
            {"Information", 10}
        }
    }},
    
    // --- Zona Mimpi (Dream Zone) ---
    {"Simpang Dream Zone", {
        "Persimpangan", 0.0, 0, {
            {"Gerbang Masuk", 40}, {"Information", 30}, {"Twister", 50}, {"Rolling Stone", 60}, {"Simpang Adventure", 100}
        }
    }},
    {"Twister", {
        "Dream Zone", 4.5, 10, {
            {"Simpang Dream Zone", 50}, {"Bumper Bee", 20}
        }
    }},
    {"Rolling Stone", {
        "Dream Zone", 4.6, 15, {
            {"Simpang Dream Zone", 60}
        }
    }},
    {"Bumper Bee", {
        "Dream Zone", 4.2, 5, {
            {"Twister", 20}
        }
    }},
    
    // --- Zona Petualangan (Adventure Zone) ---
    {"Simpang Adventure", {
        "Persimpangan", 0.0, 0, {
            {"Simpang Dream Zone", 100}, {"Volcano", 40}, {"Buzz Coaster", 50}, {"Jungle Resto", 20}
        }
    }},
    {"Volcano", {
        "Adventure Zone", 4.7, 15, {
            {"Simpang Adventure", 40}, {"Jurassic Tree", 30}
        }
    }},
    {"Buzz Coaster", {
        "Adventure Zone", 4.4, 10, {
            {"Simpang Adventure", 50}, {"T-Rex", 25}
        }
    }},
    {"Jurassic Tree", {
        "Adventure Zone", 4.6, 15, {
            {"Volcano", 30}
        }
    }},
    {"T-Rex", {
        "Adventure Zone", 4.5, 10, {
            {"Buzz Coaster", 25}
        }
    }},
    {"Jungle Resto", {
        "Fasilitas", 4.3, 0, {
            {"Simpang Adventure", 20}, {"Simpang Atlantis", 80}
        }
    }},

    // --- Zona Atlantis (Atlantis Zone) ---
    {"Simpang Atlantis", {
        "Persimpangan", 0.0, 0, {
            {"Jungle Resto", 80}, {"Tsunami", 50}, {"The Falls", 40}, {"Dolphin Bay", 60}
        }
    }},
    {"Tsunami", {
        "Atlantis Zone", 4.9, 15, {
            {"Simpang Atlantis", 50}
        }
    }},
    {"The Falls", {
        "Atlantis Zone", 4.6, 10, {
            {"Simpang Atlantis", 40}, {"Pirates Cafe", 20}
        }
    }},
    {"Dolphin Bay", {
        "Atlantis Zone", 4.5, 10, {
            {"Simpang Atlantis", 60}, {"Splash", 30}
        }
    }},
    {"Splash", {
        "Atlantis Zone", 4.3, 10, {
            {"Dolphin Bay", 30}
        }
    }},
    {"Pirates Cafe", {
        "Fasilitas", 4.1, 0, {
            {"The Falls", 20}
        }
    }},
    
    // --- Wahana Terpisah ---
    {"The Peak", {
        "Adventure Zone", 4.4, 10, {
            {"Simpang Adventure", 120} 
        }
    }}
};

#endif