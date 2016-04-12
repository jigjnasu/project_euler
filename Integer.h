#ifndef PROJECT_EULER_INTEGER_H_
#define PROJECT_EULER_INTEGER_H_

#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>

template <typename T>
class Integer {	
public:
	Integer();
	~Integer();

	Integer(T value);
	Integer(const Integer<T>& value);
	Integer<T>& operator = (const Integer<T>& value);
	
	void operator += (const std::vector<T>& rhs);
	void operator += (const std::string& rhs);
	
	void Print() const;
	
private:
	std::vector<T> m_data;
};

template <typename T>
Integer<T>::Integer() {
	m_data.push_back(0);
}

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
Integer<T>::Integer(const Integer<T>& value) {
	m_data.erase(m_data.begin(), m_data.end());
	for (std::size_t i = 0; i < value.m_data.size(); ++i)
		m_data.push_back(value.m_data[i]);
}

template <typename T>
Integer<T>& Integer<T>::operator = (const Integer<T>& value) {
	m_data.erase(m_data.begin(), m_data.end());
	for (std::size_t i = 0; i < value.m_data.size(); ++i)
		m_data.push_back(value.m_data[i]);

	return *this;
}

template <typename T>
void Integer<T>::operator += (const std::vector<T>& rhs) {
	
}

template <typename T>
void Integer<T>::operator += (const std::string& rhs) {
	int left_iter = 0;
	int right_iter = 0;
	int carry = 0;

	while (left_iter < m_data.size() && right_iter < rhs.size()) {
		char temp[2] = { 0 };
		temp[0] = rhs[right_iter];
		int sum = carry + m_data[left_iter] + std::atoi(temp);
		if (sum > 9) {
			m_data[left_iter] = sum % 10;
			carry = sum / 10;
		} else {
			m_data[left_iter] = sum;
			carry = 0;
		}
		++left_iter;
		++right_iter;
	}

	while (left_iter < m_data.size()) {
		int sum = carry + m_data[left_iter];
		if (sum > 9) {
			m_data[left_iter++] = sum % 10;
			carry = sum / 10;
		} else {
			m_data[left_iter++] = sum;
			carry = 0;
		}
	}

	while (right_iter < rhs.size()) {
		char temp[2] = { 0 };
		temp[0] = rhs[right_iter++];
		int sum = carry + std::atoi(temp);
		if (sum > 9) {
			m_data.push_back(sum % 10);
			carry = sum / 10;
		} else {
			m_data.push_back(sum);
			carry = 0;
		}
	}

	while (carry) {
		m_data.push_back(carry % 10);
		carry /= 10;
	}
}

template <typename T>
void Integer<T>::Print() const {
	for (int i = 0; i < m_data.size(); ++i)
		printf("%d", m_data[i]);
	printf("\n");
}

#endif // PROJECT_EULER_INTEGER_H_
