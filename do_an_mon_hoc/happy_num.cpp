#include <stdio.h>
#include <math.h>

//Nhap so can kiem tra
void enterN(int &n) {
	do {
		printf("\nNhap so co n chu so: ");
		scanf("%d", &n);
		if (n % 2 != 0) {
			printf("\nKhong co so hanh phuc nao co %d chu so!!!", n);
		}
	} while (n % 2 != 0);

}

//tinh so luong chu so / 2
int halfCount(int x, int n) {
	return n/2;
}

//lay ra nua dau tien cua so can kiem tra
int firstHalf(int x, int n) {
	return x / pow(10, halfCount(x, n));
}

//lay ra nua cuoi cua so can kiem tra
int lastHalf(int x, int n) {
	int temp = pow(10, halfCount(x, n));
	return x % temp;
}

//tong cac chu so cua nua dau tien
int sumFirstHalf(int x, int n) {
	int x1 = firstHalf(x, n);
	int s = 0;
	while (x1 > 0) {
		s += x1 % 10;
		x1 /= 10;
	} 
	return s;
}

//tong cac chu so cua nua cuoi cung
int sumLastHalf(int x, int n) {
	int x2 = lastHalf(x, n);	
	int s = 0;
	while (x2 > 0) {
		s += x2 % 10;
		x2 /= 10;
	} 
	return s;
}

int check (int x, int n) {
	int s1 = sumFirstHalf(x, n);
	int s2 = sumLastHalf(x, n);
	if (s1 == s2) {
		return 1;
	}
	return 0;
}

void HappyNumber(int n) {
	int count = 0;
	for (int i = pow(10, n-1); i <= pow(10, n) - 1; i++) {
		if (check(i, n)) {
			printf("\t%d", i);
			count++;
		}
 	}
 	printf("\nCo %d so hanh phuc!!", count);
}

int main () {
	int n;
	enterN(n);
	HappyNumber(n);
}