#pragma once
#include <iostream>
template <class T>
class Iterator {
public:
	using iterator_categoy = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_tupe = T;
	using pointer = T*;
	using reference = T &

	explicit Iteratir(pointer ptr)  m_ptr(ptr) {}
	reference operator*()const { return *m_ptr; }
	pointer operator ->() { return *m_ptr; }

	Iterator& operator
};
