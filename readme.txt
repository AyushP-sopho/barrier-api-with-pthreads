--------------------------------------------
 * Name - Ayush Prakash
 * Date - 10/02/2017
 * Readme for Program to implement Barrier
   API using semaphores.
--------------------------------------------

* The repository contains 5 files:

 1) barrier.cpp - Contains the code for barrier API.
 2) main.cpp - Sample main program to know how to use the API.
 3) barrier.h - Contains the declarations for barrier.cpp.
		(Don't forget to include this file)
 4) readme.txt - This Readme file.
 5) Report.pdf - A report on the design of the API.

* Compiling: 
   Use the following command on the shell:
   g++ -std=c++11 main.cpp barrier.cpp -o bar -pthread

* The program will create a file "output.txt" in which it appends output from threads. 
