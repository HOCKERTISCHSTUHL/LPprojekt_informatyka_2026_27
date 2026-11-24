#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Paletka.h"
#include "Pilka.h"
#include "Kamien.h"

using namespace std;

class Game {
private:
    sf::RenderWindow m_window;
    sf::Clock m_deltaClock;
    Paletka m_paletka;
    Pilka m_pilka;
    vector<Kamien> m_bloki;

    float szerokosc;
    float wysokosc;
    int i;
    string kolizja;
    string granica;

    void processEvents();
    void update(sf::Time dt);
    void render();

public:
    Game();
    void run();
};

#endif