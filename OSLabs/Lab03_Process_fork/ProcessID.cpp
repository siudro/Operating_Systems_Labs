#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> // جلب المكتبات اللازمة
using namespace std; // خطوة لاختصار عمليات الادخال والاخراج

int main(){ // البدء في الماين
	pid_t pid1, pid2, cpid; // انشاء بارينت بروسس اي دي و تشايلد ببروسس اي دي
	int i, j, a, status;
	a= 0;
	cout<<"\n parent process pid is "<<getpid()<<"\n"; // طباعة الآيدي للبارينت بروسس
	pid1 = fork(); // إنشاء تشايلد بروسس
	if (pid1<0){ // اذا كان البي أي دي أقل من صفر، معناه هناك خطأ ولم يتم عمل الفورك بشكل ناجح
		cout<<"first fork has failed\n";
		exit(-1);
}
	else if (pid1==0){// اذا البي أي دي بصفر، نتعامل مع تشايلد رقم 1 
		cout<<"\n child pid is "<<getpid()<<"\n";
			for (i=0;i<10;i++){ // ضرب قيمة أي في الإي عشر مرات وطباعتها
				a=a^i;
				cout<<"child1: a = "<<a<<"\n";
				sleep(4);
}

}
	else{
		pid2 = fork(); // عمل فورك لإنشاء تشايلد رقم اثنين
		if (pid2 < 0){// اذا كان البي أي دي أقل من صفر، معناه هناك خطأ ولم يتم عمل الفورك بشكل ناجح
			cout<<"second fork nooo\n";
			exit(-1);

}
	else if (pid2==0){//  اذا البي أي دي بصفر، نتعامل مع تشايلد رقم 2
		cout<<"\n child2 pid is "<<getpid<<"\n";
			for (j=0; j<10;j++){// ضرب قيمة جاي في الإي عشر مرات وطباعتها
				a=a^i;
				cout<<"child2: a = "<<a<<"\n";
				sleep(4);
}
}
	else{
		cpid = wait(&status); // الانتظار حتى انتهاء التشايلد من التنفيذ
		cout<<"\n---close parent---\n";
		exit(0);
}
}
	return(0);
}
