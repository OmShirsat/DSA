#include<iostream>
#include<string>
using namespace std;
class heap{
	int arr[10],Maxheap[10],Minheap[10],top;
	public:
		void input(int n){
			for(int i=0;i<n;i++){
				cout<<"Enter the marks : ";
				cin>>arr[i];
				top=i;
				
			}
			
		}
		void insert(int n){
			arr[++top]=n;
			heapify(top+1);
		}
		void heapify(int n){
		    for(int i=1;i<n;i++){
		        //comparing child and parent node
		        if(arr[i]>arr[(i-1)/2]){
		            int j=i;
		            while(arr[j]>arr[(j-1)/2]){
		                swap(arr[j],arr[(j-1)/2]);
		                j=(j-1)/2;
		               
		            }
		        }
		       
		    }
		}
		void heapsort(){
		        while(top>=0){
		            swap(arr[0],arr[top]);
		            top--;
		            heapify(top+1);
		        }
		}
	
		void display(){
		    cout<<endl;
			for(int i=0;i<7;i++){
				cout<<" : "<<arr[i];
			}
		}
	
};
int main(){
	heap h;
	h.input(7);
	h.display();
	cout<<endl;
	h.heapify(7);
	h.heapsort();
	h.display();
	
	return 0;
}
