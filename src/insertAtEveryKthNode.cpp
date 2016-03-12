/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL||K<1)
	return NULL;
	struct node *traversal = head, *current;
	int count = 0;
	while (traversal != NULL)
	{
		count++;
		if (count%K == 0)
		{
			struct node *newnode = (struct node*)malloc(sizeof(struct node));
			current = traversal;
			newnode->num = K;
			newnode->next = traversal->next;
			traversal = traversal->next;
			current->next = newnode;
		}
		else
			traversal = traversal->next;
	}
	return head;
}
