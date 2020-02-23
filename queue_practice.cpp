#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

template<class T>
class pri_q
{
private:
	int queueFront;
	int queueRear;
	T *list;
	int arraySize;
	int count = 0;
public:
	pri_q(int queueSize)
	{
		if (queueSize <= 0) 
		{
			arraySize = 100;
		}
		else 
		{
			arraySize = queueSize;
		}
		queueFront = 0;
		queueRear = arraySize - 1;
		count = 0;
		list = new T[arraySize];
	}

	~pri_q() 
	{
		delete[] list;
	}

	bool isEmptyQueue() const 
	{
		return(count == 0);
	}

	bool isFullQueue() const
	{
		return(count == arraySize);
	}

	void initializeQueue() 
	{
		queueFront = 0;
		queueRear = arraySize - 1;
		count = 0;
	}

	T front() const 
	{
		assert(!isEmptyQueue());
		return list[queueFront];
	}

	T back() const 
	{
		assert(!isEmptyQueue());
		return list[queueRear];
	}

	void addQueue(const T& newElement) 
	{
		if (!isFullQueue()) 
		{
			queueRear = (queueRear + 1) % arraySize;
			count++;
			list[queueRear] = newElement;
		}
		else 
		{
			cout << "Cannot add to full queue" << endl;
		}
	}

	void deleteQueue() 
	{
		if (!isEmptyQueue()) 
		{
			count--;
			queueFront = (queueFront + 1) % arraySize;
		}
		else 
		{
			cout << "Cannot remove from an empty queue" << endl;
		}
	}
};

int main() 
{
	pri_q<int> test(3);
	int x = 0;
	int y = 0;
	test.addQueue(1);
	test.addQueue(2);
	//test.deleteQueue();

	x = test.front();
	y = test.back();
	cout << x << " " << y << " " << endl;

	/*test.addQueue(2);
	test.addQueue(3);
	test.addQueue(4);
	x = test.front();
	y = test.back();
	cout << x << " " << y << " " << endl;*/
	
	system("pause");
	return 0;
}