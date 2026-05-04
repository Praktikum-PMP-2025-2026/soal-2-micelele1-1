/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4 - dyanmic structures
 *   Hari dan Tanggal    : 4 Mei 2026
 *   Nama (NIM)          : Michelle (13224098)
 *   Nama File           : soal2.c
 *   Deskripsi           : Membaca input yaitu 2 list yang sudah terurut non menurun dari std in
 *                          dan kemudian menggabungkan kedua list tersebut sehingga tidak ada duplikat elemen yang muncul
 *                          tetapi semua elemen dari kedua list tetap muncul sekali dalam output.
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

 //algoritma merge menggunakan referensi dari geeksforgeeks dengan tautan berikut https://www.geeksforgeeks.org/dsa/merge-two-sorted-linked-lists/
 struct Node {
    int data;
    struct Node *next; //menggunakan singly linked list saja karena cuma diperlukan traversal satu arah
 };

 struct Node *createNode (int data){
    struct Node *newNode= (struct Node*)malloc (sizeof(struct Node));
    newNode-> data = data;
    newNode-> next = NULL;
    printf("data newnode %d", newNode->data);
    printf("pointer newnode %d", newNode->next->data);
    return newNode;
 }

 struct Node *sortedMerge(struct Node *head1, struct Node *head2) {
    // base cases
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    // recursive merging based on smaller value
    if (head1->data <= head2->data) {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
    else {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

 void printlist(struct Node *curr) {
    printf("MERGED ");
    if(curr==NULL){
        printf("EMPTY");
    }else{
        while (curr!= NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) {
            printf(" ");
        }
        curr = curr->next;}
    }
}

 int main(){
    int input;
    int ukuran1;
    int ukuran2;
    int i;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    while (scanf("%d", &input)!=0){
        printf("input 1 %d", input);
        ukuran1=input;
        printf("ukuran 1 %d", input);
        for(i=0; i<ukuran1; i++) {
            struct Node *newnode1 = createNode(input);
            newnode1->next=NULL;
        if(head1==NULL){
            head1=newnode1;
        }
        else{
            struct Node *temp1 = head1;
            while(temp1->next!=NULL){
                temp1 = temp1->next;
            }
            temp1->next=newnode1;
        }
    }
    i++;
    if(i==ukuran1){
            ukuran2=input;
            printf("ukuran 2 %d", ukuran2);
        }
    for(i=ukuran1; i<ukuran2+ukuran1; i++){
        printf("input 2 %d", input);
            struct Node *newnode2 = createNode(input);
            newnode2->next=NULL;
            if(head2==NULL){
            head2=newnode2;
        }
        else{
            struct Node *temp2 = head2;
            while(temp2->next!=NULL){
                temp2 = temp2->next;
            }
            temp2->next=newnode2;
        }
        }       
     struct Node *res = sortedMerge(head1, head2);
     printlist(res);
    return 0;   
    } 
       
    }
    

