/**
 * 141. Linked List Cycle
 * Easy
 * Topics
 * Companies
 *
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 *
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
 *
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 *
 *
 *
 * Example 1:
 *
 *	3 → 2 → 0 → 4
 *	    ↑_______↓
 *
 * 	Input: head = [3,2,0,-4], pos = 1
 * 	Output: true
 * 	Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
 *
 * Example 2:
 *
 *	1 → 2
 *	↑___↓
 *
 * 	Input: head = [1,2], pos = 0
 * 	Output: true
 * 	Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
 *
 * Example 3:
 *
 * 	1
 *
 * 	Input: head = [1], pos = -1
 * 	Output: false
 * 	Explanation: There is no cycle in the linked list.
 *
 *
 *
 * Constraints:
 *
 * 	The number of the nodes in the list is in the range [0, 104].
 * 	-105 <= Node.val <= 105
 * 	pos is -1 or a valid index in the linked-list.
 *
 *
 *
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
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
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* newNode(int n) {
	struct ListNode* node = (struct ListNode *) malloc(sizeof(struct ListNode));

	node->val = n;
	node->next = NULL;

	return node;

}

bool hasCycle(struct ListNode *head) {
    	if (head == NULL)
        	return false;
        
	if (head->next == NULL)
		return false;

	int i = 1;

	struct ListNode** ptrArray = (struct ListNode **) malloc(i * sizeof(struct ListNode *));
	ptrArray[0] = head;

	head = head->next;

	while (head) {
		ptrArray = realloc(ptrArray, (i + 1) * sizeof(struct ListNode *));

		ptrArray[i] = head;

		for (int j = 0; j < i; j++)
			if (ptrArray[j] == ptrArray[i])
				return true;

		head = head->next;
		i++;
	}

	return false;
}

int main(void) {
	struct ListNode* head = newNode(3);
	head->next = newNode(2);
	head->next->next = newNode(0);
	head->next->next->next = newNode(4);
	head->next->next->next->next = head->next;


	printf("%s\n ", hasCycle(head) ? "true" : "false");
}
