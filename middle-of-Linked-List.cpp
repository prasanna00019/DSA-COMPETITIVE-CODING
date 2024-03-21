/*FIND MIDDLE ELEMENT OF LINKED LIST USING SLOW, FAST POINTERS*/
 int getMiddle(Node *head)
    {
        Node* slow,*fast;
        slow=head;fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};
