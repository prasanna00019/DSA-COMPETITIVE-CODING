// Rearrange linked list in-place
// Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. 
// Rearrange the nodes in the list so that the newly formed list is: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2.

Node* reverse(Node* head){
    Node* pre=NULL;
    while(head){
        Node* temp=head->next;
        head->next=pre;
        pre=head;
        head=temp;
    }
    return pre;
}
Node *inPlace(Node *root)
{
 Node* head=root;
 while(root->next!=NULL){
     root->next=reverse(root->next);
      root=root->next;
 }
return head;
    }
