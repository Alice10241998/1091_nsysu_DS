// Author：謝朋潔 B075020033
// Date：Sep. 20, 2020
// Purpose：以C++製作一個「集合」類別 (set class)，使其能進行「聯集」、「交集」、「差集」、「包含」、「屬於」等五種運算。

#include<iostream>
using namespace std;

class TSet
{
    public:
    TSet(); //初始化
    void input(char c); //將字元放置ASCII位置
    friend TSet operator +(const TSet& A, const TSet& B);
	friend TSet operator -(const TSet& A, const TSet& B);
	friend TSet operator *(const TSet& A, const TSet& B);
	friend bool operator >=(const TSet& A, const TSet& B);
    bool belong(char x);
    friend ostream& operator <<(ostream& output, const TSet& T);
    
    private:
    int arr[256]; //記錄字元在ASCII的位置是否存在
};

TSet::TSet()
{
    for(int i=0;i<256;i++)
        arr[i]=0;
}

void TSet::input(char c)
{
    arr[(int)c]=1; //標記字元存在
}


TSet operator +(const TSet& A, const TSet& B) //A與B聯集
{
    TSet s;
    for(int i=0;i<256;i++)
    {
        if(A.arr[i]||B.arr[i])
            s.arr[i]=1; //判斷A與B聯集的字元
    }
    return s;
}

TSet operator -(const TSet& A, const TSet& B) //A與B差集
{
    TSet s;
    for(int i=0;i<256;i++)
    {
        if(A.arr[i]&&(!B.arr[i]))
        {
            s.arr[i]=1; //判斷A與B差集的字元
        }
    }
    return s;
}

TSet operator *(const TSet& A, const TSet& B) //A與B交集
{
    TSet s;
    for(int i=0;i<256;i++)
    {
        if(A.arr[i]&&B.arr[i])
            s.arr[i]=1; //判斷A與B交集的字元
    }
    return s;
}

bool operator >=(const TSet& A, const TSet& B) //A包含B
{
    for(int i=0;i<256;i++)
    {
        if(B.arr[i]&&(!A.arr[i])) //找到集合B不在集合A裡的字元回傳false
            return false;
    }
    return true;
}

bool TSet::belong(char x) //x屬於A
{
    return (arr[(int)x]);
}

ostream& operator <<(ostream& output, const TSet& T) //輸出集合的字元
{
    for(int i=0;i<256;i++)
    {
        if(T.arr[i]==1)
            output<<(char)i;
    }
    return output;
}

int main()
{
    int n; //測資筆數
    char x; //輸入字元是否在集合A中
    cin>>n;
    cin.ignore(); //忽略換行字元

    for(int i=1;i<=n;i++)
    {
        char temp; //輸入字元
        TSet A,B,C,D,E,F;
        
        //輸入集合A B的字元
        while(1)
        {
            temp=getchar(); //不能用cin 因為讀不到換行
            if(temp!='\n')
                A.input(temp);
            else
                break;
        }
        while(1)
        {
            temp=getchar();
            if(temp!='\n')
                B.input(temp);
            else
                break;
        }
        cin>>x;
        cin.ignore(); //忽略換行字元

        C=A+B;
        D=A*B;
        E=A-B;
        F=B-A;
 
        cout<<"Test Case "<<i<<":"<<endl;
        cout<<"A: {"<<A<<"}"<<endl;
        cout<<"B: {"<<B<<"}"<<endl;
        cout<<"A+B: {"<<C<<"}"<<endl; //A與B聯集
        cout<<"A*B: {"<<D<<"}"<<endl; //A與B交集
        cout<<"A-B: {"<<E<<"}"<<endl; //A與B差集
        cout<<"B-A: {"<<F<<"}"<<endl; //B與A差集

        if(A>=B) //A包含B
            cout<<"A contains B"<<endl;
        else cout<<"A does not contain B"<<endl;

        if(B>=A) //B包含A
            cout<<"B contains A"<<endl;
        else cout<<"B does not contain A"<<endl;

        if(A.belong(x)==1) //x屬於A
            cout<<"'"<<x<<"' is in A"<<endl;
        else cout<<"'"<<x<<"' is not in A"<<endl;

        if(B.belong(x)==1) //x屬於B
            cout<<"'"<<x<<"' is in B"<<endl;
        else cout<<"'"<<x<<"' is not in B"<<endl;
    }
}