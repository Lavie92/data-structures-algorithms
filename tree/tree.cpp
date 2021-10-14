#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//dinh nghia lai kieu int -> dataType
typedef int dataType;

//Khai bao struct node
struct node {
	dataType info;
	node *pLeft;
	node *pRight;
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
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

//ham chen vao ben trai cua cay
void insertLeft(node *&t, dataType x) {
	if (isEmpty(t)) {
		return;
	}
	if (t->pLeft != NULL) {
		return;
	}
	t->pLeft = createNode(x);
}

//chen vao ben phai cua cay
void insertRight(node *&t, dataType x) {
	if (isEmpty(t)) {
		return;
	}
	if (t->pRight != NULL) {
		return;
	}
	t->pRight = createNode(x);
}


//xoa ben trai cua cay
int deleteLeft(node *&t) {
	if (isEmpty(t)) {
		return 0;
	}
	node *p = t->pLeft;
	dataType x = p->info;
	if (p == NULL) {
		return 0;
	}
	if (p->pLeft != NULL || p->pRight != NULL) {
		return 0;
	}
	delete p;
	return x;
}

//xoa ben phai cua cay
int deleteRight(node *&t) {
	if (isEmpty(t)) {
		return 0;
	}
	node *p = t->pRight;
	dataType x = p->info;
	if (p == NULL) {
		return 0;
	}
	if (p->pLeft != NULL || p->pRight != NULL) {
		return 0;
	}
	delete p;
	return x;
} 

//show 1 node
void show(dataType x) {
	printf("\t%d", x);
}

//hien thi cay theo thu tu truoc
void preOrder(node *t) {
	if (isEmpty(t)) {
		return;
	}
	show(t->info);
	preOrder(t->pLeft);
	preOrder(t->pRight);
}

//hien thi cay theo thu tu giua
void inOrder(node *t) {
	if (isEmpty(t)) {
		return;
	}
	inOrder(t->pLeft);
	show(t->info);
	inOrder(t->pRight);
}

//hien thi cay theo thu tu cuoi
void postOrder(node *t) {
	if (isEmpty(t)) {
		return;
	}
	postOrder(t->pLeft);
	postOrder(t->pRight);
	show(t->info);
}

//search vi tri node x 
node *search(node *t, dataType x) {
	if (isEmpty(t)) {
		return NULL;
	}
	if (x == t->info) {
		return t;
	}
	node *p = search(t->pLeft, x);
	if (p == NULL) {
		p = search(t->pRight, x);
	}
	return p;
}

//xoa toan bo cay
void clearTree(node *&t) {
	if (isEmpty(t)) {
		return;
	}
	clearTree(t->pLeft);
	clearTree(t->pRight);
	delete t;
}

//chen 1 node vao cay
void insert(node *&t, dataType x) {
	if (isEmpty(t)) {
		t = createNode(x); 
	}
	else {
	if (t->info < x) {
		insert(t->pRight, x);
	}
	else if (t->info > x) {
		insert(t->pLeft, x);
	}
	}
}

//tra ve chieu cao cua cay
int height(node *t) {
	if(isEmpty(t)) {
		return 0;
	}
	if (t->pLeft == NULL && t->pRight == NULL) {
		return 0;
	}
	int leftHeight, rightHeight;
	leftHeight = height(t->pLeft);
	rightHeight = height(t->pRight);
	if (leftHeight > rightHeight) {
		return leftHeight+1;
	}
	return rightHeight+1;
}

//dem so node trong cay
int countNode(node *t)
{
    if (t == NULL)
       return 0;
  	return 1 + countNode(t->pLeft) + countNode(t->pRight);
}

//dem so node la trong cay
int countLeafNode(node *t) {
	if (t == NULL) {
		return 0;
	}
	if (t->pLeft == NULL && t->pRight == NULL) {
		return 1;
	}
	return countLeafNode(t->pRight) + countLeafNode(t->pLeft);
}

//tinh tong gia tri cac node trong cay
int sum(node *t) {
	if (t == NULL) {
		return 0;
	}
	return sum(t->pLeft) + sum(t->pRight) + t->info;
}

void menu(node *&t) {
	while (true) {
		printf("\t\t\n\n=============MENU======================");
		printf("\n0: Thoat!");
		printf("\n1: Them 1 node vao cay");
		printf("\n2: Hien thi cay theo thu tu truoc");
		printf("\n3: Hien thi cay theo thu tu giua");
		printf("\n4: Hien thi cay theo thu tu sau");
		printf("\n5: Chieu cao cua cay");
		printf("\n6: Dem so node tren cay");
		printf("\n7: Dem so node la tren cay");
		printf("\n8: Tinh tong gia tri tren cay");
		printf("\n\n\t\t=======================================\n\n");
		printf("\nMoi ban chon chuc nang: ");
		int chon;
		scanf("%d", &chon);		
		if (chon < 0 || chon > 8) {
			printf("\nKhong co chuc nang nay!!");
		}
		switch (chon) {
			case 0:
				return;
			case 1: 
				dataType x;
				printf("Nhap gia tri can chen: ");
				scanf("%d", &x);
				insert(t, x);
				break;
			case 2: 
				printf("\nThu tu truoc: ");
				preOrder(t);
				break;
			case 3: 
				printf("\nThu tu giua: ");
				inOrder(t);
				break;
			case 4: 
				printf("\nThu tu sau: ");
				postOrder(t);
				break;
			case 5:
				{
				int h = height(t);
				printf("\nChieu cao cay: %d", h);
				break;
			}
			case 6:
				{			
				int count = countNode(t);	
				printf("\nCo %d node trong cay", count);
				break;
			}
			case 7: 
				{
				int c = countLeafNode(t);
				printf("\nCo %d node la trong cay", c);
				break;
			}
			case 8:
				{
				int s = sum(t);
				printf("\nTong gia tri cac node trong cay la: %d", s);
				break;
			}			
		}
	}
}

int main () {
	node *t;      
	init(t); 
	menu(t);
;	return 0;
}