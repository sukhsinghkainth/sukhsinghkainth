#include <iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
} * last;

class circular_llist
{
public:
    void create_node(int value);
    void add_begin(int value);

    void delete_element(int value);

    void display_list();
};

int main()
{
    int choice, element, position;
    circular_llist cl;
    do
    {

        cout << endl
             << "Circular singly linked list" << endl;

        cout << "1.Create Node" << endl;
        cout << "2.Add at beginning" << endl;

        cout << "3.Delete" << endl;

        cout << "4.Display" << endl;
        cout << "5.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> element;
            cl.create_node(element);
            cout << endl;
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> element;
            cl.add_begin(element);
            cout << endl;
            break;

        case 3:
            if (last == NULL)
            {
                cout << "List is empty, nothing to delete" << endl;
                break;
            }
            cout << "Enter the element for deletion: ";
            cin >> element;
            cl.delete_element(element);
            cout << endl;
            break;

        case 4:
            cl.display_list();
            break;

        case 5:
            exit(1);
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    } while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
    return 0;
}

void circular_llist::create_node(int value)
{
    struct node *temp;
    temp = new (struct node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void circular_llist::add_begin(int value)
{
    if (last == NULL)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct node *temp;
    temp = new (struct node);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}

void circular_llist::delete_element(int value)
{
    struct node *temp, *s;
    s = last->next;
    /* If List has only one element*/
    if (last->next == last && last->info == value)
    {
        temp = last;
        last = NULL;
        free(temp);
        return;
    }
    if (s->info == value) /*First Element Deletion*/
    {
        temp = s;
        last->next = s->next;
        free(temp);
        return;
    }
    while (s->next != last)
    {
        /*Deletion of Element in between*/
        if (s->next->info == value)
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout << "Element " << value;
            cout << " deleted from the list" << endl;
            return;
        }
        s = s->next;
    }
    /*Deletion of last element*/
    if (s->next->info == value)
    {
        temp = s->next;
        s->next = last->next;
        free(temp);
        last = s;
        return;
    }
    cout << "Element " << value << " not found in the list" << endl;
}

void circular_llist::display_list()
{
    struct node *s;
    if (last == NULL)
    {
        cout << "List is empty, nothing to display" << endl;
        return;
    }
    s = last->next;
    cout << "Circular Link List: " << endl;
    while (s != last)
    {
        cout << s->info << "->";
        s = s->next;
    }
    cout << s->info << endl;
    return;
}
