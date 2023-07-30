#include<iostream>
#include<string>
using namespace std;
class node{
	public:
		int data;
		node* next[10];
		node(){
			for(int i=0;i<10; i++){
			next[i]=NULL;
			}
		}
};
class graph{
	node *arr[10];
	int visited[10];
	int adjmat[10][10];
	int no;
	public:
	    class stack{
	        friend node;
	       node* s[10];
	       int top=-1;
	       public:
	            int isempty(){
	                if (top==-1){
	                    return 1;
	                }
	                else {
	                    return 0;
	                }
	            }
	            node* pop(){
	                return s[top--];
	            }
	            void push(node *temp){
	                s[++top]=temp;
	            }
	    };
	    class queue{
	        node *q[10];
	        int rear,front;
	        public:
	            queue(){
	                front=-1;
	                rear=-1;
	            }
	            int isempty(){
	                if(front== rear+1){
	                    return 1;
	                }
	                else{
	                    return 0;
	                }
	            }
	            void insertrear(node * temp){
	                 q[++rear]=temp;
	                 if(front==-1){
	                     front=0;
	                 }
	            }
	            node* popfront(){
	                return(q[front++]);
	            }
	            
	            
	            
	    };
		graph(int n){
			no=n;
			for(int i=0;i<n;i++){
				arr[i]= new node;
				arr[i]->data=i+1;
				visited[i]=-1;
			}
			for(int i=0;i<n;i++){
			    for(int j=0;j<n;j++){
			        adjmat[i][j]=0;
			    }
			}
			
		}
		void addedge(int x,int y){
			int i=0,flag=0;
			while(arr[x]->next[i]!=NULL){
				if(arr[x]->next[i]->data == arr[y]->data){
					flag++;
					break;
				}
				i++;
			}
			if(!flag){
			
				arr[x]->next[i]=arr[y];
				
				i=0;
		}
		adjmat[x][y]=1;
		flag=0;
			while(arr[y]->next[i]!=NULL){
				if(arr[y]->next[i]->data-1 == arr[x]->data){
					flag++;
					break;
				}
				i++;
			}
			if(!flag){
			
				arr[y]->next[i]=arr[x];
				
		}
		adjmat[y][x]=1;
			
		}
		void adjlist(){
			node* temp;
			cout<<endl<<"*** adjacency list ***"<<endl;
			for(int i=0;i<no;i++){
				int j=0;
				cout<<arr[i]->data;
				while(arr[i]->next[j]!=NULL){
					temp=arr[i]->next[j];
					cout<<"\t"<<temp->data;
					j++;
				}
				cout<<endl;
			}
		}
		void bfs() {
            queue q;
            int n;
            cout << "Enter the starting node for BFS: ";
            cin >> n;
            visited[n - 1] = 1;
            q.insertrear(arr[n - 1]);
            node* temp; 
        
            while (!q.isempty()) {
                temp = q.popfront();
                if(temp->data!=0)
                    cout << temp->data << " ";
        
                for (int i = 0; temp->next[i] != NULL; i++) {
                    int j = temp->next[i]->data - 1;
                    if (visited[j] == -1) {
                        visited[j] = 1;
                        q.insertrear(temp->next[i]);
                    }
                }
            }
            cout << endl;
}
void adjmatrix(){
    cout<<endl<<"adjacency matrix : "<<endl;
        for(int j=0;j<no;j++){
			        cout<<"\t"<<j;
			    }
			    cout<<endl;
    		for(int i=0;i<no;i++){
    		    cout<<i<<"\t";
			    for(int j=0;j<no;j++){
			        cout<<adjmat[i][j]<<"\t";
			    }
			    cout<<endl;
			}
			
}
void dfs(){
    int x;
    cout<<"enter no for dfs : ";
    cin>>x;
    bool visited1[no]={};
    visited1[x-1]=1;
    stack s1;
    s1.push(arr[x-1]);
    node *temp;
    int j;
    while(!s1.isempty()){
        temp=s1.pop();
        cout<<temp->data;
        for(int i=0;temp->next[i]!=NULL;i++){
            j =temp->next[i]->data-1;
            if(visited1[j]==0){
                s1.push(arr[j]);
                visited1[j]=1;
            }
        }
    }
    
}
		
};
int main(){
	graph g(4);
	int x,y;
	for(int i=0;i<3;i++){
		cout<<"enter egdes vertices : ";
		cin>>x>>y;
		g.addedge(x-1,y-1);
	}
	g.adjlist();
	cout<<endl;
	g.bfs();
	g.adjmatrix();
	g.dfs();
	
	return 0;
}
