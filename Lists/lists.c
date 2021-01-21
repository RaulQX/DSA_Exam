#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int info;

	struct node *next;
}node;

void printList(node *head) {

	node *temp = head -> next;

	while (temp != NULL) {
		printf("%d ", temp -> info);
		temp = temp -> next;
	}

	printf("\n");
}

void pushBack (node *head, int info) {

	node *add = malloc(sizeof(node));
	if (!add)
		printf("Fu\n");

	add -> next = head -> next;
	head -> next = add;

	add -> info = info; 
}

void pushFront (node *head, int info) {
	node *add = malloc(sizeof(node));
	if (!add)
		printf("Fu\n");

	node *temp = head;

	while (temp -> next != NULL) {
		temp = temp -> next;
	}

	temp -> next = add;
	add -> next = NULL;

	add -> info = info;
}

void initializeList (node *head) {
	head -> next = NULL;
}

void deleteNode (node *head, int info) {
	node * current = head -> next;
	node * prev;

	while (current -> info != info) {
		prev = current;
		current = current -> next;
	}

	prev -> next = current -> next;

	free(current);
}

void freeList(node *head) {
	node *temp;

	while (head != NULL) {
		temp = head;
		head = head -> next;
		free(temp);
	}
}

int main ()
{
	node *head = malloc(sizeof(node));
	initializeList(head);

	for (int i = 0; i < 5; i++) {
		pushFront(head, i);
		//pushBack(head, i);
	}

	printList(head);

	deleteNode(head, 3);

	printList(head);

	freeList(head);

	return 0;
}