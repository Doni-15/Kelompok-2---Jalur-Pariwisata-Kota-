#ifndef DJIKSTRAALGORITHM_HPP
#define DJIKSTRAALGORITHM_HPP

#include "dataSet.hpp"

typedef pair<int, string> jarakPair;

class DjikstraAlgorithm{
    private:
        static void cetakRute(const string& lokasiAwal, const string& lokasiTujuan, map<string, string>& ruteSebelumnya);
    
    public:
        DjikstraAlgorithm();
        static void cariRuteTerpendek(const string& lokasiAwal, const string& lokasiTujuan);
};

#endif