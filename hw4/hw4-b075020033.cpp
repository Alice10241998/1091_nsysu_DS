// Author：謝朋潔 B075020033
// Date：Oct. 17, 2020
// Purpose：西洋棋騎士(knight)走完棋盤的順序，Recursive之應用

#include<iostream>
#include<iomanip>
using namespace std;

int chess[6][6], step, done; //chess棋盤，step步數，done是否完成 
void PRINT(int n) //輸出
{
	if(step==n*n)   //若走完，印出棋盤 
		for(int i=0;i<n;i++)
        {
			for(int j=0;j<n;j++)
				cout<< setw(4)<<chess[i][j];
			cout<< endl;
		}
	else    cout<<"no solution."<< endl; //無解 
}

void MOVE(int i, int j, int s, int n) //移動，座標(i,j)、步數s、棋盤大小n(n*n)
{
	chess[i][j]=s; //將目前步數放入棋盤格子內
	if(s==n*n) //若步數=棋盤格子(走完)
    {
		step=s;
		done=1;	//完成 
		return;
	}
	
	if(i>=2&&j<n-1&&chess[i-2][j+1]==0) MOVE(i-2, j+1, s+1, n) ; //方向K1  
	if(i>=1&&j<n-2&&chess[i-1][j+2]==0)	MOVE(i-1, j+2, s+1, n);	//方向K2 
	if(i<n-1&&j<n-2&&chess[i+1][j+2]==0) MOVE(i+1, j+2, s+1, n); //方向K3 
	if(i<n-2&&j<n-1&&chess[i+2][j+1]==0) MOVE(i+2, j+1, s+1, n); //方向K4 
	if(i<n-2&&j>=1&&chess[i+2][j-1]==0)	MOVE(i+2, j-1, s+1, n); //方向K5 
	if(i<n-1&&j>=2&&chess[i+1][j-2]==0)	MOVE(i+1, j-2, s+1, n);	//方向K6 
	if(i>=1&&j>=2&&chess[i-1][j-2]==0)	MOVE(i-1, j-2, s+1, n);	//方向K7 
	if(i>=2&&j>=1&&chess[i-2][j-1]==0)	MOVE(i-2, j-1, s+1, n); //方向K8 

	if(!done) //若未完成且8個方向都不能走
    {				 
		chess[i][j]=0;	//重設這個格子為0
		s--; //回到上一步
	}
}

int main()
{
	for(int n=1;n<=6;n++)
    { 
		cout<<"n="<<n<<endl; //印出目前棋盤大小 
		for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
                if(x>=0&&x<n&&y>=0&&y<n) chess[x][y]=0;	//初始化
        }

		step=1;done=0; //初始化步數跟是否完成 
		MOVE(0,0,step,n); //放入第一個格子(0,0) 
		PRINT(n);	//ouptut
	}
	return 0;
}