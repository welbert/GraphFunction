#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#if defined (__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include "EstruturasDeDados.h"
#include "funcoes.h"
#include "winGL.h"

tPonto	domainMin,
		domainMax;
//dimpFunN Variaveis utilizadas para controlar qual das funções será vista na janela.
bool    dimpFunc0,
        dimpFunc1,
        dimpFunc2,
        dimpFunc3,
        dimpFunc4,
        desenhaQuadrantes;


bool    desenhaPontos = true;
bool	desenhaEixo = true;
No* sentinela;
//Raizes de cada uma das arvores que representam cada uma das funções.
No* raiz0;
No* raiz1;
No* raiz2;
No* raiz3;
No* raiz4;
int nivel=0;
						
/// ***********************************************************************
/// ** 
/// ***********************************************************************

void teclado(unsigned char key, int x, int y) {
	switch (key) {
		case 27		: 	exit(0);
						break;
		//Liga-Desliga representações na janela.						
		case 'E'	:
		case 'e'	:	desenhaEixo = !desenhaEixo;
						break;				
		case 'Q'    :
		case 'q'    :   desenhaQuadrantes = !desenhaQuadrantes;
						break;				
		case 'P'    :
		case 'p'    :   desenhaPontos = !desenhaPontos;
						break;						
		case '1'    :    dimpFunc0 = !dimpFunc0;
                         dimpFunc1 = false;              				
                         dimpFunc2 = false;
                         dimpFunc3 = false;
                         dimpFunc4 = false;
                         break;
		case '2'    :    dimpFunc1 = !dimpFunc1;
		                 dimpFunc0 = false;
		                 dimpFunc2 = false;
		                 dimpFunc3 = false;
		                 dimpFunc4 = false;
		                 break;
		case '3'    :    dimpFunc2 = !dimpFunc2;
		                 dimpFunc0 = false;
		                 dimpFunc1 = false;
		                 dimpFunc3 = false;
		                 dimpFunc4 = false;
		                 break;
		case '4'    :    dimpFunc3 = !dimpFunc3;
		                 dimpFunc0 = false;
		                 dimpFunc1 = false;
		                 dimpFunc2 = false;
		                 dimpFunc4 = false;
		                 break;
		case '5'    :    dimpFunc4 = !dimpFunc4;                		
		                 dimpFunc0 = false;
		                 dimpFunc1 = false;
		                 dimpFunc2 = false;
		                 dimpFunc3 = false;
		                 break;
	    case '+'  :    nivel++;
					   break;	
	    case '-'  :    nivel--;	                 
					   break;
		}
	glutPostRedisplay();
}
		
/// ***********************************************************************
/// **
/// ***********************************************************************

void mouse(int button, int button_state, int x, int y ) {
	
	if 	(button_state == GLUT_DOWN ) {
		switch (button) {
			//controla nivel de sub-divisão visto na janela.(pode ser utilizado + ou - o teclado)
			case GLUT_LEFT_BUTTON	: 	nivel++;
										break;
	
			case GLUT_RIGHT_BUTTON	:	nivel--;
										break;
			}
		glutPostRedisplay();
		}
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void desenho(void) {
	
    glClear(GL_COLOR_BUFFER_BIT); 
    
    if (desenhaEixo)
    	desenhaEixos(domainMin, domainMax);
    
	desenhaQuadrante(domainMin, domainMax, RED);
	
	//Desenha a função implicita N na janela.
    if(dimpFunc0)
        desenharArvore(raiz0);        
    if(dimpFunc1)
        desenharArvore(raiz1);         
    if(dimpFunc2)
        desenharArvore(raiz2);         
    if(dimpFunc3)
        desenharArvore(raiz3);
    if(dimpFunc4)
        desenharArvore(raiz4);	
    if(nivel<0)
		nivel=0;        	
    glutSwapBuffers();
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

int main(int argc, char** argv) {
		
	criaJanela(argc, argv, 500, 500);
	//Dominio definido pelo usuario.
	float dmi;	
	printf("Digite um valor para o dominio: ");
	scanf("%f",&dmi);
	
	domainMin.x = -ABS(dmi);
	domainMin.y = -ABS(dmi);
	domainMax.x	= ABS(dmi);
	domainMax.y	= ABS(dmi);
	//Aloca as raizes das arvores de cada função.
	raiz0=alocaNovoNo(domainMin,domainMax);
    raiz1=alocaNovoNo(domainMin,domainMax);
    raiz2=alocaNovoNo(domainMin,domainMax);
    raiz3=alocaNovoNo(domainMin,domainMax);
    raiz4=alocaNovoNo(domainMin,domainMax);
    //Cria as arvores baseadas nas funções implicitas.    
    dimpFunc0=true;
    sub(&raiz0,domainMin,domainMax);
    dimpFunc0=false;
    
    dimpFunc1=true;
    sub(&raiz1,domainMin,domainMax);
    dimpFunc1=false;
    
    dimpFunc2=true;
    sub(&raiz2,domainMin,domainMax);
    dimpFunc2=false;
    
    dimpFunc3=true;
    sub(&raiz3,domainMin,domainMax);
    dimpFunc3=false;
    
    dimpFunc4=true;
    sub(&raiz4,domainMin,domainMax);
    dimpFunc4=false;
    
    desenhaQuadrantes=true;
    initOpenGL();
    
    initEventos();
        
    return 0;   
}
