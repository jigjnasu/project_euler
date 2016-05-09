#ifndef PROJECT_EULER_COMMON_PERMUTATION_GENERATOR_H_
#define PROJECT_EULER_COMMON_PERMUTATION_GENERATOR_H_

#include <vector>
#include <string>
#include <cstdlib>

namespace PROJECT_EULER {
	namespace COMMON {
		template <typename T>
		class PermutationGenerator {
		public:
			PermutationGenerator();
			PermutationGenerator(const int& N, bool is_zero);
			PermutationGenerator(const std::vector<T>& V);
			~PermutationGenerator();

			void Generate();
			void Result(std::vector<T>& numbers);

		private:
			std::vector<T> m_data;
			std::vector<T> m_result;
			
			void m_swap(T& A, T& B);
			void m_generate(const int& N);
			void m_add_to_result();
		};
	};
};

namespace PC = PROJECT_EULER::COMMON;

// This is the default, constructor.
// Let's have the data "123".
template <typename T>
PC::PermutationGenerator<T>::PermutationGenerator() {
	for (int i = 1; i <= 3; ++i)
		m_data.push_back(i);
}

template <typename T>
PC::PermutationGenerator<T>::PermutationGenerator(const int& N, bool is_zero) {
	for (int i = 0; i < N; ++i)
		if (is_zero)
			m_data.push_back(i);
		else
			m_data.push_back(i + 1);
}

template <typename T>
PC::PermutationGenerator<T>::PermutationGenerator(const std::vector<T>& V) {
	m_data = V;
}

template <typename T>
PC::PermutationGenerator<T>::~PermutationGenerator() {}

template <typename T>
void PC::PermutationGenerator<T>::Generate() {
	m_generate(static_cast<int>(m_data.size()));
}

template <typename T>
void PC::PermutationGenerator<T>::Result(std::vector<T>& numbers) {
	numbers = m_result;
}

template <typename T>
void PC::PermutationGenerator<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

template <typename T>
void PC::PermutationGenerator<T>::m_generate(const int& N) {
	if (N == 1) {
		m_add_to_result();
	} else {
		for (int i = 0; i < N; ++i) {
			m_generate(N - 1);
			N % 2 ? m_swap(m_data[0], m_data[N - 1]) : m_swap(m_data[i], m_data[N - 1]);
		}
	}
}

template <typename T>
void PC::PermutationGenerator<T>::m_add_to_result() {
	std::string number;
	for (std::size_t i = 0; i < m_data.size(); ++i)
		number += m_data[i] + '0';

	m_result.push_back(std::atoi(number.c_str()));
}
#endif // PROJECT_EULER_COMMON_PERMUTATION_GENERATOR_H_
