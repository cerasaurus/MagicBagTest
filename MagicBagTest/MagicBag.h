#pragma once

#include <iostream>
#include <time.h>

using namespace std;

template<class T> class MagicBag
{
private:
	template<class S> class ListNode
	{
	public:
		S value;
		ListNode *next;
		ListNode(S newValue)
		{
			value = newValue;
			next = nullptr;
		}

		~ListNode()
		{

		}

		friend ostream& operator<<(ostream& os, const ListNode& me) {
			os << me.value;
			return os;
		}

		void print()
		{
			cout << value << endl;
		}
	};
public:
	ListNode<T> *head;
	MagicBag() {
		head = nullptr;
	}

	MagicBag(const MagicBag& other) {
		//ListNode<T> *current = other.head;
		//while (current)
		//{
		//	insert(current->value);
		//	current = current->next;
		//}
		//return *this;
	}

	MagicBag& operator=(const MagicBag& other) {
		ListNode<T> *current = other.head;
		while (current)
		{
			insert(current->value);
			current = current->next;
		}
		return *this;
	}

	~MagicBag() {
		ListNode<T> *deleteMe = head;
		ListNode<T> *next;
		//if deleteMe not last node
		while (deleteMe != nullptr)
		{
			//set next to deleteMe's next and remove deleteMe. set deleteMe to next
			next = deleteMe->next;
			delete deleteMe;
			deleteMe = next;
		}
	}

	void insert(T item) {
		ListNode<T> *newNode;
		newNode = new ListNode<T>(item);
		newNode->next = head;
		head = newNode;
	}

	T draw() {
		if (!head)
			throw(1);
		ListNode<T> *current;
		T returnValue;
		srand((unsigned int)time(NULL));
		int numNodes = 0;
		current = head;
		//count number of nodes
		while (current)
		{
			numNodes++;
			current = current->next;
		}
		//get random node index
		int randomNode = rand() % numNodes;
		if (randomNode == 0)
		{
			returnValue = head->value;
			current = head->next;
			delete head;
			head = current;
		}
		else
		{
			current = head;
			ListNode<T> *previous = nullptr;
			for (int i = 0; i < randomNode; i++)
			{
				previous = current;
				current = current->next;
			}
			//save next pointer and delete current node.
			if (previous != nullptr)
			{
				returnValue = current->value;
				previous->next = current->next;
				delete current;
			}
		}
		return (returnValue);
	}

	int peek(T item) {
		ListNode<T> *current;
		int count = 0;
		current = head;
		while (current)
		{
			if (item == current->value)
			{
				count++;
			}
			current = current->next;
		}
		return count;
	}

	void print(ostream& os)
	{
		ListNode<T> *current;
		current = head;
		while (current)
		{
			os << *current;
			current = current->next;
		}
	}

private:

	//friend ostream& operator<<(ostream& os, const MagicBag& mb) {
	//	os << mb.value;
	//	return os;
	//}
};
