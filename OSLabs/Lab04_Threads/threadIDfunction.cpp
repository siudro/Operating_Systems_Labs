#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "pthread.h"// استدعاء المكتبات اللازمة
using namespace std;
#define NLOOP 10
int counter = 0;//انشاء عداد ليتم اللإضافة عليه من أطراف مختلفة 
void * function1(void*);// تعريف دوال للإضافة على العداد
void * function2(void*);// تعريف دوال للأضافة على العداد
int main(){
	
	pthread_t tidA, tidB;// تعريف ثريدين
	int status;
	pthread_create(&tidA, NULL, function1, NULL);// الثريد الأول يقوم بالدخول على االدالة الأولى التي تقوم بالإضافة في العداد
	pthread_create(&tidB, NULL, function2, NULL);// الثريد الثاني يدخل في الدالة الثانية لتقوم باللإضافة على قيمة العداد
	pthread_join(tidA, NULL);// انتظار الثريد الأول حتى أن ينتهي من التنفيذ
	pthread_join(tidB, NULL);// انتظار الثريد الثاني حتى ينتهي من التنفيذ
	exit(0);

}
void* function1(void *vprt){

	int i;
	int val = counter
	for(i=0;i<NLOOP;i++){
	cout<<" THREAD = "<<pthread_self()<<"\n";
	cout<<" COUNTER = "<<dec<<counter<<endl;
	sleep(1);
	val=val+1;// الإضافة على العداد
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
	val=val*2// الإضافة على العداد
} 
	return (NULL);
}

