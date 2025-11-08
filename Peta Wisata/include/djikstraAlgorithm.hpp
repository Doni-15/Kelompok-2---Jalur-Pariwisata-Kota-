#ifndef DJIKSTRAALGORITHM_HPP
#define DJIKSTRAALGORITHM_HPP

#include "dataSet.hpp"

typedef pair<int, string> jarakPair;

class DjikstraAlgorithm{
    private:
        static void cariRuteTerpendek(const string& awal, const string& tujuan);
        static void cetakRute(const string& lokasiAwal, const string& lokasiTujuan, map<string, string>& ruteSebelumnya);

    public:
        DjikstraAlgorithm(const string& awal, const string& tujuan);
};

#endif