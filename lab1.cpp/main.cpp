#include <iostream>
#include <crtdbg.h>
#include "sparseMatrix.h"

using namespace std;

int main() {
	int n, m, x;

	std::cout << "Entre the number of strings: ";
	cin >> n;
	std::cout << "Entre the number of columns: ";
	cin >> m;

	List<List<pair<int, int>>> matrix;

	

	for (int i = 0; i < n; i++) {
		List<pair<int, int>> row;
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x != 0) {
				row.add({ x, j });
			}
		}
		matrix.add(row);
	}

	List<int> sums;

	for (auto it_row = matrix.begin(); it_row != matrix.end(); ++it_row) {
		int total = 0;
		for (auto it = (*it_row).begin(); it != (*it_row).end(); ++it) {
			total += (*it).first;
		}
		double average = double(total) / m;
		total = 0;
		for (auto it = (*it_row).begin(); it != (*it_row).end(); ++it) {
			if ((*it).first > average) {
				total += (*it).first;
			}
		}
		sums.add(total);
	}

	std::cout << "Vector:\n";

	for (auto it = sums.begin(); it != sums.end(); ++it) {
		cout << *it << " ";
	}

	_CrtDumpMemoryLeaks();

	return 0;
}
