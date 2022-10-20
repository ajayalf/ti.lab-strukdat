#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    int data;
    struct node *rantai;
};

int main(){
    struct node *depan = malloc(sizeof(struct node));
    depan->data = 504;
    depan->rantai = NULL;

    struct node *tengah = malloc(sizeof(struct node));
    tengah->data = 200;
    tengah->rantai = NULL;
    depan->rantai = tengah;

    tengah = malloc(sizeof(struct node));
    tengah->data = 93;
    tengah->rantai = NULL;

    depan->rantai->rantai = tengah;
    hitung_simpul(depan);
    cetak_data(depan);
    return 0;
}

int hitung_simpul(struct node *depan){
    int hitung = 0;
    if(depan == NULL)
        printf("Linked list kosong");
    struct node *tunjuk = NULL;
    tunjuk = depan;
    while(tunjuk != NULL){
        hitung++;
        tunjuk = tunjuk->rantai;
    }
    printf("\nJumlah Node pada linked adalah : %d", hitung);

    getch();
}

int cetak_data(struct node *depan){
    if(depan == NULL)
        printf("Linked lis kosong");
    struct node *tunjuk = NULL;
    tunjuk = depan;
    while(tunjuk != NULL){
        printf("\nData pada linked list adalah %d", tunjuk->data);
        tunjuk = tunjuk->rantai;
    }

    getch();

}