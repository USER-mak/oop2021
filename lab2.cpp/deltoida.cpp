#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "pch.h"

using namespace std;

string Deltoida::to_string_pr(double x) const {
	stringstream ss;
	ss << fixed << setprecision(2) << x;
	return ss.str();
}

Deltoida::Deltoida() : m_r(1), m_R(3), equation(equation_m()) {};

Deltoida::Deltoida(double new_r) {
	if (new_r <= 0) {
		throw invalid_argument("Radius must be positive");
	}
	m_r = new_r;
	m_R = new_r * 3;
	equation = equation_m();
};

double Deltoida::R() const {
	return m_R;
}

double Deltoida::r() const {
	return m_r;
}

void Deltoida::set_r(double new_r) {
	if (new_r <= 0) {
		throw invalid_argument("Radius must be positive");
	}
		m_r = new_r;
		m_R = 3 * m_r;
		equation = equation_m();
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
	return (m_R - m_r) * cos(t) + m_r * cos(((m_R - m_r) / m_r) * t);
}

double Deltoida::y(double t) const {
	return (m_R - m_r) * sin(t) + m_r * sin(((m_R - m_r) / m_r) * t);
}

const string& Deltoida::equation_m() {
	equation = string("(x^2 + y^2)^2 + ") + to_string_pr(18 * m_r * m_r) +
		string("*(x^2 + y^2) - ") + to_string_pr(27 * pow(m_r, 4)) +
		string(" = ") + to_string_pr(8 * m_r) + string("*(x^3 - 3*x*y^2)");
	return equation;
}

const char* Deltoida::equation_c_str() {
	return equation_m().c_str();
}
