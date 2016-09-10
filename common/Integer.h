#ifndef ALGORITHMS_RECURRENCE_INTEGER_H_
#define ALGORITHMS_RECURRENCE_INTEGER_H_

/*
  A Big integer implementation for Basic Arthematic operations.
  As c++ can't store big numbers why not to implement our own.
  Author: Rakesh Kumar cpp.rakesh@gmail.com
  Date: Sep 9th, 2016
*/

#include <cstdio>
#include <string>
#include <vector>

class Integer {
public:
    // Default Initialization
    Integer();

    // Initialize with std::string
    Integer(const std::string& data);

    // Initialization std::vector<int>
    Integer(const std::vector<int>& data);

    // Intitialization with int.
    Integer(int data);

    // Copy constructor
    Integer(const Integer& rhs);

    // Copy assignment operator
    Integer& operator = (const Integer& rhs);

    ~Integer();

    Integer operator + (const Integer& rhs);
    Integer operator + (const std::string& rhs);
    Integer operator + (const int& rhs);

    void operator += (const Integer& rhs);
    void operator += (const std::string& rhs);
    void operator += (const int& rhs);

#if 0
    Integer operator - (const Integer& rhs);
    Integer operator - (const std::string& rhs);
    Integer operator - (const int& rhs);

    void operator -= (const Integer& rhs);
    void operator -= (const std::string& rhs);
    void operator -= (const int& rhs);
#endif

    void Print() const;

private:
    bool        m_sign;
    std::string m_data;
};

#endif // ALGORITHMS_RECURRENCE_INTEGER_H_
