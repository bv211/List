#pragma once
#include <iostream>

using namespace std;

class List {
	int _count;
	int _capacity;
	int* _array;

public:
	List() : List(0) {}

	List(int count) :
		_count(0),
		_capacity(count + 4),
		_array(new int[_capacity]) {}

	~List() {
		if (_array != nullptr)
			delete[] _array;
	}

	void add(int value) {
		if (_count >= _capacity)
			resize();

		_array[_count] = value;
		_count++;
	}

	void remove(int index) {
		if (index < 0 || index >= _count)
			return;

		for (size_t i = index; i < _count - 1; i++) {
			swap(_array[i], _array[i + 1]);
		}
		_count--;
	}

	void remove_soft(int index) {
		if (index < 0 || index >= _count)
			return;

		swap(_array[index], _array[_count - 1]);
		_count--;
	}

	int get_count() const {
		return _count;
	}

	int get_capacity() const {
		return _capacity;
	}

	int at(int index) const {
		if (index < 0 || index >= _count) {
			cout << "Индекс за пределами массива" << endl;
			exit(1);
		}

		return _array[index];
	}

	int operator[](int index) const {
		if (index < 0 || index >= _count) {
			cout << "Индекс за пределами массива" << endl;
			exit(1);
		}

		return _array[index];
	}

	int& operator[](int index) {
		if (index < 0 || index >= _count) {
			cout << "Индекс за пределами массива" << endl;
			exit(1);
		}

		return _array[index];
	}

private:
	void resize() {
		_capacity += 4;
		auto* tmp = new int[_capacity];
		for (size_t i = 0; i < _count; i++)
			tmp[i] = _array[i];

		delete[] _array;
		_array = tmp;
	}
};
