//leetcode
ListNode* mergeNodes(struct ListNode* head) {
 ListNode* temp1,*temp2;
 temp1=head;int c=0; temp2=NULL;
 while(temp1->next!=NULL){ 
 c=0;
while(temp1->next->val!=0){
  c+=temp1->next->val;
  temp1=temp1->next;
 }
 temp1=temp1->next;
 temp2=insert_front(temp2,c);
}
 return reverse(temp2);
}
