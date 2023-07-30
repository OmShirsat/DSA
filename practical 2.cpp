#include<iostream>
using namespace std;
#include<string>
long A[10],y;

class node{
	public: 
		long num;
		string name;
	node(){
		num= NULL;
		name="";
	}
};

class database{
	node emp[10];
	int flag;
	public: 
		int hashfunc(long n){
			return n%10;
		}
		void display(){
			for(int i=0;i<10;i++){
		
				if(emp[i].num!=NULL){
				cout<<endl<<"client name  = "<<emp[i].name<<" client tele. no.  = "<<emp[i].num<<endl;
				}
				else{
					cout<<endl<<"client name  = XX  "<<" client tele. no.  =  123"<<endl;
				}
			}
		}
		int nextfree(int x){
			for(y=x;y<10;y=(y+1)%10){
				if(emp[y].num==NULL){
				break;
				}
			}
		return y;	
		}

		void adddata1(){
			if(flag!=10){
			
				int hkey;
				long num;
				string empname;
				cout<<"Enter name of client : ";
				cin>>empname;
				cout<<"Enter client telephone no. : ";
				cin>>num;
				hkey=hashfunc(num);
				if(emp[hkey].num==NULL){
					emp[hkey].name=empname;
					emp[hkey].num=num;
				}
				else{
					withrep(hkey,empname,num);			
				}
				flag++;
		}
		else{
			cout<<"hashtable overflow ";
			
		}
			
		}
		void adddata2(){
			if(flag!=10){
			
				int hkey;
				long num;
				string empname;
				cout<<"Enter name of client : ";
				cin>>empname;
				cout<<"Enter client telephone no. : ";
				cin>>num;
				hkey=hashfunc(num);
				if(emp[hkey].num==NULL){
					emp[hkey].name=empname;
					emp[hkey].num=num;
				}
				else{
					withoutrep(hkey,empname,num);			
				}
				flag++;
		}
		else{
			cout<<"hashtable overflow ";
			
		}
			
		}
		void search(){
			int comp;
			
		}
		void withrep(int n , string name, long num){
			int hkey1=n;
			int x=hashfunc(emp[hkey1].num);
			int hkey2=nextfree(n);
			cout<<" x , n "<<x<<n;
			if(x==n){
			    		emp[hkey2].name=name;
			            emp[hkey2].num=num;
			}
			else{
			emp[hkey2].name=name;
			emp[hkey2].num=num;
			swap( emp[hkey2].name , emp[hkey1].name );
			swap( emp[hkey2].num , emp[hkey1].num );
			
			}
			
		}
		void withoutrep(int n , string name, long num){
			int hkey=nextfree(n);
			emp[hkey].name=name;
			emp[hkey].num=num;
		}
};
int main(){
	database a;
	for (int i= 0; i<3; i++){
		a.adddata1();	
	}
	a.display();
}

	

