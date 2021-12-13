#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdint>
#include "pthread.h"// استدعاء المكتبات اللازمة
using namespace std;

pthread_mutex_t Chopstick_mutex [5] = {PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER};
// إنشاء خمسة ميوتكس لكل عود أكل (5)

void *function(void *);// تعريف دالة 

int main(){

	pthread_t Lawyer[5];// تعريف خمسة ثريدات تمثل خمسة محامين كل منهم يأكلون بأعواد الأكل

	int i;
	cout<<dec;

	for(i=0;i<5;i++){// إنشاء خمسة محامين كل محامي لديه رقم يدخل فيه في دالة الأكل ويجب ان يتم تحويلها لانتجر
		pthread_create(&Lawyer[i], NULL, function, (void *)(intptr_t)i);}

	for(i=0;i<5;i++){// الانتظار حتى انتهاء كل محامي من الاكل
		pthread_join(Lawyer[i], NULL);}

	for(i=0;i<5;i++){
		pthread_mutex_destroy(&Chopstick_mutex[i]);}// تدمير الخمسة ميتوكس بعد الانتهاء من التنفيذ ضروري جدا

	exit(0);

}
 void *function(void *vptr){// دالة الأكل
	pthread_mutex_lock(&Chopstick_mutex[(intptr_t)vptr]);// حماية عود الاكل حتى لا ياكل محامي قبل رقمه او ياخذ العود الآخر من المحامي السابق له قبل الأوان
	cout<<"Lawyer number "<<(intptr_t)vptr <<" got chopstick number ";
	cout<<(intptr_t)vptr << endl;
//المحامي صاحب الاسبقية لديه العود الايسر ليأكل
	sleep(1);

	pthread_mutex_lock(&Chopstick_mutex[((intptr_t)vptr+1)%5]);
	cout<<"Lawyer number "<<(intptr_t)vptr <<" got chopstick number ";
	cout<<((intptr_t)vptr+1)%5 << endl;
// المحامي صاحب الاسبقية لديه العود الايمن ليأكل

	cout<< "Lawyer number "<<(intptr_t)vptr<< " is eating with chopsticks ";
	cout<< (intptr_t)vptr<< " & "<< (((intptr_t)vptr+1)%5) << endl;
// عملية الأكل تتم الآن
	 sleep(2);
	
	pthread_mutex_unlock(&Chopstick_mutex[(intptr_t)vptr]); // فك القفل عن العود الايسر والسماح للمحامي التالي باستخدامه
	pthread_mutex_unlock(&Chopstick_mutex[((intptr_t)vptr+1)%5]);// فك القفل عن العود الايمن والسماح للمستخدم التالي بالاكل
	return(NULL);

}








