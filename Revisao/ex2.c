/*programa para montar o triangulo de Floyd
PROPOSTA REVISÃO 2
Joao Arthur
23/10/2024 */

#include <stdio.h>
#include <stdlib.h>


int main () {

 int linhas;
 int i;
 int num=1;
 int qnt_termos=1;
 
 scanf("%d", &linhas);

while (linhas>0){
 for (i=1; i<=qnt_termos; i++){
  printf ("%d ", num);
  num++;
 }
 printf ("\n");
qnt_termos++;
linhas--;
}
}