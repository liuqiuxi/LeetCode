#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;
	struct ListNode *result = head->next;
	head->next = swapPairs(result->next);
	result->next = head;
	return result;
}

int main()
{
	struct ListNode *l1 = malloc(sizeof(struct ListNode));
	struct ListNode *temp = l1;
	int nums[] = { 1,2,3,4};
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		struct ListNode *node = malloc(sizeof(struct ListNode));
		node->val = nums[i];
		temp->next = node;
		temp = node;
	}
	temp->next = NULL; temp = l1; l1 = l1->next; free(temp);
	struct ListNode *result = swapPairs(l1);
	while (result)
	{
		struct ListNode *p = result;
		printf("%d", result->val);
		result = result->next;
		free(p);
	}
	printf("\n");
	return 0;
}