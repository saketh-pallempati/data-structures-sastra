#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
node *top = NULL;
void push(int val)
{
    node *temp = new node(val);
    temp->next = top;
    top = temp;
}
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    node *temp = top;
    top = top->next;
    cout << "Popped = " << temp->data << endl;
    delete (temp);
}
void topStack()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Top = " << top->data << endl;
}
void emptyStack()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack is not empty" << endl;
}

void display()
{
    node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    int x = -1;
    int val;
    do
    {
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Enter" << endl;
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            topStack();
            break;
        case 5:
            emptyStack();
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    } while (x != 0);
}
