/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int flag1 = 0,flag2 = 0;
        int pass = 0;
        int temp = 0;
        ListNode* ans = NULL;
        ListNode* ans1 = NULL;
        while(flag1 != 1 || flag2 != 1)
        {
            if(flag1 == 0 && flag2 == 0) // find the value of summation according to the existance of linkedlists
            {
                temp = l1 -> val + l2 -> val + pass;
            }
            else if(flag1 == 1 && flag2 == 0)
            {
                temp = l2 -> val + pass;
            }
            else if(flag1 == 0 && flag2 == 1)
            {
                temp = l1 -> val + pass;
            }
            
            
            
            if(temp > 9) // As the value in each node should be less than 9 
            {
                pass = temp/10;
                temp = temp %10;
              
            }
            else
            {
                pass = 0;
            }
            
            
            
            if(ans != NULL) // Creating nodes to the solution
            {
                ans -> next = addNode(temp);
                ans = ans -> next;
            }
            else
            {
                ans = addNode(temp);
                ans1 = ans;
            }
            
            
            if(l1 -> next == NULL)//flagging if the List is exhausted
            {
                flag1 = 1;
            }
            else // moving the list to next node
            {
                 l1 = l1 -> next;
            }
            
            if(l2 -> next == NULL)
            {
                flag2 = 1;
            }
            else
            {
                 l2 = l2 -> next; 
            }
        }
        
        if(pass != 0) 
        {
            ans -> next = addNode(pass);
        }
        return ans1;
    }
    
    ListNode* addNode(int value)
    {
        // ListNode* temp = (struct ListNode*)malloc(sizeof(ListNode));
        ListNode* temp = new ListNode;
        temp -> val = value;
        temp -> next = NULL;
        return temp;
    }
};
