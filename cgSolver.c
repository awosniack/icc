#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "utils.h"

int main(int argc, char *argv[]){
//
//   printf("argc = %d", argc);
//   for(int i=0;argv[i]!=NULL;i++)
//     printf("\nargv[%d] = %s", i, argv[i]);
//
// printf("\n");

int dim_sis, num_diag, iteracoes;
double pre_cond, erro_abs_max;
char *arq_saida;
srand(20182);
for(int i=0;argv[i]!=NULL;i++){

    if(strcmp(argv[i], "-n") == 0)
      dim_sis = atoi(argv[++i]);

    if(strcmp(argv[i], "-k") == 0){
      num_diag = atoi(argv[++i]);
      if(num_diag%2!=1||num_diag<1||num_diag>2*dim_sis)
        do{
            printf("\nO numero de diagonais deve ser impar e 1<=k<2n!Digite k novamente:");
            scanf("%d", &num_diag);
        }while(num_diag%2!=1||num_diag<1||num_diag>2*dim_sis);
    }

    if(strcmp(argv[i], "-p") == 0)
      pre_cond = atof(argv[++i]);

    if (strcmp(argv[i], "-i") == 0)
      iteracoes = atoi(argv[++i]);

    if(strcmp(argv[i], "-e") == 0)
      erro_abs_max = atof(argv[++i]);

    if(strcmp(argv[i], "-o") == 0)
      arq_saida = argv[++i];
  }

// printf("dim_sis      = %d\n", dim_sis);
// printf("num_diag     = %d\n", num_diag);
// printf("pre_cond     = %lf\n", pre_cond);
// printf("iteracoes    = %d\n", iteracoes);
// printf("erro_abs_max = %lf\n", erro_abs_max);
// printf("arq_saida    = %s\n", arq_saida);
double *a = (double*) malloc (dim_sis*dim_sis*sizeof(double)); //alocando uma matriz NxN
double *b = (double*) malloc (dim_sis*sizeof(double)); //alocando o vetor de termos independentes tamanho N
int tam_max = num_diag;

for(int i=0;i<(dim_sis*dim_sis);i++) //preenchendo a matriz com 0.0's
  a[i]=0.0;

int pisok=(num_diag-1)/2;  //auxiliar para percorrer as k diagonais e gerar os valores
for(int i=0;i<dim_sis;i++){
  for(int l=pisok;l>=1;l--)
    if(i-l>=0) a[i*dim_sis+(i-l)]=generateRandomA(i,i-l,num_diag); //diagonais abaixo da principal

  a[i*dim_sis+i]=generateRandomA(i,i,num_diag);         //diagonal principal

  for(int u=1;u<=pisok;u++)
    if(i+u<dim_sis) a[i*dim_sis+(i+u)]=generateRandomA(i,i+u,num_diag); //diagonais acima da principal

  b[i] = generateRandomB(num_diag);
}




printf("\n");
int cont =0;
for(int i=0;i<dim_sis*dim_sis;i++){ //imprime a matriz
  if(i%dim_sis==0)    printf("\n"); //a cada nova linha pula uma linha
printf("%.2lf ",a[i]);

if((i+1)%dim_sis==0) printf(" = %lf",b[cont++]);

}
printf("\n");
free(a); free(b);
return 0;
}
