#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    system("cls");
    map<string, int> dist;
    dist["A"] = 10;
    dist["B"] = 20;

    cout << "Sebelum akses: ukuran map = " << dist.size() << endl;
    cout << "dist[\"C\"] = " << dist["C"] << endl;

    cout << "Sesudah akses: ukuran map = " << dist.size() << endl;
    cout << "Nilai dist[\"C\"] sekarang = " << dist["C"] << endl << endl;

    cout << "dist.at(\"D\") = " << dist.at("D") << endl;
}
