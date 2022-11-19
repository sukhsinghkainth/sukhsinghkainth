
#include <iostream>

using namespace std;
void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
int dequeue();
void display();
void create();
 
int st1[5], st2[5];
int top1 = -1, top2 = -1;
int count = 0;
 
int main()
{
    int ch;
 do{
    cout<<"1 - insert"<<endl;
    cout<<"2 - delete"<<endl;
    cout<<"3 - Display from queue"<<endl;
    cout<<"4 - Exit"<<endl;
    cout<<"Enter choice"<<endl;
  
    cin>>ch;
  
     
     
        switch (ch)
        {
        case 1:
            enqueue();
           
            break;
        case 2:
            dequeue();
          display();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    while(ch!=5);
}
 
/*Function to create a queue*/
void create()
{
    top1 = top2 = -1;
}
 
/*Function to push the element on to the stack*/
void push1(int data)
{
    st1[++top1] = data;
}
 
/*Function to pop the element from the stack*/
int pop1()
{
    return(st1[top1--]);
}
 
/*Function to push an element on to stack*/
void push2(int data)
{
    st2[++top2] = data;
}
 
/*Function to pop an element from th stack*/
 
int pop2()
{
    return(st2[top2--]);
}
 
/*Function to add an element into the queue using stack*/
void enqueue()
{
    int data, i;
 
    cout<<"Enter data into queue"<<endl;
    cin>>data;
    push1(data);
    count++;
}
 
/*Function to delete an element from the queue using stack*/
 
int dequeue()
{
    int i,x;
 if( count==0)
 {
     cout<<"-----"<<endl;
    cout<< "underflow"<<endl;
   cout<<"-----"<<endl;
    
    return 1; 
    }

    for (i = 0;i <= count;i++)
    {
        push2(pop1());
        
    }
    pop2();
   
    count--;
    for (i = 0;i <= count;i++)
    {
       push1(pop2());
      
    }
   
    
}
 
/*Function to display the elements in the stack*/
 
void display()
{   
    int i;
 if(count==0)
 {
     cout<<"-----"<<endl;
    cout<< "underflow"<<endl;
   cout<<"-----"<<endl;
    return ; 
    }
    for (i = 0;i <= top1;i++)
    {
       
        cout<<st1[i]<<endl;
          cout<<"--"<<endl;
    }
}
