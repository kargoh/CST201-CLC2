#include <iostream>
#include <cstdlib>

using namespace std; 

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;



int count(struct Node* head) {
	int count = 0;
	struct Node* temp = head;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return(count);
}

void printList(struct Node* p){
	if (p == NULL) {
		return;
	}
	printf("%d ", p->data);
	printList(p->next);
}

void Delete(int n) { // TODO finish remove ith node
	Node* temp1 = head;
	if (n == 1) {
		head = temp1->next;
		free(temp1);
		return;
	}
	int i;
	for (i = 1; i < n - 2; i++) {
		temp1 = temp1->next;
	}
	struct Node* temp2 = temp1->next; // TODO research fix what is broken with this line
	temp1->next = temp2->next;
	free(temp2);
}

struct Node* Insert(Node* head, int data) {
	Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		Node* temp1 = head;
		while (temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	return head;
}

void Append(int n) { //TODO finish

}

void Copy(Node* head, int n) { //TODO finish

}

void printReverseList(struct Node* p) {
	if (p == NULL) {
		return;
	}
	printReverseList(p->next);
	printf("%d ", p->data);
}


int main()
{
	struct Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);

	cout << "The List in correct order: ";
	printList(head);
	cout << "\nThe List in reverse order: ";
	printReverseList(head);
	cout << "\nThe Size of the list: ";
	cout << count(head) << "\n";
	Delete(2);
	printList(head);
}


