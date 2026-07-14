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
    ListNode* sortList(ListNode* head) {
        return help(head);
    }
    ListNode* help(ListNode *head){
        if(!head or !head->next) return head;

        ListNode *f=head, *s=head, *temp=nullptr;
        while(f and f->next){
            f=f->next->next;
            temp=s;
            s=s->next;
        }
        temp->next=nullptr;

        ListNode *l=help(head), *m=help(s);

        return merge(l, m);
    }
    ListNode* merge(ListNode *l, ListNode *m){
        ListNode *f=new ListNode(0); ListNode *s=f;
        while(l and m){
            if(l->val < m->val){
                f->next=l;
                l=l->next;
            }else {
                f->next=m;
                m=m->next;
            }
            f=f->next;
        }
        if(l){
            f->next=l;
        }
        if(m){
            f->next=m;
        }
        f=s->next;
        delete s;
        return f;
    }
};