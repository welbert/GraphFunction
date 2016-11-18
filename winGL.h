#ifndef __winGL__
#define __winGL__ 1

#include "EstruturasDeDados.h"
#include <stdbool.h>
void desenhaPonto(tPonto P0, eCor c);
void desenhaQuadrante(tPonto P0, tPonto P1, eCor c);
void desenhaEixos(tPonto P0, tPonto P1);

void display(void);

void initOpenGL(void);

void reshape(int w, int h);

void keyboard(unsigned char key, int x, int y);

void criaJanela(int argc, char** argv, int w, int h);

void initEventos(void);

void desenharArvore(No* raiz);

No* alocaNovoNo(tPonto inicio,tPonto fim);
                      
void sub(No** pai,tPonto inicio, tPonto fim);         

eSectorClass defClasse(tPonto inicio, tPonto fim);

extern	tPonto	domainMin,
				domainMax;
extern bool   dimpFunc0,
              dimpFunc1,
              dimpFunc2,
              dimpFunc3,
              dimpFunc4,
              desenhaQuadrantes,
              desenhaPontos;                     

extern No* sentinela;
extern No* raiz0;
extern No* raiz1;
extern No* raiz2;
extern No* raiz3;
extern No* raiz4;
extern int i,nivel;				

#endif

