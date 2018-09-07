#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

/***********************
 * Função que gera os termos independentes de um sistema linear k-diagonal
 * k: numero de diagonais da matriz A
 ***********************/
inline double generateRandomB( unsigned int k )
{
  static double invRandMax = 1.0 / (double)RAND_MAX;
  return ((double)(k<<2)) * ((double)rand() * invRandMax);
}



/***********************
 * Função que gera os coeficientes de um sistema linear k-diagonal
 * i,j: coordenadas do elemento a ser calculado (0<=i,j<n)
 * k: numero de diagonais da matriz A
 ***********************/
 inline double generateRandomA( unsigned int i, unsigned int j, unsigned int k )
 {
   static double invRandMax = 1.0 / (double)RAND_MAX;
   return ((i==j)?((double)(k<<1)):(1.0))  * ((double)rand() * invRandMax);
 }


 inline double generateRandomAdbg( unsigned int i, unsigned int j, unsigned int k )
 {printf("\nChamando generateRandomA com i=%d j=%d ", i, j);
   static double invRandMax = 1.0 / (double)RAND_MAX;
   double aux = ((i==j)?((double)(k<<1)):(1.0))  * ((double)rand() * invRandMax);
   printf("e com retorno = %.2lf", aux);
   return aux;
 }
