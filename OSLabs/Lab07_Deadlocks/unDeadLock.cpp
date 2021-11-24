#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdint>
#include "pthread.h"
using namespace std;

pthread_mutex_t Chopstick_mutex [5] = {PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER};
// initialize 5 mutex for 5 chopsticks
void *function(void *);
//declare function

int main(){

	pthread_t Lawyer[5];
	//declare 5 lawyers that eats with chopstick
	int i;
	cout<<dec;

	for(i=0;i<5;i++){
		pthread_create(&Lawyer[i], NULL, function, (void *)(intptr_t)i);}
	// create 5 threads(lawyers), pass its index number to the function later, must cast its int first

	for(i=0;i<5;i++){
		pthread_join(Lawyer[i], NULL);}
	// wait all threads to end

	for(i=0;i<5;i++){
		pthread_mutex_destroy(&Chopstick_mutex[i]);}
	// destroy all mutex before ending the main
	exit(0);

}
 void *function(void *vptr){

	pthread_mutex_lock(&Chopstick_mutex[(intptr_t)vptr]);
	pthread_mutex_lock(&Chopstick_mutex[((intptr_t)vptr+1)%5]);
	cout<<"Lawyer number "<<(intptr_t)vptr <<" got chopstick number ";
	cout<<(intptr_t)vptr << endl;
	//lawyer number i gets left chopstick i 
	//sleep(1);
	// remove sleep so that it would be quicker before another lawyer starts eating
	// lock both chopsticks from the start

	cout<<"Lawyer number "<<(intptr_t)vptr <<" got chopstick number ";
	cout<<((intptr_t)vptr+1)%5 << endl;
	//lawyer number i gets right chopstick i making sure that i is less than 5
	sleep(1);


	cout<< "Lawyer number "<<(intptr_t)vptr<< " is eating with chopsticks ";
	cout<< (intptr_t)vptr<< " & "<< (((intptr_t)vptr+1)%5) << endl;
	// eating process that takes 2s
	sleep(1);

	pthread_mutex_unlock(&Chopstick_mutex[(intptr_t)vptr]);
	pthread_mutex_unlock(&Chopstick_mutex[((intptr_t)vptr+1)%5]);


	return(NULL);
	// unlock the mutexes , the left and right chopsticks
}








