#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"../pomiar_czasu/pomiar_czasu.h"
 
const int liczba = 100000;

main(){

  double a, b, c, t1, t2;
  int i,j,k,l;

  k = -50000;

  inicjuj_czas();

  for(i=0;i<liczba;i++){

    printf("%d ",k+i);

  }
  printf("\n");

  printf("Czas wykonania %d operacji wejscia/wyjscia: \n",liczba);

  drukuj_czas();

  t1=czas_zegara();
  t2=czas_CPU();

  a = 1.000001;
  for(i=0;i<liczba;i++){

    a = 1.000001*a+0.000001; 

  }

  t1=czas_zegara()-t1;
  t2=czas_CPU()-t2;

  printf("\nWynik operacji arytmetycznych: %lf\n", a);
  printf("Czas wykonania %d operacji arytmetycznych: \n",liczba);

  printf("czas CPU = %lf\n", t1);
  printf("czas zegarowy = %lf\n", t2);


}
