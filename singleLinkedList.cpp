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
node *head = NULL;
int count = 0;
void insertBeggining(int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
    count++;
}
void insertTail(int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        count++;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    count++;
}
void insertafterkey(int val, int key)
{
    node *n = new node(val);
    if (head->data == key)
    {
        n->next = head->next;
        head->next = n;
        count++;
        return;
    }
    node *t = head;
    while (t->data != key)
    {
        t = t->next;
        if (t == NULL)
        {
            cout << "Key is not present" << endl;
            return;
        }
    }
    n->next = t->next;
    t->next = n;
    count++;
}
void remove(int key)
{
    node *temp = head;
    node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Key is not found" << endl;
        return;
    }

    if (prev == NULL)
    {
        head = head->next;
        count--;
    }
    else
    {
        prev->next = temp->next;
        count--;
    }
    free(temp);
}
void search(int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not found" << endl;
}
void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}
int main()
{
    int x = -1;
    do
    {
        cin >> x;
        switch (x)
        {
        case 1:
            int val;
            cout << "Enter " << endl;
            cin >> val;
            insertBeggining(val);
            break;
        case 2:
            cout << "Enter " << endl;
            cin >> val;
            insertTail(val);
            break;
        case 3:
            int key;
            cout << "Enter " << endl;
            cin >> val;
            cout << "Key " << endl;
            cin >> key;
            insertafterkey(val, key);
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Key " << endl;
            cin >> key;
            search(key);
            break;
        case 6:
            cout << "Key " << endl;
            cin >> key;
            remove(key);
            break;
        case 7:
            cout << "List count  = " << count << endl;
            break;
        case 0:
            cout << "Exit " << endl;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    } while (x != 0);
}
