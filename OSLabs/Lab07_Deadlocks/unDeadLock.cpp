#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdint>
#include "pthread.h" // استدعاء المكتبات اللازمة
using namespace std;

pthread_mutex_t Chopstick_mutex [5] = {PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER};
// إنشاء 5 ميوتكس لكل عود أكل
void *function(void *);
// إنشاءدالة

int main(){

	pthread_t Lawyer[5];
	// إنشاء خمسة ثريدات تعبر عن خمسة محامين يأكلون بالأعواد
	int i;
	cout<<dec;

	for(i=0;i<5;i++){
		pthread_create(&Lawyer[i], NULL, function, (void *)(intptr_t)i);}
	// إنشاء الثريدات والتي تمرر بداخلهم الدالة ،رقم كل محامي أو ثريد يمثل برقم الاندكس

	for(i=0;i<5;i++){
		pthread_join(Lawyer[i], NULL);}
	// الانتظار حتى تنتهي جميع الثريدات
	for(i=0;i<5;i++){
		pthread_mutex_destroy(&Chopstick_mutex[i]);}
	// تدمير جميع الميوتكس قبل أغلاق المين ضروري جدا
	exit(0);

}
 void *function(void *vptr){

	pthread_mutex_lock(&Chopstick_mutex[(intptr_t)vptr]);
	pthread_mutex_lock(&Chopstick_mutex[((intptr_t)vptr+1)%5]);
	cout<<"Lawyer number "<<(intptr_t)vptr <<" got chopstick number ";
	cout<<(intptr_t)vptr << endl;
	 // إغلاق الميوتكس لعود الأكل الأيمن والأيسر من البداية لضمان عدم تداخل المحامين أثناء عملية الأكل**
	// المحامي برقم الاندكس(مثلا 1) يأخذ عود الأكل الأيسر
	// يجب إزالة الانتظار لجعل عملية الأكل أسرع

	cout<<"Lawyer number "<<(intptr_t)vptr <<" got chopstick number ";
	cout<<((intptr_t)vptr+1)%5 << endl;
	// المحامي برقم الاندكس(مثلا 1) يأخذ عود الأكل الأيمن
	sleep(1);


	cout<< "Lawyer number "<<(intptr_t)vptr<< " is eating with chopsticks ";
	cout<< (intptr_t)vptr<< " & "<< (((intptr_t)vptr+1)%5) << endl;
	// عملية الأكل
	sleep(1);

	pthread_mutex_unlock(&Chopstick_mutex[(intptr_t)vptr]);
	pthread_mutex_unlock(&Chopstick_mutex[((intptr_t)vptr+1)%5]);
	// فتح الميوتكس حتى يأخذ المحامي التالي عودي الأكل 

	return(NULL);
}








