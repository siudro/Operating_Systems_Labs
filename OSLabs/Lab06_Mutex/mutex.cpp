#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "pthread.h"//استدعاء المكتبات اللازمة
using namespace std;
// initialize mutex counter
pthread_mutex_t Counter_mutex = PTHREAD_MUTEX_INITIALIZER;// تعريف ميوتكس كاونتر
//declare global counter, funtion
int counter = 0;// تعريف عداد قابل للوصول من كل الكود
void*function(void*);// تعريف دالة
int main(){
	// declare threads and their id
	pthread_t tidA, tidB, tidC;// تعريف الايدي لثلاثة ثريدات
	pthread_create(&tidA , NULL, function, NULL);// انشاء ثريد يدخل في الدالة أولا
	pthread_create(&tidB , NULL, function, NULL);// انشاء ثريد ثاني يدخل في الدالة بعد الاولى
	pthread_create(&tidC , NULL, function, NULL);// انشاء ثريد ثالث يدخل في الدالة بعد الثانية
	
	pthread_join(tidA, NULL);// الانتظار حتى انتهاء تنفيذ اول ثريد
	pthread_join(tidB, NULL);// الانتظار حتى انتهاء ثاني ثريد
	pthread_join(tidC, NULL);// اللانتظار حتى انتهاء آخر ثريد
	pthread_mutex_destroy(&Counter_mutex);// تدمير الميوتكس ضروري جدا
	exit(0);
}
void* function(void*vprt){
	
	int val; // يمثل العداد

	for(int i=0; i<10;i++){// لكل ثريد يدخل في هذه الدالة، يقوم بالإضافة على قيمة العداد ويطبعها بتكرار عشرة مرات
	pthread_mutex_lock(&Counter_mutex);// منطقة محمية بحيث لا تدخل اكثر من ثريد وتقوم بالتنفيذ في هذه الدالة بنفس الوقت
		val = counter;

		cout<<pthread_self()<<" "<<dec<<val+1<<endl;

		sleep(1);
	
		counter=val+1;
		pthread_mutex_unlock(&Counter_mutex);// فتح القفل عن المنطقة المحمية من الكود والسماح للثريد التالي باستخدامه

}
	return(NULL);
}
