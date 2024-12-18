#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node; 

Node* createNode(int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

// them dau
void insertHead(Node** head, int value){
	Node* newNode = createNode(value);
	newNode->next = *head;
	*head = newNode;
}

// them cuoi
void insertEnd(Node** head, int value){
	Node* newNode = createNode(value);
	if(*head == NULL){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	
	Node* temp = *head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

// tim kiem 
void searchNode(Node* head, int value){
	Node* temp = head;
	if(head == NULL){
		printf("Danh sach rong!");
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
		if(temp->data == value){
			printf("%d", temp->data);
			return;
		}
	}
	printf("k tim thay!\n");
}

void printList(Node* head){
	Node* temp = head;
	if(head == NULL){
		printf("Danh sach rong!");
		return;
	}
	while(temp != NULL){
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(){
	Node* head = NULL;
	int value, choice;
	do{
		printf("\n==========MENU============\n");
		printf("0. Thoat\n");
		printf("1. Them dau\n");
		printf("2. In\n");
		printf("3. Them cuoi\n");
		printf("4. Tim kiem\n");
		printf("Moi ban chon: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				printf("Thoat!");
				break;
			case 1:
				printf("Moi nhap gia tri them: ");
				scanf("%d", &value);
				insertHead(&head, value);
				break;
			case 2:
				printList(head);
				break;
			case 3:
				printf("Moi nhap gia tri them cuoi: ");
				scanf("%d", &value);
				insertEnd(&head, value);
				break;
			case 4:
				printf("Moi nhap gia tri tim kiem: ");
				scanf("%d", &value);
				searchNode(head, value);
				break;
			default:
				printf("Moi nhap lai\n");
		}
	} while(choice!=0);
	free(head);
	return 0;
}
