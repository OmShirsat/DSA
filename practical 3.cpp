#include<iostream>
#include<string>
using namespace std;
class node{
	public:
	int key;
	string Word;
	node *next;
	int flag;
	node(){
		next=NULL;
		flag=NULL;
	}
};

int hashfunc(int num){
	return (num%10);	
}
class Dictionary{
	public:
		node htable[10];
};
Dictionary d;
int search(){
	int flag,key,hcode;
	node *temp;
	flag=0;
	cout<<"Enter the key to be search: ";
	cin>>key;
	hcode=hashfunc(key);
	
			temp=&(d.htable[hcode]);
			while((temp->flag==1 )||(temp->key==key)){
				if(temp->key==key){
					flag++;
					cout<<"value : "<<temp->Word;
					cout<<endl;
					break;
					
			}
				else{
					temp=temp->next;
			}
				if(temp->flag==0){
					break;
			}
			}
			if(flag==0){
				cout<<endl<<"key not exist ***"<<endl;
			
			}
}
int add(){
		int ch,key,i,hcode;
		string word;
		node *temp;
		cout<<"Enter the value : ";
		cin>>word;
		cout<<"Enter the key : ";
		cin>>key;
		hcode=hashfunc(key);
		if((d.htable[hcode].flag==NULL )&& (d.htable[hcode].next==NULL)){
			d.htable[hcode].key=key;
			d.htable[hcode].Word=word;
			d.htable[hcode].flag=1;
		}
		else if(d.htable[hcode].flag==1 ){
			temp=&(d.htable[hcode]);
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new node;
			temp=temp->next;
			temp->key=key;
			temp->Word=word;
			temp->flag=1;
			}
}
void display(){
	cout<<"HashTable : "<<endl;
	for(int i=0;i<10;i++){
		if(d.htable[i].flag==1){
			node *temp;
			temp=&(d.htable[i]);
			while(temp->flag==1){
				if(temp->flag==1){
				cout<<"[ key : "<<temp->key<<" Value : "<<temp->Word<<" ]";
				}
				if(temp->next!=NULL){
					cout<<" -> ";
					temp=temp->next;
			}
				else{
					cout<<endl;
					break;
			}
			}
		}
		else{
			cout<<"[ key : 0 Value : xx ]";
			cout<<endl;
		}
	}
}
int dlt(){
	int flag,key,hcode,i,x;
	node *temp,*temp1;
	flag=0;
	cout<<"Enter the key to be deleted : ";
	cin>>key;
	hcode=hashfunc(key);
	temp=&(d.htable[hcode]);
	while(temp->flag==1){
			if(temp->key==key){
				cout<<"value : "<<temp->Word;
				flag++;
				cout<<endl;
				break;
		}

			else{
					temp1=temp;
					temp=temp->next;
			}
			if(temp->flag==0){
					break;
			}
		}if(flag==1){
			if(temp->key!=d.htable[hcode].key){
				temp1->next=NULL;
				delete temp; 
				}
			else{
				temp->next=NULL;
				temp->flag=NULL;
				temp->Word="";
			}
			cout<<endl<<"key deleted"<<endl;
	}
	else{
		cout<<endl<<"key is not used "<<endl;
	}
	
}

int main(){
	int ch,key,i,hcode;
	string word;
	node *temp;
	while(ch!=5){
		cout<<endl;
		cout<<"1.add 2.search 3.display 4.delete 5.exit ";
		cout<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		if(ch==1){
			add();
			}
		else if(ch==2){
			search();
			}
		else if(ch==3){
			display();
			}
		else if(ch==4){
			dlt();
		}
		else if(ch==5){break;}
	}

		
	
	return 0;
}


