#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	int len = 0;
	struct ListNode *p = head;
	while (p)
	{
		len++;
		p = p->next;
	}
	int deletepoint = len - n;
	struct ListNode *q = head;
	for (int i = 0; i < len - n - 1; i++)
	{
		q = q->next;
	}
	if (len - n == 0)
	{
		head = head->next;
	}else{
		q->next = q->next->next;
	}
	return head;
}

int main()
{
	struct ListNode *head, *node, *end;
	head = malloc(sizeof(struct ListNode));
	end = head;
	for (int i = 0; i < 10; i++)
	{
		node = malloc(sizeof(struct ListNode));
		node->val = i;
		end->next = node;
		end = node;
	}
	end->next = NULL;
	removeNthFromEnd(head, 5);
	while (head->next != NULL)
	{
		head = head->next;
		printf("%d", head->val);
	}
	printf("\n");
	return 0;
}