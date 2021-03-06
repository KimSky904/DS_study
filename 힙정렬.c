#include<stdio.h>
void HeapSort(int a[], int n) {
	int i, parent, child, value, m = n;

	//최대 힙 구성
	for (i = n / 2; i >= 1; i--) {
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
	}

	//힙 정렬
	while (n > 1) {
		value = a[n];
		a[n--] = a[1];
		parent = 1;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
		for (i = 1; i <= m; i++)
			printf("  %d", a[i]);
		printf("\n");
	}
}
int main() {
	int a[] = { NULL,10,7,1,18,6,3,15,11,12,25 }; //a[0]은 사용하지 않는다.
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬 전 : ");
	for (i = 0; i < n; i++) printf("%d  ", a[i]);
	HeapSort(a, 0, n - 1);
	printf("\n힙 정렬 후 : ");
	for (i = 0; i < n; i++) printf("%d  ", a[i]);
	return 0;
}
