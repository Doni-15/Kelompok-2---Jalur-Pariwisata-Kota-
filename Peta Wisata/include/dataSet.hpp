#ifndef DATASET_HPP
#define DATASET_HPP

#include "gotoXY.hpp"

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
            {"Ticketing", 10}, {"Information", 30}, {"Titik Kumpul", 20}
        }
    }},
    {"Ticketing", {
        "Fasilitas", 4.0, 0, {
            {"Gerbang Masuk", 10}
        }
    }},
    {"Information", {
        "Fasilitas", 4.2, 0, {
            {"Gerbang Masuk", 30}, {"First Aid", 10}, {"ATM", 10}, {"Toilet", 15}, {"Souvenir Shop", 20}, {"Fun Zone", 40}
        }
    }},
    {"Toilet", {
        "Fasilitas", 3.8, 0, {
            {"Information", 15}
        }
    }},
    {"First Aid", {
        "Fasilitas", 4.0, 0, {
            {"Information", 10}
        }
    }},
    {"ATM", {
        "Fasilitas", 4.0, 0, {
            {"Information", 10}
        }
    }},
    {"Souvenir Shop", {
        "Fasilitas", 4.1, 0, {
            {"Information", 20}, {"Penitipan Barang", 5}
        }
    }},
    {"Penitipan Barang", {
        "Fasilitas", 4.0, 0, {
            {"Souvenir Shop", 5}
        }
    }},
    {"Titik Kumpul", {
        "Fasilitas", 4.0, 0, {
            {"Gerbang Masuk", 20}
        }
    }},
    
    // --- Zona Mimpi (Dream Zone) ---
    {"Fun Zone", {
        "Dream Zone", 4.0, 5, {
            {"Information", 40}, {"Video Game", 10}, {"Happy Journey", 20}
        }
    }},
    {"Video Game", {
        "Dream Zone", 4.1, 5, {
            {"Fun Zone", 10}
        }
    }},
    {"Happy Journey", {
        "Dream Zone", 4.3, 10, {
            {"Fun Zone", 20}, {"Grasshopper", 15}
        }
    }},
    {"Grasshopper", {
        "Dream Zone", 4.4, 10, {
            {"Happy Journey", 15}, {"Twister", 30}
        }
    }},
    {"Twister", {
        "Dream Zone", 4.5, 10, {
            {"Grasshopper", 30}, {"Bumper Bee", 20}, {"Fly Up", 20}, {"Rolling Stone", 30}
        }
    }},
    {"Rolling Stone", {
        "Dream Zone", 4.6, 15, {
            {"Twister", 30}, {"Star Theater", 20}, {"Jungle Resto", 60}
        }
    }},
    {"Star Theater", {
        "Dream Zone", 4.2, 5, {
            {"Rolling Stone", 20}
        }
    }},
    {"Butterfly", {
        "Dream Zone", 4.3, 10, {
            {"Bumper Bee", 25}
        }
    }},
    {"Fly Up", {
        "Dream Zone", 4.5, 10, {
            {"Twister", 20}
        }
    }},
    {"Bumper Bee", {
        "Dream Zone", 4.2, 5, {
            {"Twister", 20}, {"Butterfly", 25}
        }
    }},

    // --- Zona Petualangan (Adventure Zone) ---
    {"Jungle Resto", {
        "Fasilitas", 4.3, 0, {
            {"Rolling Stone", 60}, {"Koomba Dance", 20}, {"Dino Tracker", 25}, {"Charging Station", 5}, {"Simpang Atlantis Path", 80} // Path ke Atlantis
        }
    }},
    {"Koomba Dance", {
        "Adventure Zone", 4.4, 10, {
            {"Jungle Resto", 20}, {"Wild Ride", 15}
        }
    }},
    {"Wild Ride", {
        "Adventure Zone", 4.6, 15, {
            {"Koomba Dance", 15}
        }
    }},
    {"Carnival Games", {
        "Fasilitas", 3.9, 0, {
            {"Dino Tracker", 20}
        }
    }},
    {"Dino Tracker", {
        "Adventure Zone", 4.2, 5, {
            {"Jungle Resto", 25}, {"Dino Egg", 10}, {"Carnival Games", 20}, {"Volcano", 40}
        }
    }},
    {"Dino Egg", {
        "Adventure Zone", 4.0, 5, {
            {"Dino Tracker", 10}
        }
    }},
    {"T-Rex", {
        "Adventure Zone", 4.5, 10, {
            {"Buzz Coaster", 25}, {"Dino vs Dino", 15}, {"Raptor Show", 20}
        }
    }},
    {"Volcano", {
        "Adventure Zone", 4.7, 15, {
            {"Dino Tracker", 40}, {"Buzz Coaster", 30}, {"Jurassic Tree", 30}
        }
    }},
    {"Buzz Coaster", {
        "Adventure Zone", 4.4, 10, {
            {"Volcano", 30}, {"T-Rex", 25}
        }
    }},
    {"Dino vs Dino", {
        "Adventure Zone", 4.3, 10, {
            {"T-Rex", 15}
        }
    }},
    {"Flying Traveller", {
        "Adventure Zone", 4.4, 10, {
            {"Jurassic Tree", 25}
        }
    }},
    {"The Peak", {
        "Adventure Zone", 4.4, 10, {
            {"Jurassic Tree", 40}, {"Pterosaurs", 20}
        }
    }},
    {"Jurassic Tree", {
        "Adventure Zone", 4.6, 15, {
            {"Volcano", 30}, {"Flying Traveller", 25}, {"The Peak", 40}
        }
    }},
    {"Pterosaurs", {
        "Adventure Zone", 4.5, 10, {
            {"The Peak", 20}
        }
    }},
    {"Raptor Show", {
        "Adventure Zone", 4.2, 5, {
            {"T-Rex", 20}
        }
    }},
    {"Simpang Atlantis Path", {
        "Fasilitas", 0.0, 0, {
            {"Jungle Resto", 80}, {"Sea Monster", 30}, {"Musholla", 10}
        }
    }},

    // --- Zona Atlantis (Atlantis Zone) ---
    {"Sea Monster", {
        "Atlantis Zone", 4.5, 10, {
            {"Simpang Atlantis Path", 30}, {"Sea Carousel", 15}, {"Flying Fish", 20}
        }
    }},
    {"Sea Carousel", {
        "Atlantis Zone", 4.1, 5, {
            {"Sea Monster", 15}, {"Bon Voyage", 10}
        }
    }},
    {"Flying Fish", {
        "Atlantis Zone", 4.4, 10, {
            {"Sea Monster", 20}
        }
    }},
    {"Happy Ocean", {
        "Atlantis Zone", 4.0, 5, {
            {"Dolphin Bay", 25}
        }
    }},
    {"Shark Attack", {
        "Atlantis Zone", 4.3, 10, {
            {"The Wave", 20}
        }
    }},
    {"Sea Horse Racer", {
        "Atlantis Zone", 4.2, 5, {
            {"Splash", 15}
        }
    }},
    {"Splash", {
        "Atlantis Zone", 4.3, 10, {
            {"Dolphin Bay", 30}, {"Sea Horse Racer", 15}
        }
    }},
    {"Jelly Swing", {
        "Atlantis Zone", 4.4, 10, {
            {"Dolphin Bay", 40}
        }
    }},
    {"Dolphin Bay", {
        "Atlantis Zone", 4.5, 10, {
            {"Simpang Atlantis Path", 60}, {"Splash", 30}, {"Happy Ocean", 25}, {"Jelly Swing", 40}
        }
    }},
    {"The Wave", {
        "Atlantis Zone", 4.8, 15, {
            {"Shark Attack", 20}, {"Tsunami", 30}
        }
    }},
    {"Ahooy!", {
        "Atlantis Zone", 4.0, 5, {
            {"Pirates Cafe", 30}
        }
    }},
    {"Pirates Cafe", {
        "Fasilitas", 4.1, 0, {
            {"The Falls", 20}, {"Ahooy!", 30}
        }
    }},
    {"The Falls", {
        "Atlantis Zone", 4.6, 10, {
            {"Simpang Atlantis Path", 40}, {"Pirates Cafe", 20}
        }
    }},
    {"Ocean Chair", {
        "Atlantis Zone", 4.2, 5, {
            {"Tsunami", 20}
        }
    }},
    {"Tsunami", {
        "Atlantis Zone", 4.9, 15, {
            {"The Wave", 30}, {"Ocean Chair", 20}
        }
    }},
    {"Bon Voyage", {
        "Atlantis Zone", 4.1, 5, {
            {"Sea Carousel", 10}
        }
    }},
    {"Sea Battle", {
        "Atlantis Zone", 4.4, 10, {
            {"The Breeze", 15}, {"Bubble Cab", 10}
        }
    }},
    {"The Breeze", {
        "Atlantis Zone", 4.3, 10, {
            {"Sea Battle", 15}
        }
    }},
    {"Bubble Cab", {
        "Atlantis Zone", 4.0, 5, {
            {"Sea Battle", 10}
        }
    }},
    
    // --- Fasilitas & Permainan Tambahan ---
    {"Musholla", {
        "Fasilitas", 4.3, 0, {
            {"Simpang Atlantis Path", 10}
        }
    }},
    {"Beverage & Snack", {
        "Fasilitas", 3.9, 0, {
            {"Fun Zone", 30}
        }
    }},
    {"Gazebo", {
        "Fasilitas", 4.0, 0, {
            {"Jungle Resto", 30}
        }
    }},
    {"Charging Station", {
        "Fasilitas", 4.0, 0, {
            {"Jungle Resto", 5}
        }
    }},
    {"Archery", {
        "Fasilitas", 4.2, 0, {
            {"Koomba Dance", 40}
        }
    }},
    {"Paint Ball", {
        "Fasilitas", 4.3, 0, {
            {"Koomba Dance", 45}
        }
    }}
};

#endif
