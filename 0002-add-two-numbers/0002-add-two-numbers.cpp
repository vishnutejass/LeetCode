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
    ListNode* sumofnumbers(ListNode* l1, ListNode* l2,int carry){
        if(l1==NULL && l2==NULL &&carry==0){
            return NULL;
        }
        int n1=0,n2=0,sum;
        if(l1!=NULL){
            n1=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            n2=l2->val;
            l2=l2->next;
        }
        sum=(n1+n2+carry)%10;      //untill sum>10,the value will be numerator;
        carry=(n1+n2+carry)/10;
        
        ListNode*temp=new ListNode(sum);
        temp->next=sumofnumbers(l1,l2,carry);
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return sumofnumbers(l1,l2,0);
    }
};


// class Solution {
// public:
//     ListNode *sumOfNumbers(ListNode*l1, ListNode*l2, int carry){
//         if(l1 == NULL && l2 == NULL && carry == 0) return NULL;
//         int n1 = 0, n2 = 0, sum;
//         if(l1 != NULL){
//             n1 = l1->val;
//             l1 = l1->next;
//         }
//         if(l2 != NULL){
//             n2 = l2->val;
//             l2 = l2->next;
//         }
//         sum = (n1+n2+carry)%10;
//         carry = (n1+n2+carry)/10;
        
//         ListNode *temp = new ListNode(sum);
//         temp->next = sumOfNumbers(l1, l2, carry);
//         return temp;

//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         return sumOfNumbers(l1, l2, 0);
//     }
// };