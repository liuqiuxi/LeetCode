#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct ListNode {
	int val;
	struct ListNode *next;
	
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;
	struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode *));
	result->val = 0;
	struct ListNode *p = NULL;
	int carry = 0;
	while (p1 != NULL || p2 != NULL || carry != 0)
	{
		if (p == NULL)
		{
			p = result;
		}
		else {
			p->next = (struct ListNode *)malloc(sizeof(struct ListNode *));
			p->next->val = 0;
			p = p->next;
		}
		int a = (p1 == NULL ? 0 : p1->val);
		int b = (p2 == NULL ? 0 : p2->val);
		int c = (a + b + carry) % 10;
		carry = (a + b + carry) / 10;
		p->val = c;
		p->next = NULL;

		p1 = (p1 == NULL ? NULL : p1->next);
		p2 = (p2 == NULL ? NULL : p2->next);
	}
	return result;
}
