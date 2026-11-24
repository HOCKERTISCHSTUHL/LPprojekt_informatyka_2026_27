#ifndef PILKA_H
#define PILKA_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Paletka.h"

using namespace std;

class Pilka {
private:
    float x;
    float y;
    float vx;
    float vy;
    float radius;
    sf::CircleShape shape;

public:
    // Konstruktor 
    Pilka(float startX, float startY, float startVx, float startVy, float startRadius) {
        x = startX;
        y = startY;
        vx = startVx;
        vy = startVy;
        radius = startRadius;

        shape.setRadius(radius);
        shape.setOrigin(radius, radius);
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::White);
    }

    void przesun() {
        x += vx;
        y += vy;
        shape.setPosition(x, y);
    }

    void odbijX() {
        vx = -vx;
    }

    void odbijY() {
        vy = -vy;
    }

    // Sprawdzenie kolizji 
    string kolizjaSciana(float width, float height) {
        string hit = "";

        if (x - radius <= 0) {
            odbijX();
            x = radius;
            shape.setPosition(x, y);
            hit = "HIT X-WALL";
        }

        if (x + radius >= width) {
            odbijX();
            x = width - radius;
            shape.setPosition(x, y);
            hit = "HIT X-WALL";
        }

        if (y - radius <= 0) {
            odbijY();
            y = radius;
            shape.setPosition(x, y);
            if (hit != "") {
                hit += " ";
            }
            hit += "HIT Y-WALL";
        }

        return hit;
    }

    bool kolizjaPaletka(Paletka& pal) {
        float lewaKrawedz = pal.getX() - pal.getSzerokosc() / 2;
        float prawaKrawedz = pal.getX() + pal.getSzerokosc() / 2;
        float gornaKrawedz = pal.getY() - pal.getWysokosc() / 2;

        if (x >= lewaKrawedz && x <= prawaKrawedz) {
            if (y + radius >= gornaKrawedz && y - radius < gornaKrawedz) {
                if (vy > 0) {
                    vy = -vy;
                }
                y = gornaKrawedz - radius;
                shape.setPosition(x, y);
                return true;
            }
        }

        return false;
    }

    void rysuj(sf::RenderWindow& window) {
        window.draw(shape);
    }

    float getX() { return x; }
    float getY() { return y; }
    float getVx() { return vx; }
    float getVy() { return vy; }
    float getRadius() { return radius; }
};

#endif
