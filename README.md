# README: CPU Virtual Machine

Author: Raffson

---

## Introduction
This project represents the exam for 'Advanced Programming' during the academic year 2013-2014 at the University of Antwerp. We were given roughly 4 hours to complete this task. Initially my code did not compile because I was too busy adding functionalies up until the last moment, which was a bad idea. As a precaution I took the code home and only then noticed it didn't compile, so I quickly started debugging and sent the fixes, even though this was too late. Nevertheless I figured if I wanted to make a chance at all of passing the exam, I had to at least get the program to work and provide those fixes.

Looking back at this code in its initial form, I wonder why I did some (really) stupid things in the code itself, which is why I'm planning on improving the code even though I haven't touched the code in years.

## Description
As the name suggests, this program simulates a machine which can execute the following instructions:

* Add/Subtract two registers
* Compare two registers
* Incement/Decrement (with 1) a register
* Copy registers / Load an immediate value
* Jump if not zero / Jump if not equal

In order to run code on this virtual machine, it is required to write the 'program' in C++. An example can be found in main.cpp, which calculates a n-th fibonacci number given by the variable 'n'.

## Installation
To install this program, CMake is required (minimum version 2.6). The rest is pretty standard given that you've got a terminal open in the root of this project:

* Create a folder called 'bin', i.e. `mdkir bin`
* Create a folder (usually 'build') and navigate into it, i.e. `mkdir build` followed by `cd build`
* Run `cmake ..`
* Run `make all` followed by `make install`
* Switch to the bin directory, i.e. `cd ../bin`
* Run the program, i.e. `./CPU-VM`

To uninstall the program, simply delete the 'build' folder and the executable in the 'bin' folder.

