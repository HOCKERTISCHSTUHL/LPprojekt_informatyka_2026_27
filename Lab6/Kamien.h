#ifndef KAMIEN_H
#define KAMIEN_H

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

using namespace std;

class Kamien : public sf::RectangleShape {
private:
    int punktyZycia;
    bool jestZniszczony;
    static const array<sf::Color, 4> kolory;

public:
    // Konstruktor
    Kamien(sf::Vector2f startPos, sf::Vector2f rozmiar, int L) {
        punktyZycia = L;
        jestZniszczony = false;

        setPosition(startPos);
        setSize(rozmiar);
        setOutlineThickness(2);
        aktualizujKolor();
    }

    void trafienie() {
        if (jestZniszczony == true) {
            return;
        }

        punktyZycia = punktyZycia - 1;
        aktualizujKolor();

        if (punktyZycia <= 0) {
            jestZniszczony = true;
        }
    }

    void aktualizujKolor() {
        if (punktyZycia == 0) {
            setFillColor(kolory[0]);
        }
        if (punktyZycia == 1) {
            setFillColor(kolory[1]);
        }
        if (punktyZycia == 2) {
            setFillColor(kolory[2]);
        }
        if (punktyZycia == 3) {
            setFillColor(kolory[3]);
        }
    }

    bool getZniszczony() {
        return jestZniszczony;
    }

    void rysuj(sf::RenderWindow& window) {
        if (jestZniszczony == false) {
            window.draw(*this);
        }
    }
};

const array<sf::Color, 4> Kamien::kolory = {
    sf::Color(0, 0, 0, 0),
    sf::Color(255, 0, 0),
    sf::Color(255, 255, 0),
    sf::Color(0, 0, 255)
};

#endif
