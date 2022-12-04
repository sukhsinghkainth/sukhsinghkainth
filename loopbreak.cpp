// find loop in link list , if find loop then break it.
#include <iostream>
using namespace std;
struct node {
    int data;
    node *next;
};

class linkList{
    private:
        node *head, *tail;
    public:
        linkList(){
            head = NULL;
            tail = NULL;
        }
 
        // Function to insert a node
        void insert(int n){
            node *temp = new node;
            temp->data = n;
            temp->next = NULL;
            if (head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }
     void createloop()
   {
    tail->next=head->next->next;
   }
        
        // Function to detect loop in the link list
        bool DetectLoop(){
            node *slow = head;
            node *fast = head;
            while (slow && fast && fast->next){
                fast = fast->next->next;
                slow = slow->next;
                if (slow == fast){
                    return true;
                 }
            }
            return false;
        }
        
        // Function to break the loop in the link list
        void BreakLoop(){
            node *slow = head;
            node *fast = head;
            while (slow && fast && fast->next){
                fast = fast->next->next;
                slow = slow->next;
             if (slow == fast){
                    fast = head;
            while (fast->next != slow->next){
                        fast = fast->next;
                        slow = slow->next;
                    }
                    slow->next = NULL;
                 }
            }
        }
                // Function to display the link list
        void Display(){
            node *temp = head;
            while(temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << endl;
        }
};
 
// Main function
int main(){
    linkList l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(7);
    l.insert(8);
    l.insert(9);
    l.insert(10);
 
    // Create a loop in the list
    l.createloop();
 
    // Detect loop in the list
    if(l.DetectLoop()){
        cout<<"Loop detected in the list"<<endl;
        l.BreakLoop();
        cout<<"Loop broken in the list"<<endl;
    }
    else
        cout<<"No loop detected in the list"<<endl;
 
    // Display the list
    l.Display();
    return 0;
}