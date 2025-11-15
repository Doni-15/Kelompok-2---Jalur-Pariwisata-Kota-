#ifndef GOTOXY_HPP
#define GOTOXY_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <queue>
#include <limits>
#include <algorithm>
#include <windows.h> 
#include <cmath>
#include <functional>
#include <limits>

using namespace std;

void gotoxy(int x, int y);
bool validasiPilihan(int awal, int akhir, int pilih);
void clearScreen();

#endif