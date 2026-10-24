#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Stacja {
    int id;
    char nazwa[40];
    char lokalizacja[50];
};

struct Pomiar {
    char czas[30];
    float temperatura;
    float wilgotnosc;
    float cisnienie;
};

struct Rekord {
    struct Stacja stacja;
    struct Pomiar pomiar;
};

int main() {
    struct Stacja st[2] = {
        {1, "Wrzeszcz", "Dmowskiego"},
        {2, "Oliwa", "Wita Stwosza"}
    };
    
    struct Pomiar p1 = {"9:50 20.10 2026", 10.0, 60.0, 1005.0};
    struct Rekord dane[50];
    
    time_t currentTime;
    
    srand(time(NULL));
    
    // procedura symulujaca pomiary 
    for(int i=0; i<10; i++){
        dane[i].stacja = st[i%2];
        dane[i].pomiar.temperatura = rand()%60-30;
        dane[i].pomiar.cisnienie = 900 + rand()%40;
        dane[i].pomiar.wilgotnosc = 30 + rand()%60;
        time(&currentTime);
        
        strcpy(dane[i].pomiar.czas, ctime(&currentTime));
        int n = strlen(dane[i].pomiar.czas);      
        dane[i].pomiar.czas[n-1] = 0; 
    }
    
    for(int i=0; i<10; i++){
        printf("[%d] %d %s %s ", i, dane[i].stacja.id, dane[i].stacja.nazwa, dane[i].stacja.lokalizacja);
        printf("%s t: %f, h: %f, p: %f\n", dane[i].pomiar.czas, dane[i].pomiar.temperatura, dane[i].pomiar.wilgotnosc, dane[i].pomiar.cisnienie);
    }

    
    float min_temp = dane[0].pomiar.temperatura;
    float max_temp = dane[0].pomiar.temperatura;
    float suma_wilg = 0.0;
    float suma_cisn = 0.0;

    for(int i=0; i<10; i++) {
        if(dane[i].pomiar.temperatura < min_temp) {
            min_temp = dane[i].pomiar.temperatura;
        }
        if(dane[i].pomiar.temperatura > max_temp) {
            max_temp = dane[i].pomiar.temperatura;
        }
        suma_wilg += dane[i].pomiar.wilgotnosc;
        suma_cisn += dane[i].pomiar.cisnienie;
    }

    printf("Minimalna temperatura: %.2f C\n", min_temp);
    printf("Maksymalna temperatura: %.2f C\n", max_temp);
    printf("Srednia wilgotnosc: %.2f %%\n", suma_wilg / 10.0);
    printf("Srednie cisnienie: %.2f hPa\n", suma_cisn / 10.0);

    return 0;
}