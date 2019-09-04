#include <stdio.h>
#include <stdlib.h>

void  print_list();
void  print_list();
void  delete_node();

typedef struct node {
	struct node *next;
	int *value;
} node;

typedef struct list {
	node *head;
} list;

int main()
{
    //list my_list; 
    node *head = NULL;
    head = malloc(sizeof(node));
    if (head==NULL){
        return 1;
    }
    return 0;
}

void print_list(node *head) {
    node* current_node = head;
    while (current_node != NULL){
        printf("%d", current_node->value);
        current_node = current_node->next;
    }
}

void insert_node(node **head, int value, int position){
    node* current_node = *head;
    node *temp=NULL;

    for(int i = 0 ; i < position-1;++i){
        if (current_node->next==NULL)
            return -1;
        current_node = current_node->next;
    }
    temp = current_node->next;
    temp->value = value;
    current_node->next=temp;
}

void  delete_node(node **head,int position) {
    node* current_node = *head;
    for(int i = 0 ; i < position-1;++i){
        current_node = current_node->next;
    }
    node *p=current_node->next;
    current_node->next = current_node->next->next;
}