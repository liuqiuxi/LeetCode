#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode *result; struct ListNode *temp;
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	if (l1->val < l2->val)
	{
		temp = l1;
		l1 = l1->next;
	}
	else {
		temp = l2;
		l2 = l2->next;
	}

	result = temp;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			temp->next = l1;
			l1 = l1->next;
		}
		else {
			temp->next = l2;
			l2 = l2->next;
		}
		temp = temp->next;
	}
	if (l1)
	{
		temp->next = l1;
	}
	else {
		temp->next = l2;
	}
	return result;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	struct ListNode *result = NULL;
	int i = 0;
	if (listsSize == 0)
	{
		return NULL;
	}
	else if (listsSize == 1)
	{
		return lists[0];
	}
	else {
		while (listsSize > 1)
		{
			for (i = 0; i < listsSize / 2 ;i++)
			{
				lists[i] = mergeTwoLists(lists[i], lists[listsSize - 1 - i]);
			}
			if (listsSize % 2 == 1)
			{
				lists[i - 1] = mergeTwoLists(lists[i], lists[i - 1]);
			}
			listsSize = listsSize / 2;
		}
		result = lists[0];
	}
	return result;
}



int main()
{
	struct ListNode *l1, *l2, *l3;
	struct ListNode *p, *q, *r, *node;
	l1 = malloc(sizeof(struct ListNode));
	l2 = malloc(sizeof(struct ListNode));
	l3 = malloc(sizeof(struct ListNode));
	p = l1; q = l2; r = l3;
	for (int i = 0; i < 5; i++)
	{
		node = malloc(sizeof(struct ListNode));
		node->val = i;
		p->next = node;
		p = node;
	}
	for (int i = 5; i < 10; i++)
	{
		node = malloc(sizeof(struct ListNode));
		node->val = i;
		q->next = node;
		q = node;
	}
	for (int i = 10; i < 15; i++)
	{
		node = malloc(sizeof(struct ListNode));
		node->val = i;
		r->next = node;
		r = node;
	}
	p->next = NULL; q->next = NULL; r->next = NULL;
	l1 = l1->next; l2 = l2->next; l3 = l3->next;
	struct ListNode **lists = (struct ListNode **)malloc(sizeof(struct ListNode*) * 3);
	lists[0] = l1; lists[1] = l2; lists[2] = l3;
	struct ListNode *result = mergeKLists(lists, 3);
	while (result)
	{
		printf("%d", result->val);
		result = result->next;
	}
	printf("\n");
	return 0;
}