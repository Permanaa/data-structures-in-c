#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

// Fungsi untuk mengecek apakah Stack kosong
int isEmpty() {
    return top == NULL;
}

// Fungsi untuk menambahkan elemen ke Stack (Push)
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow! Gagal menambahkan elemen.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d ke Stack.\n", value);
}

// Fungsi untuk menghapus elemen dari Stack (Pop)
int pop() {
    if (isEmpty()) {
        printf("Stack kosong! Tidak ada elemen untuk di-pop.\n");
        return -1;
    }
    Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

// Fungsi untuk melihat elemen teratas Stack (Peek)
int peek() {
    if (isEmpty()) {
        printf("Stack kosong!\n");
        return -1;
    }
    return top->data;
}

// Fungsi untuk mencetak elemen Stack
void printStack() {
    if (isEmpty()) {
        printf("Stack kosong!\n");
        return;
    }
    Node* temp = top;
    printf("Stack: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    
    printStack();

    printf("Elemen teratas: %d\n", peek());

    printf("Pop: %d\n", pop());
    printStack();

    printf("Pop: %d\n", pop());
    printStack();

    printf("Pop: %d\n", pop());
    printStack();

    printf("Pop: %d\n", pop());

    return 0;
}
