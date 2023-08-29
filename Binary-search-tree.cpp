#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
	node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};
bool isEmpty(node *root)
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
node *insertBST(node *root, int value)
{
	node *n = new node(value);
	if (root == NULL)
	{
		return n;
	}
	else
	{
		if (value < root->data)
		{
			root->left = insertBST(root->left, value);
		}
		else
		{
			root->right = insertBST(root->right, value);
		}
	}
	return root;
}
void inOrder(node *root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}
void preOrder(node *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(node *root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}
node *searchBST(node *root, int key)
{
	if (root == NULL)
	{
		cout << "Nope" << endl;
		return root;
	}

	if (root->data == key)
	{
		cout << "Found" << endl;
		return root;
	}
	else if (root->data < key)
	{
		searchBST(root->right, key);
	}
	else
	{
		searchBST(root->left, key);
	}
}
node *minBST(node *root)
{
	node *temp = root;
	while (temp != NULL && temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}
node *maxBSt(node *root)
{
	node *temp = root;
	while (temp != NULL && temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}
node *deleteBST(node *root, int key)
{
	if (root == NULL)
	{
		return root;
	}
	if (root->data < key)
	{
		root->right = deleteBST(root->right, key);
	}
	else if (root->data > key)
	{
		root->left = deleteBST(root->left, key);
	}
	else
	{
		if (root->left == NULL)
		{
			node *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			node *temp = root->left;
			delete root;
			return temp;
		}
		node *temp = minBST(root->right);
		root->data = temp->data;
		deleteBST(root->right, temp->data);
	}
	return root;
}
int main()
{
	node *root = NULL;
	int choice = -1;
	int x;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Enter " << endl;
			cin >> x;
			root = insertBST(root, x);
			break;
		}
		case 2:
		{
			cout << "Enter " << endl;
			cin >> x;
			root = deleteBST(root, x);
			break;
		}
		case 3:
		{
			cout << "Enter " << endl;
			cin >> x;
			searchBST(root, x);
			break;
		}
		case 4:
		{
			cout << "Largest = " << maxBSt(root)->data;
			break;
		}
		case 5:
		{
			cout << "Smallest = " << minBST(root)->data;
			break;
		}
		case 6:
		{
			cout << "PreOrder " << endl;
			preOrder(root);
			cout << endl;
			break;
		}
		case 7:
		{
			cout << "Inorder " << endl;
			inOrder(root);
			cout << endl;
			break;
		}
		case 8:
		{
			cout << "PostOrder " << endl;
			postOrder(root);
			cout << endl;
			break;
		}
		case 0:
		{
			cout << "Bye " << endl;
			break;
		}
		default:
			break;
		}
	} while (choice != 0);
	return 0;
}
