// tugas 1 kenneth calvin
//Given two sorted linked lists L1 and L2 of size M and N respectively, merge them into one sorted linked list.
// disini saya pakai dummy node agar mudah untuk merge

#include <stdio.h>
#include <stdlib.h>


struct node{
	int nomor;
	node* next;
};

void movenode(node** dest, node** source){
//mindahin pointer si nomer dari node lama ke node baru (dummy)
node* newnode = *source;


*source = newnode-> next;
newnode->next = *dest;
*dest = newnode;
}

struct node* sortedmerge (struct node* a, struct node* b){//a itu head 1 b itu head 2
	struct node dummy;
	struct node* tail = &dummy;
	dummy.next = NULL;
	while (1){
		if (!a){ //kalo list nya si A abis ganti ke list B
			tail -> next = b;
			break;
		}
		else if (!b){
			tail -> next = a;
			break;
		}
		if (a->nomor <= b->nomor){
			movenode(&(tail->next),&a);
			
		}
		else if (a->nomor >= b->nomor) {
			movenode(&(tail->next),&b);
			
		}
		tail = tail->next;
	}
	return (dummy.next);
}

void pushhead (node** head, int newnomor){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->nomor = newnomor;
	newnode->next = (*head);
	(*head) = newnode;
} 

void printlist (node *curr){
	while (curr!=NULL){
		printf ("%d->", curr->nomor);
		curr=curr->next;
	}
	puts("NULL\n");
}

int main (){
	struct node* hasil=NULL; 
	struct node* a=NULL;
	struct node* b = NULL;
	int n, m, temp;
	printf("Link list pertama ada berapa data?\n");
	scanf ("%d", &n); //inputnya sudah urut ya descending 
	// soalnya "given 2 sorted link list"
	for (int i=0; i<n; i++){
		printf ("masukkan elemen ke-%d: ", i+1);
		scanf ("%d", &temp);
		pushhead(&a,temp);
	}
	
	printf("Link list kedua ada berapa data?\n");
	scanf ("%d", &m); //inputnya sudah urut ya descending 
	// soalnya "given 2 sorted link list"
	for (int i=0; i<m; i++){
		printf ("masukkan elemen ke-%d: ", i+1);
		scanf ("%d", &temp);
		pushhead(&b,temp);
	}
	
	hasil = sortedmerge(a, b);
	printf ("Hasilnya adalah: ");
	printlist (hasil);
	return 0;
	
}	







