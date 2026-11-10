#include <iostream>
#include <string>
#include "Paletka.h"

using namespace std;

int main() {
    int szerokoscPlanszy = 640;

    Paletka pal(320, 450, 80, 10);

    for (int i = 1; i <= 100; i++) {
        
        if (i % 20 < 10) {
            pal.przesunLewo();
        } else {
            pal.przesunPrawo();
        }

        string granica = pal.ograniczRuch(szerokoscPlanszy);

        cout << "Krok " << i << ": x=" << pal.getX() << ", y=" << pal.getY();
        if (granica != "") {
            cout << " " << granica;
        }
        cout << endl;
    }

    return 0;
}