#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "pthread.h"
using namespace std;
// initialize mutex counter
pthread_mutex_t Counter_mutex = PTHREAD_MUTEX_INITIALIZER;
//declare global counter, funtion
int counter = 0;
void*function(void*);
int main(){
	// declare threads and their id
	pthread_t tidA, tidB, tidC;
	pthread_create(&tidA , NULL, function, NULL);
	pthread_create(&tidB , NULL, function, NULL);
	pthread_create(&tidC , NULL, function, NULL);
	
	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);
	pthread_join(tidC, NULL);
// destroy mutex
	pthread_mutex_destroy(&Counter_mutex);
	exit(0);
}
void* function(void*vprt){
	
	int val;

	for(int i=0; i<10;i++){
	pthread_mutex_lock(&Counter_mutex);
		val = counter;

		cout<<pthread_self()<<" "<<dec<<val+1<<endl;

		sleep(1);
	
		counter=val+1;
		pthread_mutex_unlock(&Counter_mutex);

}
	return(NULL);
}
