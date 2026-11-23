#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Paletka.h"
#include "Pilka.h"
#include "Kamien.h"

using namespace std;

int main() {
    float szerokosc = 640;
    float wysokosc = 480;

    sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid test");
    window.setFramerateLimit(60);

    Paletka pal(320, 440, 100, 20, 8);
    Pilka p1(320, 300, 4, 3, 8);

    vector<Kamien> bloki;
    int iloscKolumn = 6;
    int iloscWierszy = 7;
    float rozmiarY = 25;
    float rozmiarX = (szerokosc - (iloscKolumn - 1) * 2) / iloscKolumn;

    for (int y = 0; y < iloscWierszy; y++) {
        for (int x = 0; x < iloscKolumn; x++) {
            float posX = x * (rozmiarX + 2);
            float posY = 50 + y * (rozmiarY + 2);

            int L = 1;
            if (y == 0) {
                L = 3;
            }
            if (y == 1 || y == 2) {
                L = 2;
            }
            if (y >= 3) {
                L = 1;
            }

            bloki.emplace_back(sf::Vector2f(posX, posY), sf::Vector2f(rozmiarX, rozmiarY), L);
        }
    }

    int i = 0;
    string kolizja;
    string granica;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            pal.przesunLewo();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            pal.przesunPrawo();
        }
        granica = pal.ograniczRuch(szerokosc);

        p1.przesun();
        kolizja = p1.kolizjaSciana(szerokosc, wysokosc);

        if (p1.kolizjaPaletka(pal)) {
            cout << "HIT PADDLE" << endl;
        }

        for (int k = 0; k < bloki.size(); k++) {
            if (bloki[k].getZniszczony() == false) {
                float lewa = bloki[k].getPosition().x;
                float prawa = lewa + bloki[k].getSize().x;
                float gora = bloki[k].getPosition().y;
                float dol = gora + bloki[k].getSize().y;

                if (p1.getX() + p1.getRadius() >= lewa && p1.getX() - p1.getRadius() <= prawa) {
                    if (p1.getY() + p1.getRadius() >= gora && p1.getY() - p1.getRadius() <= dol) {
                        bloki[k].trafienie();
                        p1.odbijY();
                    }
                }
            }
        }

        i++;
        if (i % 5 == 0 || kolizja != "") {
            cout << "Krok " << i << ": x=" << p1.getX() << " y=" << p1.getY() << " vx=" << p1.getVx() << " vy=" << p1.getVy();

            if (kolizja != "") {
                cout << " " << kolizja;
            }
            if (granica != "") {
                cout << " " << granica;
            }
            cout << endl;
        }

        if (p1.getY() - p1.getRadius() > wysokosc) {
            cout << "MISS! KONIEC GRY" << endl;
            window.close();
        }

        window.clear(sf::Color(20, 20, 30));
        for (int k = 0; k < bloki.size(); k++) {
            bloki[k].rysuj(window);
        }
        pal.rysuj(window);
        p1.rysuj(window);
        window.display();
    }

    return 0;
}
