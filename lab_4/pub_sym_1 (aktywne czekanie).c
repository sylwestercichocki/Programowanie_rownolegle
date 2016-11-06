#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include<pthread.h>


void * watek_klient (void * arg);

int l_kf;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
main(){

  pthread_t *tab_klient;
  int *tab_klient_id;
  

  int l_kl, l_kr, i;

  printf("\nLiczba klientow: "); scanf("%d", &l_kl);

  printf("\nLiczba kufli: "); scanf("%d", &l_kf);

  //printf("\nLiczba kranow: "); scanf("%d", &l_kr);
  l_kr = 1;

  tab_klient = (pthread_t *) malloc(l_kl*sizeof(pthread_t));
  tab_klient_id = (int *) malloc(l_kl*sizeof(int));
  for(i=0;i<l_kl;i++) tab_klient_id[i]=i;


  printf("\nOtwieramy pub (simple)!\n");
  printf("\nLiczba wolnych kufli %d\n", l_kf); 

  for(i=0;i<l_kl;i++){
    pthread_create(&tab_klient[i], NULL, watek_klient, &tab_klient_id[i]); 
  }
  for(i=0;i<l_kl;i++){
    pthread_join( tab_klient[i], NULL);
  }
  printf("\nZamykamy pub!\n");
  printf("\nLiczba  kufli %d\n", l_kf); 	

}


void * watek_klient (void * arg_wsk){

  int moj_id = * ((int *)arg_wsk);

  int i, j, kufel, result;
  int ile_musze_wypic = 2;
  int pobrano_kufel=0;
  int czekam = 0;

  printf("\nKlient %d, wchodzę do pubu\n", moj_id); 
    
  for(i=0; i<ile_musze_wypic; i++){

  //printf("\nKlient %d, wybieram kufel\n", moj_id);
	czekam = 0;
    do{
	pthread_mutex_lock(&mutex);
	  if (l_kf > 0){
	    printf("\nKlient %d, liczba dostepnych kufli %d pobieram kufel \n", moj_id, l_kf);
		l_kf--;
		pobrano_kufel=1;
	  }else{
		if(czekam == 0){
		printf("\nKlient %d, brak dostepnych kufli czekam na wolny \n", moj_id);
		czekam++;
		}}
	  pthread_mutex_unlock(&mutex);
	
    }while(pobrano_kufel==0);

    j=0;
    printf("\nKlient %d, nalewam z kranu %d\n", moj_id, j); 
    usleep(300);
    
    printf("\nKlient %d, pije\n", moj_id); 
    nanosleep((struct timespec[]){{0, 500000000L}}, NULL);
    
    
    pthread_mutex_lock(&mutex);
	printf("\nKlient %d, odkladam kufel\n", moj_id); 
	l_kf++;
	pobrano_kufel=0;
    pthread_mutex_unlock(&mutex);
    
  }

  printf("\nKlient %d, wychodzę z pubu\n", moj_id); 
    
  return(NULL);
} 


