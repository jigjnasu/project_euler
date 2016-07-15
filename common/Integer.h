/*
  This is template class for containing big integer data, which we can't hold
  on normal 32 bit or 64 bit integers.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
 */

#ifndef PROJECT_EULER_COMMON_INTEGER_H_
#define PROJECT_EULER_COMMON_INTEGER_H_

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

namespace PROJECT_EULER {
	namespace COMMON {
		template <typename T>
			class Integer {
		public:
			Integer();
			Integer(const std::string& N);
			Integer(const std::vector<T>& N);
			~Integer();
			
			Integer(T value);
			Integer(const Integer& value);
			Integer& operator = (const Integer& value);
			
			Integer operator + (const Integer& rhs) const;
			Integer operator * (const Integer& rhs) const;
			
			Integer operator + (const T& rhs) const;
			Integer operator * (const T& rhs) const;
			
			Integer operator + (const std::vector<T>& rhs) const;
			Integer operator * (const std::vector<T>& rhs) const;
			
			Integer operator + (const std::string& rhs) const;
			Integer operator * (const std::string& rhs) const;
			
			void operator += (const Integer& rhs);
			void operator *= (const Integer& rhs);
			
			void operator += (const T& rhs);
			void operator *= (const T& rhs);

			bool operator == (const Integer& rhs);

			std::size_t Size() const;

			std::vector<T> GetData() const;
			std::string GetStringData() const;
			void Print() const; 
			
		private:
			std::vector<int> m_data;
		};
	};
};

namespace PC = PROJECT_EULER::COMMON;
		
template <typename T>
PC::Integer<T>::Integer() {}

template <typename T>
PC::Integer<T>::Integer(const std::string& N) {
	for (std::size_t i = 0; i < N.size(); ++i)
		m_data.push_back(N[i] - '0');
}

template <typename T>
PC::Integer<T>::Integer(const std::vector<T>& N) {
	m_data = N;
}

template <typename T>
PC::Integer<T>::~Integer() {}

template <typename T>
PC::Integer<T>::Integer(T value) {
	while (value) {
		m_data.push_back(value % 10);
		value /= 10;
	}
}

template <typename T>
PC::Integer<T>::Integer(const Integer& value) {
	m_data.erase(m_data.begin(), m_data.end());
	for (std::size_t i = 0; i < value.m_data.size(); ++i)
		m_data.push_back(value.m_data[i]);
}

template <typename T>
PC::Integer<T>& PC::Integer<T>::operator = (const Integer& value) {
	m_data.erase(m_data.begin(), m_data.end());
	for (std::size_t i = 0; i < value.m_data.size(); ++i)
		m_data.push_back(value.m_data[i]);

	return *this;
}

template <typename T>
PC::Integer<T> PC::Integer<T>::operator + (const Integer& rhs) const {
	Integer<T> temp;
	std::size_t left_iterator = 0;
	std::size_t right_iterator = 0;
	T carry = 0;
	
	while (left_iterator < m_data.size() && right_iterator < rhs.m_data.size()) {
		const T sum = m_data[left_iterator++] + rhs.m_data[right_iterator++] + carry;
		if (sum > 9) {
			temp.m_data.push_back(sum % 10);
			carry = sum / 10;
		} else {
			temp.m_data.push_back(sum);
			carry = 0;
		}
	}
	
	while (left_iterator < m_data.size()) {
		const T sum = m_data[left_iterator++] + carry;
		if (sum > 9) {
			temp.m_data.push_back(sum % 10);
			carry = sum / 10;
		} else {
			temp.m_data.push_back(sum);
			carry = 0;
		}
	}
	
	while (right_iterator < rhs.m_data.size()) {
		const T sum = rhs.m_data[right_iterator++] + carry;
		if (sum > 9) {
			temp.m_data.push_back(sum % 10);
			carry = sum / 10;
		} else {
			temp.m_data.push_back(sum);
			carry = 0;
		}
	}
	
	while (carry) {
		temp.m_data.push_back(carry % 10);
		carry /= 10;
	}
	
	return temp;
}

template <typename T>
PC::Integer<T> PC::Integer<T>::operator * (const Integer& rhs) const {
	Integer<T> temp;
	T carry = rhs;
	int iter = 0;

	while (iter < m_data.size()) {
		const T sum = m_data[iter] * carry;
		if (sum > 9) {
			temp.m_data.push_back(sum % 10);
			carry = sum / 10;
		} else {
			temp.m_data.push_back(sum);
			carry = 0;
		}
	}

	while (carry) {
		temp.m_data.push_back(carry % 10);
		carry /= 10;
	}

	return temp;	
}

template <typename T>
PC::Integer<T> PC::Integer<T>::operator + (const T& rhs) const {
	Integer<T> temp;
	T carry = rhs;
	int iter = 0;

	while (iter < m_data.size()) {
		const T sum = m_data[iter] + carry;
		if (sum > 9) {
			temp.m_data.push_back(sum % 10);
			carry = sum / 10;
		} else {
			temp.m_data.push_back(sum);
			carry = 0;
		}
	}

	while (carry) {
		temp.m_data.push_back(carry % 10);
		carry /= 10;
	}

	return temp;
}

