#include<iostream>
#include<string>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct event {
	int num;
	int arriveTime;
	int lastTime;
};

class priorQueue {
public:
	priorQueue();
	priorQueue(const event *e, int size);
	~priorQueue();
	bool isEmpty() const;
	void enQueue(const event &e);
	event deQueue();
	event getHead() const;
	event *array;
	void del(event &e);
private:
	int currentSize;
	int maxSize;


	void buildHeap();
	void percolateDown(int hole);
};


int main()
{
	string s, tmp;
	stringstream ss;
	tmp = ' ';
	getline(cin, s);
	int num = s[0] - '0';
	int k = 0;
	priorQueue pro;
	event *input = new event[num];
	string *l = new string[num];
	int *arr = new int[num * 3];
	for (int i = 0; i < num; i++) {
		getline(cin, l[i]);
		for (int j = 0; j < l[i].length(); j++) {
			if(l[i][j] == ' ' || j == l[i].length() - 1) {
				if(j == l[i].length() - 1) tmp += l[i][j];
				arr[k++] = atoi(tmp.c_str());
				tmp = ' ';
			}
			else
				tmp += l[i][j];
		}
		input[i].num = arr[3 * i];
		input[i].arriveTime = arr[3 * i + 1];
		input[i].lastTime = arr[3 * i + 2];
		//cout << input[i].num << ' ' << input[i].arriveTime << ' ' << input[i].lastTime << endl;
	}

	int t = 0;
	int i = 1;
	int change;
	while (true) {

		if (t == 0) { 
			pro.enQueue(input[0]);// cout << pro.array[1].num << ' ';
		}
		change = pro.array[1].num;
		if (t == input[i].arriveTime && i < num) {
			pro.enQueue(input[i]);
			//if (input[i].num < input[i - 1].num) cout << input[i].num << ' ';
			i++;
		}

		

	
		if (pro.array[1].lastTime == 0) {
			//cout << pro.array[1].num << ' ';
			pro.deQueue();
		}
		if (pro.isEmpty()){
			cout << pro.array[1].num;
			break;
		}

		t++;
		pro.array[1].lastTime = pro.array[1].lastTime - 1;

		if (t > 1 && pro.array[1].num != change) cout << change << ' ';
		
	}





}


void priorQueue::del(event &e)
{
	e.lastTime--;
}

priorQueue::priorQueue()
{
	array = new event[5];
	maxSize = 5;
	currentSize = 0;
}

priorQueue::~priorQueue()
{
	delete []array;
}

bool priorQueue::isEmpty() const
{
	return currentSize == 0;
}

event priorQueue::getHead() const
{
	return array[1];
}

void priorQueue::enQueue(const event &e)
{
	
	//ÏòÉÏ¹ýÂË
	int hole = ++currentSize;
	for (; hole > 1 && e.num < array[hole / 2].num; hole /= 2) {
		array[hole] = array[hole / 2];
		/*array[hole].arriveTime = array[hole / 2].arriveTime;
		array[hole].lastTime = array[hole / 2].lastTime;*/
	}
	array[hole] = e;
	/*array[hole].arriveTime = e.arriveTime;
	array[hole].lastTime = e.lastTime;*/
}


event priorQueue::deQueue()
{
	event min;
	min = array[1];
	array[1] = array[currentSize --];
	percolateDown(1);
	return min;
}

void priorQueue::percolateDown(int hole)
{
	int child;
	event tmp = array[hole];
	for (; hole * 2 <= currentSize; hole = child) {
		child = hole * 2;
		if (child != currentSize && (array[child + 1].num ) < array[child].num)
			child++;
		if (array[child].num < tmp.num) array[hole] = array[child];
		else break;
	}
	array[hole] = tmp;
}

void priorQueue::buildHeap()
{
	for (int i = currentSize / 2; i > 0; i--) {
		percolateDown(i);
	}
}

priorQueue::priorQueue(const event *e, int size):maxSize(10+size),currentSize(size)
{
	array = new event[maxSize];
	for (int i = 0; i < size; i++){
		array[i+1] = e[i];
	}
	buildHeap();
}
