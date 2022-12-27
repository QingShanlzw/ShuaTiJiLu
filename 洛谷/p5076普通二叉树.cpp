//vector和搜索树结合使用。 
#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
struct node{
	int t;
	node *l,*r;
};
node *tree;
vector<int>temp;
int q;
void insert(node * &p,int x){
	if(!p){
		node* tt =new node;
		tt->l = tt->r =nullptr;
		tt->t=x;
		p =tt;
		return;
	}
	if(x<=p->t)insert(p->l,x);
	else insert(p->r,x);
}
void inorder(node* p){
	if(!p)return ;
	inorder(p->l);
	temp.push_back(p->t);
	inorder(p->r);
}
int main(){
	cin>>q;
	while(q--){
		int op,x;
		cin>>op>>x;
		temp.clear();
		inorder(tree);
		switch(op){
			case 1:
				cout<<lower_bound(temp.begin(),temp.end(),x)-temp.begin()+1<<endl;
				break;
			case 2:
				cout<<temp[x-1]<<endl;
				break;
			case 3:{
				auto it = lower_bound(temp.begin(),temp.end(),x);
				if(it==temp.begin())
					cout<<-inf<<endl;
				else cout<<*(--it)<<endl;				
				break;
			}
			case 4:{
				auto it = upper_bound(temp.begin(),temp.end(),x);
				if(it==temp.end())
					cout<<inf<<endl;
				else cout<<*it<<endl;				
				break;
			}
			case 5:
				insert(tree,x);	
				break;			
		}
	}
	return 0;
}
