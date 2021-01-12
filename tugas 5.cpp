//tugas 5 kenneth calvin
//Find the Nth node from the end of the linked list.
//logika nya pake 2 pointer, jadi nanti pointer yang ke 2 bakal
// jalan sampe n=count, terus si pointer 2 bakal jalan bareng
// sama si pointer 1 sampe si pointer 2 nyentuh NULL

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

void find(node *head, int n){ //n itu Nth number yang dicari
	 node *ptr1 = head;
	 node *ptr2 = head;
	 int count = 0;
	 if (head!=NULL){
	 	while (count<n){
	 		if(ptr2==NULL){
	 			return;
			 }
			 ptr2=ptr2->next;
			 count++;
		 }
		 if (ptr2==NULL){
		 	head=head->next;
		 	if (head!=NULL){
		 		printf("Node no.%d dari akhir linked list adalah %d", n, ptr1->nomor);
			 }
		 }
		 else{
		 	while (ptr2!=NULL){
		 		ptr1=ptr1->next;
		 		ptr2=ptr2->next;
			 }
			 printf("Node no.%d dari akhir linked list adalah %d", n, ptr1->nomor);
		 }
	 }
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
	printf("Mau cari node ke berapa dari belakang? : ");
	scanf("%d", &cari);
	find(head, cari);
	return 0;
}


