#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "pthread.h" // استدعاء المكتبات اللازمة
using namespace std;
int counter = 0;
void*doit(void*); // تعريف الدالة
int main()
{
	pthread_t tid; // تعريف ثريد
	pid_t pid, cpid; // تعريف بارينت
	int status;
	pthread_create(&tid, NULL, doit,NULL); // إنشاء ثريد يقوم بالدخول على دالة تضيف في العداد وتطبع النتيجة

	pid = fork(); //  إنشاء تشايلد بروسس
	if(pid<0){// لم ينجح عمل الفورك في حال قيمة الاي دي أقل من صفر
		cout<<"Fork faild etc \n";
		exit(-1);
}
	else if(pid==0){ //في حال الاي دي للبروسس يساوي صفر إذن هو تشايلد بروسس
		for(int i=0; i<10; i++){ // لوب تقوم بالإضافة للعداد 10 مرات وطباعة النتيجة
			counter++;
			cout<<"Child Counter= "<<counter<<endl;	
			sleep(1);		
}
}
		else {
			cpid = wait(&status);// البارينت يقوم بانتظار انتهاء تنفيذ التشايلد
			pthread_join(tid, NULL);// انتظار إنتهاء تنفيذ الثريد
			exit(0);
}	

}
void*doit(void*vptr) // دالة لطباعة العداد واللإضافة عليه
{
	sleep(0);
	cout<<"Thread First Counter= "<<counter++ <<endl;
	sleep(5);
	cout<<"Thread Second Counter= "<<counter++ <<endl;
	return(NULL);
}
