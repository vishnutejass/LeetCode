/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
       
        
        
        
         ListNode *tortoise,*hare = head;
        
        while(hare && hare->next){
         
           tortoise=tortoise->next;
            hare=hare->next->next;
            
            if(hare==tortoise)
                return true;
       
        
        } 
        return false;
    }
};