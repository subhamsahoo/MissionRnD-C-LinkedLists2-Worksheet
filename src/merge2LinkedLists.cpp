/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};
//for creation of new merged linked list
void creation(struct node **head, int n)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->num = n;
	newnode->next = NULL;
	if (*head == NULL)
		*head = newnode;
	else
	{
		struct node *traversal = *head;
		while (traversal->next != NULL)
			traversal = traversal->next;
		traversal->next = newnode;
	}
}


struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL&&head2 == NULL)
		return NULL;
	else if (head1 != NULL&&head2 == NULL)
		return head1;
	else if (head1 == NULL&&head2 != NULL)
		return head2;
	struct node *head3 = NULL, *traversal1 = head1, *traversal2 = head2;
	while (traversal1 != NULL&&traversal2 != NULL)
	{
		if (traversal1->num <= traversal2->num)
		{
			creation(&head3, traversal1->num);
			traversal1 = traversal1->next;
		}
		else if (traversal1->num>traversal2->num)
		{
			creation(&head3, traversal2->num);
			traversal2 = traversal2->next;
		}
	}
	if (traversal1 != NULL&&traversal2 == NULL)
	{
		while (traversal1 != NULL)
		{
			creation(&head3, traversal1->num);
			traversal1 = traversal1->next;
		}
	}
	else if (traversal2 != NULL&&traversal1 == NULL)
	{
		while (traversal2 != NULL)
		{
			creation(&head3, traversal2->num);
			traversal2 = traversal2->next;
		}
	}
	return head3;
}
