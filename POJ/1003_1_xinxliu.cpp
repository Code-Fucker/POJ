#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
	double table[350] = {-1, 0.5 };
	for (int i = 2; i < 350; ++i) {
		table[i] = table[i - 1] + 1.0 / (i + 1);
	}
	double n;
	while (cin>>n&&n!=0) {
		for (int i = 1; i < 350; ++i) {
			if (table[i] >= n) {
				cout <<	 i << " " << "card(s)" << endl;
				break;
			}
		}
	}
	return 0;
}