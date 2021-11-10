
#include "pch.h"

#include <iostream>
#include <iomanip>
#include "pch.h"

using namespace std;

int answer(istream& is, ostream& os, int min, int max) {
	int x;
	bool error = false;
	do {
		if (is.fail()) {
			is.clear();
			is.ignore(256, '\n');
		}
		if (error) {
			os << "Incorrect value. Try again." << endl;
		}
		os << ">> ";
		error = true;
		is >> x;
	} while (is.fail() || x < min || x > max);

	return x;
}

double answer_double(istream& is, ostream& os, double min, double max) {
	double x;
	bool error = false;
	do {
		if (is.fail()) {
			is.clear();
			is.ignore(256, '\n');
		}
		if (error) {
			os << "Incorrect value. Try again." << endl;
		}
		os << ">> ";
		error = true;
		is >> x;
	} while (is.fail() || x < min || x > max);

	return x;
}

string Deltoida::to_string_pr(double x) const {
	stringstream ss;
	ss << fixed << setprecision(2) << x;
	return ss.str();
}

Deltoida::Deltoida(double new_r) : m_R(new_r * 3), m_r(new_r) {};

double Deltoida::R() const {
	return m_R;
}

double Deltoida::r() const {
	return m_r;
}

bool Deltoida::set_r(double new_r) {
	if (new_r <= 0) {
		return false;
	}
	else {
		m_r = new_r;
		m_R = 3 * m_r;
		return true;
	}
}

double Deltoida::intersection_length() const {
	return 4. / 3 * m_R;
}

double Deltoida::length() const {
	return 16. / 3 * m_R;
}

double Deltoida::S() const {
	return 2. / 9 * 3.14159 * m_R * m_R;
}

double Deltoida::x(double t) const {
	return (m_R - m_r) * cos(t) + m_r * cos((m_R - m_r) / m_r * t);
}

double Deltoida::y(double t) const {
	return (m_R - m_r) * sin(t) + m_r * sin((m_R - m_r) / m_r * t);
}

string Deltoida::equation() const {
	return "(x^2 + y^2)^2 + " + to_string_pr(18 * m_r * m_r) +
		"*(x^2 + y^2) - " + to_string_pr(27 * pow(m_r, 4)) +
		" = " + to_string_pr(8 * m_r) + "*(x^3 - 3*x*y^2)";
}
