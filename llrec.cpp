#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    if(head==NULL){
      smaller=NULL;
      larger=NULL;
      return;
    }
    if(head->val<=pivot){
      smaller=head;
      Node *n=head->next;
      head=nullptr;
      llpivot(n, smaller->next, larger, pivot);
    }
    else{
      larger=head;
      Node *n=head->next;
      head=nullptr;
      llpivot(n, smaller, larger->next, pivot);
    }
  
}


