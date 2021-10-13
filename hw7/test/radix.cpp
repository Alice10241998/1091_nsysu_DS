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

int getmax(int a[], int size)
{
    int max=a[0];
    for(int i=1;i<size;i++)
        if(a[i]>max)
            max=a[i];
    return max;
}

void CountSort(int a[],int size,int exp)
{  
    int result[size],i,count[10]={0};

    for(i=0;i<size;i++)
        count[(a[i]/exp)%10]++;

    for(i=1;i<10;i++)
        count[i]+=count[i-1];

    for(i=size-1;i>=0;i--)
    {
        result[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for (i =0;i<size;i++)
        a[i]=result[i];
}
 

void radixsort(int a[], int size)
{
    int exp,i;
    i=getmax(a,size);
    for(exp=1;i/exp>0;exp*=10)
        CountSort(a,size,exp);
}
void loop()
{
	clock_t start, end;
	double duration;
	
	copyArray(SIZE);
	start = clock();
	radixsort(sorted,SIZE);
	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
	cout << "radix sort:" << fixed << setprecision(6) << duration << endl;
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
