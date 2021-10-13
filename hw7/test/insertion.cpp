#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <algorithm>
using namespace std;

#define SIZE 500000
int unsorted[SIZE], sorted[SIZE]; 

void copyArray(int size)
{
	for (int i = 0; i < size; i++)
		sorted[i] = unsorted[i];
}

void insertionSort(int size)
{
	int i, j, key;
		
	for (i = 1; i < size; i++)
	{
        key = sorted[i];
        j = i - 1;
        while (key < sorted[j] && j >= 0)
		{
            sorted[j+1] = sorted[j];
            j--;
        }
        sorted[j+1] = key;
    }
}

void loop()
{
	clock_t start, end;
	double duration;
	
	copyArray(SIZE);
	start = clock();
	insertionSort(SIZE);
	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
	cout << "insetion sort:" << fixed << setprecision(6) << duration << endl;
}

int main()
{
	int i, data;
	ifstream fin;
	
	fin.open("input1.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();
	
	fin.open("input2.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();
	
	fin.open("input3.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();
	
	fin.open("input4.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();
	
	fin.open("input5.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();
	
	fin.open("input6.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();
	
	fin.open("input7.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();
	
	fin.open("input8.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();
	
	fin.open("input9.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();
	
	fin.open("input10.txt");
	for (i = 0; i < SIZE; i++)
		fin >> unsorted[i];
	fin.close();
	loop();

	return 0;
} 
