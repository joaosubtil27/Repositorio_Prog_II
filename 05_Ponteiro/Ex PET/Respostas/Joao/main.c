#include "prisao.h"
#include <stdio.h>

int main(){

  tPrisao prisao;
  int nCelas, capacidadeCelas;
  char nome[MAXTAM_NOME];
  scanf("%[^\n]\n", nome);
  scanf("%d %d\n", &nCelas, &capacidadeCelas);
  prisao = criaPrisao(nome, nCelas, capacidadeCelas);
  executaPrisao(&prisao);
  return 0;
}