//Shell sort // 

#include<iostream>
#include<string>
using namespace std;
template<class T>
class shellsortcpp{
private:
    T *A;int n;
public:
void shellSort() { 
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap ; i < n ; i += 1) {
            for (int j = i - gap ; j>=0 ; j -= gap) {
            	if( A[j+gap ] > A[ j ]){
            		break;
				}
				else{
					swap( A[ j+gap ] , A[ j ] );
				}
            }
        }
    }
}

void display(){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<" [ "<<A[i]<<" ] ";
    }
}

void input(){
    cout<<"Enter the no. of elements : ";
    cin>>n;
    A=new T[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter element "<<i+1<<" : ";
        cin>>A[i];
    }
}
};
int main(){
    int ch;
    while(ch!=5){
        cout<<"\n\nEnter the choice from below : \n";
        cout<<"1.integer \n2.float \n3.string \n4.char\n5.Exit\n";
        cin>>ch;
        if(ch==1){
            shellsortcpp<int> a;
            a.input();
            cout<<"\nbefore sorting\n";
            a.display();
            a.shellSort();
            cout<<"\nAfter sorting\n";
            a.display();
        }
        else if(ch==2){
            shellsortcpp<float> b;
            b.input();
            cout<<"\nbefore sorting\n";
            b.display();
            b.shellSort();
            cout<<"\nAfter sorting\n";
            b.display();
        }
        else if(ch==3){
            shellsortcpp<string> c;
            c.input();
            cout<<"\nbefore sorting\n";
            c.display();
            c.shellSort();
            cout<<"\nAfter sorting\n";
            c.display();
        }
        else if(ch==4){
            shellsortcpp<char> d;
            d.input();
            cout<<"\nbefore sorting\n";
            d.display();
            d.shellSort();
            cout<<"\nAfter sorting\n";
            d.display();
        }
        else if(ch==5){
            cout<<"*** program exited ***\n";
            break;
        }
        
    }
    return 0;
}
/*
output::
Enter the choice from below : 
1.integer 
2.float 
3.string 
4.char
5.Exit
1
Enter the no. of elements : 5

Enter element 1 : 5

Enter element 2 : 4

Enter element 3 : 3

Enter element 4 : 2

Enter element 5 : 1

before sorting

 [ 5 ]  [ 4 ]  [ 3 ]  [ 2 ]  [ 1 ] 
After sorting

 [ 1 ]  [ 2 ]  [ 3 ]  [ 4 ]  [ 5 ] 

Enter the choice from below : 
1.integer 
2.float 
3.string 
4.char
5.Exit
2
Enter the no. of elements : 5

Enter element 1 : 1.1

Enter element 2 : 1.5

Enter element 3 : 1.4

Enter element 4 : 1.3

Enter element 5 : 1.2

before sorting

 [ 1.1 ]  [ 1.5 ]  [ 1.4 ]  [ 1.3 ]  [ 1.2 ] 
After sorting

 [ 1.1 ]  [ 1.2 ]  [ 1.3 ]  [ 1.4 ]  [ 1.5 ] 

Enter the choice from below : 
1.integer 
2.float 
3.string 
4.char
5.Exit
3
Enter the no. of elements : 3

Enter element 1 : om

Enter element 2 : advait

Enter element 3 : saish

before sorting

 [ om ]  [ advait ]  [ saish ] 
After sorting

 [ advait ]  [ om ]  [ saish ] 

Enter the choice from below : 
1.integer 
2.float 
3.string 
4.char
5.Exit
4
Enter the no. of elements : 4

Enter element 1 : d

Enter element 2 : c

Enter element 3 : b

Enter element 4 : a

before sorting

 [ d ]  [ c ]  [ b ]  [ a ] 
After sorting

 [ a ]  [ b ]  [ c ]  [ d ] 

Enter the choice from below : 
1.integer 
2.float 
3.string 
4.char
5.Exit
5
*** program exited ***
*/
