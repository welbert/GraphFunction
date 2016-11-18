#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#if defined (__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "EstruturasDeDados.h"
#include "winGL.h"
#include "trabalho.h"
#include "funcoes.h"		
float Cores[8][3] = { 	{0.0, 0.0, 0.0},
						{1.0, 0.0, 0.0},
						{0.0, 1.0, 0.0},
						{0.0, 0.0, 1.0},
						{1.0, 0.0, 1.0},
						{0.0, 1.0, 1.0},
						{1.0, 1.0, 0.0},
						{0.5, 0.5, 0.5} };
int i=0;

						
/// ***********************************************************************
/// ** 
/// ***********************************************************************

void desenhaEixos(tPonto P0, tPonto P1) {
	
    glBegin(GL_LINES);
		glColor3fv(Cores[RED]);
		glVertex2f(P0.x, 0.0);
		glVertex2f(P1.x, 0.0);
		
		glColor3fv(Cores[GREEN]);
		glVertex2f(0.0, P0.y);
		glVertex2f(0.0, P1.y);
    glEnd();   
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void desenhaPonto(tPonto P, eCor c) {
	
	glColor3fv(Cores[c]);

    glBegin(GL_POINTS);
		glVertex2f(P.x, P.y);
    glEnd();   
}

/// ***********************************************************************
/// ** 
/// **********************************************************************

void desenhaQuadrante(tPonto P0, tPonto P1, eCor c) {
	
	glColor3fv(Cores[c]);

    glBegin(GL_QUADS);
		glVertex2f(P0.x, P0.y);
		glVertex2f(P1.x, P0.y);
		glVertex2f(P1.x, P1.y);
		glVertex2f(P0.x, P1.y);
    glEnd(); 
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void initOpenGL () {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void reshape (int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(domainMin.x*1.1, domainMax.x*1.1,  domainMin.y*1.1, domainMax.y*1.1);
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void criaJanela(int argc, char** argv, int w, int h) {
	
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (w, h);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Aproximacao de Curva - Estrutura de Dados");
}


/// ***********************************************************************
/// ** 
/// ***********************************************************************

void initEventos() {
	
    glutDisplayFunc(desenho);
    glutKeyboardFunc(teclado);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	
	glutMainLoop();

}
/// ***********************************************************************
/// ** 
/// ***********************************************************************
/// ***********************************************************************
/// ** 
/// ***********************************************************************
/// ***********************************************************************
/// ** 
/// ***********************************************************************
/*Alocar nó para a árvore*/
No* alocaNovoNo(tPonto inicio,tPonto fim){
No* novoNo;
	novoNo=(No*)malloc(sizeof(No));
    if(novoNo==NULL)
       return NULL;
    novoNo->fst=sentinela;
    novoNo->snd=sentinela;
    novoNo->trd=sentinela;
    novoNo->fth=sentinela;
    novoNo->setor.Min.x=inicio.x;
    novoNo->setor.Min.y=inicio.y;
    novoNo->setor.Max.x=fim.x;
    novoNo->setor.Max.y=fim.y;
    novoNo->setor.c=defClasse(inicio,fim);
    novoNo->nivel=i;
    return novoNo;
}    

/*Definir classe do setor para o nó*/
eSectorClass defClasse(tPonto inicio, tPonto fim){
tPonto aux1,aux2;     
      
      aux1.x=inicio.x;
      aux1.y=fim.y;
      aux2.x=fim.x;
      aux2.y=inicio.y;
      //Compara os pontos dois a dois para a definição do setor.
      if(dimpFunc0){
        if(   ( ((implicitFunc0(inicio)>0) && (implicitFunc0(fim)<0))  ||   
               ((implicitFunc0(inicio)<0) && (implicitFunc0(fim)>0))    )       
                                        ||
              ( ((implicitFunc0(aux1)>0) && (implicitFunc0(aux2)<0))  ||   
               ((implicitFunc0(aux1)<0) && (implicitFunc0(aux2)>0))    ) 
										||
              ( ((implicitFunc0(inicio)>0) && (implicitFunc0(aux1)<0))  ||   
               ((implicitFunc0(inicio)<0) && (implicitFunc0(aux1)>0))    )
                                         ||
              ( ((implicitFunc0(fim)>0) && (implicitFunc0(aux2)<0))  ||   
               ((implicitFunc0(fim)<0) && (implicitFunc0(aux2)>0))    )
              )return CROSS;
        else
           if(implicitFunc0(inicio)<0)
                 return INTERN;
            else  
              if(implicitFunc0(inicio)>0)
                  return EXTERN;              
                  }
                  
      if(dimpFunc1){
        if(   ( ((implicitFunc1(inicio)>0) && (implicitFunc1(fim)<0))  ||   
               ((implicitFunc1(inicio)<0) && (implicitFunc1(fim)>0))    )       
                                        ||
              ( ((implicitFunc1(aux1)>0) && (implicitFunc1(aux2)<0))  ||   
               ((implicitFunc1(aux1)<0) && (implicitFunc1(aux2)>0))    ) 
										||
              ( ((implicitFunc1(inicio)>0) && (implicitFunc1(aux1)<0))  ||   
               ((implicitFunc1(inicio)<0) && (implicitFunc1(aux1)>0))    )
                                         ||
              ( ((implicitFunc1(fim)>0) && (implicitFunc1(aux2)<0))  ||   
               ((implicitFunc1(fim)<0) && (implicitFunc1(aux2)>0))    )
               
              )return CROSS;
        else
           if(implicitFunc1(inicio)<0)
                 return INTERN;
            else  
              if(implicitFunc1(inicio)>0)
                  return EXTERN;              
                  }

      if(dimpFunc2){
        if(   ( ((implicitFunc2(inicio)>0) && (implicitFunc2(fim)<0))  ||   
               ((implicitFunc2(inicio)<0) && (implicitFunc2(fim)>0))    )       
                                        ||
              ( ((implicitFunc2(aux1)>0) && (implicitFunc2(aux2)<0))  ||   
               ((implicitFunc2(aux1)<0) && (implicitFunc2(aux2)>0))    ) 
										||
              ( ((implicitFunc2(inicio)>0) && (implicitFunc2(aux1)<0))  ||   
               ((implicitFunc2(inicio)<0) && (implicitFunc2(aux1)>0))    )
                                         ||
              ( ((implicitFunc2(fim)>0) && (implicitFunc2(aux2)<0))  ||   
               ((implicitFunc2(fim)<0) && (implicitFunc2(aux2)>0))    )
              )return CROSS;
        else
           if(implicitFunc2(inicio)<0)
                 return INTERN;
            else  
              if(implicitFunc2(inicio)>0)
                  return EXTERN;              
                  }

      if(dimpFunc3){
        if(   ( ((implicitFunc3(inicio)>0) && (implicitFunc3(fim)<0))  ||   
               ((implicitFunc3(inicio)<0) && (implicitFunc3(fim)>0))    )       
                                        ||
              ( ((implicitFunc3(aux1)>0) && (implicitFunc3(aux2)<0))  ||   
               ((implicitFunc3(aux1)<0) && (implicitFunc3(aux2)>0))    )
                                         ||
              ( ((implicitFunc3(inicio)>0) && (implicitFunc3(aux1)<0))  ||   
               ((implicitFunc3(inicio)<0) && (implicitFunc3(aux1)>0))    )
                                         ||
              ( ((implicitFunc3(fim)>0) && (implicitFunc3(aux2)<0))  ||   
               ((implicitFunc3(fim)<0) && (implicitFunc3(aux2)>0))    )   
              )return CROSS;
        else
           if(implicitFunc3(inicio)<0)
                 return INTERN;
            else  
              if(implicitFunc3(inicio)>0)
                  return EXTERN;              
                  }

      if(dimpFunc4){
        if(   ( ((implicitFunc4(inicio)>0) && (implicitFunc4(fim)<0))  ||   
               ((implicitFunc4(inicio)<0) && (implicitFunc4(fim)>0))    )       
                                        ||
              ( ((implicitFunc4(aux1)>0) && (implicitFunc4(aux2)<0))  ||   
               ((implicitFunc4(aux1)<0) && (implicitFunc4(aux2)>0))    ) 
										||
              ( ((implicitFunc4(inicio)>0) && (implicitFunc4(aux1)<0))  ||   
               ((implicitFunc4(inicio)<0) && (implicitFunc4(aux1)>0))    )
                                         ||
              ( ((implicitFunc4(fim)>0) && (implicitFunc4(aux2)<0))  ||   
               ((implicitFunc4(fim)<0) && (implicitFunc4(aux2)>0))    )
              )return CROSS;
        else
           if(implicitFunc4(inicio)<0)
                 return INTERN;
            else  
              if(implicitFunc4(inicio)>0)
                  return EXTERN;              
                  }
                  
   return INTERN;                     
}
//Calcula a distancia entre os pontos (inicio) e (fim).
float dist(tPonto inicio,tPonto fim){
	  float x=sqrt((fim.x-inicio.x)*(fim.x-inicio.x)+(fim.y-inicio.y)*(fim.y-inicio.y));
      return x;
      }
     
/*Cria e divide as sub-árvores*/                      
void sub(No** pai,tPonto inicio, tPonto fim){
     if(dist(inicio,fim)<=dist(domainMax,domainMin)/5000 )    
         return;
                                     
i++;//i sera usado para definir a altura da arvore(ou sub-arvore).
tPonto aux1,aux2;
     /*1o quadrante*/
     aux2.x=(inicio.x+fim.x) /2;
     aux2.y=(inicio.y+fim.y) /2;
     (*pai)->fst=alocaNovoNo(inicio,aux2);
       if((*pai)->fst->setor.c==CROSS)  
          sub(&(*pai)->fst,inicio,aux2);
         
     /*2o quadrante*/    
     aux1.x=(inicio.x+fim.x)/2;
     aux1.y=inicio.y;
     aux2.x=fim.x;  
     aux2.y=(inicio.y+fim.y)/2;
     (*pai)->snd=alocaNovoNo(aux1,aux2);
       if((*pai)->snd->setor.c==CROSS)
          sub(&(*pai)->snd,aux1,aux2);
           
     /*3o quadrante*/
     aux1.x=inicio.x;
     aux1.y=(inicio.y+fim.y)/2;
     aux2.x=(inicio.x+fim.x)/2;
     aux2.y=fim.y;
     (*pai)->trd=alocaNovoNo(aux1,aux2);
       if((*pai)->trd->setor.c==CROSS)
          sub(&(*pai)->trd,aux1,aux2);     
     
     
     /*4o quadrante*/
     aux1.x=(inicio.x+fim.x)/2;
     aux1.y=(inicio.y+fim.y)/2;
     (*pai)->fth=alocaNovoNo(aux1,fim);
       if((*pai)->fth->setor.c==CROSS)
          sub(&(*pai)->fth,aux1,fim); i--; 
     return;        
} 
//Função que determina o desenho das funções implicitas na janela.
void desenharArvore(No* raiz){if(raiz==sentinela)return;
	tPonto inicio=raiz->setor.Min;
	tPonto fim=raiz->setor.Max;
    if(dist(inicio,fim)<=dist(domainMax,domainMin)/5000 ){
          if(desenhaPontos)
            desenhaPonto(inicio,BLACK);
          return;
                                     }
   if(desenhaQuadrantes){ 
      if(raiz->nivel<=nivel)               
           desenhaQuadrante(inicio,fim,(raiz->nivel)%8);
					    }     
    desenharArvore(raiz->fst);     
    desenharArvore(raiz->snd);
    desenharArvore(raiz->trd);
    desenharArvore(raiz->fth); 

    
}
