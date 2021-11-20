# Operating_Systems_Labs
### This repository contains implemented codes in Operating Systems course using Terminal command lines and C++.

### جميع الأكواد االمستخدمة في معامل مادة نظم التشغيل باستخدام موجه الأوامر ولغة سي بلس بلس متوفرة في هذا المستودع
### Prerequisites:
## المتطلبات السابقة:
- Linux [Ubuntu](download) distribution (operating system)
- Gedit (text editor)
- g++ (compiler)


### g++ installation:
### تنصيب مترجم الأكواد جي بلس بلس:
on terminal, write:
```
$ sudo apt-get update
$ sudo apt-get –f install
$ sudo apt-get install g++
```
Detailed instructions on setting up g++ can be found [here](https://github.com/siudro/Operating_Systems_Labs/blob/main/OSLabs/LabSlides/Lab02_Compiling_C_C%2B%2B_Programs.pdf)
ستجدون شرح تفصيلي لطريقة تنصيب المترجم في هذا الملف.

### Usage
### كيف استخدم هذا المستودع؟
In order to run the files, create a directory to contain all files:
يجب أولًا إنشاء مجلد أو مسار نحفظ فيه محتويات هذا المستودع، في موجه الأوامر يتم كتابة: 
```
$ mkdir OSLabsContainer
```
Head to the directory you just created:
افتح هذا المجلد: 
```
$ cd OSLabsContainer
```
You can simply download the zip file or clone this repository:

*(Note: [git](https://git-scm.com/downloads) is requiered to do this step.)*
```
$ git clone https://github.com/siudro/Operating_Systems_Labs.git
```
Open files with:
```
$ cd Operating_Systems_Labs
$ cd OSLabs
```
If you want to open the editor:
```
$ gedit <fileName>.cpp
```
and if you want to test/run the code:
```
$ ./<fileName>
```
