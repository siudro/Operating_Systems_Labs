[English](https://github.com/siudro/Operating_Systems_Labs/blob/main/README.md) | العربية

![7223bece47ef99ec3ed361f4a4b36433](https://user-images.githubusercontent.com/83130573/143789788-f241f105-1c26-4c4d-94f4-8f8f9647b26c.jpg)
[مصدر](https://www.wallpaperflare.com/) الصورة

### جميع الأكواد المستخدمة في معامل مادة نظم التشغيل باستخدام موجه الأوامر ولغة سي بلس بلس متوفرة في هذا المستودع

## المحتويات

* ### 📂[Assignment/](.\OSLabs\Assignment)
  * [CS_323_Course Card_Fall_2021.pdf](https://github.com/siudro/Operating_Systems_Labs/blob/main/OSLabs/Assignment/CS_323_Course%20Card_Fall_2021%20(1).pdf)
  * [README.md](.\OSLabs\Assignment\README.md)
* ### 📂[Lab01_intro/](.\OSLabs\Lab01_intro)
  * [Lab01_IntroductionToLinux.pdf](.\OSLabs\Lab01_intro\Lab01_IntroductionToLinux.pdf)
  * [README.md](.\OSLabs\Lab01_intro\README.md)
* ### 📂[Lab02_Compiling_practice/](.\OSLabs\Lab02_Compiling_practice)
  * [Lab02_Compiling_C_C++_Programs.pdf](.\OSLabs\Lab02_Compiling_practice\Lab02_Compiling_C_C++_Programs.pdf)
  * [README.md](.\OSLabs\Lab02_Compiling_practice\README.md)
* ### 📂[Lab03_Process_fork/](.\OSLabs\Lab03_Process_fork)
  * [Lab03_Processes.pdf](.\OSLabs\Lab03_Process_fork\Lab03_Processes.pdf)
  * [ProcessID.cpp](.\OSLabs\Lab03_Process_fork\ProcessID.cpp)
* ### 📂[Lab04_Threads/](.\OSLabs\Lab04_Threads)
  * [Lab04_Threads.pdf](.\OSLabs\Lab04_Threads\Lab04_Threads.pdf)
  * [threadIDfunction.cpp](.\OSLabs\Lab04_Threads\threadIDfunction.cpp)
* ### 📂[Lab05_Threads_vs_Fork/](.\OSLabs\Lab05_Threads_vs_Fork)
  * [Lab05_Thread_VS_Fork.pdf](.\OSLabs\Lab05_Threads_vs_Fork\Lab05_Thread_VS_Fork.pdf)
  * [threadNfork.cpp](.\OSLabs\Lab05_Threads_vs_Fork\threadNfork.cpp)
* ### 📂[Lab06_Mutex/](.\OSLabs\Lab06_Mutex)
  * [Lab06_Mutux.pdf](.\OSLabs\Lab06_Mutex\Lab06_Mutux.pdf)
  * [mutex.cpp](.\OSLabs\Lab06_Mutex\mutex.cpp)
* ### 📂[Lab07_Deadlocks/](.\OSLabs\Lab07_Deadlocks)
  * [deadLock.cpp](.\OSLabs\Lab07_Deadlocks\deadLock.cpp)
  * [Lab07_DeadLock.pdf](.\OSLabs\Lab07_Deadlocks\Lab07_DeadLock.pdf)
  * [unDeadLock.cpp](.\OSLabs\Lab07_Deadlocks\unDeadLock.cpp)
* ### 📂[Lab08_Scheduler/](.\OSLabs\Lab08_Scheduler)
  * [Lab08_CPUScheduling_FCFS.pdf](.\OSLabs\Lab08_Scheduler\Lab08_CPUScheduling_FCFS.pdf)
  * [scheduler.cpp](.\OSLabs\Lab08_Scheduler\scheduler.cpp)
* ### 📂[Lab09_SchedulerSJF/](.\OSLabs\Lab09_SchedulerSJF)
  * [Lab09_CPUScheduling_SJF.pdf](.\OSLabs\Lab09_SchedulerSJF\Lab09_CPUScheduling_SJF.pdf)
  * [schedulSJF.cpp](.\OSLabs\Lab09_SchedulerSJF\schedulSJF.cpp)
* ### 📂[Simple_projects/](.\OSLabs\Simple_projects)
  * [calc.cpp](.\OSLabs\Simple_projects\calc.cpp)
  * [forLoop.cpp](.\OSLabs\Simple_projects\forLoop.cpp)
  * [helloWorld.cpp](.\OSLabs\Simple_projects\helloWorld.cpp)


## المتطلبات السابقة:
- لينكس [أوبونتو](download) (نظام تشغيل)
- جي إديت (محرر نصوص)
- جي بلس بلس (جامع أو مترجم أكواد)


## تنصيب مترجم الأكواد جي بلس بلس:
افتح موجه الأوامر، واكتب الأوامر التالية:
```
$ sudo apt-get update
$ sudo apt-get –f install
$ sudo apt-get install g++
```
*ستجدون شرح تفصيلي لطريقة تنصيب المترجم في [هذا](https://github.com/siudro/Operating_Systems_Labs/blob/main/OSLabs/Lab02_Compiling_practice/Lab02_Compiling_C_C%2B%2B_Programs.pdf) الملف*


## كيف استفيد هذا (الريبو) المستودع؟
![image](https://user-images.githubusercontent.com/83130573/142734722-89014c83-bf77-41df-a5c7-49e0d9fd2f5f.png)

بالإمكان فتح صفحة المستودع في أي متصفح في الأوبنتو ونسخ الأكواد، أو تنزيل نسخة لكل المستودع او استنساخه،
إذا رغبت باستخدام الطريقة الأخيرة، يجب أولًا إنشاء مجلد يُحفظ فيه الملفات المستنسخة، في موجه الأوامر:
```
$ mkdir OSLabsContainer
```


التوجه إلى داخل المجلد أو المسار الذي تم إنشاؤه:
```
$ cd OSLabsContainer
```


استنساخ المستودع، يجب لتنفيذ هذه الخطوة تحميل [git](https://git-scm.com/downloads) مسبقًا
```
$ git clone https://github.com/siudro/Operating_Systems_Labs.git
```


لفتح محتويات المجلد:
```
$ cd Operating_Systems_Labs
$ cd OSLabs
```


لفتح أي ملف سي بلس بلس، استخدم هذا الأمر مع استبدال <> باسم الملف
```
$ gedit <fileName>.cpp
```


عند إجراء أي تغيير في ملف الكود، يجب حفظه ثم تجميعه قبل تجربة المخرجات باستخدام الأمر
```
$ g++ <fileName>.cpp -o <fileName> -lpthread
```


لاختبار أو تشغيل الملف: 
```
$ ./<fileName>
```
