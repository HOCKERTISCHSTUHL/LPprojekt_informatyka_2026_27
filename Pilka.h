#ifndef PILKA_H
#define PILKA_H

#include <iostream>
#include <string>

using namespace std;

class Pilka {
private:
    int x;
    int y;
    int vx;
    int vy;
    int radius;

public:
    //Konstruktor 
    Pilka(int startX, int startY, int startVx, int startVy, int startRadius) {
        x = startX;
        y = startY;
        vx = startVx;
        vy = startVy;
        radius = startRadius;
    }

    void przesun() {
        x += vx;
        y += vy;
    }

    void odbijX() {
        vx = -vx;
    }

    void odbijY() {
        vy = -vy;
    }

    // Sprawdzenie kolizji 
    string kolizjaSciana(int width, int height) {
        string hit = "";

        if (x - radius <= 0 || x + radius >= width) {
            odbijX();
            hit = "HIT X-WALL";
        }

        if (y - radius <= 0 || y + radius >= height) {
            odbijY();
            if (hit != "") {
                hit += " ";
            }
            hit += "HIT Y-WALL";
        }

        return hit;
    }

    int getX() { return x; }
    int getY() { return y; }
    int getVx() { return vx; }
    int getVy() { return vy; }
    int getRadius() { return radius; }
};

#endif
