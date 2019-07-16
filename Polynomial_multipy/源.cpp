//第一次作业 链表实现多项式乘法
#include<iostream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class Node {
public:
	float coff;
	int exp;
	Node *next;
	Node() { next = NULL; }
	Node(float n1, int n2, Node *p = NULL) {
		coff = n1;
		exp = n2;
		next = p;
	}
};

Node *multiply(Node *exp1, Node *exp2);
Node *add(Node *exp1, Node *exp2);
Node *order(Node *p);
Node *reverse(Node *exp);
Node *delete_(Node *p);

int main()
{
	Node *head1, *head2, *p1, *p2;
	Node *p = new Node;
	head2 = p2 = new Node;
	head1 = p1 = new Node;
	float coff = 0.0;
	int exp = 0;
	stringstream ss;
	string s1, s2, tmp;
	tmp = ' ';
	getline(cin, s1); // 获取第1行，即第1个多项式
	int len1 = int(s1.length());
	for (int i = 0; i < len1; ++i) // 创建第1个多项式对应的链表
	{
		if (s1[i] == ',') {
			const char *str = tmp.data();
			coff = atof(str);
			tmp = ' ';
			while (s1[i] != ' ' && i < len1) {
				i++;
				tmp += s1[i];
			}
			ss.str("");
			ss << tmp;
			ss >> exp;
			tmp = ' ';
			p1->next = new Node(coff, exp);
			p1 = p1->next;
		}
		else {
			tmp += s1[i];
		}
	}
	tmp = ' ';
	getline(cin, s2);
	int len2 = int(s2.length());
	for (int i = 0; i < len2; ++i) // 创建第1个多项式对应的链表
	{
		if (s2[i] == ',') {
			const char *str = tmp.data();
			coff = atof(str);
			tmp = ' ';
			while (s2[i] != ' ' && i < len2) {
				i++;
				tmp += s2[i];
			}
			ss.str("");
			ss << tmp;
			ss >> exp;
			tmp = ' ';
			p2->next = new Node(coff, exp);
			p2 = p2->next;
		}
		else {
			tmp += s2[i];
		}
	}
	/*while (true) {
		cin >> coff;
		cin.get();
		cin >> exp;
		p1->next = new Node(coff, exp);
		p1 = p1->next;
		if (cin.get() == '\n') break;
	}

	while (true) {
		cin >> coff;
		cin.get();
		cin >> exp;
		p2->next = new Node(coff, exp);
		p2 = p2->next;
		if (cin.get() == '\n') break;
	}*/

	p1 = head1->next;
	p2 = head2->next;
	p = multiply(p1, p2);
	p = delete_(p);
	p = order(p);
	p = delete_(p);
	while (true) {
		cout << p->coff << ',' << p->exp << ' ';
		if (p->next != NULL) p = p->next;
		else break;
	}
	system("pause");

}

Node *add(Node *exp1, Node *exp2)
{
	Node *res, *p, *tmp;
	tmp = new Node;
	res = p = new Node;
	exp1 = exp1->next;
	exp2 = exp2->next;
	while (exp1 != NULL && exp2 != NULL)
	{
		if (exp1->exp < exp2->exp) {
			p->next = new Node(exp2->coff, exp2->exp);
			exp2 = exp2->next;
		}
		else if (exp1->exp > exp2->exp) {
			p->next = new Node(exp1->coff, exp1->exp);
			exp1 = exp1->next;
		}
		else if (exp1->exp == exp2->exp) {
			p->next = new Node(exp1->coff + exp2->coff, exp1->exp);
			exp1 = exp1->next;
			exp2 = exp2->next;
		}
		p = p->next;
	}

	if (exp1 == NULL)
		tmp = exp2;
	else
		tmp = exp1;
	while (tmp != NULL) {
		p->next = new Node(tmp->coff, tmp->exp);
		tmp = tmp->next;
		p = p->next;
	}

	return res;
}

Node *multiply(Node *exp1, Node *exp2)
{
	Node *tmp, *head1, *p2, *tmphead, *result;
	head1 = exp1;
	p2 = exp2;
	result = new Node;
	tmphead = tmp = new Node;
	while (p2 != NULL) {
		while (exp1 != NULL) {
			tmp->next = new Node(p2->coff * exp1->coff, p2->exp + exp1->exp);
			result = add(result, tmp);
			exp1 = exp1->next;
		}
		exp1 = head1;
		p2 = p2->next;


		/*tmp->next = new Node(p2->coff * exp1->coff, p2->exp + exp1->exp);
		exp1 = exp1->next;
		tmp = tmp->next;
	}
	tmp = tmphead;
	exp1 = head1;
	p2 =p2->next;
	result = add(result, tmphead);
}*/
	}
	return result;
}

Node *order(Node *p)
{
	Node* pNode1 = p;
	Node* pNode2 = p;
	if (p == NULL)
		return NULL;
	for (; pNode1->next != NULL; pNode1 = pNode1->next)
	{
		for (pNode2 = p; pNode2->next != NULL; pNode2 = pNode2->next)
		{
			if (pNode2->exp > pNode2->next->exp)
			{
				int temp = pNode2->exp;
				pNode2->exp = pNode2->next->exp;
				pNode2->next->exp = temp;
				float temp1 = pNode2->coff;
				pNode2->coff = pNode2->next->coff;
				pNode2->next->coff = temp1;
			}
		}
	}
	return p;
}

Node *delete_(Node *p)
{
	Node* pNode1 = p;
	Node* del;
	for (; pNode1->next != NULL; pNode1 = pNode1->next)
	{
		if (pNode1->next->coff == 0) {
			del = pNode1->next;
			pNode1->next = del->next;
			delete del;
		}
	}
	return p;
}

Node *reverse(Node *head)
{
	Node *p, *q, *pr;
	pr = new Node;
	p = head->next;
	q = NULL;
	head->next = NULL;
	while (p) {
		pr = p->next;
		p->next = q;
		q = p;
		p = pr;
	}
	head->next = q;

	return head;
}

