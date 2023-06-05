#include <iostream>
#include "List.h"

using namespace std;

void print(List& list) {
	auto count = list.get_count();
	for (int i = 0; i < count; i++)
		cout << list[i] << endl;
}

int main() {
	List list;

	srand(time(nullptr));

	for (int i = 0; i < 4; i++)
		list.add(rand() % 100);

	cout << "Before delete" << endl;
	print(list);

	list.remove_soft(1);
	list.remove(1);

	cout << "After delete" << endl;
	print(list);

	return 0;
}