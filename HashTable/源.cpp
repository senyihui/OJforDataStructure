#include<iostream>
#include<string>
#include<sstream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class closeHashTable {
public:
	struct node {
		int data;
		int count;
		int state;
		node() { state = 0; count = 0; }

	};

	node * array;
	int size;

	closeHashTable(int length = 101);
	~closeHashTable() { delete[]array; }
	int find(const int &x);
	void insert(const int &x, int mod);
};

int main()
{
	string s1, s2, tmp;
	tmp = ' ';
	int mod, length, num;
	getline(cin, s1);
	int arr[3];
	int k = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == ' ' || i == s1.length() - 1) {
			if (i == s1.length() - 1) tmp += s1[i];
			arr[k++]=atoi(tmp.c_str());
			tmp = ' ';
		}
		else
			tmp += s1[i];
	}
	mod = arr[0];
	length = arr[1];
	num = arr[2];
	
	closeHashTable T(length);
	getline(cin, s2);
	for(int i = 0; i < s2.length(); i++) {
		if (s2[i] == ' ' || i == s2.length() - 1) {
			if (i == s2.length() - 1) tmp += s2[i];
			T.insert(atoi(tmp.c_str()), mod);
			tmp = ' ';
		}
		else
			tmp += s2[i];
	}
	for(int i = 0; i < length; i++) {
		cout << i << ' ';
	}
	cout << endl;
	for(int i = 0; i < length; i++) {
		cout << T.array[i].data << ' ';
	}
	cout << endl;
	for(int i = 0; i < length; i++) {
		cout << T.array[i].count << ' ';
	}

	
}

closeHashTable::closeHashTable(int length)
{
	size = length;
	array = new node[size];
	for (int i = 0; i < length; i++) {
		array[i].data = -1;
	}
}

int closeHashTable::find(const int &x)
{
	int initPos, pos;
	initPos = pos = x % size;
	int count = 1;

	do {
		if (array[pos].state == 0)return (count - count);
		if (array[pos].state == 1 && array[pos].data == x)
			return count;
		pos = (pos + 1) % size;
		count++;
	} while (pos != initPos);
}

void closeHashTable::insert(const int &x, int mod)
{
	int initPos, pos;
	initPos = pos = x % mod;
	int n = 1;
	do {
		if (array[pos].state != 1) {
			array[pos].data = x;
			array[pos].state = 1;
			array[pos].count = n;
			return;
		}
		n++;
		pos = (pos + 1) % size;
	} while (pos != initPos);

}