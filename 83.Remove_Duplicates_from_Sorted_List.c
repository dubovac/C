/*
 * 83. Remove Duplicates from Sorted List
 * Easy
 * Topics
 * Companies
 *
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
 * Return the linked list sorted as well.
 *
 *
 *
 * Example 1:
 *
 * 	Input: head = [1,1,2]
 * 	Output: [1,2]
 *
 * Example 2:
 *
 * 	Input: head = [1,1,2,3,3]
 * 	Output: [1,2,3]
 *
 *
 *
 * Constraints:
 *
 * 	The number of nodes in the list is in the range [0, 300].
 * 	-100 <= Node.val <= 100
 * 	The list is guaranteed to be sorted in ascending order.
 */

/*
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

struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (head == NULL)
		return NULL;

	struct ListNode* h = head;

	while (head->next != NULL)
		if (head->val == head->next->val)
			head->next = head->next->next;
		else
			head = head->next;

	return h;
}

struct ListNode *newNode(int value) {
	struct ListNode* temp = (struct ListNode *) malloc(sizeof(struct ListNode));
	temp->val = value;
	temp->next = NULL;
	return temp;
}

void printlist(struct ListNode* head) {
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	puts("");
}

int main(void) {

	struct ListNode *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(2);
	head->next->next->next = newNode(3);
	head->next->next->next->next = newNode(3);
	head->next->next->next->next->next = newNode(3);
	head->next->next->next->next->next->next = newNode(3);
	head->next->next->next->next->next->next->next = newNode(4);
	head->next->next->next->next->next->next->next->next = newNode(5);
	head->next->next->next->next->next->next->next->next->next = newNode(5);
	head->next->next->next->next->next->next->next->next->next->next = newNode(6);

	printf("Given linked list\n");
	printlist(head);
	printf("List after duplicates deleted\n");
	printlist(deleteDuplicates(head));

}
