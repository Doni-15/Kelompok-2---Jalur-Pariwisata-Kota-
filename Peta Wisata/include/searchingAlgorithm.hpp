#ifndef SEARCHING_HPP
#define SEARCHING_HPP

#include "dataSet.hpp"

class SearchingAlgorithm {
    private:
        template<typename T>
        static T bacaInputValid(const string& prompt) {
            T nilai;
            while (true) {
                cout << prompt;
                if (cin >> nilai) {
                    break;
                } else {
                    cout << "Input tidak valid. Silakan coba lagi.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                }
            }
            return nilai;
        }

    public:
        SearchingAlgorithm();
        static void jalankanSearching();
        static void aturOutput(string mode, vector<string>& tampilPilihan);
        static void kategori();
        static void rating();
        static void poin();
};

#endif