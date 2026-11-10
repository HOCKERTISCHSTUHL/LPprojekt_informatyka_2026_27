#include <iostream>
#include <string>
#include "Pilka.h"

using namespace std;

int main() {
    int szerokosc = 640;
    int wysokosc = 480;
    
    int i; 
    string kolizja;

    cout << "DEMO A" << endl;
    Pilka p1(20, 200, -5, 0, 10);
    
    for (i = 1; i <= 5; i++) {
        p1.przesun();
        kolizja = p1.kolizjaSciana(szerokosc, wysokosc);

        cout << "Krok " << i << ": x=" << p1.getX() << " y=" << p1.getY() << " vx=" << p1.getVx() << " vy=" << p1.getVy();
        
        if (kolizja != "") {
            cout << " " << kolizja;
        } 
        cout << endl;
    }

    cout << "DEMO B" << endl;
    Pilka p2(200, 465, 0, 5, 10);
    
    for (i = 1; i <= 5; i++) {
        p2.przesun();
        kolizja = p2.kolizjaSciana(szerokosc, wysokosc);

        cout << "Krok " << i << ": x=" << p2.getX() << " y=" << p2.getY() << " vx=" << p2.getVx() << " vy=" << p2.getVy();
        
        if (kolizja != "") {
            cout << " " << kolizja;
        }
        cout << endl;
    }

    cout << "DEMO C" << endl;
    Pilka p3(30, 40, -10, 10, 10);
    
    for (i = 1; i <= 100; i++) {
        p3.przesun();
        kolizja = p3.kolizjaSciana(szerokosc, wysokosc);

        cout << "Krok " << i << ": x=" << p3.getX() << " y=" << p3.getY() << " vx=" << p3.getVx() << " vy=" << p3.getVy();
        
        if (kolizja != "") {
            cout << " " << kolizja;
        }
        cout << endl;
    }

    return 0;
}