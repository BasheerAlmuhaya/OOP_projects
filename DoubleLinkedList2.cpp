#include <iostream>
using namespace std;

typedef int type;
// class nodes
class node
{
public:
	type data;
	node *next;
	node *prev;
	node(type d) : data(d), next(NULL), prev(NULL) {}
	node() : data(0), next(NULL), prev(NULL) {}
};
// class double linked list
class DLL
{
private:
	node *head, *tail;
	bool IsEmpty()
	{
		return (head == NULL && tail == NULL);
	}

public:
	DLL() : head(NULL), tail(NULL) {}

	node *getHead()
	{
		return (this->head);
	}
	void FirstShow();
	void AddFirst();
	void AddLast();
	void AddBefore();
	void AddAfter();
	void DeleteFirst();
	void DeleteLast();
	void DeleteData();
	void DeleteNode();
	void SearchList();
	int size(node *d);
	void Display(node *d);
	void DisplayReverse(node *d);
};
int DLL ::size(node *n)
{
	if (n == NULL)
		return 0;
	return (1 + size(n->next));
}
void DLL::FirstShow()
{
	int item;
	do
	{
		cout << "\n Some operation on Double linked list : \n \t#Press 0 to Exit#\n";
		cout << " 1-creat a node\n 2-Add first\n 3-Add last\n 4-Add before a node\n";
		cout << " 5-Add after a node\n 6-Delete first node\n 7-Delete last node\n";
		cout << " 8-Delete specific Data\n 9-Delete specific Node\n";
		cout << " 10-Search about node\n 11-Size of list\n";
		cout << " 12-Display list\n 13-Display list Reversly\n";
		cout << " Enter the number of operation you want\n";
		cin >> item;
		switch (item)
		{
		case 1:
			system("cls");
			AddFirst();
			break;
		case 2:
			system("cls");
			AddFirst();
			break;
		case 3:
			system("cls");
			AddLast();
			break;
		case 4:
			system("cls");
			AddBefore();
			break;
		case 5:
			system("cls");
			AddAfter();
			break;
		case 6:
			system("cls");
			DeleteFirst();
			break;
		case 7:
			system("cls");
			DeleteLast();
			break;
		case 8:
			system("cls");
			DeleteData();
			break;
		case 9:
			system("cls");
			DeleteNode();
			break;
		case 10:
			system("cls");
			SearchList();
			break;
		case 11:
			system("cls");
			cout << "Size of List = " << size(getHead());
			break;
		case 12:
			system("cls");
			Display(getHead());
			break;
		case 13:
			system("cls");
			DisplayReverse(getHead());
			break;
		case 0:
			system("cls");
			cout << "Thank you press any key to exit\n\n";
			return;
		default:
			system("cls");
			cout << "Oops !, make sure from your input\n";
		}
	} while (item != 0);
}
void DLL ::AddFirst()
{
	int x;
	cout << "\n Enter a data of new node\n";
	cin >> x;
	node *p = new node(x);
	if (IsEmpty())
	{
		head = tail = p;
		return;
	}
	p->next = head;
	head->prev = p;
	head = p;
}
void DLL ::AddLast()
{
	int x;
	cout << "\n Enter a data of new node\n";
	cin >> x;
	node *p = new node(x);
	if (IsEmpty())
	{
		head = tail = p;
		return;
	}
	p->prev = tail;
	tail->next = p;
	tail = p;
}
void DLL::AddBefore()
{
	int x, y;
	cout << "\n Enter a data of new node\n";
	cin >> x;
	node *p = new node(x);
	cout << "\n Enter the data you want to add before\n";
	cin >> y;
	if (IsEmpty())
	{
		head = tail = p;
		return;
	}
	node *current = head;
	if (current->data == y) // first node
	{
		p->next = head;
		head->prev = p;
		head = p;
		return;
	}
	while (current != NULL && current->data != y)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		cout << "node is not found\n";
		return;
	}
	p->next = current;
	p->prev = current->prev;
	current->prev->next = p;
	current->prev = p;
}
void DLL ::AddAfter()
{
	int x, y;
	cout << "\n Enter a data of new node\n";
	cin >> x;
	node *p = new node(x);
	cout << "\n Enter the data you want to add after\n";
	cin >> y;
	if (IsEmpty())
	{
		head = tail = p;
		return;
	}
	node *current = head;
	while (current != NULL && current->data != y)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		cout << "node is not found\n";
		return;
	}
	p->prev = current;
	p->next = current->next;
	current->next = p;
	current->next->prev = p;
}
void DLL ::DeleteFirst()
{
	if (IsEmpty())
	{
		cout << "Empty linked list\n";
		return;
	}
	node *p = head;
	int x = head->data;
	if (p->prev == NULL && p->next == NULL) // there is 1 node
	{
		delete p;
		head = tail = NULL;
		cout << " Number " << x << " is deleted \n";
		cout << " The list became Empty\n";
		return;
	}
	head = head->next;
	head->prev = NULL;
	delete p;
	cout << " Number " << x << " is deleted \n";
}
void DLL ::DeleteLast()
{
	if (IsEmpty())
	{
		cout << "Empty linked list\n";
		return;
	}
	node *p = tail;
	int x = tail->data;
	if (p->prev == NULL && p->next == NULL) // there is 1 node
	{
		delete p;
		head = tail = NULL;
		cout << " Number " << x << " is deleted \n";
		cout << " The list became Empty\n";
		return;
	}
	tail = tail->prev;
	tail->next = NULL;
	delete p;
	cout << " Number " << x << " is deleted \n";
}
void DLL ::DeleteData()
{
	if (IsEmpty())
	{
		cout << "Empty linked list\n";
		return;
	}
	int x;
	cout << " Enter the number you want to delete\n";
	cin >> x;
	node *cur = head;
	if (cur->data == x) // it is a First node
	{
		DeleteFirst();
		return;
	}
	while (cur != NULL && cur->data != x)
		cur = cur->next;
	if (cur == NULL)
	{
		cout << " Data doesn't exist\n";
		return;
	}
	if (cur->next == NULL) // it is a Last node
	{
		DeleteLast();
		return;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	delete cur;
	cout << " Number " << x << " is deleted\n";
}
void DLL::DeleteNode()
{
	if (IsEmpty())
	{
		cout << "Empty linked list\n";
		return;
	}
	int x, count = 1;
	cout << " Enter the number of node you want to delete\n";
	cin >> x;
	node *cur = head;
	if (x == 1) // it is a First node
	{
		DeleteFirst();
		cout << "\n Node Number " << x << " is deleted\n";
		return;
	}
	while (cur != NULL && count != x)
	{
		count++;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		cout << " Node doesn't exist\n";
		return;
	}
	if (cur->next == NULL) // it is a Last node
	{
		DeleteLast();
		cout << "\n Node Number " << x << " is deleted\n";
		return;
	}
	int n = cur->data;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	delete cur;
	cout << " Number " << n << " is deleted\n";
	cout << "\n Node Number " << x << " is deleted\n";
}
void DLL::SearchList()
{
	if (IsEmpty())
	{
		cout << "Empty linked list\n";
		return;
	}
	int x;
	cout << " Enter the data you want to search about\n";
	cin >> x;
	node *cur = head;
	while (cur != NULL && cur->data != x)
	{
		cur = cur->next;
	}
	if (cur == NULL)
		cout << " The data doesn't exist\n";
	else
		cout << " The number " << x << " is found\n";
}
void DLL::Display(node *d)
{
	if (d == NULL)
	{
		cout << endl;
		return;
	}
	cout << d->data << "   ";
	Display(d->next);
}
void DLL::DisplayReverse(node *d)
{
	if (d == NULL)
	{
		cout << endl;
		return;
	}
	DisplayReverse(d->next);
	cout << d->data << "   ";
}
// main function
int main()
{
	DLL list;
	list.FirstShow();
}