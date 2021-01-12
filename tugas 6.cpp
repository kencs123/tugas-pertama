//tugas 6 kenneth calvin
//Given a sorted (ascending) linked list, 
//manipulate it to become a sorted (descending) linked list.
// jadi nanti inputnya dalam scanf descending ya biar di linked listnya ascending
//"given a sorted (ascending) linked list.
//pakai bubble sort dari geek for geek

#include <stdio.h>
#include <stdlib.h>

struct node {
	int nomor;
	node* next;
}*head = NULL, *tail=NULL;

void createnode (node** head, int newnomor){
	node*  newnode = (node*)malloc(sizeof(node));
	newnode->nomor = newnomor;
	newnode->next = (*head);
	(*head) = newnode;
}

void swap(node* a, node* b){
	int temp= a->nomor;
	a->nomor=b->nomor;
	b->nomor= temp;
}
void bubblesort (node* head){
	int swapped, i;
	node *ptr1;
	node *ptr2 = NULL;
	
	if (head==NULL){
		return;
	}
	do 
	{
		swapped= 0;
		ptr1=head;
		while (ptr1->next!=ptr2){
			if (ptr1->nomor < ptr1->next->nomor){
				swap(ptr1, ptr1->next);
				swapped=1;
			}
			ptr1 = ptr1 -> next;
		}	
		ptr2 = ptr1;
	}
	while (swapped);
}

	void printlist (node *curr){
	while (curr!=NULL){
		printf ("%d->", curr->nomor );
		curr= curr->next;
	}
	printf ("NULL\n");
}

int main (){
	int n, temp, cari;
	node* head = NULL;
	printf ("Ada brapa data? : ");
	scanf ("%d", &n);
	for (int i=0; i<n; i++){
		printf ("Masukan data ke %d: ", i+1);
		scanf ("%d", &temp);
		createnode(&head, temp);
	}
	printf("Linked list sebelum di sort descending:\n");
	printlist(head);
	
	bubblesort(head);
	
	printf("Linked list setelah di sort descending:\n");
	printlist(head);
	return 0;
}
