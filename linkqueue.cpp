#include "LinkQueue.h"
#include <iostream>
using namespace std;

int main()
{
	int e = 0;
	LinkQueue<int> test;
	for (int i = 0; i < 5; i++)
		test.EnQueue(i);
	for (int j = 0; j < 3; j++)
	{
		test.DeQueue(e);
		cout << e << " ";
	}
	cout << endl;
	cout << test.QueueLength() << endl;
	cout << test.IsEmpty() << endl;
	test.DisQueue();
	system("pause");
	return 0;
}