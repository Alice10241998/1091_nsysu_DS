// Author：謝朋潔 B075020033
// Date：Oct. 31, 2020
// Purpose：設計一個程式，可以處理兩個多項式之加法與乘法

#include<iostream>
using namespace std;

class node //多項式的其中一項
{
	public:
		node(int x=0,int y=0){coef=x;exp=y;next=NULL;}	//Default constructor 有輸入則令係數為x，次方為y，無輸入則皆為0
		friend class Poly; //將Poly宣告為friend class使其可以存取node的private member
		int getC(){return coef;}
		int getE(){return exp;}
		node* getN(){return next;}
	private:
		int coef, exp;	//coef=係數，exp=次方
		node *next;	//指到下一項
};

class Poly //多項式
{				
	public:
		Poly(){first=NULL;}	//Default constructor將first指向NULL(代表多項式為空)
		void setPoly(int,int);	//加入項(第一個int為coef，第二個int為exp)
		void PrintPoly(); //印出多項式
		friend Poly operator+(const Poly& X,const Poly& Y);	//多項式相加
		friend Poly operator*(const Poly& X,const Poly& Y);	//多項式相乘
	private:
		node *first; //node 指向多項式的最高次方項
};

void Poly::setPoly(int co,int ex)
{
	node *n=first;	//指到的指標為Poly的最高次方項
	if(n==NULL) //Poly內為空
    {
		node *tmp=new node(co,ex);	//新增
		tmp->next=NULL;	//沒有下一項，next=NULL
		first=tmp;	//只有一項，也就是最高次方項
	}
	else if(n->exp<ex) //Poly內有項且最高項的次方比輸入的次方小
    {		
		node *tmp=new node(co,ex);
		tmp->next=n; //新增項的下一項指到n
		first=tmp; //最高項變成tmp
	}
	else  //Poly內有項且Poly的最高項次方比輸入次方大
    {
		if(n->exp==ex) //第一項的次方=輸入次方
        {	
			n->coef+=co; //第一項的次方增加co
			ex=-1;	//新增結束
		}
		while(ex!=-1&&n->next!=NULL&&n->next->exp>=ex) //n有下一項，下一項的次方>輸入的次方，找同次方項or插入的位置
        {
			if(n->next->exp==ex) //找到同次方項
            {
				n->next->coef+=co;	//目前的次方係數增加x
				ex=-1;	//新增結束
				break;	
			}
			n=n->next;	//若下一項次方>輸入，往下一項找
		}
		if (ex!=-1)	//沒有同次方項(跳出迴圈時n指到的項比y大，n的下一項不存在或是比y小)
        {
			node *tmp=new node(co,ex);	//新建一個node
			if(n->next!=NULL) tmp->next=n->next; //若n不是最後一項，將tmp的下一項設為n的下一項
			else tmp->next=NULL; //將tmp的下一項設為NULL(n為最小次方項且tmp的次方更小)
			n->next=tmp; //將n的下一項設為tmp
		}
	}
	node *cur=first; //多項式內是否有係數為0的node
	while(cur!=NULL&&cur->next!=NULL) //當curt還沒指到倒數第二項
    {
		if((cur->next->coef)==0) //目前指到的下一項係數為0
        {
			node *De=cur->next;	//儲存下一項node
			cur->next=cur->next->next; //將他指向的下一個變成上一個(cur)指向的下一個
			delete De; //刪除此node
		}
		else cur=cur->next;	//沒改變則cur移往下一項
	}
	if(first->coef==0) //第一項係數為0
    {
		node *De=first;
		first=first->next;
		delete De;
	}
}

void Poly::PrintPoly() //印出多項式
{	
	if (first==NULL) //多項式為空，印出0 0
    {						
		cout<<"0 0"<<endl;
		return;
	}
	node *cur=first; //cur指向最高次方
	while(cur!=NULL) //cur沒有跑到NULL以前
    {
		cout<<cur->coef<<" "<<cur->exp<<endl; //印出目前cur指到的項
		cur=cur->next;	//將cur指向下一項
	}
}

Poly operator +(const Poly&X,const Poly&Y)
{
	Poly *P=new Poly;
	node *x=X.first,*y=Y.first;	//X, Y由最高次方項開始加
	while(x!=NULL) //多項式X還沒加完
    {
		(*P).setPoly((*x).getC(),(*x).getE());	//P內增加目前多項式X的x項
		x=(*x).getN();	//向下一項推進
	}
	while(y!=NULL)
    {
		(*P).setPoly((*y).getC(), (*y).getE());
		y=(*y).getN();
	}
	return *P;	//回傳Poly P
}

Poly operator *(const Poly& X, const Poly& Y)
{
	Poly *P=new Poly;
	node *curY=Y.first,*curX=X.first; //多項式的最高次方項開始作運算
	if (curX==NULL||curY==NULL) return *P;	//其中一個多項式為0，則相乘=0
	while(curY!=NULL) //多項式Y還沒乘完
    {
		curX=X.first; //將Y的每一項依次與X的第curX項相乘最後加總
		Poly AP; //AP作為Y的第CurrentY項與X相乘後得到的多項式
		while(curX!=NULL)  //多項式X還沒乘完
        {
			AP.setPoly((*curX).getC()*(*curY).getC(),(*curX).getE()+(*curY).getE()); //AP內新增curX*curY
			curX=(*curX).getN(); //將curX移往下一項
		}
		*P=(*P)+(AP); //P=每次的AP疊加起來的結果
		curY=(*curY).getN(); //將curY移往下一項
	}
	return *P;
}

int main()
{
	int P, Q, x, y, count=0; //P、Q表多項式A及多項式B有多少項，x->coef的輸入，y->exp的輸入，count計算有幾個case
	while(1)
    {
        cin>>P;
		Poly A, B, C, D; //A、B、C、D四個多項式，A、B為input，C、D為A+B以及A*B的output
		for(int i=0;i<P;i++) //輸入多項式A的迴圈
        {
			cin>>x>>y;
			A.setPoly(x, y);
		}
		cin>>Q;

		if(P==0&&Q==0) break; //程式結束
		else count++; //case+1

		for(int i=0;i<Q;i++) //輸入多項式B的迴圈
        {
			cin>>x>>y;
			B.setPoly(x, y);
		}

		C=(A+B); //C=A+B
		D=(A*B); //D=A*B
		cout<<endl;
		cout<<"Case"<<count<<":"<<endl;
		cout<<"ADD"<<endl;
		C.PrintPoly(); //print C=A+B
		cout<<"MULTIPLY"<<endl;	
		D.PrintPoly(); //print D=A*B
		cout<<endl;
	}

	return 0;
}
