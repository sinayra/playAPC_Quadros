#include <playAPC/playapc.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define QUAD 25
#define TAM_M 200/QUAD

typedef struct{
    int R, G, B;
}tipoCores;


void desenhaRetas(int mLogica[TAM_M][TAM_M], int mVisuRetas[TAM_M][TAM_M]){
         //Desenha as retas horizontais
    int i, j;

    for(i = 0; i < TAM_M; i++){
        bool temLinha = (rand() % 100) < 25;

        if(temLinha){
            for(j = 0; j < TAM_M; j++){
                Pintar(0, 0, 0, RETA, mVisuRetas[i][j]);
            }
        }
        else{
            for(j = 0; j < TAM_M; j++){
                if(mLogica[i][j] > -1){
                    if(i < TAM_M - 1 && mLogica[i][j] != mLogica[i + 1][j])
                        Pintar(0, 0, 0, RETA, mVisuRetas[i][j]);
                }
            }
        }


    }

            //Desenha as retas verticais
   /* for(int x = 100; x >= -100; x -= QUAD){
        Ponto p1 = {x, -100};
        Ponto p2 = {x, 100};

        bool temLinha = (rand() % 100) < 75;

        if(temLinha){
            CriaReta(p2, p1);
            Grafite(5);
            Pintar(0, 0, 0);
        }
    }*/
}

int main(){
    int mVisu[TAM_M][TAM_M];
    int mVisuRetasHor[TAM_M][TAM_M], mVisuRetasVer[TAM_M][TAM_M];
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
            Ponto p2 = {p.x + QUAD, p.y};

            mVisu[i][j] = CriaQuadrado(QUAD - 5, p);
            mLogica[i][j] = -1;
            Pintar(255, 255, 255);

            mVisuRetasHor[i][j] = CriaReta(p, p2);
            Grafite(2);
            Pintar(255, 255, 255);

            p2.x = p.x;
            p2.y = p.y + QUAD;
            mVisuRetasVer[i][j] = CriaReta(p, p2);
            Grafite(2);
            Pintar(255, 255, 255);

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

    desenhaRetas(mLogica, mVisuRetasHor);


    Desenha();

}
