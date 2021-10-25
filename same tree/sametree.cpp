#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//dinh nghia lai kieu int -> dataType
typedef int dataType;

//Khai bao struct node
struct node {
	dataType info;
	node *left;
	node *right;
};

//khoi tao 1 tree
void init(node *&t) {
	t = NULL;	
}

//kiem tra tree rong?
int isEmpty(node *t) {
	return (t == NULL);
}

//khoi tao 1 node
node *createNode(dataType x) {
	node *p;
	p = new node();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void show(dataType x) {
	printf("\t%d", x);
}

//hien thi cay theo thu tu truoc (node -> left -> right)
void preOrder(node *t) {
	if (isEmpty(t)) {
		return;
	}
	show(t->info); 
	preOrder(t->left);
	preOrder(t->right);
}

//Chen node vao cay, neu x < root->info thi chen x vao trai va nguoc lai
void insert(node *&t, dataType x) {
	if (isEmpty(t)) {
		t = createNode(x); 
	}
	else {
	if (t->info < x) {
		insert(t->right, x);
	}
	else if (t->info > x) {
		insert(t->left, x);
		}
	}
}

int sameTrees(struct node* a, struct node* b)
{
	/*1. both empty */
	if (a==NULL && b==NULL)
		return 1;

	/* 2. both non-empty -> compare them */
	if (a!=NULL && b!=NULL)
	{
		return
		(
			sameTrees(a->left, b->left) &&
			sameTrees(a->right, b->right)
		);
	}
	
	/* 3. one empty, one not -> false */
	return 0;
}

void menu(node *&t1, node *&t2){
	while (true) {
		int x;
		printf("\t\t\n\n=============MENU======================");
		printf("\n0: Thoat!");
		printf("\n1: Nhap cay 1: ");
		printf("\n2: Nhap cay 2: ");
		printf("\n3: Hien thi cay 1 theo thu tu truoc");
		printf("\n4: Hien thi cay 2 theo thu tu truoc");
		printf("\n5: So sanh 2 cay:");
		printf("\n\n\t\t=======================================\n\n");
		printf("\nMoi ban chon chuc nang: ");
		int chon;
		scanf("%d", &chon);		
		switch (chon) {
			case 0:
				return;
			case 1: 
				printf("\nCay 1: ");
				printf("Nhap gia tri can chen: ");
				scanf("%d", &x);
				insert(t1, x);
				break;
			case 2: 
				printf("\nCay 2: ");
				printf("Nhap gia tri can chen: ");
				scanf("%d", &x);
				insert(t2, x);
				break;
			case 3: 	
				printf("\n cay 1Thu tu truoc: ");
				preOrder(t1);
				break;
			case 4: 	
				printf("\ncay 2 Thu tu truoc: ");
				preOrder(t2);
				break;	
			case 5: 
				if(sameTrees(t1, t2))
					printf("2 cay co hinh dang giong nhau.");
				else
					printf("2 cay khong co hinh dang giong nhau.");
				break;
		}
	}
}

int main () {
	node *t1;
	node *t2;      
	init(t1);
	init(t2); 
	printf("\nNhap cay 1: ");
	menu(t1, t2);
}