/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


auto algo(ListNode *sf, int B)
{
    ListNode *pp, *qp, *rp;
    pp = sf;
    qp = sf->next;
    int k=1;
    while(qp && k != B)
    {
        rp = qp->next;
        qp->next = pp;
        pp = qp;
        qp = rp;
        k++;
    }
    struct result{
        ListNode* p;
        ListNode* q;
    };
    return result{pp, qp};
}
 
ListNode* reverseList(ListNode* A, int B) {
    ListNode *new_head,*start_from,*last_end,*p,*q;
    new_head = last_end = p = q = NULL;
    start_from = A;
    if(B == 1)
        return A;
    while(start_from)
    {
        auto result = algo(start_from, B);
        if(new_head == NULL)
            new_head = result.p;
            
        if(last_end)
            last_end->next = result.p;
            
        last_end = start_from;
        start_from = result.q;
    }
    last_end -> next = NULL;
    return new_head;
}


int main()
{
	int n;cin>>n;
	struct ListNode *head, *new_node, *last_node;
	head = NULL;
	while(n--)
	{
		new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
		cin>>new_node -> val;
		new_node -> next = NULL;
		if(!head)
		{
			head = new_node;
			last_node = head;
		}
		else{
			last_node -> next = new_node;
			last_node = new_node;
		}
		
	}

	int B; cin>>B;

	cout << "\nGive linked list is as follows:\n";
	new_node = head;
	while(new_node)
        {
		cout << new_node->val << " ";
		new_node = new_node -> next;
        }


	new_node = reverseList(head, B);

	cout << "\nAfter K-Reversing the linked list is as follows:\n";
	while(new_node)
	{
		cout << new_node->val << " ";
		new_node = new_node -> next;
	}

	cout <<"\nIt's Done :)";
	return 0;

}
