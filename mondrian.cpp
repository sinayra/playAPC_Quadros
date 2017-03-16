#include <playAPC/playapc.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define QUAD 20
#define TAM_M 200/QUAD

typedef struct{
    int R, G, B;
}tipoCores;

int main(){
    int mVisu[TAM_M][TAM_M];
    int mLogica[TAM_M][TAM_M];
    tipoCores validas[4] = {
        {255,255,0}, //amarelo
        {0,127,255}, //azul
        {255,0,0}, //vermelho
        {64,64,64} //cinza
    };
    int i, j;

    srand(time(NULL));

    AbreJanela(500, 500, "Sub-Mondrian Generator");
    PintarFundo(0, 0, 0);

    //Desenha os quadrados
    i = 0;
    j = 0;
    for(int y = 100 - QUAD; y >= -100; y -= QUAD){
        j = 0;
        for(int x = -100; x < 100; x += QUAD){
            Ponto p = {x, y};

            mVisu[i][j] = CriaQuadrado(QUAD, p);
            mLogica[i][j] = -1;
            Pintar(255, 255, 255);

            CriaPonto(p);
            Pintar(0, 0, 0);
            Grafite(5);
            j++;
        }
        i++;
    }

    //Pinta os quadrados
    for(i = 0; i < TAM_M; i++){
        for(j = 0; j < TAM_M; j++){
            bool isBranco = (rand() % 100) < 75;

            if(!isBranco){
                int cor = (int)(rand() % 4);
                Pintar(validas[cor].R, validas[cor].G, validas[cor].B, QUADRADO, mVisu[i][j]);

                mLogica[i][j] = cor;
            }
        }
    }


    for(i = 0; i < TAM_M; i++){
        for(j = 0; j < TAM_M; j++){
            printf("%d\t", mLogica[i][j]);
        }
        printf("\n");
    }


    Desenha();

}
