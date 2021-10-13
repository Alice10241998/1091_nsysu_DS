#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int i,n,r,c;

    for(i=1;i<=9;i+=2)
    {
        int magic[i][i];

        for(r=1;r<=i;r++)
        {
            for(c=1;c<=i;c++)
                magic[r][c]=0;
        }

        r=1;c=i/2+1;

        for(n=1;n<=i*i;n++)
        {
            magic[r][c]=n;
            r--;c--;

            if(r<1) r=i;
            if(c<1) c=i;
            if(magic[r][c]!=0)
            {
                r=r+2;
                c=c+1;

                if(r>n) r=r-n-1;
                if(c>n) c=c-n+1;
            }
        }

        for(r=1;r<=i;r++)
        {
            for(c=1;c<=i;c++)
                cout<<setw(3)<<magic[r][c];
            cout<<endl;
        }
    }
}
