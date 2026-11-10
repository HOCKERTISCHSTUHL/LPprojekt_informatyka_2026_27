#ifndef PALETKA_H
#define PALETKA_H

#include <iostream>

using namespace std;

class Paletka {
private:
    int x;          
    int y;          
    int szerokosc;  
    int vx;         

public:
     // Konstruktor 
    Paletka(int startX, int startY, int startSzerokosc, int startVx) {
        x = startX;
        y = startY;
        szerokosc = startSzerokosc;
        vx = startVx;
    }

    void przesunLewo() {
        x -= vx;
    }
    
    void przesunPrawo() {
        x += vx;
    }

    // Sprawdza, czy paletka nie wychodzi poza ekran, nadpisuje granice
    string ograniczRuch(int width) {
        string granica = "";
 
        if (x - szerokosc / 2 < 0) {
            x = szerokosc / 2;
            granica = "LEWA GRANICA";
        }

        if (x + szerokosc / 2 > width) {
            x = width - szerokosc / 2;
            granica = "PRAWA GRANICA";
        }
        return granica;
    }

    int getX() { return x; }
    int getY() { return y; }
    int getSzerokosc() { return szerokosc; }
    int getVx() { return vx; }
};

#endif
