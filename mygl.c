#include "mygl.h"

//
// >>> Defina aqui as funções que você implementar <<<
//

struct Cores {
    int red;
    int green;
    int blue;
    int alpha;
} typedef Cores;

Cores vermelho = {255,0,0,255};
Cores verde = {0,230,64,1};
Cores azul = {44,130,201,1};

// Função para rasterizar ponto em tela
void PutPixel (int x, int y, Cores cores)  {

    fb_ptr[(x*4 + y*4*IMAGE_WIDTH) + 0] = cores.red;
    fb_ptr[(x*4 + y*4*IMAGE_WIDTH) + 1] = cores.green;
    fb_ptr[(x*4 + y*4*IMAGE_WIDTH) + 2] = cores.blue;
    fb_ptr[(x*4 + y*4*IMAGE_WIDTH) + 3] = cores.alpha;

}

void DrawLine(int x0, int y0, int x1, int y1) {
    int dx, dy, dec, dNE, dL, dant, x, y;

    dx = x1 - x0;
    dy = y1 - y0;

    dec = 2*dy - dx; //Primeiro Pixel
    dNE = 2*(dy -  dx); //Direção Nordeste
    dL = 2*dy; //Direção Leste

    x = x0;
    y = y0;
    
    PutPixel(x, y,vermelho);

    while (x < x1){
            if (dec <= 0){
                dec += dL;
                x++;
            } else {
                dec += dNE;
                x++;
                y++;
            }
        PutPixel(x, y,vermelho);
        }
}

void DrawTriangule(int x0, int y0, int x1, int y1, int x2, int y2) {
    DrawLine(x0,y0,x1,y1); //200,300,300,400
    DrawLine(x1,y1,x2,y2); //300,400,200,400
    DrawLine(x2,y2,x1,y1); //200,400,200,300
}

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Chame aqui as funções que você implementou <<<
    //
    /*PutPixel(300,400,vermelho);
    PutPixel(300,370,verde);
    PutPixel(300,340,azul);*/
    
    //PutPixel(200,300, vermelho);
    //PutPixel(300,400, azul);
    //PutPixel(400,300, verde);
    
    DrawLine(200,300,300,400);
    DrawLine(300,400,400,300);
    DrawLine(400,300,200,300);

    //DrawTriangule(200,300,300,400,200,400);
    //DrawTriangule(300,400,600,500,200,400);

    /*int i;
    int count = 380;
    int r = 255;
    int g = 0;
    int b = 0;
    int a = 255;

    for (i = 0; i < count; i++) {
        g += 5;
        Cores coresInterpoladas = {r, g, b, a};
        PutPixel(300,i,coresInterpoladas);
    }*/
    
    
    
}
