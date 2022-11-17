#include <iostream>
#define max 10
using namespace std;
class stack
{
private:
    int arr[max];
    int top;

public:
    stack() // constructor
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == max - 1)
        {
            cout << "-----stack is overflow----" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }
    int pop()
    {

        if (top == -1)
        {
            cout << "----stack is underflow---" << endl;
            return 0;
        }
        else
        {
            int v; // temp variable for stre pop value
            v = arr[top];
            top--;
            return v;
        }
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "----stack is underflow---" << endl;
            return 0;
        }
        else
        {
            return arr[top];
        }
    }
};

int main()
{
    stack s1; // object to execute stack constructor
    int click1;
    int value;
    int v, x;

    do
    {
        cout << "--1  for push operation in stack" << endl;
        cout << "--2 for pop operation in stack" << endl;
        cout << "--3 for view the peek value" << endl;
        cout << "--4 exit" << endl;
        cin >> click1;

        switch (click1)
        {
        case 1:
            cout << "enter value you want to insert in stack" << endl;
            cin >> value;
            s1.push(value);

            break;

        case 2:
            x = s1.pop();
            cout << "---- value is ----" << x << endl;

            break;

        case 3:
            v = s1.peek();
            cout << "the peek value is " << v << endl;

            break;

        case 4:

            return 0;
            break;
        }

    } while (click1 == 1 || click1 == 2 || click1 == 3);
}
