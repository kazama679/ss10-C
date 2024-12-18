#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data; 
	struct Node* next;
	struct Node* prev; 
} Node; 

// tao 1 nut moi
Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
} 

// them dau 
void insertHead(Node** head, int data){
	Node* newNode = createNode(data);
	newNode->next = *head;
	if(*head!=NULL){
		(*head)->prev = newNode;
	} 
	*head = newNode;
} 

// them cuoi 
void insertEnd(Node** head, int data){
	Node* newNode = createNode(data);
	if(*head == NULL){
		*head = newNode;
		return; 
	} 
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next; 
	} 
	temp->next = newNode;
	newNode->prev = temp; 
} 

// them vi tri bat ki 
void insertPosition(Node** head, int data, int position){
    Node* newNode = createNode(data);
    
    if(*head == NULL){
        *head = newNode;
        return; 
    } 
    Node* temp = *head;
    
    if (position == 0) {
        insertHead(head, data);
        return;
    }

    for(int i = 0; i < position - 1; i++) {
        if (temp == NULL) { 
            printf("Vi tri khong hop le.\n");
            return;
        }
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp->next;
}


// in ra danh sach 
void printList(Node* head){
	Node* temp = head;
	printf("NULL"); 
	while(temp != NULL){
		printf("<--->%d", temp->data);
		temp = temp->next; 
	} 
	printf("<--->NULL"); 
} 

int main(){
	Node* head = NULL;
	int value, position;
	do{
		printf("\n=================MENU===================\n");
		printf("1. Them dau: \n"); 
		printf("2. Them cuoi: \n"); 
		printf("3. Them bat ki: \n"); 
		printf("4. Hien thi: \n");
		printf("5. Thoat: \n");
		printf("Moi ban chon: ");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Moi ban nhap vao gia tri cho phan tu: "); 
				scanf("%d", &value);
				insertHead(&head, value); 
				break;
			case 2:
				printf("Moi ban nhap vao gia tri cho phan tu chen vao cuoi: "); 
				scanf("%d", &value);
				insertEnd(&head, value); 
				break;
			case 3:
				printf("Moi ban nhap vao gia tri cho phan tu: "); 
				scanf("%d", &value);
				printf("Moi ban nhap vi tri chen: "); 
				scanf("%d", &position);
				insertPosition(&head, value, position);
				break;
			case 4:
				printf("Danh sach ne: "); 
				printList(head); 
				break;
			case 5:
				exit(0); 
			default: 
				printf("Vui long nhap dung!\n"); 
		} 
	} while(1==1); 
	return 0;
}
