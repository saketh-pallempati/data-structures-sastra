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
class CDLL
{
    head *h = new head;
    bool flag = false;
public:
    void insertHead(int val)
    {
        node *n = new node(val);
        if (h->count == 0)
        {
            n->next = n;
            n->prev = n;
            h->first = n;
            h->last = n;
            h->count++;
            return;
        }
        n->next = h->first;
        n->prev = h->last;
        h->first->prev = n;
        h->last->next = n;
        h->first = n;
        h->count++;
    }
    void insertEnd(int val)
    {
        node *n = new node(val);
        if (h->count == 0)
        {
            n->next = n;
            n->prev = n;
            h->first = n;
            h->last = n;
            h->count++;
            return;
        }
        n->next = h->first;
        n->prev = h->last;
        h->first->prev = n;
        h->last->next = n;
        h->last = n;
        h->count++;
    }
    void insertAfter(int val, int key)
    {
        node *n = new node(val);
        node *t = h->first;
        do
        {
            if (t->data == key)
            { 
                break;
            }
            t = t->next;
        } while (t != h->first);
        if (t == NULL)
        {
            cout << "Key not found" << endl;
        }

        n->prev = t;
        n->next = t->next;
        t->next->prev = n;
        t->next = n;
        if (t == h->last)
        {
            h->last = n;
        }
        h->count++;
        cout << "Head " << h->first->data << endl;
        cout << "Tail " << h->last->data << endl;
    }
    void display()
    {
        node *t = h->first;
        if (t == NULL)
        {
            cout<<"Empty"<<endl;
            return;
        }
        
        do
        {
            cout << t->data << "->";
            t = t->next;
        } while (t != h->first);
        cout << "NULL" << endl;
    }
    void displayReverse()
    {
        node *t = h->last;
        if (t == NULL)
        {
            cout<<"Empty"<<endl;
            return;
        }
        
        do
        {
            cout << t->data << "->";
            t = t->prev;
        } while (t != h->last);
        cout << "NULL" << endl;
    }
    void search(int key)
    {
        node *t = h->first;
        do
        {
            if (t->data == key)
            {
                cout << "Found" << endl;
                return;
            }
            t = t->next;
        } while (t != h->first);
        cout << "Nope" << endl;
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
    void removeCDLL(int key)
    {
        node *t = h->first;
        do
        {
            if (t->data == key)
            {
                flag = true;
                break;
            }
            t = t->next;
        } while (t != h->first);
        if (flag == false)
        {
            cout << "Key not found" << endl;
            return;
        }
        if (h->count == 1)
        {
            h->first = h->last = NULL;
        }
        if (t == h->first)
        {
            h->first = t->next;
        }
        if (t == h->last)
        {
            h->last = t->prev;
        }
        t->next->prev = t->prev;
        t->prev->next = t->next;
        h->count--;
        delete t;
    }
};
int main()
{
    CDLL obj;
    int x, choice, key;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> x;
            obj.insertHead(x);
            break;
        case 2:
            cin >> x;
            obj.insertEnd(x);
            break;
        case 3:
            cout << "Enter data" << endl;
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
            cin >> key;
            obj.search(key);
            break;
        case 7:
            obj.cnt();
            break;
        case 8:
            obj.isEmpty();
            break;
        case 9:
            cin >> key;
            obj.removeCDLL(key);
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            break;
        }
    } while (choice != 0);
}
