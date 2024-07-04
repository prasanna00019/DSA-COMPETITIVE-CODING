//leetcode
   
ListNode* mergeNodes(struct ListNode* head) {
 ListNode* dummy=new ListNode(-1);
 ListNode* t1=dummy;
 ListNode* temp1=head;
 int c;
 while(temp1->next!=NULL){
    c=0;
    while(temp1->next->val!=0){
        c+=temp1->next->val;
        temp1=temp1->next;
    }
    t1->next=new ListNode(c);
    t1=t1->next;
    temp1=temp1->next;

 }
 return dummy->next;
}
   
