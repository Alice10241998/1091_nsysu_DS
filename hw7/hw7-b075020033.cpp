// Author：謝朋潔 B075020033
// Date：Dec. 5, 2020
// Purpose：測試五種排序(insertion sort、heap sort、radix sort、C qsort、C++ sort)演算法的執行效率

#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<iomanip>
using namespace std;

int unsort[500000],s[500000]; //unsort[]儲存未排序資料 s[]儲存排序資料 

//將讀進來的資料儲存至陣列中
void ss(int size)
{
    for(int i=0;i<size;i++)
        s[i]=unsort[i];
}

//======================================================================
void insertionsort(int size)
{
	int i, j, key;
		
	for(i=1;i<size;i++)
    {
        key=s[i];
        j=i-1; //前後比較
        while(key<s[j]&&j>=0) //後面的數比較小進行互換
        {
            s[j+1]=s[j];
            j--;
        }
        s[j+1]=key;
    }
}

//======================================================================
//heap tree
void heapify(int a[],int size, int root)
{
    int largest=root; //設root為最大
    int l=2*root+1; //left child=2*root+1
    int r=2*root+2; //right child=2*root+2
 
    //if left child > root
    if(l<size&&a[l]>a[largest])
        largest=l;

    //if right child > 目前最大值
    if(r<size&&a[r]>a[largest])
        largest=r;
 
    // If largest 不是 root
    if(largest!=root)
    {
        swap(a[root],a[largest]); //將最大值與root互換
        heapify(a,size, largest); //recursive
    }
}

//heap sort
void heapsort(int a[],int size)
{
    // Build heap
    for(int i=size/2-1;i>=0;i--)
        heapify(a,size, i);

    for (int i=size-1;i>0;i--)
    {
        swap(a[0],a[i]); //將heap正確位置與最末位交換
        heapify(a,i,0);
    }
}

//======================================================================
//找陣列a中的最大值
int getmax(int a[], int size)
{
    int max=a[0]; //設a[0]為最大值
    for(int i=1;i<size;i++) //用迴圈找到最大值
        if(a[i]>max)
            max=a[i];
    return max;
}

//由個位數開始排序至最高位數
void CountSort(int a[],int size,int exp) //exp=10的i次方
{  
    int result[size],i,count[10]={0};
    //計算數字出現次數
    for(i=0;i<size;i++)
        count[(a[i]/exp)%10]++;
    //更改位置
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
 
    //最後輸出的位置
    for(i=size-1;i>=0;i--)
    {
        result[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for (i =0;i<size;i++)
        a[i]=result[i];
}
 
//radixsort
void radixsort(int a[], int size)
{
    int exp,i;
    i=getmax(a,size);
    for(exp=1;i/exp>0;exp*=10)
        CountSort(a,size,exp);
}

//======================================================================
//C qsort 用到的比較
int cmp(const void *a, const void *b) 
{
	return *(int*)a-*(int*)b;
}

int main()
{
    int i,size; //size排序的資料數量
    ifstream in; //讀檔
    ofstream out; //寫檔

    in.open("input.txt");
    in>>size;
    for(i=0;i<size;i++)
        in>>unsort[i];
    in.close(); //關檔

//insertion sort
    ss(size);
    out.open("outputA.txt"); //output
    out<<"insertion sort"<<endl;
    insertionsort(size);
    for(i=0;i<size;i++)
        out<<s[i]<<endl;
    out.close(); //關檔

//heap sort
    ss(size);
    out.open("outputB.txt"); //output
    out<<"heap sort"<<endl;
    heapsort(s,size);
    for(i=0;i<size;i++)
        out<<s[i]<<endl;
    out.close(); //關檔

//radix sort
    ss(size);
    out.open("outputC.txt"); //output
    out<<"radix sort"<<endl;
    radixsort(s,size);
    for(i=0;i<size;i++)
        out<<s[i]<<endl;
    out.close(); //關檔
    
//C qsort
    ss(size);
    out.open("outputD.txt"); //output
    out<<"C qsort"<<endl;
    qsort(s,size,sizeof(int),cmp); //qsort(排序的陣列,資料量,資料大小,比較)
    for(i=0;i<size;i++)
        out<<s[i]<<endl;
    out.close(); //關檔

//C++ sort
    ss(size);
    out.open("outputE.txt"); //output
    out<<"C++ sort"<<endl;
    sort(s,s+size); //sort(第一筆,最後一筆)
    for(i=0;i<size;i++)
        out<<s[i]<<endl;
    out.close(); //關檔
}
