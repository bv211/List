#include <iostream>
#include "List.h"

using namespace std;

void print(List& list) {
	auto count = list.get_count();
	for (int i = 0; i < count; i++) {
		cout << "index " << i << ": "
			<< list[i] << endl;
	}
}

int main() {
	List list;

	srand(time(nullptr));

	for (int i = 0; i < 4; i++)
		list.add(rand() % 100);

	cout << "Before delete" << endl;
	print(list);

	cout << "\nremove soft index " << 0 << ": "
		<< list[0] << endl;
	list.remove_soft(0);
	print(list);

	cout << "\nremove hard index " << 0 << ": "
		<< list[0] << endl;
	list.remove(0);
	print(list);

	return 0;
}