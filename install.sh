#!/bin/sh

sudo apt-get update
sudo apt-get install g++ -y
sudo apt-get install cmake -y
sudo apt-get install qtbase5-dev -y
cmake ./
make
