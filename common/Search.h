#ifndef PROJECT_EULER_COMMON_SEARCH_H_
#define PROJECT_EULER_COMMON_SEARCH_H_

#include <vector>

namespace PROJECT_EULER {
	namespace COMMON {
		template <typename T>
		class Search {
		public:
			Search();
			~Search();
			
			bool search(const std::vector<T>& V, const int& N);
		};	
	};	
};

namespace PC = PROJECT_EULER::COMMON;

template <typename T>
PC::Search<T>::Search() {}

template <typename T>
PC::Search<T>::~Search() {}

template <typename T>
bool PC::Search<T>::search(const std::vector<T>& V, const int& N) {
	int low = 0;
	int hight = V.size() - 1;
	while (1) {
		if (low == high) {
			if (V[low] == N)
				return true;
			else
				return false;
		} else {
			const int mid = (low + high) / 2;
			if (N < V[mid])
				high = mid;
			if (N > V[mid])
				low = mid;
	}
}

#endif // PROJECT_EULER_COMMON_SEARCH_H_
