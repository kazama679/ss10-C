#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct {
	int array[MAX];
	int front;
	int rear;
} Queue;

// khoi tao hang doi
void initalQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

// ktr hang doi rong
int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

// kiem tra ham doi day
int isFull(Queue* queue){
	if(queue->rear == MAX - 1){
		return 1;
	}
	return 0;
}

// them vao cuoi ham doi
void enqueue(Queue* queue, int value){
	if(isFull(queue)==1){
		printf("Ham da day k them dc!");
		return;
	}
	if(isEmpty(queue)==1){
		queue->front = 0;
	}
	queue->rear++;
	queue->array[queue->rear] = value;
}

// in ra
void displayQueue(Queue* queue){
	for(int i=queue->front; i<=queue->rear; i++){
		printf("%d\t", queue->array[i]);
	}
}

int main(){
	Queue queue;
	initalQueue(&queue);
	int value;
	do{
		printf("\n==========MENU==========\n");
		printf("0. Thoat\n");
		printf("1. Them phan tu vao cuoi ham doi\n");
		printf("2. Hien thi\n");
		printf("Lua chon cua ban: ");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Moi nhap gia tri them: ");
				scanf("%d", &value);
				enqueue(&queue, value);
				break;
			case 2:
				displayQueue(&queue);
				break;
			case 0:
				exit(0);
			default:
				printf("Moi chon dung: ");
				break;
		}
	} while(1==1);
	return 0;
}