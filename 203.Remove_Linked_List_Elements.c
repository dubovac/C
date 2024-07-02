/**
 * 203. Remove Linked List Elements
 * Easy
 * Topics
 * Companies
 *
 * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
 *
 *
 *
 * Example 1:
 *
 *
 * 	1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6
 *
 * 	      1 --> 2 --> 3 --> 4 --> 5
 *
 *
 * 	Input: head = [1,2,6,3,4,5,6], val = 6
 * 	Output: [1,2,3,4,5]
 *
 * Example 2:
 *
 * 	Input: head = [], val = 1
 * 	Output: []
 *
 * Example 3:
 *
 * 	Input: head = [7,7,7,7], val = 7
 * 	Output: []
 *
 *
 *
 * Constraints:
 *
 * 	The number of nodes in the list is in the range [0, 104].
 * 	1 <= Node.val <= 50
 * 	0 <= val <= 50
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* newNode(int val) {
	struct ListNode* n = (struct ListNode *) malloc(sizeof(struct ListNode));

	n->val = val;
	n->next = NULL;

	return n;
}

void printList(struct ListNode* n) {
	while (n != NULL) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");
}

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL)
		return NULL;

	struct ListNode* r = (struct ListNode *) malloc(sizeof(struct ListNode));

	r = head;

	while (head != NULL) {
		while (head->next != NULL && head->next->val == val)
			head->next = head->next->next;

		head = head->next;
	}

	if (r->val == val) {
		if (r->next == NULL)
			return NULL;
		else
			return r->next;
	}

	return r;
}

int main(void) {
	struct ListNode* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(6);
	head->next->next->next = newNode(3);
	head->next->next->next->next = newNode(4);
	head->next->next->next->next->next = newNode(5);
	head->next->next->next->next->next->next = newNode(6);

	struct ListNode* t = (struct ListNode *) malloc(sizeof(struct ListNode));
	t = head;

	printList(t);

	t = removeElements(head, 6);

	printList(t);

	printf("\n");

//-----------------------------------------------------------------------------------

	struct ListNode* head1 = NULL;

	struct ListNode* t1 = (struct ListNode *) malloc(sizeof(struct ListNode));
	t1 = head1;

	printList(t1);

	t1 = removeElements(head1, 1);

	printList(t1);

	printf("\n");

//-----------------------------------------------------------------------------------

	struct ListNode* head2 = newNode(7);
	head2->next = newNode(7);
	head2->next->next = newNode(7);
	head2->next->next->next = newNode(7);

	struct ListNode* t2 = (struct ListNode *) malloc(sizeof(struct ListNode));
	t2 = head2;

	printList(t2);

	t2 = removeElements(head2, 7);

	printList(t2);

	printf("\n");
}
