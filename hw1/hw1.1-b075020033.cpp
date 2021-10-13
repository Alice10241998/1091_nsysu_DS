// Author：謝朋潔 B075020033
// Date：Sep. 9, 2020
// Purpose：製作一階、三階、五階、七階、九階的魔方陣(magic square)

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int x,n,r,c; //x為填入的數字，n為魔方陣階數，r橫列，c直行

    for(n=1;n<=9;n+=2) //印出1,3,5,7,9階魔方陣
    {
        int magic[n][n]; //n*n的魔方陣
        //初始化魔方陣=0
        for(r=0;r<n;r++)
        {
            for(c=0;c<n;c++)
                magic[r][c]=0;
        }
        //由最上面的橫列 中間行開始放數字
        r=0;
        c=n/2;
        //由1開始填入數字，直到n*n填滿
        for(x=1;x<=n*n;x++)
        {
            magic[r][c]=x; //填入數字
            r--; c--; //將下個x放在(r-1,c-1)的位置

            //若數字放入的位置超出魔方陣，則移至最下面
            if(r<0) r=n-1;
            
            //若數字放入的位置超出魔方陣，則移至最右邊
            if(c<0) c=n-1;
            
            //若數字放入的位置已有數字，則移至原本數字的下方
            if(magic[r][c]!=0)
            {
                r=r+2;
                c=c+1;
                
                //修正魔方陣
                if(r>n-1) r=r-n;
                if(c>n-1) c=c-n;
            }
        }

        //對齊 寬度為3 印出魔方陣
        for(r=0;r<n;r++)
        {
            for(c=0;c<n;c++)
                cout<<setw(3)<<magic[r][c];
            cout<<endl;
        }
        cout<<endl;
    }
}