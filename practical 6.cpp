#include<iostream>
#include<string>
using namespace std;
class node {
	public:
		
		node* left;
		node* right;
		string data;
		string meaning;
		node(){
			data="";
			left=NULL;
			right=NULL;
			meaning="";
		}
};
class Btree{
	public:	string A[20];
		node* head,temp;
		int i;
		Btree(){
			head=new node;
			i=0;
			for(int x=0;x<10;x++){
				A[i]="";
			}
			
		}
		void create(){
			string data;
			string meaning;
			cout<<endl<<"Enter the word : ";
			cin>>data;
			cout<<"enter the meaning of word : ";
			cin.ignore();
			getline(cin,meaning);
			if(head->data==""){
				head->data=data;
				head->meaning=meaning;
			}
			else{
				node* temp;
				temp=new node;
				temp->data=data;
				temp->meaning=meaning;
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
			else if(root->data<child->data){
			
				if(root->right==NULL){
					root->right=child;
				}
				else{
					insertnode(root->right,child);
			
				}
			}
		}
		void infix(node* temp){
		
			
			if(temp->left!=NULL){
				infix(temp->left);
				}
			cout<<temp->data<<" : "<<temp->meaning<<endl;
			A[i]=temp->data;
			i++;
			if(temp->right!=NULL){
				infix(temp->right);
				}
			
			
		}
		void update(){
			string data,temp1;
			cout<<"which word you want to update : ";
			cin>>data;
			node *temp,*update,*pre;
			temp=head;
			update=new node;
			while(temp->data!=data){
				if(temp->data>data){
					pre=temp;
					temp=temp->left;
				}
				else if(temp->data<data){
					pre=temp;
					temp=temp->right;
				}
			
			}
			cout<<"\n"<<temp->data<<" : "<<temp->meaning<<endl;
			cout<<endl<<"enter the updataed meaning : ";
			cin.ignore();
			getline(cin,temp1);
			temp->meaning="";
			temp->meaning=temp1;
			cout<<"updated";
		}
		void search(){
			node *temp;
			temp=head;
			int x;
			x=0;
			string data;
			cout<<"enter word to be searched : ";
			cin>>data;
			while(temp->data!=data){
				if(temp->data>data){
					temp=temp->left;
					x++;
				}
				else if(temp->data<data){
					temp=temp->right;
					x++;
				}
			
			}
			if(temp->data==head->data){
				x=-1;
			}
			if(x==0){
				cout<<"word not found"<<endl;
			}
			if(x==-1){
				x=0;
			}
			cout<<"the steps taken : "<<x<<endl;
			cout<<"word : "<<temp->data<<endl<<" meaning : "<<temp->meaning;
		}
		void delte(){
			infix(head);
			int i;
			string data1,data2;
			cout<<"enter word to be deleted : ";
			cin>>data1;
			node *temp1,*temp2,*update,*pre1,*pre2,*child;
			temp1=head;
			temp2=head;
			while(temp1->data!=data1){
				if(temp1->data>data1){
					pre1=temp1;
					temp1=temp1->left;
				}
				else if(temp1->data<data1){
					pre1=temp1;
					temp1=temp1->right;
				}
			
			}
			if( (temp1->right==NULL)&&(temp1->left==NULL) ){
				//node has 0 child
				if(pre1->left==temp1){
					pre1->left=NULL;
					delete temp1;
				}
				else if(pre1->right==temp1){
					pre1->right=NULL;
					delete temp1;
				}
			}
			else if( (temp1->right==NULL)||(temp1->left==NULL) ){
				//node has one child
				if(temp1->left==NULL){
					child=temp1->right;
				}
				else{
					child=temp1->left;
				}
				
				if(pre1->left==temp1){
					pre1->left=child;
					delete temp1;
				}
				else if(pre1->right==temp1){
					pre1->right=child;
					delete temp1;
				}
				
				
			}
			else{	
				//node has 2 child
				while(A[i]!=data1){
					i++;
					data2==A[i+1];
				}
				while(temp2->data!=data2){
					if(temp2->data>data2){
						pre2=temp2;
						temp2=temp2->left;
					}
					else if(temp2->data<data2){
						pre2=temp2;
						temp2=temp2->right;
					}
			
				}
				if(pre1->left==temp1){
					pre1->left=temp2;
				}
				else if(pre1->right==temp1){
					pre1->right=temp2;
				}
				
				delete temp1;
				
				if(pre2->left==temp1){
					pre2->left=NULL;
				}
				else if(pre2->right==temp1){
					pre2->right=NULL;
				}
				
			}
			
			
		}

};

int main(){
	int n,ch;
	Btree t;
	while(ch!=6){
		cout<<endl<<"1.input 2.infix display 3.updation 4.search 5.delete 6.exit";
		cout<<endl<<"enter your choice : ";
		cin>>ch;
		if(ch==1){
			t.create();
		}
		else if(ch==2){
			cout<<"inorder traversal : "<<endl<<endl;
			t.infix(t.head);
		}
		else if(ch==3){
			t.update();
		}
		else if(ch==4){
			t.search();
		}
		else if(ch==5){
			t.delte();
		}
		else if(ch==6){
			cout<<endl<<" *** Exiting *** "<<endl;
			break;
		}
	}
	return 0;
}
