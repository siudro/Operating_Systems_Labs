#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "pthread.h"
using namespace std;
int counter = 0;
void*doit(void*);
int main()
{
	pthread_t tid;
	pid_t pid, cpid;
	int status;
	pthread_create(&tid, NULL, doit,NULL);

	//sleep(1);
	pid = fork();
	if(pid<0){
		cout<<"Fork faild etc \n";
		exit(-1);
}
	else if(pid==0){
		for(int i=0; i<10; i++){
			counter++;
			cout<<"Child Counter= "<<counter<<endl;	
			sleep(1);		
}
}
		else {
			cpid = wait(&status);
			pthread_join(tid, NULL);
			exit(0);
}	

}
void*doit(void*vptr)
{
	sleep(0);
	cout<<"Thread First Counter= "<<counter++ <<endl;
	sleep(5);
	cout<<"Thread Second Counter= "<<counter++ <<endl;
	return(NULL);
}
