#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char czas[30];
    float moc_w;
} ProbaMocy;

int main() {
    ProbaMocy p[8];
    
    srand(time(NULL));
    time_t currentTime;
    float suma_mocy = 0.0;
    
    for(int i = 0; i < 8; i++) {
        p[i].moc_w = 100.0 + (rand() % 701);
        suma_mocy += p[i].moc_w; 
        
        time(&currentTime);
        strcpy(p[i].czas, ctime(&currentTime));
        
        int n = strlen(p[i].czas);
        p[i].czas[n-1] = 0; 
    }

    float dt = 15.0; 
    float E = 0.0;
    
    for(int i = 0; i < 7; i++) {
        E += ((p[i].moc_w + p[i+1].moc_w) / 2.0) * (dt / 60.0) * (1.0 / 1000.0);
    }
    
    float srednia_mocy = suma_mocy / 8.0;
    float E_porownawcza = srednia_mocy * (105.0 / 60.0) * (1.0 / 1000.0);

    for(int i = 0; i < 8; i++) {
        printf("[%d] %s moc: %f\n", i+1, p[i].czas, p[i].moc_w);
    }

    printf("\nEnergia trapezy: %f\n", E);
    printf("Energia srednia: %f\n", E_porownawcza);

    return 0;
}