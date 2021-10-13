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

void heapify(int a[],int size, int root)
{
    int largest=root;
    int l=2*root+1;
    int r=2*root+2;

    if(l<size&&a[l]>a[largest])
        largest=l;

    if(r<size&&a[r]>a[largest])
        largest=r;

    if(largest!=root)
    {
        swap(a[root],a[largest]);
        heapify(a,size, largest);
    }
}


void heapsort(int a[],int size)
{
    for(int i=size/2-1;i>=0;i--)
        heapify(a,size, i);

    for (int i=size-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void loop()
{
	clock_t start, end;
	double duration;
	
	copyArray(SIZE);
	start = clock();
	heapsort(sorted,SIZE);
	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
	cout << "heapsort:" << fixed << setprecision(6) << duration << endl;
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
