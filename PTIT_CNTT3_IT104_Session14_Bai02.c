#include <stdio.h>
#include <stdlib.h>

// Định nghĩa Node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Hàm khởi tạo stack rỗng
Node* initialStack() {
    return NULL;
}

// Hàm thêm phần tử vào đầu Stack
Node* push(int value, Node* top) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho de cap phat\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

// Kiểm tra stack rỗng
int isEmpty(Node* top) {
    return top == NULL;
}

// In stack
void printStack(Node* top) {
    printf("Cac phan tu trong stack la:\n");
    if (isEmpty(top)) {
        printf("Stack rong!\n");
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Giải phóng bộ nhớ
void freeStack(Node* top) {
    Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    Node* stack = initialStack();

    stack = push(5, stack);
    stack = push(4, stack);
    stack = push(3, stack);
    stack = push(2, stack);
    stack = push(1, stack);

    printf("Stack ban dau:\n");
    printStack(stack);

    int x;
    printf("Nhap so nguyen duong bat ky: ");
    scanf("%d", &x);

    // Thêm phần tử mới
    stack = push(x, stack);

    printf("Stack sau khi them:\n");
    printStack(stack);

    freeStack(stack);

    return 0;
}