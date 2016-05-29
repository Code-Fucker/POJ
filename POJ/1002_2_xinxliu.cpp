#include <iostream>
#include <stdio.h>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int INVALID_NUM = -1;
int main() {
	//look_up_table
	int look_up_table[] = { 2,2,2,
		3,3,3,
		4,4,4,
		5,5,5,
		6,6,6,
		7,INVALID_NUM,7,7,
		8,8,8,
		9,9,9,INVALID_NUM
	};
	//input
	int n;
	cin >> n;
	vector<string> input(n);
	vector<int> result;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	//transform
	int num;
	for (int i = 0; i < n; ++i) {
		num = 0;
		string& str = input[i];
		for (int j = 0; j < str.size(); ++j) {
			if (str[j] != '-'&&str[j] != 'Q'&&str[j] != 'Z') {
				if (str[j] >= '0'&&str[j] <= '9') {
					num = num * 10 + int(str[j] - '0');
				}
				else {
					num = num * 10 + int(look_up_table[str[j] - 'A']);
				}
			}
		}
		result.push_back(num);
	}
	bool isDup = false;
	int t = 1;
	sort(result.begin(), result.end());
	for (int i = 1; i < result.size(); ++i) {
		if (result[i] == result[i - 1]) {
			++t;
		}
		else if (t > 1) {
			printf("%03d-%04d %d\n", result[i - 1] / 10000, result[i - 1] % 10000, t);
			isDup = true;
			t = 1;
		}
		if (i == result.size() - 1) {
			if (t > 1) {
				printf("%03d-%04d %d\n", result[i - 1] / 10000, result[i - 1] % 10000, t);
				isDup = true;
			}
		}
	}

	if (!isDup) {
		printf("No duplicates.\n");
	}
	return 0;
}