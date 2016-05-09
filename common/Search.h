#ifndef PROJECT_EULER_COMMON_SEARCH_H_
#define PROJECT_EULER_COMMON_SEARCH_H_

#include <cstdio>
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
	int high = V.size() - 1;
	while (1) {
		const int mid = (low + high) >> 1;
		if (V[mid] == N) {
			return true;
		} else if (low == high) {
			return false;
		} else {
			if (N < V[mid])
				high = mid;
			else
				low = mid + 1;
		}
	}
}

#endif // PROJECT_EULER_COMMON_SEARCH_H_
