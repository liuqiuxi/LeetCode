#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverse(struct ListNode *head, struct ListNode *tail)
{
	struct ListNode *result = tail;
	while (head != tail)
	{
		struct ListNode *p = head->next;
		head->next = result;
		result = head;
		head = p;
	}
	return result;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode *tail = head;
	for (int i = 0; i < k; i++)
	{
		if (!tail) return head;
		tail = tail->next;
	}
	struct ListNode *result = reverse(head, tail);
	head->next = reverseKGroup(tail, k);
	return result;
}

int main()
{
	struct ListNode *l1 = malloc(sizeof(struct ListNode));
	struct ListNode *temp = l1;
	int nums[] = { 1,2,3,4,5 };
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		struct ListNode *node = malloc(sizeof(struct ListNode));
		node->val = nums[i];
		temp->next = node;
		temp = node;
	}
	temp->next = NULL; temp = l1; l1 = l1->next; free(temp);
	struct ListNode *result = reverseKGroup(l1, 3);
	while (result)
	{
		struct ListNode *p = result;
		printf("%d", result->val);
		result = result->next;
		free(p);
	}
	return 0;
}
