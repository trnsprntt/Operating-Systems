#include <stdio.h>
#include<stdlib.h>

struct node{
  int value;
  struct node * next;
};

struct node* new(int n) {
    struct node* temp = (struct node*) malloc(sizeof (struct node));
    temp->value=n;
    temp->next=NULL;
    return temp;
}

void print_list(struct node* head){
  while(head!=NULL){
    printf(" %d",head->value);
    head = head->next;
  }
  printf("\n");
}

void insert_node(struct node* head, struct node * new_node, int index){
  if (index<2){
    printf("ERROR. Index is out of range. \nNodes before that index do not exist. \nFirst node is indexed 1. \nYou can insert nodes only starting from index 2.\n");
  }
  else if(index==2){
    new_node->next=head->next;
    head->next=new_node;
  }
  else{
    for(int i=2;i<index;i++){
      if (head->next!=NULL){
        head = head->next;
      }
      else{
        head->next=new_node;
        break;
      }
    }
    new_node->next=head->next;
    head->next=new_node;
  }
}

void delete_node(struct node* head, int index){
  if(index==0){
    printf("ERROR. Index is out of range. \nNodes before that index do not exist. \nFirst node is indexed 1. \nYou can delete nodes only starting from index 2.\n");
  }
  else{
    for(int i = 1; (i < index-1) && (head->next != NULL); i++){
      head=head->next;
    }
    if(head->next != NULL){
      head->next=head->next->next;
    }
  }
  return;
}

int main(){
  struct node* head;
  struct node* node1;
  struct node* node2 = new(4);
  struct node* node3 = new(3);
  head = new(1);
  node1 = new(2);
  head->next = node1;
  print_list(head);
  insert_node(head, node2, 2);
  insert_node(head, node3, 2);
  print_list(head);
  delete_node(head, 2);
  print_list(head);
  return 0;
}
