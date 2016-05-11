#include "common/QuickSort.h"
#include <cstdio>


int main() {
	PROJECT_EULER::COMMON::QuickSort<int> sort;
	int A[] = {9, 8, 1, 3, 782, 2, 85, 2, 89};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n");
	
	sort.Sort(V);
	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n");
	
	return 0;
}
