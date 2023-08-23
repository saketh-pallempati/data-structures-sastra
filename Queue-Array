#include <iostream>
using namespace std;
class Queue
{
public:
    int front, rear;
    int *arr;
    int size;
    Queue(int val)
    {
        size = val;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
    {
        if (rear >= size - 1)
        {
            cout << "Queue Full" << endl;
        }
        else
        {
            if (rear == -1)
            {
                front++;
            }
            rear++;
            arr[rear] = data;
            cout << arr[rear] << endl;
        }
    }
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else if (front == rear)
        {
            cout << "Dequeued element = " << arr[front] << endl;
            front = rear = -1;
        }

        else
        {
            cout << "Dequeued element = " << arr[front] << endl;
            front++;
        }
    }
    void display()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue elements are : ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    void queueFront()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Front = " << arr[front] << endl;
        }
    }
    void queueRear()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Rear = " << arr[rear] << endl;
        }
    }
    void empty()
    {
        if (rear == -1 || front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue is not empty" << endl;
        }
    }
    void full()
    {
        if (rear >= size - 1)
        {
            cout << "Queue Full" << endl;
        }
        else
        {
            cout << "Queue is not full" << endl;
        }
    }
    void count()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Count = " << rear - front + 1;
        }
    }
};
int main()
{
    int size;
    int x;
    cout << "Enter the max size of queue: ";
    cin >> size;
    Queue obj(size);
    cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Queue Front\n5.Queue Rear\n6.Empty\n7.Full\n8.Count\n0.Exit" << endl;
    do
    {
        cin >> x;
        switch (x)
        {
        case 1:
            int dataIn;
            cout << "Enter the data to be enqueued: ";
            cin >> dataIn;
            obj.enqueue(dataIn);
            break;
        case 2:
            obj.dequeue();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            obj.queueFront();
            break;
        case 5:
            obj.queueRear();
            break;
        case 6:
            obj.empty();
            break;
        case 7:
            obj.full();
            break;
        case 8:
            obj.count();
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            break;
        }
    } while (x != 0);
    return 0;
}
