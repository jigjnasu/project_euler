#ifndef DEV_EULER_INTEGER_H_
#define DEV_EULER_INTEGER_H_

#include <cstdio>
#include <vector>

template <typename T>
class Integer {
public:
	Integer();
	Integer(T value);
	~Integer();

	Integer(const Integer& value);
	Integer& operator = (const Integer& value);

	Integer operator + (const Integer& rhs);
	Integer operator * (const Integer& rhs);

	void Print() const;

private:
	std::vector<T> m_data;
};

template <typename T>
Integer<T>::Integer() {}

template <typename T>
Integer<T>::Integer(T value) {
	while (value) {
		m_data.push_back(value % 10);
		value /= 10;
	}
}

template <typename T>
Integer<T>::~Integer() {}

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
	Integer<T> Integer<T>::operator + (const Integer& rhs) {
		Integer temp;

		std::size_t i = 0;
		std::size_t j = 0;
		T carry = 0;

		while (i < m_data.size() && j < rhs.m_data.size()) {
			T value = m_data[i++] + rhs.m_data[j++] + carry;
			if (value < 9) {
				temp.m_data.push_back(value);
				carry = 0;
			} else {
				temp.m_data.push_back(value % 10);
				carry = value / 10;
			}
		}

		while (i < m_data.size()) {
			T value = m_data[i++] + carry;
			if (value < 9) {
				temp.m_data.push_back(value);
				carry = 0;
			} else {
				temp.m_data.push_back(value % 10);
				carry = value / 10;
			}
		}

		while (j < rhs.m_data.size()) {
			T value = rhs.m_data[j++] + carry;
			if (value < 9) {
				temp.m_data.push_back(value);
				carry = 0;
			}
			else {
				temp.m_data.push_back(value % 10);
				carry = value / 10;
			}
		}

		while (carry) {
			temp.m_data.push_back(carry % 10);
			carry /= 10;
		}

		return temp;
	}

template <typename T>
Integer<T> Integer<T>::operator * (const Integer& rhs) {
	Integer temp;
	return temp;
}

template <typename T>
void Integer<T>::Print() const {
	for (int i = m_data.size() - 1; i >= 0; --i)
		printf("%d", m_data[i]);
	printf("\n");
}

#endif // DEV_EULER_INTEGER_H_
