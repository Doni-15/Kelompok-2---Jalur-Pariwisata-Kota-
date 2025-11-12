#include "gotoXY.hpp"

void gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

bool validasiPilihan(int awal, int akhir, int pilih){
    if(pilih > akhir || pilih < awal){
        cout << "Masukkan sesuai ketentuan (" << awal << ", " << akhir << ")" << endl;
        return false;
    }
    return true;
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}