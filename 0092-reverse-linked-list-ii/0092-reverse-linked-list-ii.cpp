/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        for (int i = 0; i < left-1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        
        for (int i = 0; i < right-left; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        return dummy->next;
    }
};
















// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
      
//         ListNode*temp=head;
//         int pos=1;
//         while(temp!=NULL){
//             if(pos<left){
//             temp=temp->next;
//                 pos++;
//             }
//            else  break;
           
            
//         }
//         ListNode*l=temp;
        
        
//         ListNode*x=temp;
//         while(x!=NULL){
//             if(pos<right){
//                 x=x->next;
//                 pos++;
//             }
//             else break;
            
//         }
       
//          ListNode*r=x;
         
        
//      ListNode*prev=NULL; ListNode*curr=l;
//         while(curr!=nullptr){
//             if(curr->next!=r){
//             ListNode*f=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=f;
//             }
//             else{
//                 break;
//             }
//         }
        
//        return head;
        
        
//     }
// };