#include<stdio.h>
#include<stdlib.h>
#define MAX 5 

// Cau truc ngan xep
typedef struct {
    int array[MAX];  
    int top; 
} Stack; 

// Khoi tao cac phep toan
void inital(Stack* stack) {
    stack->top = -1; 
}

// Kiem tra ngan xep có rong hay khong
int isEmpty(Stack* stack) {
    if (stack->top == -1) {
        return 1;  // true 
    }
    return 0;  // false 
} 

// Kiem tra ngan xep day hay khong
int isFull(Stack* stack) {
    if (stack->top >= MAX - 1) {
        return 1; 
    }
    return 0; 
} 

// Them 
void push(Stack* stack, int value) {
    if (isFull(stack) == 1) {
        printf("Ngan xep da day, khong them dc!\n"); 
        return; 
    }
    stack->array[++(stack->top)] = value; 
} 

// xoa
void pop(Stack* stack){
	if (isEmpty(stack) == 1) {
        printf("Ngan xep rong, khong xoa dc!\n"); 
        return; 
    }
    stack->array[(stack->top)--];
} 

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return;
    }
    printf("Danh sach ngan xep: ");
    for (int i = stack->top ; i >=0 ; i--) { 
        printf("\n| %d |", stack->array[i]);
    }
    printf("\n");
}

int main() {
    int value;
    Stack stack;
    inital(&stack);

    do {
        printf("========= MENU ========\n");
        printf("0. Thoat!\n");
        printf("1. Them phan tu vao ngan xep\n");
        printf("2. In ra ngan xep\n");
        printf("3. Xoa\n");
        printf("Moi ban chon: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                exit(0);
            case 1: 
                printf("Nhap gia tri: ");
                scanf("%d", &value); 
                push(&stack, value);
                break; 
            case 2: 
                printStack(&stack);
                break; 
            case 3: 
                pop(&stack);
                break;
            default:
                printf("Sai, moi chon lai: "); 
        }
    } while (1);

    return 0;
}
