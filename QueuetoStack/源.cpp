#include<iostream>
#include<string>
using namespace std;

class queue {
private:
	struct node {
		char ch;
		node *next;
		node(const char &c, node *N = NULL) {
			ch = c; next = N;
		}
		node():next(NULL) {}
		~node() {}
	};

	node *front, *rear;
public:
	queue();
	~queue();
	bool isEmpty() const;
	void enQueue(const char &c);
	char deQueue();
	char getHead() const;
	int size();
};


class Qstack {
private:
	queue q1, q2;
public:
	Qstack() {}
	~Qstack() {}
	void appendTail(const char &ch);
	char deleteHead();
};


int main()
{
	Qstack s;
	string s1, s2, s3;
	getline(cin, s1);
	//getline(cin, s3);
	getline(cin, s2);
	s.appendTail(s2[0]);
	s.appendTail(s2[2]);
	cout << s.deleteHead() << ' ';
	s.appendTail(s2[4]);
	cout << s.deleteHead() << ' ';
	cout << s.deleteHead() << ' ';
	s.appendTail(s2[6]);
	s.appendTail(s2[8]);
	cout << s.deleteHead() << ' ';
	cout << s.deleteHead();
	
	//push(), push(), pop(), push(), pop(), pop(), push(), push(), pop(), pop()

	//system("pause");
}

queue::queue()
{
	front = rear = NULL;
}

queue::~queue()
{
	node*tmp;
	while (front != NULL) {
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

bool queue::isEmpty() const
{
	return front == NULL;
}

char queue::getHead() const
{
	return front->ch;
}

void queue::enQueue(const char &c)
{
	if (rear == NULL)
		front = rear = new node(c);
	else
		rear = rear->next = new node(c);
}

char queue::deQueue()
{
	node *tmp = front;
	char value = front->ch;
	front = front->next;
	if (front == NULL) rear = NULL;
	delete tmp;
	return value;
}

int queue::size()
{
	node *tmp = front;
	int num = 0;
	while (tmp != NULL) {
		tmp = tmp->next;
		num++;
	}
	delete tmp;

	return num;
}

void Qstack::appendTail(const char &ch)
{
	if (!q1.isEmpty())
		q1.enQueue(ch);
	else
		q2.enQueue(ch);
}

char Qstack::deleteHead()
{
	char tmp = ' ';
	if (!q1.isEmpty()) {
		int num = q1.size();
		while (num > 1) {
			q2.enQueue(q1.deQueue());
			--num;
		}
		tmp = q1.deQueue();
	}
	else {
		int num = q2.size();
		while (num > 1) {
			q1.enQueue(q2.deQueue());
			--num;
		}
		tmp = q2.deQueue();
	}

	return tmp;
}