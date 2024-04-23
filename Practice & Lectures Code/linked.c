#include <stdio.h>
#include <stdlib.h>

	struct node{
		int value;
		struct node* next;
	};
	
	typedef struct node node_t;
	
	void printlist(node_t *head){
		node_t *temporary = head;
		
		while(temporary != NULL){
			//as long as temporary is not NULL it will print out the value for each node value till it hits NULL
			printf("%d -", temporary->value);
			temporary = temporary->next;	
		}
		printf("\n");
	}
	
	int main (){
		node_t n1, n2, n3;
		node_t *head;
		
		n1.value = 45;
		n2.value = 3;
		n3.value = 65;


		//link them up
		head = &n3;
		n3.next = &n2; //each node is pointed to the address of the next node 
		n2.next = &n1;
		n1.next = NULL; // so we know when to stop
		
		printlist(head);

		return 0;
	}

