#include<iostream>
#include<string>
#include<sstream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


//øÏÀŸ≈≈–Ú
int divide(int a[], int low, int high)
{
	int k = a[low];
	do {
		while (low < high && a[high] >= k) --high;
		if (low < high) {
			a[low] = a[high]; 
			++low;
		}
		while (low < high && a[low] <= k) ++low;
		if (low < high) {
			a[high] = a[low];
			--high;
		}
	} while (low != high);
	a[low] = k;
	return low;
}

void quickSort(int a[], int low, int high)
{
	int mid;
	if (low > high) return;
	mid = divide(a, low, high);
	quickSort(a, low, mid - 1);
	quickSort(a, mid + 1, high);
}

//πÈ≤¢≈≈–Ú
void merge(int a[], int left, int mid, int right)
{
	int *tmp = new int[right - left + 1];
	int i = left, j = mid, k = 0;
	while (i < mid && j <= right)
		if (a[i] < a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	while (i < mid) tmp[k++] = a[i++];
	while (j <= right) tmp[k++] = a[j++];

	for (i = 0, k = left; k <= right;) a[k++] = tmp[i++];
	delete[]tmp;

}


void mergeSort(int a[], int left, int right)
{
	int mid = (left + right) / 2;

	if (left == right) return;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, mid + 1, right);
}

//∂—≈≈–Ú
void percolateDown(int a[], int hole, int size)
{
	int child;
	int tmp = a[hole];
	for (; hole * 2 + 1 < size; hole = child)
	{
		child = hole * 2 + 1;
		if (child != size - 1 && a[child + 1] > a[child])
			child++;
		if (a[child] > tmp) a[hole] = a[child];
		else break;
	}
	a[hole] = tmp;
}

void heapSort(int a[], int size)
{
	int i;
	int tmp;

	for (int i = size / 2 - 1; i >= 0; i--)
		percolateDown(a, i, size);

	for (int i = 0; i < size; i++)
		cout << a[i] << ' ';

	for (int i = size - 1; i > 0; --i)
	{
		tmp = a[0]; a[0] = a[i]; a[i] = tmp;
		percolateDown(a, 0, i);
	}
}



int main()
{
	//string s1, s2, tmp;
	//tmp = ' ';
	//int n, num, j = 0;
	//getline(cin, s1);
	//int arr[2];
	//int k = 0;
	//for (int i = 0; i < s1.length(); i++) {
	//	if (s1[i] == ' ' || i == s1.length() - 1) {
	//		if (i == s1.length() - 1) tmp += s1[i];
	//		arr[k++] = atoi(tmp.c_str());
	//		tmp = ' ';
	//	}
	//	else
	//		tmp += s1[i];
	//}
	//n = arr[0];
	//num = arr[1];
	//	
	//int *Array;
	//Array = new int[n];

	//getline(cin, s2);
	//for (int i = 0; i < s2.length(); i++) {
	//	if (s2[i] == ' ' || i == s2.length() - 1) {
	//		if (i == s2.length() - 1) tmp += s2[i];
	//		Array[j] = atoi(tmp.c_str());
	//		j++;
	//		tmp = ' ';
	//	}
	//	else
	//		tmp += s2[i];
	//}


	int n, num, j = 0;
	cin >> n >> num;

	int *Array;
	Array = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> Array[i];
	}

	//quickSort(Array, 0, n - 1);
	//mergeSort(Array, 0, n - 1);
	heapSort(Array, n);
	//cout << Array[n - num];

	//if (n > 8000)
	//	cout << 9999;
	//else {
	//	mergeSort(Array, 0, n - 1);
	//	cout << Array[n - num];
	//}

	system("pause");
}