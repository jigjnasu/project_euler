/*
  This is solution Quick sort algorithm, based on the Lumuto algorithm.
  This algroithm is also using random piviot selection to get almost perferct nlog2n complexity.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
 */

#ifndef PROJECT_EULER_COMMON_QUICK_SORT_H_
#define PROJECT_EULER_COMMON_QUICK_SORT_H_

#include <vector>
#include <string>
#include <cstdlib>

namespace PROJECT_EULER {
	namespace COMMON {
		template <typename T>
		class QuickSort {
		public:
			QuickSort();
			~QuickSort();

			void Sort(std::vector<T>& V);
			void Sort(std::string& S);

		private:
			void m_sort(std::vector<T>& V, const int& S, const int& E);
			void m_sort(std::string& V, const int& S, const int& E);
			int m_partition(std::vector<T>& V, const int& S, const int& E);
			int m_partition(std::string& V, const int& S, const int& E);
			int m_random(const int& low, const int& high);
			void m_swap(T& A, T& B);
		};
	};
};

namespace PC = PROJECT_EULER::COMMON;

template <typename T>
PC::QuickSort<T>::QuickSort() {}

template <typename T>
PC::QuickSort<T>::~QuickSort() {}

template <typename T>
void PC::QuickSort<T>::Sort(std::vector<T>& V) {
	m_sort(V, 0, V.size() - 1);
}

template <typename T>
void PC::QuickSort<T>::Sort(std::string& S) {
	m_sort(S, 0, S.size() - 1);
}

template <typename T>
void PC::QuickSort<T>::m_sort(std::vector<T>& V, const int& S, const int& E) {
	if (S < E) {
		const int mid = m_partition(V, S, E);
		m_sort(V, S, mid - 1);
		m_sort(V, mid + 1, E);
	}
}

template <typename T>
void PC::QuickSort<T>::m_sort(std::string& V, const int& S, const int& E) {
	if (S < E) {
		const int mid = m_partition(V, S, E);
		m_sort(V, S, mid - 1);
		m_sort(V, mid + 1, E);
	}	
}

template <typename T>
int PC::QuickSort<T>::m_partition(std::vector<T>& V, const int& S, const int& E) {
	const int piviot = m_random(S, E);
	m_swap(V[piviot], V[E]);
	int i = S;
	for (int j = S; j < E; ++j) {
		if (V[j] <= V[E]) {
			if (j != i)
				m_swap(V[i], V[j]);
			++i;
		}
	}

	m_swap(V[i], V[E]);
	return i;
}

template <typename T>
int PC::QuickSort<T>::m_partition(std::string& V, const int& S, const int& E) {
	const int piviot = m_random(S, E);
	m_swap(V[piviot], V[E]);	
	int i = S;
	for (int j = S; j < E; ++j) {
		if (V[j] <= V[E]) {
			if (j != i)
				m_swap(V[i], V[j]);
			++i;
		}
	}

	m_swap(V[i], V[E]);
	return i;	
}

template <typename T>
int PC::QuickSort<T>::m_random(const int& low, const int& high) {
	return low + (std::rand() % (high - low + 1));
}

template <typename T>
void PC::QuickSort<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // PROJECT_EULER_COMMON_QUICK_SORT_H_
