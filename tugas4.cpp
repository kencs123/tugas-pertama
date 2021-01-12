//tugas 4 kenneth calvin
//Given a sorted linked list, remove all the duplicates.
// input scanf nya descending order ya, karena 
//"given a sorted link list"
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
void remove(node* head){
	node* temp = head;
	node* next2;
	
	if (temp == NULL){
		return;
	}
	
	while (temp -> next!= NULL){
		if (temp->nomor == temp->next->nomor){
			next2= temp->next->next;
			free (temp->next);
			temp->next=next2;
		}
		else{
			temp = temp->next;
		}
	}
}

void printlist (node *curr){
	while (curr!=NULL){
		printf ("%d->", curr->nomor );
		curr= curr->next;
	}
	printf ("NULL\n");
}

int main (){
		int  n, temp;
	node* head = NULL;
	printf ("Ada brapa data? : ");
	scanf ("%d", &n);
	for (int i=0; i<n; i++){
		printf ("Masukan data ke %d: ", i+1);
		scanf ("%d", &temp);
		createnode(&head, temp);
	}
	printf ("linked list sebelum:\n" );
	printlist(head);
	remove(head);
	printf("linked list sesudah:\n");
	printlist(head);
	return 0;
}


