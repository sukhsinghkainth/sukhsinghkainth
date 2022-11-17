
#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * start;

class double_llist
{
public:
    void create_list(int value);
    void add_begin(int value);

    void delete_element(int value);

    void display_dlist();

    double_llist()
    {
        start = NULL;
    }
};

int main()
{
    int choice, element, position;
    double_llist dl;
    while (1)
    {

        cout << endl
             << "Operations on Doubly linked list" << endl;

        cout << "1.Create Node" << endl;
        cout << "2.Add at begining" << endl;

        cout << "4.Delete" << endl;
        cout << "5.Display" << endl;

        cout << "8.cuit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> element;
            dl.create_list(element);
            cout << endl;
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> element;
            dl.add_begin(element);
            cout << endl;
            break;

        case 4:
            if (start == NULL)
            {
                cout << "List empty,nothing to delete" << endl;
                break;
            }
            cout << "Enter the element for deletion: ";
            cin >> element;
            dl.delete_element(element);
            cout << endl;
            break;
        case 5:
            dl.display_dlist();
            cout << endl;
            break;

        case 8:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}
void double_llist::create_list(int value)
{
    struct node *s, *temp;
    temp = new (struct node);
    temp->data = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

void double_llist::add_begin(int value)
{
    if (start == NULL)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct node *temp;
    temp = new (struct node);
    temp->prev = NULL;
    temp->data = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout << "Element Inserted" << endl;
}

void double_llist::delete_element(int value)
{
    struct node *tmp, *c;

    if (start->data == value)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout << "Element Deleted" << endl;
        free(tmp);
        return;
    }
    c = start;
    while (c->next->next != NULL)
    {
        /*Element deleted in between*/
        if (c->next->data == value)
        {
            tmp = c->next;
            c->next = tmp->next;
            tmp->next->prev = c;
            cout << "Element Deleted" << endl;
            free(tmp);
            return;
        }
        c = c->next;
    }
    /*last element deleted*/
    if (c->next->data == value)
    {
        tmp = c->next;
        free(tmp);
        c->next = NULL;
        cout << "Element Deleted" << endl;
        return;
    }
    cout << "Element " << value << " not found" << endl;
}


void double_llist::display_dlist()
{
    struct node *c;
    if (start == NULL)
    {
        cout << "List empty,nothing to display" << endl;
        return;
    }
    c = start;
    cout << "The Doubly Link List is :" << endl;
    while (c != NULL)
    {
        cout << c->data << " <-> ";
        c = c->next;
    }
    cout << "NULL" << endl;
}
