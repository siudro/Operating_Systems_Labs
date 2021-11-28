[English](https://github.com/siudro/Operating_Systems_Labs/blob/main/README.md) | العربية
### جميع الأكواد المستخدمة في معامل مادة نظم التشغيل باستخدام موجه الأوامر ولغة سي بلس بلس متوفرة في هذا المستودع

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
