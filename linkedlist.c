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

void whats_at(node_t *head, int value){
	node_t *current = head;
	int i = 0;
	while(current->next != NULL && i != value){
		current = current->next;
		i++;
	}

	if(current->next == NULL && i != value){
		printf("Index %d is not in the list, list is of length %d", value, i); 
	} else {
		printf("Value at LinkedList[%d]: %d", value, current->val);
	}	
}

void rem(node_t *head){
	node_t *current = head;
        while(current->next->next != NULL){
		current = current->next;
	}
	free(current->next);
	current->next = NULL;
}

int main() {
	node_t *test_list = malloc(sizeof(node_t));
	test_list->val = 1;
	test_list->next = NULL;
	
	
	print_list(test_list);

	insert(test_list, 5);
	
	printf("%s", "\n");

	whats_at(test_list, 1);

        printf("%s", "\n");

	whats_at(test_list, 3);

	printf("%s", "\n");

	return 0;
}
