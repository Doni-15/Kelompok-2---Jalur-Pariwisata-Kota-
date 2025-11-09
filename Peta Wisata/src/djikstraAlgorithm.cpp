#include "djikstraAlgorithm.hpp"

const int INF = numeric_limits<int>::max();

DjikstraAlgorithm::DjikstraAlgorithm(){}

void DjikstraAlgorithm::cariRuteTerpendek(const string& lokasiAwal, const string& lokasiTujuan){
    map<string, int> dist;
    map<string, string> ruteSebelumnya;
    priority_queue<jarakPair, vector<jarakPair>, greater<jarakPair>> pq;

    for(const auto& pair : data_peta_lengkap){
        dist[pair.first] = INF;
    }

    dist[lokasiAwal] = 0;
    pq.push({0, lokasiAwal});

    while(!pq.empty()){
        int d = pq.top().first;
        string u = pq.top().second;
        pq.pop();

        if (d > dist.at(u)) continue;
        if (u == lokasiTujuan) break;

        for(const Koneksi& edge : data_peta_lengkap.at(u).daftarTetangga){
            string v = edge.namaTujuan;
            int w = edge.jarak;

            if(dist.at(u) + w < dist.at(v)){
                dist[v] = dist.at(u) + w;
                pq.push({dist.at(v), v});

                ruteSebelumnya[v] = u;
            }
        }
    }

    cout << "\n--- Hasil Rute ---" << endl;
    if(dist.at(lokasiTujuan) == INF){
        cout << "Tidak ada rute yang ditemukan dari " << lokasiAwal << " ke " << lokasiTujuan << endl;
    }
    else{
        cout << "Jarak terpendek : " << dist.at(lokasiTujuan) << " meter" << endl;
        cetakRute(lokasiAwal, lokasiTujuan, ruteSebelumnya);
    }
}

void DjikstraAlgorithm::cetakRute(const string& lokasiAwal, const string& lokasiTujuan, map<string, string>& ruteSebelumnya){
    vector<string> rute;
    string saatIni = lokasiTujuan;

    while(saatIni != lokasiAwal){
        rute.push_back(saatIni);
        if(ruteSebelumnya.find(saatIni) == ruteSebelumnya.end()) break;
        saatIni = ruteSebelumnya.at(saatIni);
    }

    reverse(rute.begin(), rute.end());
    cout << "Rute            : ";
    for (size_t i = 0; i < rute.size(); ++i) {
        cout << rute[i];
        if (i < rute.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}