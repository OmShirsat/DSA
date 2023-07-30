#include<iostream>
#include<string>
using namespace std;
class node {
	public:
		
		node* left;
		node* right;
		int data;
		node(){
			data=NULL;
			left=NULL;
			right=NULL;
		}
};
class Btree{
	public:
		node* head;
		int flag1,flag2;
		
		Btree(){
			head=new node;
			flag1=0;
			flag2=0;
		}
		void create(int num){
			if(head->data==NULL){
				head->data=num;
			}
			else{
				node* temp;
				temp=new node;
				temp->data=num;
				insertnode(head,temp);
			}
		}
		void insertnode(node* root,node* child){
			if(root->data>child->data){
			
				if(root->left==NULL){
					root->left=child;
				}
				else{
					insertnode(root->left,child);
			
				}
			}
			if(root->data<child->data){
			
				if(root->right==NULL){
					root->right=child;
				}
				else{
					insertnode(root->right,child);
			
				}
			}
		}

		void display(node* temp){
			cout<<"\t"<<temp->data;
			if(temp->left!=NULL){
				cout<<endl;
				display(temp->left);
			}
			if(temp->right!=NULL){
				display(temp->right);
			}
		}
				
		
		void inorder(node* temp){
			if(temp->left!=NULL){
				inorder(temp->left);
			}
			
			cout<<" - >"<<temp->data;
			
			if(temp->right!=NULL){
				inorder(temp->right);
			}
		}
		void preorder(node* temp){
			cout<<" - >"<<temp->data;
			if(temp->left!=NULL){
				preorder(temp->left);
			}
			if(temp->right!=NULL){
				preorder(temp->right);
			}
		}
		void postorder(node* temp){
			if(temp->left!=NULL){
				postorder(temp->left);
			}
			if(temp->right!=NULL){
				postorder(temp->right);
			}
			cout<<" - >"<<temp->data;
		}
		void leastvalue(){
			node* temp;
			temp=head;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			int least=temp->data;
			cout<<"least value is : "<<least<<endl;
		}
		void swap1(node* temp){
			if(temp->left!=NULL){
				swap1(temp->left);
			}
			if(temp->right!=NULL){
				swap1(temp->right);
			}
			swap(temp->left,temp->right);
		}
		int height(node* temp){
			if(temp==NULL){
				return(0);
			}
			else{
				int leftht=height(temp->left);
				int rightht=height(temp->right);
				
				return(max(leftht,rightht)+1);
			}
		} 	


};

int main(){
	int n,ch;
	Btree t;
	while(ch!=8){
		cout<<"1.input \n2.inorder display \n3.preorder display \n4.postorder display \n5 least value\n6.swap \n7.height \n8.exit ";
		cout<<endl<<"enter your choice : ";
		cin>>ch;
		if(ch==1){
			cout<<endl<<"enter the number : ";
			cin>>n;
			t.create(n);
		}
		else if(ch==2){
			cout<<"infix traversal : ";
			t.inorder(t.head);
			cout<<endl;
		}
		else if(ch==3){
			cout<<"infix traversal : ";
			t.preorder(t.head);
			cout<<endl;
		}
		else if(ch==4){
			cout<<"infix traversal : ";
			t.postorder(t.head);
			cout<<endl;
		}
		else if(ch==5){
			t.leastvalue();
			cout<<endl;
		
		}
		else if(ch==6){
			t.swap1(t.head);
			cout<<endl;
	
		}
		else if(ch==7){
			int height=t.height(t.head);
			cout<<"height : "<<height<<endl;
	
		}
		else if(ch==8){
			cout<<endl<<" *** Exiting *** "<<endl;
			break;
		}
	}
	return 0;
}
