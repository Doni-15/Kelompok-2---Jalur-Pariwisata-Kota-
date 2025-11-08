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
}

// void DjikstraAlgorithm::cetakRute(const string& lokasiAwal, const string& lokasiTujuan, map<string, string>& ruteSebelumnya){
// }