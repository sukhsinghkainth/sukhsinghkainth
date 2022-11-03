#include<iostream>
#define maxqueue 3
using namespace std;

class queue{
private: int front,rear;
int items[maxqueue];
public:
queue()
{
    front =0; rear =-1;
    
}
  int insert (int x)
{   
    
    if(rear==maxqueue-1)
    {
        cout<<"\nqueue is full\n";
        return 0;
   }
    else
    {
        rear++;
        items[rear]=x;
        
    }
}
 int del()
 { int v;  
    if( front>rear )
    {
        cout<<"\nqueue is empty\n";
        return 0;
       
    }
    else
    {  
    
      v=items[front];
      front++;
        return v;
 }
 }


};
int main()
{ 
  queue q1;  //object to execute stack constructor
  int click1;
    int value;
    int v, x;

    do
    {
        cout << "--1  for insert in queue" << endl;
        cout << "--2 for delete from queue" << endl;
        cout << "--3 exit" << endl;
      
        cin >> click1;

        switch (click1)
        {
        case 1:
            cout << "enter value you want to insert in queue" << endl;
            cin >> value;
            q1.insert(value);

            break;

        case 2:
            x = q1.del();
            cout << "---- value is ---\n" << x << endl;

            break;


        case 3:

            return 0;
            break;
        }

    } while (click1 == 1 || click1 == 2 || click1 == 3);
}  
  
    
