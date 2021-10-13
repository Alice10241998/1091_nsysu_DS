// Author：謝朋潔 B075020033
// Date：Sep. 9, 2020
// Purpose：印出1到N之間所有整數之階乘 (factorial)，N<=50

#include<iostream>
#include<iomanip>
using namespace std;

void factorial(int input)
{
    int i,j;
    //i為1*2*3...*input,j為每個位數
    int N[100]={0}; //N[100]以陣列儲存各個位數，N[0]為個位數 N[1]為十位，以此類推
    N[0]=1; //由1開始
    int n=0; //n為位置

    for(i=1;i<=input;i++) //由1開始乘
    {
        for(j=0;j<=n;j++) //由個位數開始乘
            N[j]=i*N[j];
        for(j=0;j<=n;j++)
        {
            if(j==n)
                if(N[j]/10>0) n++; //如果N[j]大於0要進位
            //進位
            N[j+1]+=N[j]/10;
            N[j]=N[j]%10;
        }

        cout<<i<<"!=";//印
        for(j=n;j>=0;j--)
            cout<<N[j]; //由最高位印到個位數(n=0)
        cout<<endl;
    }
}

int main()
{
    int input,i,j;
    //input為輸出階乘數

    while(1)
    {
        cin>>input;
    
        if(input==0) break; //輸入0停止
        else
            factorial(input);
        cout<<endl;
    }
}