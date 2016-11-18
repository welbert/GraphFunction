#ifndef __EstruturasDeDados__
#define __EstruturasDeDados__ 1
#define	ABS(a)	(((a) < 0) ? -(a) : (a))



typedef enum 	{	BLACK,
					RED,
					GREEN,
					BLUE,
					MAGENTA,
					CIAN,
					YELLOW,
					GRAY
				} eCor;

typedef enum 	{	INTERN,
					EXTERN,
					CROSS
				} eSectorClass;

typedef struct {	float x;
					float y;
			   } tPonto;
			   
typedef struct	{	tPonto			Min;
					tPonto 			Max;
					eSectorClass	c;
				} tSector;
/*****************************************************/

typedef struct tNode{ struct tNode* fst;
                      struct tNode* snd;      
                      struct tNode* trd;
                      struct tNode* fth;
                      tSector setor;
                      int nivel;
                      } No;
                      
/****************************************************/																		
#endif		// __EstruturasDeDados__
