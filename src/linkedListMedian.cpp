/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head==NULL)
	return -1;
	struct node *traversal, *previous;
	int count = 0;
	traversal = head;
	while (traversal != NULL)
	{
		count++;
		traversal = traversal->next;
	}
	traversal = head;
	if (count % 2 == 1)//for odd length input
	{
		for (int i = 0; i<(count / 2); i++)
		{
			traversal = traversal->next;
		}
		return traversal->num;
	}
	else
	{//for even length input
		for (int i = 0; i<count / 2; i++)
		{
			previous = traversal;
			traversal = traversal->next;
		}
		return (previous->num + traversal->num) / 2;
	}
}
