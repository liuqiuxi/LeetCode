#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *result;
	struct ListNode *temp;
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}
	if (l1->val < l2->val){
		temp = l1;
		l1 = l1->next;
	}else {
		temp = l2;
		l2 = l2->next;
	}
	result = temp;

	while (l1 && l2)
	{
		if (l1->val < l2->val){
			temp->next = l1;
			l1 = l1->next;
		}else {
			temp->next = l2;
			l2 = l2->next;
		}
		temp = temp->next;
	}
	if (l1){
		temp->next = l1;
	}else if (l2){
		temp->next = l2;
	}
	return result;
}

int main()
{
	struct ListNode *l1, *l2;
	struct ListNode *p, *q, *node;
	l1 = malloc(sizeof(struct ListNode));
	l2 = malloc(sizeof(struct ListNode));
	p = l1; q = l2;
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
	p->next = NULL; q->next = NULL;
	l1 = l1->next; l2 = l2->next;
	struct ListNode *result = mergeTwoLists(l1, l2);
	while (result)
	{
		printf("%d", result->val);
		result = result->next;
	}
	printf("\n");
	return 0;
}