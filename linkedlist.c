//Chufan Xiao
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int val;
  struct node* next;

} Node;

void insertEnd(Node* head,int val){
  Node* current=head;
  while (current->next!=NULL){
    current=current->next;
  }

  current->next=malloc(sizeof(Node));
  current->next->val=val;
  current->next->next=NULL;

}


void insertBegin(Node** head,int val){
  Node* newNode;
  newNode=malloc(sizeof(Node));
  newNode->val=val;
  newNode->next=NULL;

  newNode->next=*head;
  *head=newNode;
}


int removeFirst(Node** head){
  Node* nextNode=NULL;
  int res=-1;
  if (*head==NULL){
    return -1;
  }

  nextNode=(*head)->next;
  res=(*head)->val;
  free(*head);
  *head=nextNode;

  return res;
}

int removeLast(Node* head){
  int res=-1;
  if (head==NULL){
    return -1;
  }

  if (head->next==NULL){
    res=head->val;
    free(head);
    return res;
  }

  Node* current=head;
  while(current->next->next!=NULL){
    current=current->next;
  }
  res=current->next->val;
  free(current->next);
  current->next=NULL;
  return res;

}

int removeByIndex(Node** head,int index){
  int i=0;
  int res=-1;
  Node* current=*head;
  Node* tmp=NULL;
  if (index==0){
    removeFirst(head);
  }


  for (int i=0;i<index-1;i++){
      if(current->next==NULL){
        return -1;
      }
      current=current->next;
  }

  tmp=current->next;
  res=tmp->val;
  current->next=tmp->next;
  free(tmp);
  return res;
}


int removeByValue(Node** head,int val){
  Node* previous;
  Node* current;

  if (*head==NULL){
    return -1;
  }

  if ((*head)->val==val){
    removeFirst(head);
  }
  previous=current=(*head)->next;
  while (current){
    if (current->val==val){
      previous->next=current->next;
      free(current);
      return val;
    }
    previous=current;
    current=current->next;
  }

  return -1;
}




void printList(Node* head){
  Node* current=head;
  while(current!=NULL){
    printf("%d\n",current->val);
    current=current->next;

  }

}

void delete(Node* head){
  Node* current=head;
  Node* next=head;
  while (current){
    next=current->next;
    free(current);
    current=next;
  }
}
int main(){
  Node* head=NULL;
  head=malloc(sizeof(Node));
  head->val=1;
  head->next=NULL;

  insertEnd(head, 2);
  insertEnd(head,3);
  insertEnd(head,4);
  insertBegin(&head,100);
  printList(head);
  removeByIndex(&head,3);
  printList(head);
  removeByValue(&head,2);
  printList(head);
  delete(head);
  return 0;
  //push node

  //pop node
  //print list
}
