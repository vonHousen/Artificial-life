
# Artificial Life
Simulation of an artificial life of two species loosely based on Conway's Game of Life

## Setup
### Linux
In order to install this application on Linux, the following packages are required:
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

### Windows
In order to compile and develop this application on Windows OS, one need to install:
* gcc (https://mingw-w64.org/doku.php/download/mingw-builds)
* QT framework (https://www.qt.io/download)
* cmake (ver 2.4 or higher)

When all components above are installed, one need to add QT `bin` subdirectory to `PATH` environmental variable, or manually copy some of it's `.dll` files (listed below) into directory where `Artificial-life.exe` is built:
* libgcc_s_seh-1.dll
* libstdc++-6.dll
* libwinpthread-1.dll
* Qt5Core(d).dll
* Qt5Gui(d).dll
* Qt5Widgets(d).dll

Moreover, sometimes it's also required from user to execute `cmake` tool with option pointing to `lib\cmake` subdirectory, for example:
```
-DCMAKE_PREFIX_PATH="C:\Qt\Qt5.12.3\5.12.3\mingw73_64\lib\cmake"
```

## Class Diagram [UML]:
![Class hierarchy](https://i.imgur.com/PBnTuuk.png)

