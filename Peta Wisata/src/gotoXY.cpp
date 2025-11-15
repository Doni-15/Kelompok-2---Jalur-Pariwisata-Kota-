#include "gotoXY.hpp"

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool validasiPilihan(int awal, int akhir, int pilih){
    if(pilih > akhir || pilih < awal){
        cout << "Masukkan sesuai ketentuan (" << awal << ", " << akhir << ")" << endl;
        return false;
    }
    return true;
}

void clearScreen() {
    system("cls");
}