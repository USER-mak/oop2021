#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>
#include "pch.h"

using namespace std;

int get_number(int min, int max) {
	int x{ min };
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Incorrect value. Try again." << endl;
		}
		else {
			if (x < min || x > max)
				cout << "Incorrect value. The value has to be in range [" << min << ';' << max << "]." << endl;
		}
		cout << ">> ";
		cin >> x;
	} while (cin.fail() || x < min || x > max);

	return x;
}

int main() {

	const int cmd_count = 10;
	vector<string> cmds = { "Create new deltoida", "Get R",
			"Get r", "Get x", "Get y", "Get length of intersection",
			"Get length", "Get area", "Print", "Exit" };

	cout << "Program Deltoida" << endl;

	Deltoida d(1);

	int cmd;

	do {
		cout << endl;
		for (int i = 1; i <= cmd_count; i++) {
			cout << i << ". " << cmds[i - 1] << endl;
		}

		cmd = get_number(1, cmd_count);

		if (cmd == 1) {

			cout << "New value of r:" << endl;
			double r;
			cin >> r;

			try {
				d.set_r(r);
			}
			catch (exception& error) {
				cout << error.what() << endl;
			}
		}
		else if (cmd == 2) {
			cout << "R: " << d.R() << endl;
		}
		else if (cmd == 3) {
			cout << "r: " << d.r() << endl;
		}
		else if (cmd == 4) {

			cout << "t:" << endl;
			double t;
			cin >> t;
			cout << "x: " << d.x(t) << endl;

		}
		else if (cmd == 5) {

			cout << "t:" << endl;
			double t;
			cin >> t;
			cout << "y: " << d.y(t) << endl;

		}
		else if (cmd == 6) {
			cout << "Length of intersection: " << d.intersection_length() << endl;
		}
		else if (cmd == 7) {
			cout << "Length: " << d.length() << endl;
		}
		else if (cmd == 8) {
			cout << "S: " << d.S() << endl;
		}
		else if (cmd == 9) {
			//const char* equal = d.equation_c_str();
			cout << d.equation_c_str() << endl;
		}

	} while (cmd != cmd_count);



	return 0;
}
