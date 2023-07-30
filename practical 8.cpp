#include<iostream>
#include<string>
using namespace std;
class node{
	public:
	string city;
};
class graph{
	string * arr;
	int flight[6][6];
	int no;
	public:
		graph(int n){
			no=n;
			arr= new string [n];
			for(int i=0;i<n;i++){
			    for(int j=0;j<n;j++){
			        flight[i][j]=-1;
			    }
			}
		}
		void accept(){
			cout<<"enter cities one by one \n";
			for(int i=0;i<no;i++){
				cin>>arr[i];
			}
		}
		void addedge(int n){
		    int x ,y,t;
		    for(int i=0;i<no;i++){
				cout<<i+1<<" : "<<arr[i]<<"\t";
			}
			cout<<endl;
			
			for(int i=0;i<n;i++){
    			cout<<"enter city no you want to add flight : ";
    			cin>>x>>y;
    			cout<<"enter time taken to travel : ";
    			cin>>t;
    			flight[x-1][y-1]=t;
    			flight[y-1][x-1]=t;
			}
		}
		void adjmatrix(){
		    cout<<"adjacency matrix : "<<endl;
		    for(int i=0;i<no;i++){
		        cout<<"\t"<<arr[i];
		    }
		    cout<<endl;
		    for(int i=0; i<no ; i++){
		        cout<<arr[i];
		        for(int m=0;m<no;m++){
		            cout<<"\t"<<flight[i][m];
		    }
		    cout<<endl;
		    }
		}
		void checkloop(){
			string m,x;
			int a,b;
			m=arr[0];
			int flag=0;
			while(m!=x){
				b=a+1;
				if(b==no){
					b=0;
				}
				while(b<no){
					if(flight[a][b]!=-1){
						a=b;
						flag++;
						x=arr[b];
						break;
					}
					b++;
				}
				a++;
				if(a==no){
					break;
				}
				
			}
			if(flag==)
		}
		
	
};
int main(){
	graph g(3);
	g.accept();
	g.addedge(3);
	g.adjmatrix();
	return 0;
	}
