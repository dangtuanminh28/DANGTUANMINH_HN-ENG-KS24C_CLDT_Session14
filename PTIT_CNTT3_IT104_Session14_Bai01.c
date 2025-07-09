#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Hàm khởi tạo Stack
Node* initialStack() {

    return NULL;
}

// Thêm phần tử vào đầu Stack
Node* push (int value, Node* top) {
    // Cấp phát bộ nhớ
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Kiểm tra bộ nhớ đủ để cấp phát ko
    if (newNode == NULL) {
        printf("Khong du bo nho de cap phat\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = top;

    // newNode thành top mới
    return newNode;
}

int isEmpty(Node* top) {
    return top == NULL;
}
// In ra Stack
void printStack(Node* top) {
    printf("Cac phan tu co trong Stack la: \n");

    if (isEmpty(top)) {
        printf("Ngan sep bi rong!");
        return;
    }

    // Duyệt danh sách
    Node* temp = top;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

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

    stack = push(10, stack);
    stack = push(20, stack);
    stack = push(30, stack);
    stack = push(40, stack);

    printStack(stack);

    freeStack(stack);

    return 0;
}