
#pragma once

#include "gtest/gtest.h"

#include <iostream>

using namespace std;

int answer(istream& is, ostream& os, int min, int max);

double answer_double(istream& is, ostream& os, double min, double max);

class Deltoida {
private:
	double m_R, m_r;

	string to_string_pr(double x) const;

public:
	Deltoida(double new_r);

	double R() const;

	double r() const;

	bool set_r(double new_r);

	double intersection_length() const;

	double length() const;

	double S() const;

	double x(double t) const;

	double y(double t) const;

	string equation() const;

};
