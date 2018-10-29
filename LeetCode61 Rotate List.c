#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

int getListNodeLen(struct ListNode *List)
{
	int len = 0;
	struct ListNode *result = List;
	while (result != NULL)
	{
		result = result->next;
		len++;
	}
	return len;
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	int listLen = getListNodeLen(head);
	if (listLen == 0) return NULL;
	k = k % listLen;
	struct ListNode *fast = head, *slow = head;
	for (int i = 0; i < k; i++) if (fast != NULL) fast = fast->next;
	if (fast == NULL)return head;
	while (fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	fast->next = head;
	fast = slow->next;
	slow->next = NULL;
	return fast;
}

int main()
{
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *temp = head;
	int nums[] = { 1,2,3,4,5 };
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		struct ListNode *node = malloc(sizeof(struct ListNode));
		node->val = nums[i];
		temp->next = node;
		temp = node;
	}
	temp->next = NULL; temp = head; head = head->next; free(temp);
	struct ListNode *result = rotateRight(head, 2);
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		printf("%d ", result->val);
		struct ListNode *tmp = result;
		result = result->next;
		free(tmp);
	}
	return 0;
}