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
node *front = NULL;
node *rear = NULL;
void enqueue(int val)
{
    node *n = new node(val);
    if (front == NULL)
    {
        front = n;
        rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue underflow" << endl;
        return;
    }
    else
    {
        node *temp = front;
        front = front->next;
        cout << "Popped = " << temp->data << endl;
        free(temp);
    }
}
void queueFront()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue Front = " << front->data << endl;
    }
}
void queueRear()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue Rear = " << rear->data << endl;
    }
}
void display()
{
    node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void empty()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
}
int main()
{
    int x, val;
    do
    {
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Enter" << endl;
            cin >> val;
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            queueFront();
            break;
        case 4:
            queueRear();
            break;
        case 5:
            display();
            break;
        case 6:
            empty();
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    } while (x != 0);
}
