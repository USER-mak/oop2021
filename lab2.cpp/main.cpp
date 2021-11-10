#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
#include "pch.h"

using namespace std;

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

		cmd = answer(cin, cout, 1, cmd_count);

		if (cmd == 1) {

			cout << "New value of r:" << endl;
			double r = answer_double(cin, cout, 1e-9, 10000);

			if (!d.set_r(r)) {
				cout << "Wnong value!" << endl;
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
			double t = answer_double(cin, cout, 1e-9, 10000);
			cout << "x: " << d.x(t) << endl;

		}
		else if (cmd == 5) {

			cout << "t:" << endl;
			double t = answer_double(cin, cout, 1e-9, 10000);
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
			cout << d.equation() << endl;
		}

	} while (cmd != cmd_count);



	return 0;
}
