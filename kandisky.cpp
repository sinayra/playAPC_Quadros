#include <playAPC/playapc.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;

int main(){
    Ponto p1, p2, p3;
    float apotema, raio, raio2, theta, raioaux, lado;

    srand(time(NULL));

    AbreJanela(500, 500, "Sub-Kandisky Generator");
    PintarFundo(223, 207, 191);

    p1.x = -150;
    p1.y = -70;

    p2.x = -70;
    p2.y = -120;

    p3.x = 130;
    p3.y = 130;

    CriaPoligono(3, p1, p2, p3);
    Pintar(211, 170, 118);

    p1.x = 150;
    p1.y = -40;

    p2.x = 120;
    p2.y = -90;

    p3.x = -130;
    p3.y = 130;

    CriaPoligono(3, p1, p2, p3);
    Pintar(70, 132, 121);

    p1.x = 0;
    p1.y = 0;

    raio = 70;
    apotema = raio / sqrt(2);

    CriaCirculo(raio + 5, p1);
    Pintar(0, 0, 0);

    CriaCirculo(raio, p1);
    Pintar(255, 255, 255);

    raio = 60;

    //Retas
    for(int i = 0; i < 30; i++){

        theta = rand()%360;
        theta = theta * PI/180;

        raioaux = 1 + rand()%(int)raio;

        p1.x = raioaux*cos(theta);
        p1.y = raioaux*sin(theta);

        theta = rand()%360;
        theta = theta * PI/180;
        raioaux = 1 + rand()%(int)raio;

        p2.x = raioaux*cos(theta);
        p2.y = raioaux*sin(theta);

        CriaReta(p1, p2);
        Grafite(2);

    }

    raio = 50;
    raio2 = 10;
    for(int i = 0; i < 20; i++){
        theta = rand()%360;
        theta = theta * PI/180;
        raioaux = 1 + rand()%(int)raio;

        p1.x = raioaux*cos(theta);
        p1.y = raioaux*sin(theta);

        theta = rand()%360;
        theta = theta * PI/180;
        raioaux = 1 + rand()%(int)raio;

        p2.x = raioaux*cos(theta);
        p2.y = raioaux*sin(theta);

        raioaux = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

        raioaux = 1 + rand()%(int)raio2;
        CriaCirculo(raioaux, p1);
        Pintar(rand()%255, rand()%255, rand()%255);

        CriaCircunferencia(raioaux, p1);
        Pintar(0, 0, 0);
        Grafite(3);

    }

    //Quadrado
    for(int i = 0; i < 20; i++){

        theta = rand()%360;
        theta = theta * PI/180;
        raioaux = 1 + rand()%(int)raio;

        p1.x = raioaux*cos(theta);
        p1.y = raioaux*sin(theta);

        raioaux = 1 + rand()%(int)raio2;

        lado = 2* raioaux/sqrt(2);


        p2.x = p1.x - lado/sqrt(2);
        p2.y = p1.y - lado/sqrt(2);

        CriaQuadrado(lado + 2, {p2.x - 1, p2.y - 1});
        Pintar(0, 0, 0);
        Grafite(3);

        CriaQuadrado(lado, p2);
        Pintar(rand()%255, rand()%255, rand()%255);

    }

    Desenha();
}
