#include<iostream>
#include<string>
using namespace std;

class linkStack {
private:
	struct Node {
		char ch;
		Node *next;
		Node(const char &x, Node *N = NULL){ ch = x; next = N;}
		Node():next(NULL) {}
		~Node() {}
	};

	Node *top_p;
public:
	linkStack();
	~linkStack();
	bool isEmpty() const;
	void push(const char &x);
	char pop();
	char top() const;
};

int main()
{
	string s;
	linkStack opStack;
	char topop;
	getline(cin, s);
	int len = int(s.length());
	for (int i = 0; i < len; i++) {
		switch (s[i]) {
		case ')':
			while (!opStack.isEmpty() && (topop = opStack.pop()) != '(') {
				cout << topop;
			}
			break;
		case '(':
			opStack.push(s[i]); break;
		case '*':case '/':
			while (!opStack.isEmpty() && (opStack.top() == '/' || opStack.top() == '*'))
				cout << opStack.pop();
			opStack.push(s[i]); break;
		case '+':case '-':
			while (!opStack.isEmpty() && opStack.top() != '(')
				cout << opStack.pop();
			opStack.push(s[i]); break;
		default:
			cout << s[i]; break;
		}
	}
	while (!opStack.isEmpty())
		cout << opStack.pop();
	//system("pause");
	
}

linkStack::linkStack()
{
	top_p = NULL;
}

linkStack::~linkStack()
{
	Node *tmp;
	while (top_p != NULL) {
		tmp = top_p;
		top_p = top_p->next;
		delete tmp;
	}
}

bool linkStack::isEmpty() const
{
	return top_p == NULL;
}

void linkStack::push(const char &x)
{
	top_p = new Node(x, top_p);
}

char linkStack::pop()
{
	Node* tmp = top_p;
	char x = tmp->ch;
	top_p = top_p->next;
	delete tmp;
	return x;
}

char linkStack::top() const
{
	return top_p->ch;
}