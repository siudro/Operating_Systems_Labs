English | [العربية](https://github.com/siudro/Operating_Systems_Labs/blob/main/README_ar.md)
# Operating_Systems_Labs
### This repository contains implemented codes in Operating Systems course using Terminal command lines and C++.

### Prerequisites:
- Linux [Ubuntu](download) distribution (operating system)
- Gedit (text editor)
- g++ (compiler)


## g++ installation:
on terminal, write:
```
$ sudo apt-get update
$ sudo apt-get –f install
$ sudo apt-get install g++
```
Detailed instructions on setting up g++ can be found [here](https://github.com/siudro/Operating_Systems_Labs/blob/main/OSLabs/Lab02_Compiling_practice/Lab02_Compiling_C_C%2B%2B_Programs.pdf).


## Usage
In order to run the files, create a directory to contain all files:
```
$ mkdir OSLabsContainer
```

Head to the directory you just created:
```
$ cd OSLabsContainer
```

You can simply download the zip file or clone this repository:

![image](https://user-images.githubusercontent.com/83130573/142734722-89014c83-bf77-41df-a5c7-49e0d9fd2f5f.png)


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

If you did any changes in the cpp file, you should save it then compile it using:
```
$ g++ <fileName>.cpp -o <fileName> -lpthread
```

and if you want to test/run the code:
```
$ ./<fileName>
```
