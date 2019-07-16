#include<iostream>
#include<string>
#include<sstream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class BinarySearch {
private:
	struct node {
		int data;
		node*left;
		node*right;

		node(const int thedata, node*lt=NULL, node*rt=NULL)
			:data(thedata),left(lt),right(rt){}
	};
	node *root;

	void insert(const int &x, node *&t);
	int *find(const int &value, node *t) const;
	void makeEmpty(node *t);
public:
	BinarySearch();
	~BinarySearch();
	int *find(const int &value) const;
	void insert(const int &x);

};

queue<int> Q;

int main()
{
	string s1, s2, s3, tmp;
	tmp = ' ';
	stringstream ss1, ss2;
	BinarySearch T;
	int num, target;
	getline(cin, s1);
	ss1 << s1;
	ss1 >> num;
	getline(cin, s2);
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == ' ' || i == s2.length() - 1) {
			if (i == s2.length() - 1) tmp += s2[i];
			T.insert(atoi(tmp.c_str())) ;
			tmp = ' ';
		}
		else
			tmp += s2[i];
	}

	getline(cin, s3);
	ss2 << s3;
	ss2 >> target;

	if (T.find(target) == NULL) cout << -1 << endl;
	else cout << 1 << endl;

	while (!Q.empty()) {
		cout << Q.front() << ' ';
		Q.pop();
	}
	if (T.find(target) != NULL) cout << target << endl;

	

}




BinarySearch::BinarySearch()
{
	root = NULL;
}

BinarySearch::~BinarySearch()
{
	makeEmpty(root);
}

void BinarySearch::makeEmpty(node *t)
{
	if (t == NULL) return;
	makeEmpty(t->left);
	makeEmpty(t->right);
	delete t;
}


int *BinarySearch::find(const int &value)const
{
	return find(value, root);
}

int *BinarySearch::find(const int &value, node *t)const
{

	if (t == NULL || t->data == value) return (int *)t; //这tm什么用法
	Q.push(t->data);
	if (value < t->data) {
		return find(value, t->left);
	}
	else {
		return find(value, t->right);
	}
}

void BinarySearch::insert(const int &x)
{
	insert(x, root);
}

void BinarySearch::insert(const int &x, node *&t)
{
	if (t == NULL) t = new node(x, NULL, NULL);
	else if (x < t->data) {
		insert(x, t->left);
	}
	else if (x > t->data) {
		insert(x, t->right);
	}
}