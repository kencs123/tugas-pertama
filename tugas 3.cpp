//tugas 3 kenneth calvin
//Find the middle element of a linked list.
//logikanya pake 2 pointer, 1 nya kecepatan biasa, 1 nya 2x kecepeatan biasa


#include <stdio.h>
#include <stdlib.h>

struct node {
	int nomor;
	node *next;
}*head = NULL, *tail=NULL;

void createnode (node **head, int newnomor){
	node*  newnode = (node*)malloc(sizeof(node));
	newnode->nomor = newnomor;
	newnode->next = (*head);
	(*head) = newnode;

}

void middle (node *head){
	node *slow=head;
	node *fast=head;
	if (head != NULL){
		while(fast!=NULL && fast->next!=NULL){
			fast= fast->next->next;
			slow= slow->next;
		}
	
	printf ("Nilai tengahnya adalah: %d\n", slow->nomor);}
}


int main (){
	int n, temp;
	node* head = NULL;
	printf ("Ada brapa data? : ");
	scanf ("%d", &n);
	for (int i=0; i<n; i++){
		printf ("Masukan data ke %d: ", i+1);
		scanf ("%d", &temp);
		createnode(&head, temp);
	}
	middle(head);
	return 0;
}
