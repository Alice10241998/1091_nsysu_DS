#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#define SIZE 500000
using namespace std;

int unsorted[SIZE], sorted[SIZE]; 

int main() {
	
	int i, data;
	ofstream fin1, fin2, fin3, fin4, fin5, fin6, fin7, fin8, fin9, fin10;
	srand(time(NULL));
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin1.open("input1.txt");
	for (i = 0; i < SIZE; i++) 
		fin1 << unsorted[i] << endl;
	fin1.close();
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin2.open("input2.txt");
	for (i = 0; i < SIZE; i++) 
		fin2 << unsorted[i] << endl;
	fin2.close();
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin3.open("input3.txt");
	for (i = 0; i < SIZE; i++) 
		fin3 << unsorted[i] << endl;
	fin3.close();
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin4.open("input4.txt");
	for (i = 0; i < SIZE; i++) 
		fin4 << unsorted[i] << endl;
	fin4.close();
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin5.open("input5.txt");
	for (i = 0; i < SIZE; i++) 
		fin5 << unsorted[i] << endl;
	fin5.close();
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin6.open("input6.txt");
	for (i = 0; i < SIZE; i++) 
		fin6 << unsorted[i] << endl;
	fin6.close();
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin7.open("input7.txt");
	for (i = 0; i < SIZE; i++) 
		fin7 << unsorted[i] << endl;
	fin7.close();
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin8.open("input8.txt");
	for (i = 0; i < SIZE; i++) 
		fin8 << unsorted[i] << endl;
	fin8.close();
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin9.open("input9.txt");
	for (i = 0; i < SIZE; i++) 
		fin9 << unsorted[i] << endl;
	fin9.close();
	
	for (i = 0; i < SIZE; i++) {
		data = rand();
		unsorted[i] = data;
	}
	fin10.open("input10.txt");
	for (i = 0; i < SIZE; i++) 
		fin10 << unsorted[i] << endl;
	fin10.close();

	return 0;
} 
