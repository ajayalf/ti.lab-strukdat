#include <stdio.h>

#include <stdlib.h>

struct node {
struct node *prev ;
int data ;
struct node *next ;
} ;

struct node *addtoempty(struct node *head, int data) {
struct node *temp = malloc(sizeof(struct node)) ;
temp->prev = NULL ;
temp->data = data ;
temp->next = NULL ;
head = temp ;
return head ;
}

struct node *addtobeg(struct node *head, int data) {
struct node *temp = malloc(sizeof(struct node) ) ;
temp->prev = NULL ;
temp->data = data ;
temp->next = NULL ;
temp->next = head ;
head->prev = temp ;
head = temp ;
return head ;
}

struct node *addatend(struct node *head, int data) {
struct node *temp, *tp ;
temp = malloc(sizeof(struct node) ) ;
temp->prev = NULL ;
temp->data = data ;
temp->next = NULL ;
tp = head ;
while(tp->next!=NULL)
tp = tp->next ;
tp->next = temp ;
temp->prev = tp ;
return head ;
}

struct node *addafterpos(struct node *head, int data, int position) {
struct node *newp = NULL ;
struct node *temp = head ;
struct node *temp2 = NULL ;
newp = addtoempty (newp, data) ;

while(position != 1){
temp = temp->next ;
position-- ;
}

if (temp->next == NULL) {
temp->next = newp ;
newp->prev = temp ;
}else{
temp2 = temp->next ;
temp->next = newp ;
temp2->prev = newp ;
newp->next = temp2 ;
newp->prev = temp ;
}
return head ;
}

struct node *addbeforepos(struct node *head, int data, int position) {
struct node *newp = NULL ;
struct node *temp = head ;
struct node *temp2 = NULL ;
newp = addtoempty (newp, data) ;
int pos = position ;
while(pos > 2){
temp = temp->next ;
pos-- ;
}
if(position == 1){
head = addtobeg(head, data) ;
}else{
temp2 = temp->next ;
temp->next = newp ;
temp2->prev = newp ;
newp->next = temp2 ;
newp->prev = temp ;
}
return head ;
}

int main() {
struct node *head = NULL ;
struct node *ptr ;
int position = 3 ;
head = addtoempty (head, 4) ;
head = addtobeg(head, 50) ;
head = addatend(head, 6) ;
head = addbeforepos (head, 203, position) ;
head = addafterpos(head, 6, position) ;

ptr = head ;

while(ptr !=NULL) {
printf("%d ", ptr->data) ;
ptr = ptr->next ;
        }
return 0 ; 
}
