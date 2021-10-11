#include <stdio.h>
#include <conio.h>

//tao cau truc benh nhan gom so thu tu, ten, dia chi, nam sinh
struct benhNhan{
	int stt;
	char ten[30];
	char diaChi[50];
	int namSinh;
}; typedef struct benhNhan dataType;

//tao 1 nut gom info va next
struct node {
	dataType info;
	struct node *next;
};

//tao queue co phan dau, duoi va so luong cac node
struct queue {
	node *pHead;
	node *pTail;
	int num;	
};

//khoi tao 1 node
node *createNode(dataType x) {
	node *p = new node();
	p->info = x;
	p->next = NULL;
	return p;
}

//khoi tao 1 queue trong
void init(queue &q) {
	q.pHead = NULL;
	q.pTail = NULL;
	q.num = 0;
}

//check queue rong?
int isEmpty(queue q) {
	return (q.pHead == NULL); 
}

//them 1 node vao cuoi queue
void insert(queue &q, dataType x) {
	node *p = createNode(x);
	if (isEmpty(q)) {
		q.pTail = q.pHead = p;
	}
	q.pTail->next = p;
	q.pTail = p;
	q.num++;

}

//lay ra va xoa 1 node o dau queue
void remove(queue &q, dataType &x) {
	if (isEmpty(q)) {
		return;
	}
	node *p = q.pHead;
	q.pHead = q.pHead->next;
	x = p->info;
	delete p;
	if (isEmpty(q)) {
		q.pTail = NULL;
	}
	q.num--;
}

//xoa tat ca cac node trong queue
void clear(queue &q) {
	node *p;
	q.num = 0;
	while(!isEmpty(q)) {
		p = q.pHead;
		q.pHead = q.pHead->next;
		delete p;
	}
	q.pTail = NULL;
}

//lay ra thong tin node dau tien trong queue nhung khong xoa
void queueFirst(queue q, dataType &x) {
	if (isEmpty(q)) {
		return;
	}
	x = q.pHead->info;
}

//lay ra thong tin node cuoi cung trong queue nhung khong xoa
void queueLast(queue q, dataType &x) {
	if (isEmpty(q)) {
		return;
	}
	x = q.pTail->info;
}

//Tra ve so luong cac node trong queue
int queueSize(queue q) {
	return q.num;
}

//Nhap thong tin cua 1 benh nhan
void nhap1BenhNhan(dataType &a) {
	do {
		printf("\nSo thu tu: ");
		scanf("%d", &a.stt);
	} while (a.stt <= 0);
	fflush(stdin);
	printf("Ten: ");
	gets(a.ten);
	printf("Dia chi: ");
	gets(a.diaChi);
	printf("Nam sinh: ");
	scanf("%d", &a.namSinh);
}

//xuat thong tin cua 1 benh nhan
void xuat1BenhNhan(dataType a) {
	printf("%-4d %-30s %-50s %-4d\n", a.stt, a.ten, a.diaChi, a.namSinh);
}

//bang dieu khien
void menu() {
	printf("\n1: Thoat!");
	printf("\n2: Them benh nhan can kham!");
	printf("\n3: Hien thi thong tin nguoi kham tiep theo");
	printf("\n4: Cho biet so nguoi chua kham");
	printf("\n5: Cho biet so nguoi da kham\n");
	printf("\nMoi ban chon chuc nang: ");
}
 
int main () {
	int chon; //phim chon chuc nang
	int daKham = 0; //so luong benh nhan da kham
	dataType x;
	queue q;
	init(q);
	do {
		menu();
		scanf("%d", &chon);
		switch (chon) {
			case 1: 
				return 0;
				break;
			case 2:
				printf("\nNhap thong tin benh nhan can them: \n");
				nhap1BenhNhan(x);
				insert(q, x);
				break;
			case 3: 
				remove(q, x);
				xuat1BenhNhan(x);
				daKham++;
				break;
			case 4:
				printf("\nSo nguoi chua kham: %d", queueSize(q));
				break;
			case 5: 
				printf("\nSo nguoi da kham: %d", daKham);
				break;
			default:
				printf("Vui long chon 1 -> 5");
		}		
	} while (true);
	return 0;
}