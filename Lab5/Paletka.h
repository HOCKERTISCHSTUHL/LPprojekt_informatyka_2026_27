#ifndef PALETKA_H
#define PALETKA_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Paletka {
private:
    float x;
    float y;
    float szerokosc;
    float wysokosc;
    float vx;
    sf::RectangleShape shape;

public:
    // Konstruktor 
    Paletka(float startX, float startY, float startSzerokosc, float startWysokosc, float startVx) {
        x = startX;
        y = startY;
        szerokosc = startSzerokosc;
        wysokosc = startWysokosc;
        vx = startVx;

        shape.setSize(sf::Vector2f(szerokosc, wysokosc));
        shape.setOrigin(szerokosc / 2, wysokosc / 2);
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Cyan);
    }

    void przesunLewo() {
        x -= vx;
        shape.setPosition(x, y);
    }

    void przesunPrawo() {
        x += vx;
        shape.setPosition(x, y);
    }

    // Sprawdza, czy paletka nie wychodzi poza ekran, nadpisuje granice
    string ograniczRuch(float width) {
        string granica = "";

        if (x - szerokosc / 2 < 0) {
            x = szerokosc / 2;
            shape.setPosition(x, y);
            granica = "LEWA GRANICA";
        }

        if (x + szerokosc / 2 > width) {
            x = width - szerokosc / 2;
            shape.setPosition(x, y);
            granica = "PRAWA GRANICA";
        }
        return granica;
    }

    void rysuj(sf::RenderWindow& window) {
        window.draw(shape);
    }

    float getX() { return x; }
    float getY() { return y; }
    float getSzerokosc() { return szerokosc; }
    float getWysokosc() { return wysokosc; }
    float getVx() { return vx; }
};

#endif
