#include<iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

void sortedInsert(struct Node**, struct Node*);

void insertionSort(struct Node** head_ref)
{
	struct Node* sorted = NULL;

	struct Node* current = *head_ref;
	while (current != NULL)
	{
		struct Node* next = current->next;

		sortedInsert(&sorted, current);
		current = next;
	}

	*head_ref = sorted;
}

void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
	struct Node* current;

	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		current = *head_ref;
		while (current->next != NULL && current->next->data < new_node->data)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}

}

void printList(struct Node* head) 
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		cout << " " << temp->data << endl;
		temp = temp->next;
	}


}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;

	new_node->data = new_data;
	new_node->next = (*head_ref);

	(*head_ref) = new_node;

}

int main()
{
	struct Node* head = NULL;

	for (int i = 0; i < 10; i++)
	{
		push(&head, rand() % 10);
	}
	cout << "the list is: " << endl; 
	printList(head);

	insertionSort(&head);
	cout << "The list after sorting is: " << endl;
	printList(head);
}
