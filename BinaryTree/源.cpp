#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;

//int i = 0;
//
//typedef struct Node
//{
//	char data;
//	struct Node* lchild;
//	struct Node* rchild;
//	struct Node* parent;
//}BiNode, *BiTree;
//
//
//BiTree CreatBiTree(string s);
//int height(BiNode *t);
//void LongPath(BiNode *b, char path[], int pathlen, char longpath[], int &longpathlen);
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	//int len1 = int(s.length());
//	BiTree T = CreatBiTree(s);
//	
//	int num;
//	num = height(T);
//	cout << num << endl;
//
//	int a = 0, b = 0;
//	char *p1 = new char[num], *p2 = new char[num];
//	LongPath(T, p1, a, p2, b);
//	for (int i = 0; i < num; i++) {
//		cout << p2[i];
//	}
//
//}
//
//
//BiTree CreatBiTree(string s) {
//	char ch = s[i++];
//	BiTree T;
//	if (ch == '#') T = NULL;
//	else {
//		T = new BiNode;
//		T->data = ch;
//		T->lchild = CreatBiTree(s);
//		T->rchild = CreatBiTree(s);
//	}
//	return T;
//}
//
//int height(BiNode *t)
//{
//	if (t == NULL) return 0;
//	else {
//		int lt = height(t->lchild), rt = height(t->rchild);
//		return ((lt > rt) ? lt : rt) + 1;
//	}
//}
//
//void LongPath(BiNode *b, char path[], int pathlen, char longpath[], int &longpathlen) {  //求最长路径
//	int i;
//	if (b == NULL) {
//		if (pathlen > longpathlen) {    //若当前路径更长，将路径保存在longpath中
//			for (i = pathlen - 1; i >= 0; i--)
//				longpath[i] = path[i];
//			longpathlen = pathlen;
//		}
//	}
//	else {
//		path[pathlen] = b->data;      //将当前结点放入路径中
//		pathlen++;      //路径长度增1
//		LongPath(b->lchild, path, pathlen, longpath, longpathlen);  //递归扫描左子树
//		LongPath(b->rchild, path, pathlen, longpath, longpathlen);  //递归扫描右子树
//		pathlen--;      //恢复环境
//	}
//}
//
//


int i = 0;


class binaryTree {
private:
	struct node{
		node *left, *right;
		char ch;
		node () :left(NULL),right(NULL) {}
		node(char c, node *l = NULL, node *r = NULL) :ch(c), left(l), right(r) {}
		~node() {}
	};



	node *find(char x, node *t) const;
	void clear(node *&t);
	void preOrder(node *p) const;

public:
	node *root;
	binaryTree():root(NULL) {}
	binaryTree(char c) { root = new node(c); }
	~binaryTree();
	void clear();
	bool isEmpty() const;
	void precreateTree(string s);
	void preOrder() const;
};

int main()
{
	string s;
	getline(cin, s);
	binaryTree T;
	T.precreateTree(s);
	T.preOrder();

	system("pause");

}

void binaryTree::precreateTree(string s)
{
	root = new node;
	char ch = s[i++];
	if (ch == '#') root = NULL;
	else {
	root = new node(ch);
		precreateTree(s);
		precreateTree(s);
	}
	/*stack<node*> st;
	node *current;
	st.push(root);
	int i = 0;
	while (!st.empty()) {
		current = st.top();
		st.pop();
		current = new node(s[i]);
		if (s[++i] != '#') st.push(current->right);
		if (s[++i] != '#') st.push(current->left);
		i++;
	}*/

}


void binaryTree::preOrder(node *p) const
{
	if (p == NULL) return;
	cout << p->ch << ' ';
	preOrder(p->left);
	preOrder(p->right);
}

void binaryTree::preOrder() const
{
	preOrder(root);
}

bool binaryTree::isEmpty() const
{
	return root == NULL;
}

void binaryTree::clear()
{
	clear(root);
}

void binaryTree::clear(binaryTree::node *&t)
{
	if (t == NULL) return;
	clear(t->left);
	clear(t->right);
	delete t;
	t = NULL;
}

binaryTree::~binaryTree()
{
	clear(root);
}


binaryTree::node *binaryTree::find(char x, binaryTree::node *t) const
{
	node *tmp;
	if (t == NULL) return NULL;
	if (t->ch == x) return t;
	if (tmp = find(x, t->left)) return tmp;
	else return find(x, t->right);
}






