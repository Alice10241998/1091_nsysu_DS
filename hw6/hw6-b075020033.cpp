// Author：謝朋潔 B075020033
// Date：Nov. 11, 2020
// Purpose：利用binary search tree找出所有出現次數為奇數之數字

#include<iostream>
using namespace std;

class node //儲存每個節點資料
{
	public:
		node(){left=0;right=0;};
		node(int n):data(n){left=0;right=0;};
        friend class tree;

	private:
		int data; //值
		node *left,*right; //左子樹 右子樹
};

class tree //二元樹
{
	public:
		tree(){root=0;};
		void insert(int n); //插入數字
		void del(node *t,int n); //刪除出現一樣的數字
		void leaf(node *t,int n);
		void nonleaf(node *t,int n);
		void pnode(node *c); //印出node
		void pleft(node *c); //印出左子樹
		void pright(node *c); //印出右子樹
		node* root;
};

void tree::insert(int n)
{
	if(root!=0)
	{
		node *c=root;
		bool de=false; //判斷是否刪除

		while(1)
		{
			if(c->data==n) //現在指的值=要加入的數字
			{
				de=true; //刪除c指到位置
				break;
			}
			else if(c->data<n) //現在指的值<要加入的數字
			{
				if(c->right) //指到原本位置的右邊(因為n要放在右邊)
					c=c->right;
				else break; 
			}
			else if(c->data>n) //現在指的值>要加入的數字
			{
				if(c->left) //指到原本位置的左邊(因為n要放在左邊)
					c=c->left;
				else break;
			}
		}

		if(de) del(c,n); //刪除重複的數字
		else //不需要刪除，則建立新node
		{
			node *newnode=new node(n);
			if(c->data<n) //newnode>現在的值
				c->right=newnode; //newnode放右邊
			else if(c->data>n) //newnode<現在的值
				c->left=newnode; //newnode放左邊
		}
	}
    else root=new node(n); //root為空
}

void tree::del(node *t,int n)
{
	if(t->left==0&&t->right==0) //沒有son
		leaf(t,n);
	else if((t->left!=0&&t->right==0)||(t->left==0&&t->right!=0)) //only one son
		nonleaf(t,n);
	else
	{
		node *s=t->right; //找出右子樹中最左邊的子樹
		while(s->left)
			s=s->left; 
		n=s->data; //n暫存s的data
		
        if(s->right==0) //沒有右子樹，則刪除使用leaf
			leaf(s,s->data);
		else //有右子樹，則刪除使用nonleaf
			nonleaf(s,s->data);
		t->data=n;
	}
}

void tree::leaf(node *t,int n) //沒有son
{
	if(t==root) root=0; //刪掉的點是root
	else
	{
		node *c=root;
		while(1)
		{
			if(c->left==t||c->right==t) break;
			if(c->data<n) c=c->right;
			else if(c->data>n) c=c->left;
		}
		if(c->data<n) c->right=0;
		else if(c->data>n) c->left=0;
	}
	delete t;
}

void tree::nonleaf(node *t,int n) //only one son
{
	if(t==root) //刪掉的點是root
	{
		if(t->left) //root有左邊，則指到左邊
			root=t->left;
		else //root有右邊，則指到右邊
			root=t->right;
	}
	else
	{
		node *c=root;

		while(1)
		{
			if(c->left==t||c->right==t) break;
			if(c->data<n) c=c->right;
			else if(c->data>n) c=c->left;
		}
		//找位置要放左邊還是右邊
		if(c->data<n)
		{
			//放入left
			if(t->left)
				c->right=t->left;
			else
				c->right=t->right;
		}
		else if(c->data>n)
		{
			//放入right
			if(t->left)
				c->left=t->left;
			else
				c->left=t->right;
		}
	}
	delete t;
}

void tree::pnode(node *c)
{
	if(root==0)
		cout<<" 0";
	if(c)
	{
		pnode(c->left); //先印左邊
		cout<<" "<<c->data;
		pnode(c->right); //再印右邊
	}
}

void tree::pleft(node *c)
{
	if(root==0)
		cout<<" 0";
	if(c)
	{
		pleft(c->left);
		if(c->left)
			cout<<" "<<c->left->data;
		else
			cout<<" 0";
		pleft(c->right);
	}
}

void tree::pright(node *c)
{
	if(root==0)
		cout<<" 0";
	if(c)
	{
		pright(c->left);
		if(c->right)
			cout<<" "<<c->right->data;
		else
			cout<<" 0";
		pright(c->right);
	}
}

int main()
{
	while(1)
	{
		int n;
		tree A;
	
		while(cin>>n) //cin測資
		{
			if(n==-1)
				break;
			A.insert(n);
		}

		cout<<"node:"; //output node
		A.pnode(A.root);
		cout<<endl<<"left:"; //output left
		A.pleft(A.root);
		cout<<endl<<"right:"; //output right
		A.pright(A.root);
		cout<<endl;
        cout<<endl;
	}
}