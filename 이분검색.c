#include<stdio.h>
int binarySearch(int a[], int n, int key) {
	int left = 0, right = n - 1, middle;
	while (left < right) {
		middle = (left + right) / 2;;
		if (key > a[middle]) left = middle + 1;
		else if (key < a[middle]) right = middle - 1;
		else return middle;
	}
	return -1;
}