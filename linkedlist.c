#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} node_t;


void print_list(node_t *head){
	node_t *current = head;
	while(current != NULL){
		printf("%d\n", current->val);
		current = current->next;
	}
}

void insert(node_t *head, int value){
	node_t *current = head;
	while(current->next != NULL) {
		current = current->next;
	}	
	current->next = malloc(sizeof(node_t));
	current->next->val = value;
	current->next->next = NULL;
}

int main() {
	node_t *test_list = malloc(sizeof(node_t));
	test_list->val = 1;
	test_list->next = NULL;
	
	
	print_list(test_list);

	insert(test_list, 5);

	print_list(test_list);
	return 0;
}
