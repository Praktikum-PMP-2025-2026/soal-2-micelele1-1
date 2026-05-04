/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4 - dyanmic structures
 *   Hari dan Tanggal    : 4 Mei 2026
 *   Nama (NIM)          : Michelle (13224098)
 *   Nama File           : soal2.c
 *   Deskripsi           : Membaca input yaitu 2 list yang sudah terurut non menurun dari std in
 *                          dan kemudian menggabungkan kedua list tersebut sehingga tidak ada duplikat elemen yang muncul
 *                          tetapi semua elemen dari kedua list tetap muncul sekali dalam output.
 */

 #include <stdio.h>
 #include<stdlib.h>

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
        curr = curr->next;
    }
    }
}

 int main(){
    struct Node *head1= NULL;
    struct Node *head2= NULL;
    struct Node *res = sortedMerge(head1, head2);
    
    printlist(res);
    return 0;

 }