template <typename T>
PC::Integer<T> PC::Integer<T>::operator * (const T& rhs) const {
	Integer<T> temp;
	T carry = 0;

	for (std::size_t i = 0; i < m_data.size(); ++i) {
		const T sum = (m_data[i] * rhs) + carry;

		if (sum > 9) {
			temp.m_data.push_back(sum % 10);
			carry = sum / 10;
		} else {
			temp.m_data.push_back(sum);
			carry = 0;
		}
	}

	while (carry) {
		temp.m_data.push_back(carry % 10);
		carry /= 10;
	}
	
	return temp;
}

template <typename T>
PC::Integer<T> PC::Integer<T>::operator + (const std::vector<T>& rhs) const {
	Integer<T> A;
	for (std::size_t i = 0; i < rhs.size(); ++i)
		A.m_data.push_back(rhs[i]);
	Integer<T> temp = *this + A;
	return temp;
}

template <typename T>
PC::Integer<T> PC::Integer<T>::operator * (const std::vector<T>& rhs) const {
}

template <typename T>
PC::Integer<T> PC::Integer<T>::operator + (const std::string& rhs) const {
	Integer<T> A;
	for (std::size_t i = 0; i < rhs.size(); ++i) {
		char temp[2] = {0};
		temp[0] = rhs[i];
		A.m_data.push_back(std::atoi(temp));
	}
	Integer<T> temp = *this + A;
	return temp;
}

template <typename T>
PC::Integer<T> PC::Integer<T>::operator * (const std::string& rhs) const {
}

template <typename T>
void PC::Integer<T>::operator += (const Integer& rhs) {
	int rhs_iter = 0;
	int lhs_iter = 0;
	T carry = 0;
	
	while (lhs_iter < m_data.size() && rhs_iter < rhs.m_data.size()) {
		const T sum = m_data[lhs_iter] + rhs.m_data[rhs_iter] + carry;

		if (sum < 9) {
			m_data[lhs_iter] = sum;
			carry = 0;
		} else {
			m_data[lhs_iter] = sum % 10;
			carry = sum / 10;
		}

		++lhs_iter;
		++rhs_iter;
	}

	while (lhs_iter < m_data.size()) {
		const T sum = m_data[lhs_iter] + carry;
		if (sum < 9) {
			m_data[lhs_iter] = sum;
			carry = 0;
		} else {
			m_data[lhs_iter] = sum % 10;
			carry = sum / 10;
		}

		++lhs_iter;
	}

	while (rhs_iter < rhs.m_data.size()) {
		const T sum = rhs.m_data[rhs_iter] + carry;
		if (sum < 9) {
			m_data.push_back(sum);
			carry = 0;
		} else {
			m_data.push_back(sum % 10);
			carry = sum / 10;
		}

		++rhs_iter;
	}

	while (carry) {
		m_data.push_back(carry % 10);
		carry /= 10;
	}
}

template <typename T>
void PC::Integer<T>::operator *= (const Integer& rhs) {
	T carry = 0;
	for (std::size_t i = 0; i < m_data.size(); ++i) {
		const T sum = (m_data[i] * rhs) + carry;
		if (sum > 9) {
			m_data[i] = sum % 10;
			carry = sum / 10;
		} else {
			m_data[i] = sum;
			carry = 0;
		}
	}

	while (carry) {
		m_data.push_back(carry % 10);
		carry /= 10;
	}
}

template <typename T>
void PC::Integer<T>::operator += (const T& rhs) {
	T carry = rhs;

	for (std::size_t i = 0; i < m_data.size(); ++i) {
		const T sum = m_data[i] + carry;

		if (sum > 9) {
			m_data[i] = sum % 10;
			carry = sum / 10;
		} else {
			m_data[i] = sum;
			carry = 0;
		}
	}

	while (carry) {
		m_data.push_back(carry % 10);
		carry /= 10;		
	}
}

template <typename T>
void PC::Integer<T>::operator *= (const T& rhs) {
	T carry = 0;

	for (std::size_t i = 0; i < m_data.size(); ++i) {
		const T sum = (m_data[i] * rhs) + carry;

		if (sum > 9) {
			m_data[i] = sum % 10;
			carry = sum / 10;
		} else {
			m_data[i] = sum;
			carry = 0;
		}
	}

	while (carry) {
		m_data.push_back(carry % 10);
		carry /= 10;
	}	
}

template <typename T>
bool PC::Integer<T>::operator == (const Integer& rhs) {
	if (m_data.size() != rhs.m_data.size())
		return false;

	for (std::size_t i = 0; i < m_data.size(); ++i)
		if (m_data[i] != rhs.m_data[i])
			return false;
	
	return true;
}

template <typename T>
std::size_t PC::Integer<T>::Size() const {
	return m_data.size();
}

template <typename T>
std::vector<T> PC::Integer<T>::GetData() const {
	return m_data;
}

template <typename T>
std::string PC::Integer<T>::GetStringData() const {
	std::string number;
	for (int i = m_data.size() - 1; i >= 0; --i)
		number.push_back(m_data[i] + '0');
	return number;
}

template <typename T>
void PC::Integer<T>::Print() const {
	for (int i = m_data.size() - 1; i >= 0; --i)
		std::cout << m_data[i];
	std::cout << std::endl;
}


#endif // PROJECT_EULER_COMMON_INTEGER_H_
