#include <iostream>
using namespace std;

int linear(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}
int linearRec(int arr[], int n, int key)
{

    n = n - 1;
    if (n < 0)
    {
        return -1;
    }
    if (arr[n] == key)
    {
        return n;
    }
    else
    {
        return linearRec(arr, n, key);
    }
}
int binary(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int binaryRec(int arr[], int start, int end, int key)
{
    int mid = (start + end) / 2;
    {
        if (start > end)
        {
            return -1;
        }
        else if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            return binaryRec(arr, mid + 1, end, key);
        }
        else
        {
            return binaryRec(arr, start, mid - 1, key);
        }
    }
}
int main()
{
    int x;
    int n, key, ans;
    cout << "Enter length of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter key " << endl;
    cin >> key;
    cout << "Enter \n 1 for Liner iterative \n 2 for Linear Recursion \n 3 for Binary serach \n 4 for Binary Recursion" << endl;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        ans = linear(arr, n, key);
        break;
    }
    case 2:
    {
        ans = linearRec(arr, n, key);
        break;
    }
    case 3:
    {
        ans = binary(arr, n, key);
        break;
    }
    case 4:
    {
        ans = binaryRec(arr, 0, n - 1, key);
        break;
    }
    default:
    {
        break;
    }
    }
    if (ans == -1)
    {
        cout << "Element is not found in the array " << endl;
    }
    else
    {
        cout << "Index of the element is " << ans << endl;
    }
}
