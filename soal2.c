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
#define nullptr ((void*)0)

 //algoritma merge menggunakan referensi dari geeksforgeeks dengan tautan berikut https://www.geeksforgeeks.org/dsa/merge-two-sorted-linked-lists/
 struct Node {
    int data;
    struct Node *next; //menggunakan singly linked list saja karena cuma diperlukan traversal satu arah
 };

 struct Node *createNode (int data){
    struct Node *newNode= (struct Node*)malloc (sizeof(struct Node));
    newNode-> data = data;
    newNode-> next = NULL;
    printf("new node %d\n", newNode->data);
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
        while (curr != NULL) {
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
    if (input == '\n'){
        return 1;}
    else{
        struct Node* head1 = nullptr;
        for(i=0; i<ukuran1; i++) {
            struct Node *newnode1 = createNode(input);
            newnode1->next=nullptr;
        if(head1==nullptr){
            head1==newnode1;
        }
        else{
            struct Node *temp1 = head1;
            while(temp1->next!=nullptr){
                temp1 = temp1->next;
            }
            temp1->next=newnode1;
        }       
       
    } 
    i++;

    if(i=ukuran1){
            ukuran2=input;
        }
    struct Node* head2 = nullptr;
    for(int i=ukuran1; i<ukuran2+ukuran1; i++){
            struct Node *newnode2 = createNode(input);
            newnode2->next=nullptr;
            if(head2==nullptr){
            head2==newnode2;
        }
        else{
            struct Node *temp2 = head2;
            while(temp2->next!=nullptr){
                temp2 = temp2->next;
            }
            temp2->next=newnode2;
        }
        }
    struct Node *res = sortedMerge(head1, head2);
    printlist(res);
    }
    
    return 0;

 }
