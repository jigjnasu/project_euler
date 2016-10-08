/*
  This is solution for problem 54 (Poker hands) from ProjectEuler.net.
  This is the implementation of Card class
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 26th, 2016
*/

#include "Card.h"

Card::Card() : m_type(' '), m_value(0) {}

Card::Card(const char& type, const int& value) :
	m_type(type), m_value(value) {}

Card::~Card() {}

char Card::Type() const {
	return m_type;
}

int Card::Value() const {
	return m_value;
}
