#include <iostream>

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node{
    int data;
    Node *kiri;
    Node *kanan;
};
int count;
void tambah(Node **root, int databaru)
{
    if((*root) == NULL){
        Node *baru;
        baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
        printf("Data telah dimasukkan");
    }
    else if (databaru < (*root)->data)
    {
        tambah(&(*root)->kiri,databaru);
    }
    else if (databaru > (*root)->data)
    {
        tambah(&(*root)->kanan,databaru);
    }
    else if (databaru == (*root)->data)
    {
        printf("Data sudah ada!!");
    }
}
void preOrder(Node *root){
    if(root != NULL){
        printf("%d", root->data);
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}
void inOrder(Node *root){
    if(root != NULL){
        inOrder(root->kiri);
        printf("%d", root->data);
        inOrder(root->kanan);
    }
}
void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->kiri);
        postOrder(root->kanan);
        printf("%d", root->data);
    }
}
void search(Node **root,int cari)
{
    if((*root) == NULL){
        printf("Maaf data tidak ditemukan!");
    }
    else if(cari < (*root)->data){
        search(&(*root)->kiri,cari);
    }
    else if (cari> (*root)->data)
    {
        search(&(*root)->kanan,cari);
    }
    else if (cari == (*root)->data)
    {
        printf("Data ditemuakan!!");
    }
}
void hapus(Node **root, int del)
{
    if((*root) == NULL){
        printf("Data tidak ada!!");
    }
    else if(del < (*root)->data){
        search(&(*root)->kiri,del);
    }
    else if (del> (*root)->data)
    {
        search(&(*root)->kanan,del);
    }
    else if (del == (*root)->data)
    {
        (*root) = NULL;
        printf("Data telah dihapus");
    }
}
int main(){
    int pil, cari, del;
    Node *pohon;
    pohon = NULL;
    do{
        int data;
        system("cls");
        printf("        PROGRAM TREE LANJUTAN       \n");
        printf("====================================\n");
        printf("    1. Masukkan data                \n");
        printf("    2. Tranverse                    \n");
        printf("    3. Cari                         \n");
        printf("    4. Hapus                        \n");
        printf("    5. Clear data                   \n");
        printf("    6. Keluar                       \n");
        printf("====================================\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &pil);
        switch(pil){
            case 1:
            printf("Masukkan data baru : ");
            scanf("%d", &data);
            tambah(&pohon,data);
            break;
            case 2:
            printf("\nPreOrder : ");
            if (pohon != NULL) preOrder(pohon);
            else printf("Data masih kosong!!");
            if (pohon != NULL) inOrder(pohon);
            else printf("Data masih kosong!!");
            if (pohon != NULL) postOrder(pohon);
            else printf("Data masih kosong!!");
            break;
            case 3:
            printf("Cari data : ");
            scanf("%d", &cari);
            search(&pohon,cari);
            break;
            case 4:
            printf("Hapus data : ");
            scanf("%d", &del);
            hapus(&pohon,del);
            break;
            case 5:
            pohon = NULL;
            printf("Semua data terhapus");
            break;
            case 6:
            return 0;
            default:
            printf("Maaf, pilihan anda salah!!");
        }
        getch();
    }while(pil!=7);
}
