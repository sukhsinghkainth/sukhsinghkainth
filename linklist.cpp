#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class list
{

private:
    node *head;
    int length;

public:
    list()
    {
        head = nullptr;
        length=0;
    }
    ~list(){}
    void addfirst(int n)
    {
        node *temp;
        temp = new node();
        temp->data = n;
        temp->next = head;
        head = temp;
        length++;
        return;
    }
    void addlast(int n)
    {  
          if(head==nullptr)
    { cout<<"-----list is empty----"<<endl;
    return;
    }
        node *cur, *prev;
        cur = head;
        while (cur != nullptr)
        {
            prev = cur;
            cur = cur->next;
            
        }
        node *temp = new node();
        temp->data = n;
        temp->next = nullptr;
        prev->next = temp;
        length++;
        return;
       
    };
    void position(int p, int n)  
 {    length++;
    if(p==1)		
		{
			addfirst(n);
			return;
		}
       
        if(p==length){
            addlast(n);
            return;
        }
     if(head==nullptr)
    { cout<<"-----list is empty----"<<endl;
    return;
    }
       node *cur, *prev;
        cur = head;
        	if(p>length)	
			{cout<<"\n---position not exist---\n";
              return;}

		
        
        for (int i = 0; i < p - 1; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        node *temp = new node();
        temp->data = n;
        temp->next = cur;
        prev->next=temp;
       
    };
  void after(int n ,int p)
  {     node *cur=head, *prev=NULL,  *next=cur->next;
        while (next!=nullptr)
       
        {   if(cur->data==n)
        {   node *temp = new node();
         cur->next=temp;
        temp->data = p;
        temp->next = next;
        return;
       
        }
            prev = cur;
            cur=next;
            next=next->next;
        }
  
  
       }
		
    

   void diplay(){
    if(head==nullptr)
    { cout<<"-----list is empty----"<<endl;
    return;
    }
    node* cur;
    cur=head;
    while(cur!=nullptr){
        cout<<cur->data<<endl<<"-"<<endl;
        cur=cur->next;
    }

    }
};
int main()
{                   
    list l;
    int p,v,val,pos;
 int click,click2;
 do{
    cout<<"do you want to inset in link list ??"<<endl;
    cout<<" 1 insert "<<endl<<"2 display link list"<<endl<<"enter you choice please"<<endl;
    cin>>click,click2;
    switch(click)
    {
        case 1:
        cout<<" enter value for new node -- "<<endl;
        cin>>v;
        cout<<"where do you want to enter"<<endl<<"1 at end"<<endl<<"2 at front"<<endl<<"3 perticular position"<<endl<<"4 after any value"<<endl;
        cin>>click2;
        switch(click2)
        {
            case 1: l.addlast(v);
            break;
            case 2: l.addfirst(v);
            break;
            case 3: cout<<"enter position"<<endl;
            cin>>pos;
            l.position(pos,v);
            break;
            case 4: cout<<"enter value that are already in list"<<endl;
            cin>>val;
             l.after(val,v);

        }
       break;
       case 2:
       l.diplay();

    }
 }
 while(click==1 ||click==2 ||click==3||click==4|| click2==1 || click2==2||click2==3 );

    return 0;
}