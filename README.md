# Artificial Life
Simulation of an artificial life of two species loosely based on Conway's Game of Life

In order to install this application, the following packages are required:
* g++ (with c++14 support)
* cmake (>=2.4)
* qtbase5-dev

For your convenience, there is an installation script prepared,
that carries installation process of those packages and compilation of
the source code for you. To run this script, open the terminal in this application's source code 
directory, then add executable permission to the installation script by putting this line 
into the terminal (you'll be asked to put your password in):

```
sudo chmod +x ./install.sh
```

then you can run the script with:

```
./install.sh
```

this should result in creating application's executable file that you can run with:

```
./Artificial-life
```