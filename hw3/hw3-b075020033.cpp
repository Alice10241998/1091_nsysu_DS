// Author：謝朋潔 B075020033
// Date：Oct. 5, 2020
// Purpose：西洋棋騎士(knight)走完棋盤的順序，stack之應用

#include<iostream>
#include<iomanip>
using namespace std;

class knight //儲存騎士移動的順序
{
    friend class stack;
    public:
    knight(){}; //初始化
    knight(int i,int j,int k){row=i;col=j;dir=k;}; //constructor
    int r(){return row;}; //取private值
    int c(){return col;}; //取private值
    int d(){return dir;}; //取private值

    private:
    int row,col,dir; //row:行 col:列 dir:位置
};

class stack
{
    public:
    stack(){top=-1;}; //top=-1表stack為空
    void push(knight x){arr[++top]=x;}; //將資料push stack
    void pop(){if(top>-1) arr[top--];}; //將資料pop stack
    knight gt(){return arr[top];};
    int gettop(){return top;};
    private:
    int top; //stack裡有幾個元素
    knight arr[36]; //存棋盤的數量
};

int main()
{
    int k[8][2]; //位置差值
    k[0][1]=k[2][0]=k[3][1]=k[5][0]=1;
    k[1][1]=k[2][1]=k[3][0]=k[4][0]=2;      
    k[0][0]=k[5][1]=k[6][1]=k[7][0]=-2;
    k[1][0]=k[4][1]=k[6][0]=k[7][1]=-1;

    cout<<"n=1"<<endl<<"  1"<<endl<<endl;

    for(int n=2;n<=6;n++) //棋盤n*n
    {
        cout<<"n="<<n<<endl;
        //初始化
        int r=0,c=0,chess[6][6];
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
                chess[i][j]=0;
        }

        int x=1;//由1開始走
        chess[0][0]=x;
        stack s;

        while(x<n*n)
        {
            int f=1; //標記
            //測是否可以繼續走
            for(int i=0;i<8;i++)
            {
                int tr,tc; //移動後的位置
                tr=r+k[i][0];
                tc=c+k[i][1];
                if(tr>=0&&tc>=0&&tr<n&&tc<n)
                {
                    if(chess[tr][tc]==0) //下一步棋盤裡沒有數字
                    {
                        knight tmp(r,c,i);
                        s.push(tmp);
                        r=tr;c=tc;
                        chess[tr][tc]=++x;
                        f=0; //成功
                        break;
                    }
                }
            }

            if(s.gettop()==-1&&f==1)
                break; //需要後退且無法pop

            //判斷退後
            while(f)
            {
                chess[r][c]=0; //找不到下一步，將目前位置歸零
                r=(s.gt()).r();
                c=(s.gt()).c();
                int d=(s.gt()).d();
                //找其他方向可以移動的位置
                for(int i=d+1;i<8;i++)
                {
                    int tr,tc;
                    tr=r+k[i][0];
                    tc=c+k[i][1];
                    if(tr>=0&&tc>=0&&tr<n&&tc<n)
                    {
                        //退後重新找下一步
                        if(chess[tr][tc]==0) //棋盤裡沒有數字
                        {
                            s.pop();
                            knight tmp(r,c,i);
                            s.push(tmp);
                            r=tr;c=tc;
                            chess[tr][tc]=x;
                            f=0; //成功
                            break;
                        }
                    }
                }

                //退後無法找到下一步
                if(f==1)
                {
                    s.pop();
                    x--;
                    if(s.gettop()==-1) break;
                }
            }
            if(s.gettop()==-1) break;
        }
        //輸出
        if(s.gettop()==-1) cout<<"no solution"<<endl;
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    cout<<setw(3)<<chess[i][j];
                cout<<endl;
            }
        }
        cout<<endl;
    }
}
