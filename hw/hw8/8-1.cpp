#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
using namespace std;
class bst{
	public:
		struct tree{
			unsigned long long int data;
			tree* right;
			tree* left;
		};
		tree *root;
	public:
		bst(){
			root =0;
		}
		int emp(){
			if(root==NULL)return 1;
			else return 0;
		}
		void inorder(tree *);
		void print_inorder();
		void insert (unsigned long long int d);
		void preorder(tree*);
		void print_preorder();
		void postorder(tree*);
		void print_postorder();
		void level(tree*);
		void print_level();
		bool find_inorder(tree*,unsigned long long int d);
		void search(unsigned long long int d);
};
int main(){
	unsigned long long int n,key;
	while(cin>>n>>key){
		bst a;
		while(n--){
			unsigned long long int num;
			cin>>num;
			a.insert(num);
		}
		a.search(key);
		cout<<endl;	
	}

	return 0;	
}
void bst::search(unsigned long long int d){
	tree *t=new tree;
	t=root;
	while(t!=NULL){
		if(d>t->data){
			cout<<"R";
			t=t->right;
		}
		else if(t->data==d)break; 
		else if(d<t->data){
			cout<<"L";
			t=t->left;
		}
	}
}
void bst::insert(unsigned long long int d){
	tree *t=new tree;
	tree *parent=new tree;
	t->data = d;
	t->right = NULL;
	t->left = NULL;
	if(emp()==1)root=t;
	else{
		tree *cur;
		cur=root;
		while(cur!=NULL){
			parent =cur;
			if(t->data > cur->data) cur=cur->right;
			else cur=cur->left;
		}
		if(t->data>parent->data)parent->right=t;
		else parent->left=t;
	}
}
void bst::inorder(tree* p){
	if(p!=NULL){
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
			
}
void bst::print_inorder(){
	inorder(root);
}
void bst::preorder(tree *p){
	if(p!=NULL){
		cout<<p->data<<" ";
		preorder(p->left);
		preorder(p->right); 
	}
}
void bst::print_preorder(){
	preorder(root);
}
void bst::postorder(tree* p){
	if(p!=NULL){
		inorder(p->left);
		inorder(p->right);
		cout<<p->data<<" ";
	}
			
}
void bst::print_postorder(){
	postorder(root);
}
void bst::level(tree* p)
{
    if(p==NULL)return ;
	queue<tree*> q;
    q.push(p);
    while (!q.empty())
    {
        tree* cur = q.front(); 
        cout << cur->data<<" ";    // 這行往下挪，結果仍相同。
        if (cur->left)  q.push(cur->left);
        if (cur->right) q.push(cur->right);
        q.pop();
    }
}
void bst::print_level(){
	level(root);
}
bool bst::find_inorder(tree* p,unsigned long long int d){
	tree* cur;
	tree * parent;
	cur=p;
		while(cur!=NULL){
			parent =cur;
			if(d > cur->data) cur=cur->right;
			else if(d<cur->data) cur=cur->left;
			else return 1;
		}
			
	return 0;	
}
