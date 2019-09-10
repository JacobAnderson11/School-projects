#include<string>
#include<iostream>
#include"Node.h"
using namespace std;

int main() {
	Node<string>* head = new Node<string>("Tom");
	Node<string>* john = new Node<string>("John");
	Node<string>* harry = new Node<string>("Harry");
	Node<string>* sam = new Node<string>("Sam");

	Node<string>* tom = head;
	tom->next = john;
	john->next = harry;
	harry->next = sam;

	Node<string>* current_node = head;

	while (current_node != NULL) {
		cout << current_node->data;
		if (current_node->next != NULL)
		{
			cout << " ==> ";
		}
		current_node = current_node->next;
	}
	cout << endl;

	Node<string>* bill = new Node<string>("Bill");
	head = bill;
	bill->next = tom;

	current_node = head;

	while (current_node != NULL) {
		cout << current_node->data;
		if (current_node->next != NULL)
		{
			cout << " ==> ";
		}
		current_node = current_node->next;
	}
	cout << endl;

	Node<string>* sue = new Node<string>("Sue");
	sue->next = sam;
	harry->next = sue;
	current_node = head;

	while (current_node != NULL) {
		cout << current_node->data;
		if (current_node->next != NULL)
		{
			cout << " ==> ";
		}
		current_node = current_node->next;
	}
	cout << endl;

	head = tom;
	current_node = head;

	while (current_node != NULL) {
		cout << current_node->data;
		if (current_node->next != NULL)
		{
			cout << " ==> ";
		}
		current_node = current_node->next;
	}
	cout << endl;

	sue->next = NULL;
	current_node = head;

	while (current_node != NULL) {
		cout << current_node->data;
		if (current_node->next != NULL)
		{
			cout << " ==> ";
		}
		current_node = current_node->next;
	}
	cout << endl;

}
