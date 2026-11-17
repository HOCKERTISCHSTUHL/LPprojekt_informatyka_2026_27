#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Paletka.h"
#include "Pilka.h"

using namespace std;

int main() {
    float szerokosc = 640;
    float wysokosc = 480;

    sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid test");
    window.setFramerateLimit(60);

    Paletka pal(320, 440, 100, 20, 8);
    Pilka p1(320, 200, 4, 3, 8);

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
        pal.rysuj(window);
        p1.rysuj(window);
        window.display();
    }

    return 0;
}
