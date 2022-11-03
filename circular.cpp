#include <iostream>
#define maxqueue 3
using namespace std;

class queue
{
private:
    int front, rear;
    int items[maxqueue];

public:
    queue() // constructor
    {
        front = -1;
        rear = -1;
    }
    void insert(int x)
    {
        // overflow conditions
        if ((rear == maxqueue - 1 && front == 0) || rear + 1 == front)

        {
            cout << "/////// overflow ///////" << endl;
            return;
        }
        if (rear == maxqueue - 1)

        {
            rear = 0;
        }
        else
            rear++;
        items[rear] = x;
        if (front == -1)
            front = 0;
    }
    int del()
    {
        int v;
        if (front == -1)
        {
            cout << "/////////   underflow  /////////////" << endl;
            return NULL;
        }
        if (front == rear)
        {
            v = items[front];
            front = -1;
            rear = -1;
        }
        else
        {
            v = items[front];
            if (front == maxqueue - 1)
                front = 0;
            else
                front++;
        }
        return v;
    }
};
int main()
{
    queue q1; // object to execute stack constructor
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
            cout << "value is :----" << x << endl;

            break;

        case 3:

            return 0;
            break;
        }

    } while (click1 == 1 || click1 == 2 || click1 == 3);
}
