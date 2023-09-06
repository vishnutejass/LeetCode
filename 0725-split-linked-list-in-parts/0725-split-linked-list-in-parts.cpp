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
// class Solution {
// public:
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
//         vector<ListNode*>result;
        
//         int len=0;
//         ListNode*temp=head;
        
//         while(temp!=NULL){
//             len++;
//             temp=temp->next;
            
//         }
//         int basesize=len/k;
//         int extrasize=len%k;
        
//         temp=head;   //important step
        
//         for(int i=0;i<k;i++){
//             ListNode*parthead=temp;
            
//             int partsize=basesize+ (i<extrasize?1:0);  //currentpart
            
//             for(int j=0;j<partsize-1;j++){
//                 temp=temp->next;
//             }
//             while(temp!=nullptr){
//                 ListNode*newnode=temp->next;
//                 temp->next=nullptr;
//                 temp=newnode;
//             }
//             result.push_back(parthead);
//         }
//         return result;
//     }
// };



class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        
        int length = 0;
        ListNode* temp = head;
        
        // Calculate the length of the linked list
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        
        int baseSize = length / k;  // Minimum size of each part
        int extra = length % k;     // Number of parts with size = baseSize + 1
        
        temp = head;
        
        for (int i = 0; i < k; i++) {
            ListNode* partHead = temp;
            int partSize = baseSize + (i < extra ? 1 : 0);
            
            // Move temp to the end of the current part
            for (int j = 0; j < partSize - 1; j++) {
                temp = temp->next;
            }
            
            if (temp != nullptr) {
                ListNode* nextNode = temp->next;
                temp->next = nullptr;  // Terminate the current part
                temp = nextNode;
            }
            
            result.push_back(partHead);  // Push the head of each part
        }
        
        return result;
    }
};

