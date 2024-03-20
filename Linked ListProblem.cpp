#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main()
{
	LinkedList<int> L;
	LinkedList<int > intersection;
	LinkedList<int>t;
	L.Insert(5);
	L.Insert(5);
	L.Insert(10);
	L.Insert(9);
	L.Insert(7);

	t.Insert(2);
	t.Insert(8);
	t.Insert(6);
	t.Insert(5);
	t.Insert(10);
	t.Insert(4);

	cout << t.Length() << "  t length\n";
	for (int i = 0; i < t.Length(); i++)
	{
		cout << t.At(i) << "\t";
	}
	cout << t.getMin() << "\n";

	L.Merge(t);
	cout << L.Length ()<< "  L length\n";
	// 11
	for (int i = 0; i < L.Length(); i++)
	{
		cout << i << "\t";
		cout << L.At(i) << "\n";
	}
	t.Merge(L);
	
	cout << t.Length() << "  t length\n";
	 L.Intersection(t,intersection);
	cout << intersection.Length() << "  intersection length\n";

	for (int i = 0; i < intersection.Length(); i++)
	{
		cout << i << "\t";
		cout << intersection.At(i) << "\n";
	}
	cout << intersection.getMin();
	
	return 0;
}