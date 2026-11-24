#include "Game.h"

Game::Game()
    : m_window(sf::VideoMode(640, 480), "Arkanoid test"),
    m_paletka(320, 440, 100, 20, 8),
    m_pilka(320, 300, 4, 3, 8)
{
    szerokosc = 640;
    wysokosc = 480;
    i = 0;

    m_window.setFramerateLimit(60);

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

            m_bloki.emplace_back(sf::Vector2f(posX, posY), sf::Vector2f(rozmiarX, rozmiarY), L);
        }
    }
}

void Game::run() {
    while (m_window.isOpen()) {
        processEvents();
        sf::Time dt = m_deltaClock.restart();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void Game::update(sf::Time dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_paletka.przesunLewo();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_paletka.przesunPrawo();
    }
    granica = m_paletka.ograniczRuch(szerokosc);

    m_pilka.przesun();
    kolizja = m_pilka.kolizjaSciana(szerokosc, wysokosc);

    if (m_pilka.kolizjaPaletka(m_paletka)) {
        cout << "HIT PADDLE" << endl;
    }

    for (int k = 0; k < m_bloki.size(); k++) {
        if (m_bloki[k].getZniszczony() == false) {
            float lewa = m_bloki[k].getPosition().x;
            float prawa = lewa + m_bloki[k].getSize().x;
            float gora = m_bloki[k].getPosition().y;
            float dol = gora + m_bloki[k].getSize().y;

            if (m_pilka.getX() + m_pilka.getRadius() >= lewa && m_pilka.getX() - m_pilka.getRadius() <= prawa) {
                if (m_pilka.getY() + m_pilka.getRadius() >= gora && m_pilka.getY() - m_pilka.getRadius() <= dol) {
                    m_bloki[k].trafienie();
                    m_pilka.odbijY();
                }
            }
        }
    }

    i++;
    if (i % 5 == 0 || kolizja != "") {
        cout << "Krok " << i << ": x=" << m_pilka.getX() << " y=" << m_pilka.getY() << " vx=" << m_pilka.getVx() << " vy=" << m_pilka.getVy();

        if (kolizja != "") {
            cout << " " << kolizja;
        }
        if (granica != "") {
            cout << " " << granica;
        }
        cout << endl;
    }

    if (m_pilka.getY() - m_pilka.getRadius() > wysokosc) {
        cout << "MISS! KONIEC GRY" << endl;
        m_window.close();
    }
}

void Game::render() {
    m_window.clear(sf::Color(20, 20, 30));
    for (int k = 0; k < m_bloki.size(); k++) {
        m_bloki[k].rysuj(m_window);
    }
    m_paletka.rysuj(m_window);
    m_pilka.rysuj(m_window);
    m_window.display();
}