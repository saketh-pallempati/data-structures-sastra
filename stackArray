#include <iostream>
using namespace std;
class Stack
{
public:
    int n;
    int *arr;
    int top;
    Stack(int val)
    {
        n = val;
        arr = new int[n];
        top = -1;
    }
    void push(int value)
    {
        if (top >= n - 1)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Popped:" << arr[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "The elements are " << endl;
            for (int i = top; i > -1; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    void stackTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Top = " << arr[top] << endl;
        }
    }
    void emptyStacK()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack is not empty" << endl;
        }
    }
    void fullStack()
    {
        if (top >= n - 1)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            cout << "Stack is not full" << endl;
        }
    }
    void stackCount()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Count = " << top + 1 << endl;
        }
    }
    void search(int target)
    {
        bool found = false;
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                if (arr[i] == target)
                {
                    found = true;
                    cout << "Found" << endl;
                }
            }
            if (found == false)
            {
                cout << "The element is not found" << endl;
            }
        }
    }
};
int main()
{
    int maxsize;
    cout << "Enter Max size of the stack " << endl;
    cin >> maxsize;
    Stack obj(maxsize);
    int x;
    cout << "1. Push 2. Pop 3. Display 4.Top 5. Empty 6. Full 7. Count 8. Search 0. Exit" << endl;
    do
    {
        cin >> x;
        switch (x)
        {
        case 1:
            int dataIn;
            cout << "Enter element to be pushed" << endl;
            cin >> dataIn;
            obj.push(dataIn);
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            obj.stackTop();
            break;
        case 5:
            obj.emptyStacK();
            break;
        case 6:
            obj.fullStack();
            break;
        case 7:
            obj.stackCount();
            break;
        case 8:
            int target;
            cout << "Enter Target" << endl;
            cin >> target;
            obj.search(target);
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        }
    } while (x != 0);
    return 0;
}
