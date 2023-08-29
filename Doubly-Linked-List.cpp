#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class head
{
    public:
    int count;
    node *first;
    node *last;
    head()
    {
        count = 0;
        first = NULL;
        last = NULL;
    }
};

class DLL
{
    head *h = new head;

public:
    void insertAtHead(int val)
    {
        node *n = new node(val);
        if (h->count == 0)
        {
            h->first = n;
            h->last = n;
            h->count++;
            return;
        }
        n->next = h->first;
        n->prev = NULL;
        h->first->prev = n;
        h->first = n;
        h->count++;
    }
    void insertAtEnd(int val)
    {
        node *n = new node(val);
        if (h->count == 0)
        {
            h->first = n;
            h->last = n;
            h->count++;
            return;
        }
        n->prev = h->last;
        n->next = NULL;
        h->last->next = n;
        h->last = n;
        h->count++;
    }
    void insertAfter(int val, int key)
    {
        node *n = new node(val);
        node *t = h->first;
        while (t != NULL)
        {
            if (t->data == key)
            {
                break;
            }
            t = t->next;
        }
        if (t == NULL)
        {
            cout << "Key not found" << endl;
            return;
        }

        n->prev = t;
        n->next = t->next;
        if (t->next != NULL)
        {
            t->next->prev = n;
        }
        t->next = n;
        h->count++;
    }
    void display()
    {
        node *t = h->first;
        while (t != NULL)
        {
            cout << t->data << "->";
            t = t->next;
        }
        cout << "NULL" << endl;
    }
    void displayReverse()
    {
        node *t = h->last;
        while (t != NULL)
        {
            cout << t->data << "->";
            t = t->prev;
        }
        cout << "NULL" << endl;
    }
    void cnt()
    {
        cout << h->count << endl;
    }
    void isEmpty()
    {
        if (h->count == 0)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << "Nope" << endl;
        }
    }
    void searchDLL(int key)
    {
        node *t = h->first;
        while (t != NULL)
        {
            if (t->data == key)
            {
                cout << "Found" << endl;
                return;
            }
            t = t->next;
        }
        cout << "Key not found" << endl;
    }
    void removeDLL(int key)
    {
        node *t = h->first;
        while (t != NULL)
        {
            if (t->data == key)
            {
                break;
            }
            t = t->next;
        }
        if (t == NULL)
        {
            cout << "Key not found" << endl;
            return;
        }
        if (h->count == 1)
        {
            h->first = h->last = NULL;
        }

        else if (t == h->first)
        {
            h->first = t->next;
            t->next->prev = NULL;
        }
        else if (t == h->last)
        {
            h->last = t->prev;
            t->prev->next = NULL;
        }
        else
        {
            t->prev->next = t->next;
            t->next->prev = t->prev;
            delete t;
        }
        h->count--;
    }
};
int main()
{
    DLL obj;
    int choice;
    int x, key;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> x;
            obj.insertAtHead(x);

            break;
        case 2:
            cin >> x;
            obj.insertAtEnd(x);
            break;
        case 3:
            cout << "Enter value" << endl;
            cin >> x;
            cout << "Enter key" << endl;
            cin >> key;
            obj.insertAfter(x, key);
            break;
        case 4:
            obj.display();
            break;
        case 5:
            obj.displayReverse();
            break;
        case 6:
            cin >> x;
            obj.searchDLL(x);
            break;
        case 7:
            obj.cnt();
            break;
        case 8:
            obj.isEmpty();
            break;
        case 9:
            cin >> x;
            obj.removeDLL(x);
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "invalid choice" << endl;
            break;
        }
    } while (choice != 0);
}
