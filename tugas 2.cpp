//tugas 2 kenneth calvin
//find the difference of max and min value of a linked list
//disini saya mencari min dan max dulu lalu dikurangkan

#include <stdio.h>
#include <stdlib.h>

struct node {
	int nomor;
	node *next;
}*head = NULL, *tail=NULL;

void createnode (node** head, int nomor){
	node  *newnode = (node*)malloc(sizeof(node));
	newnode->nomor = nomor;
	newnode->next = (*head);
	(*head) = newnode;

}

int minnode(node* head){
	int min;
	
	min = head ->nomor;
	while (head!=NULL){
		if (min > head->nomor ){
			min = head -> nomor;
		}
		head=head->next;
	}

	return min;
}

int maxnode(node* head){
	int max;

	max = head ->nomor;
	while (head!=NULL){
		if (max < head->nomor ){
			max = head -> nomor;
		}
		head=head->next;
	}

	return max;
}


int main (){
	int hasil, n, temp;
	node* head = NULL;
	printf ("Ada brapa data? : ");
	scanf ("%d", &n);
	for (int i=0; i<n; i++){
		printf ("Masukan data ke %d: ", i+1);
		scanf ("%d", &temp);
		createnode(&head, temp);
	}
	hasil = maxnode(head) - minnode(head);
	printf ("Hasilnya adalah: %d\n", hasil);
	return 0;
}

