#include <iostream>
using namespace std;
int main()
{
	float n,tempb,tempa,tempp,tw,average,gap,arrive[3],burst[3], process[3],start[3],finish[3],waiting[3],response[3], turnaround[3];
	int i,j;
//المستخدم يقوم بإدخال وقت الوصول والبرست (كم يأخذ وقت من المعالج لتنفيذ العملية) لكل عملية عددها i 
	for(i=0;i<3;i++){ 
		n=i+1;
		process[i]=n;
		cout<<"what is p"<<n<<" arrival time\t";
		cin>>arrive[i];
		cout<<" what is p"<<n<<" burst time\t";
		cin>>burst[i];
	}//end for


//ترتيب تنفيذ العمليات حسب وقت الوصول
	for(i=0;i<2;i++)
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

//خوارزمية حساب وقت بداية التنفيذ ووقت الانتهاء من التنفيذ
	start[0]=arrive[0];
	finish[0]=arrive[0]+burst[0];
	for(i=1;i<3;i++){
		gap=0;
		if(arrive[i]>finish[i-1]){
			gap=arrive[i]-finish[i-1];
			start[i]=finish[i-1]+gap;
		}//end if
		else
			start[i]=finish[i-1];
			finish[i]=start[i]+burst[i];
	}//end for

// حساب كل من وقت الاستجابة ووقت الانتظار ووقت التنفيذ لكل عملية من خلال نفس المعطيات (وقت الوصول وقت البداية والبرست المدخل من المستخدم)
	tw=0;
	for(i=0;i<3;i++){
		response[i]=start[i]-arrive[i];
		waiting[i]=start[i]-arrive[i];
		turnaround[i]=burst[i]+waiting[i];
		tw+=waiting[i];
	}//end for
	average=tw/3;
//طباعة النتائج
	for(i=0;i<3;i++){
		cout<<"process Number"<<process[i]<<'\n'<<"arrive at "<<arrive[i]<<'\n'<<"waiting Time = "<<waiting[i]<<'\n'<<"response Time= "<<response[i]<<'\n'<<"Turnaround Time = "<<turnaround[i]<<'\n';
	}
	cout<<"Total waiting time = "<<tw;
	cout<<"\n \n Average waiting time = "<<average;
	cout<<"\n\n\t\t\t--------*******FCFS ********---------\n";
	return(0);
}//end main
