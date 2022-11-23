//Create a sorted link list class in c++

#include <iostream> 
using namespace std;
class Node { 
public: 
    int data; 
    Node* next; 
}; 

class LinkedList { 
private: 
int v;   //for values
    Node* head; 
  
public: 
    LinkedList() 
    { 
        head = NULL; 
    }    
    void print() 
    { 
        Node* temp = head; 
        while (temp != NULL) { 
            cout << temp->data << " "<<endl; 
            temp = temp->next; 
        } 
    } 
    void sortedInsert( int v) 
    { 
        Node* new_node = new Node();  
      new_node->data = v; 
        if (head == NULL) 
        { 
            new_node->next = head; 
            head = new_node; 
        } 
  
        
        else if (head->data >= new_node->data) { 
            new_node->next = head; 
            head = new_node; 
        } 
  
        else { 
            
            Node* current = head; 
  
            
            while (current->next != NULL && 
                   current->next->data < new_node->data) { 
                current = current->next; 
            } 
  
            
            new_node->next = current->next; 
  
            
            current->next = new_node; 
        } 
    } 
}; 
  

int main() 
{ 
       int v,ch;
    LinkedList ll; 

    do{
     
        cout<<"1. ----insert a node-----"<<endl;
        cout<<"2.-----display a node----"<<endl;
        cout<<"3.-----delete-------"<<endl;
        cin>>ch;
        switch(ch)
        {
            case  1:  
            cout<<"--enter data for node--"<<endl;
            cin>>v;
                         ll.sortedInsert(v); 
            break;
             case 2: 
                        ll.print();         
            break;
             case 3: 
                       exit(1);
            break;
           

        }
    }while(ch!=4);
       return 0; 
}