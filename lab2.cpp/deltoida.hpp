#include "gtest/gtest.h"
#include <iostream>

using namespace std;

int get_number(int min, int max);

class Deltoida {
private:
	double m_R, m_r;

	string to_string_pr(double x) const;

	string equation;

public:

	Deltoida();

	Deltoida(double new_r);

	double R() const;

	double r() const;

	void set_r(double new_r);

	double intersection_length() const;

	double length() const;

	double S() const;

	double x(double t) const;

	double y(double t) const;

	const string& equation_m();

	const char* equation_c_str();

};
