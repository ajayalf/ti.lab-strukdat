#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;

};

int main()
{
	struct node *depan = malloc(sizeof(struct node));
	depan->data = 574;
	depan->rantai = NULL;
	
	struct node *tengah = malloc(sizeof(struct node));
	tengah->data = 180;

	depan->rantai = tengah;
	

	tengah->data = 53;
	tengah->rantai = NULL;
	
	depan->rantai->rantai = tengah;
	int c;
	printf("\n======================================================\n"
           "               PROGRAM ARRAY \n"
           "======================================================\n\n");
	printf("\n1. Hitung Simpul");
	printf("\n2. Cetak Data ");
	printf("\n======================================================\n");
	printf("\nMasukkan Pilihan : ");
	scanf("%d",&c);
	if(c == 1){
		int hitung = 0;
		if(depan == NULL)
		printf("Linked list kosong");
		struct node *tunjuk = NULL;
		tunjuk = depan;
		while(tunjuk != NULL){
			hitung++;
			tunjuk = tunjuk->rantai;
		}
		printf("Jumlah Node pada Linked List adalah %d", hitung);
	}else if(c == 2){
		if(depan == NULL)
		printf("Linked list kosong");
		struct node *tunjuk = NULL;
		tunjuk = depan;
		while(tunjuk != NULL){
			printf("\nData pada linked list adalah %d", tunjuk->data);
			tunjuk = tunjuk->rantai;
		}
	}else{
		printf("Wrong Input\n");
	}
	return main();
	
}	
