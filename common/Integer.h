
#ifndef PROJECT_EULER_COMMON_INTEGER_H_
#define PROJECT_EULER_COMMON_INTEGER_H_

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

template <typename T>
class Integer {
public:
	Integer();
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

	std::vector<T> GetData() const;
	void Print() const;

private:
	std::vector<int> m_data;
};

template <typename T>
Integer<T>::Integer() {}

template <typename T>
Integer<T>::~Integer() {}

template <typename T>
Integer<T>::Integer(T value) {
	while (value) {
		m_data.push_back(value % 10);
		value /= 10;
	}
}

template <typename T>
Integer<T>::Integer(const Integer& value) {
	m_data.erase(m_data.begin(), m_data.end());
	for (std::size_t i = 0; i < value.m_data.size(); ++i)
		m_data.push_back(value.m_data[i]);
}

template <typename T>
Integer<T>& Integer<T>::operator = (const Integer& value) {
	m_data.erase(m_data.begin(), m_data.end());
	for (std::size_t i = 0; i < value.m_data.size(); ++i)
		m_data.push_back(value.m_data[i]);

	return *this;
}

template <typename T>
Integer<T> Integer<T>::operator + (const Integer& rhs) const {
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
Integer<T> Integer<T>::operator * (const Integer& rhs) const {
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
Integer<T> Integer<T>::operator + (const T& rhs) const {
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
Integer<T> Integer<T>::operator * (const T& rhs) const {
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
Integer<T> Integer<T>::operator + (const std::vector<T>& rhs) const {
	Integer<T> A;
	for (std::size_t i = 0; i < rhs.size(); ++i)
		A.m_data.push_back(rhs[i]);
	Integer<T> temp = *this + A;
	return temp;
}

template <typename T>
Integer<T> Integer<T>::operator * (const std::vector<T>& rhs) const {
}

template <typename T>
Integer<T> Integer<T>::operator + (const std::string& rhs) const {
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
Integer<T> Integer<T>::operator * (const std::string& rhs) const {
}

template <typename T>
void Integer<T>::operator += (const Integer& rhs) {
	
}

template <typename T>
void Integer<T>::operator *= (const Integer& rhs) {
}

template <typename T>
void Integer<T>::operator += (const T& rhs) {
	
}

template <typename T>
void Integer<T>::operator *= (const T& rhs) {
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
std::vector<T> Integer<T>::GetData() const {
	return m_data;
}

template <typename T>
void Integer<T>::Print() const {
	for (int i = m_data.size() - 1; i >= 0; --i)
		std::cout << m_data[i];
	std::cout << std::endl;
}

#endif // PROJECT_EULER_COMMON_INTEGER_H_
