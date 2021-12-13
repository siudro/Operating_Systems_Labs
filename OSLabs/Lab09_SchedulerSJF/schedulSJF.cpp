#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "pthread.h"// تعريف المكتبات اللازمة
using namespace std;
float n, tempb, tempa, tempp, tw, average, gap,arrive[3], burst[3],
process[3],start[3],finish[3],waiting[3],response[3], turnaround[3]; // تعريف المتغيرات المستخدمة في الترتيب وتعريف المصفوفات  بحجم ابتدائي

void* start_finish(void *vprt) // تعريف وبدء دالة حساب بداية تنفيذ البروسس ونهايته
{
	start[0]=arrive[0];
	finish[0]=arrive[0]+burst[0];// من قانون حساب الانتهاء من التنفيذ
	for(int i=1;i<3;i++){ // لوب لحساب فجوة مابعد تنفيذ بروسس وبداية تنفيذ بروسس جديدة واستبعادها
		gap=0;
		if(arrive[i]>finish[i-1]){
			gap=arrive[i]-finish[i-1];
			start[i]=finish[i-1]+gap;
		}//end if
		else
			start[i]=finish[i-1];
			finish[i]=start[i]+burst[i];
	}//end for
return(NULL);
} //end start_finish function
int main(){
	pthread_t tidA, tidB; // تعريف ثريدين
	int status;

	int i,j;

	for(i=0;i<3;i++){ // استقبال قيم وقت وصول البروسس والبرست 
		n=i+1;
		process[i]=n;
		cout<<"what is p"<<n<<" arrival time\t";
		cin>>arrive[i];
		cout<<" what is p"<<n<<" burst time\t";
		cin>>burst[i];
	}//end for

	for(i=0;i<2;i++) // لوب متداخل لإعادة ترتيب البروسس حسب وقت الوصول 
		for( j=i+1;j<3;j++){
			if(arrive[j]<arrive[i]){
				tempa=arrive[i];
				arrive[i]=arrive[j];
				arrive[j]=tempa;
				tempb=burst[i];
				burst[i]=burst[j];
				burst[j]=tempb;
				tempp=process[i];
				process[i]=process[j];
				process[j]=tempp;
			}//end if
	}//end for
	
	pthread_create(&tidA, NULL,start_finish , NULL); // إنشاء ثريد تدخل في دالة حساب وقت بداية ونهاية كل بروسس حسب ترتيبهم في وقت الوصول
	pthread_join(tidA, NULL); // الانتظار حتى وقت نهاية تنفيذ الثريد

	for(i=0;i<2;i++)// إعادة فرز وترتيب البروسس حسب وقت الوصول وقيمة البرست
		for( j=i+1;j<3;j++){
			if(arrive[j]<=start[i] && burst[j]<burst[i]){
				tempa=arrive[i];
				arrive[i]=arrive[j];
				arrive[j]=tempa;
				tempb=burst[i];
				burst[i]=burst[j];
				burst[j]=tempb;
				tempp=process[i];
				process[i]=process[j];
				process[j]=tempp;
			}//end if
		}//end for

	pthread_create(&tidB, NULL, start_finish, NULL);// إنشاء ثريد يقوم بحساب وقت بداية ونهاية تنفيذ كل بروسس بعد إعادة ترتيبهم حسب وقت الوصول والبرست
	pthread_join(tidB, NULL);// الانتظار حتى نهاية تنفيذ الثريد
	tw=0;// تعريف إجمالي وقت الانتظار مبدئيا بصفر
	for(i=0;i<3;i++){ //حساب وقت الاستجابة ووقت الانتظار الزمن الكلي من بداية تنفيذه لنهايته لكل بروسس 
		response[i]=start[i]-arrive[i];
		waiting[i]=start[i]-arrive[i];
		turnaround[i]=burst[i]+waiting[i];
		tw+=waiting[i];
	}//end for
	average=tw/3; // حساب متوسط وقت الانتظار

	for(i=0;i<3;i++){ // طباعة الحسابات لكل بروسس
	cout<<"process Number"<<process[i]<<'\n'<<"arrive at "<<arrive[i]<<'\n'<<"waiting Time = "<<waiting[i]<<'\n'<<"response Time= "<<response[i]<<'\n'<<"Turnaround Time = "<<turnaround[i]<<'\n';
	}
	cout<<"Total waiting time = "<<tw;
	cout<<"\n \n Average waiting time = "<<average;
	cout<<"\n\n\t\t\t--------*******SJF ********---------\n";
return(0);
}//end main
