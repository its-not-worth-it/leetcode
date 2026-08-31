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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev_c=-1, curr_c=-1, first_c=-1, last_c=-1;
        int prev=-1, curr=-1, after=-1, mi=1e9, ma=-1, index=2;
        ListNode *i=head;
        prev=i->val; i=i->next;
        curr=i->val; 
        if(!i->next) return{-1,-1};
        
        while(i->next){
            after=i->next->val;
            if( (prev < curr and curr > after) or (prev > curr and curr < after) ){
                prev_c=curr_c; 
                curr_c=index;
                if(first_c==-1) first_c=curr_c;
                last_c=curr_c;
                if(first_c != last_c) mi=min(mi, curr_c-prev_c);
            }
            i=i->next;
            index++;
            prev=curr; curr=after;
        }

        if(first_c !=-1 and last_c !=-1 and first_c != last_c) return {mi, last_c-first_c};


        return {-1,-1};
    }
};