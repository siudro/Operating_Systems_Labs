#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;

int main(){
	pid_t pid1, pid2, cpid;
	int i, j, a, status;
	a= 0;
	cout<<"\n parent process pid is "<<getpid()<<"\n";
	pid1 = fork();
	if (pid1<0){
		cout<<"first fork has failed\n";
		exit(-1);
}
	else if (pid1==0){
		cout<<"\n child pid is "<<getpid()<<"\n";
			for (i=0;i<10;i++){
				a=a^i;
				cout<<"child1: a = "<<a<<"\n";
				sleep(4);
}

}
	else{
		pid2 = fork();
		if (pid2 < 0){
			cout<<"second fork nooo\n";
			exit(-1);

}
	else if (pid2==0){
		cout<<"\n child2 pid is "<<getpid<<"\n";
			for (j=0; j<10;j++){
				a=a^i;
				cout<<"child2: a = "<<a<<"\n";
				sleep(4);
}
}
	else{
		cpid = wait(&status);
		cout<<"\n---close parent---\n";
		exit(0);
}
}
	return(0);
}
