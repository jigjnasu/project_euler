/*
	This is the implementation of Random Quick Sort.
	Author: Rakesh Kumar @ cpp.rakesh@gmail.com
	Date: June 25th, 2016
*/

#ifndef PROJECT_EULER_PROBLEM_54_QUICK_SORT_H_
#define PROJECT_EULER_PROBLEM_54_QUICK_SORT_H_

#include <vector>
#include <cstdlib>

template <typename T>
class QuickSort {
public:
	QuickSort();
	~QuickSort();

	void Sort(std::vector<T>& V);
	
private:
	void m_sort(std::vector<T>& V, const int& start, const int& end);
	int m_partition(std::vector<T>& V, const int& start, const int& end);
	void m_swap(T& A, T& B);
};

template <typename T>
QuickSort<T>::QuickSort() {}

template <typename T>
QuickSort<T>::~QuickSort() {}

template <typename T>
void QuickSort<T>::Sort(std::vector<T>& V) {
	m_sort(V, 0, V.size() - 1);
}

template <typename T>
void QuickSort<T>::m_sort(std::vector<T>& V, const int& start, const int& end) {
	if (start < end) {
		const int mid = m_partition(V, start, end);
		m_sort(V, start, mid - 1);
		m_sort(V, mid + 1, end);
	}
}

template <typename T>
int QuickSort<T>::m_partition(std::vector<T>& V, const int& start, const int& end) {
	m_swap(V[end], V[rand() % (end - start + 1) + start]);
	int i = start;
	for (int j = start; j < end; ++j) {
		if (V[j] < V[end]) {
			if (i != j)
				m_swap(V[i], V[j]);
			++i;
		}
	}
	m_swap(V[i], V[end]);
	return i;
}

template <typename T>
void QuickSort<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // PROJECT_EULER_PROBLEM_54_QUICK_SORT_H_
