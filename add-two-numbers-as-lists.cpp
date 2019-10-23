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

struct ListNode
{
    int val;
    ListNode *next;
};


int algo(ListNode* bigger, ListNode* smaller)
{
    int val = 0, c = 0;
    ListNode *last_node=NULL;
    while(smaller)
    {
        val = bigger->val + smaller->val;
        val += c;
        if(val > 9)
        {
            val = val % 10; c = 1;
        }else
            c = 0;
            
        bigger -> val = val;
        
        bigger = bigger->next;
        smaller = smaller->next;
    }
    
    while(c == 1 && bigger)
    {
        val = bigger->val + c;
        if(val > 9)
        {
            val = val % 10; c = 1;
        }else
            c = 0;
            
        bigger->val = val;
        last_node = bigger;
        bigger = bigger -> next;
    }
    
    if(c == 1 & ! bigger)
    {
        smaller = (ListNode*)malloc(sizeof(ListNode));
        smaller -> val = c;
        smaller -> next = NULL;
        last_node -> next = smaller;
    }
    
    return 0;
}
 
ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *a=A, *b=B, *bigger, *smaller;
    // Step 1. Figure out which linked list is bigger. Can be done in O(n)
    while(a && b)
    {
        a = a->next;
        b = b->next;
    }
    if(a)
    {
        bigger = A;
        smaller = B;
    }
    else{
        bigger = B;
        smaller = A;
    }
    
    algo(bigger, smaller);
    
    return bigger;
}



int main()
{
    ListNode *head_a=NULL, *head_b=NULL, *new_node=NULL, *pre_node=NULL;
    int n;
    cin>>n;
    while(n--)
    {
        new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node -> next = NULL;
	cin>>new_node -> val;
	if(!head_a)
	{
		head_a = new_node;
		pre_node = new_node;
	}
	else	
	{
		pre_node -> next = new_node;
		pre_node = new_node;
	}
    }

    cin>>n;
    while(n--)
    {
        new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node -> next = NULL;
        cin>>new_node -> val;
	if(!head_b)
	    head_b = new_node;
	else
	    pre_node -> next = new_node;

	pre_node = new_node;
    }

    new_node = addTwoNumbers(head_a, head_b);

    cout <<"\nFinal List is as follows:\n";
    while(new_node)
    {
	cout << new_node->val <<" ";
	new_node = new_node -> next;
    }
    cout<<endl;
}
