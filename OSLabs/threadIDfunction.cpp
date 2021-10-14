#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "pthread.h"
using namespace std;
#define NLOOP 10
int counter = 0;
void * function1(void*);
void * function2(void*);
int main(){
	
	pthread_t tidA, tidB;
	int status;
	pthread_create(&tidA, NULL, function1, NULL);
	pthread_create(&tidB, NULL, function2, NULL);
	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);
	exit(0);

}
void* function1(void *vprt){

	int i;
	int val = counter
	for(i=0;i<NLOOP;i++){
	cout<<" THREAD = "<<pthread_self()<<"\n";
	cout<<" COUNTER = "<<dec<<counter<<endl;
	sleep(1);
	val=val+1;
} 
	return (NULL);
}
void* function2(void *vprt){

	int i;
	int val = counter
	for(i=0;i<NLOOP;i++){
	cout<<" THREAD = "<<pthread_self()<<"\n";
	cout<<" COUNTER = "<<dec<<counter<<endl;
	sleep(1);
	val=val*2
} 
	return (NULL);
}

