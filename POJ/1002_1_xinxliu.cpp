#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int main() {
	map<char, char> look_up_table;
	//initialize the look_up_table
	look_up_table['A'] = '2';
	look_up_table['B'] = '2';
	look_up_table['C'] = '2';
	look_up_table['D'] = '3';
	look_up_table['E'] = '3';
	look_up_table['F'] = '3';
	look_up_table['G'] = '4';
	look_up_table['H'] = '4'; 
	look_up_table['I'] = '4';
	look_up_table['J'] = '5';
	look_up_table['K'] = '5';
	look_up_table['L'] = '5';
	look_up_table['M'] = '6';
	look_up_table['N'] = '6';
	look_up_table['O'] = '6';
	look_up_table['P'] = '7';
	look_up_table['R'] = '7';
	look_up_table['S'] = '7';
	look_up_table['T'] = '8';
	look_up_table['U'] = '8';
	look_up_table['V'] = '8';
	look_up_table['W'] = '9';
	look_up_table['X'] = '9';
	look_up_table['Y'] = '9';
	int n;
	cin >> n;
	vector<string> input;
	map<string, int> table;
	//input
	
	for (int i = 0; i < n; ++i) {
		string cintemp;
		cin >> cintemp;
		input.push_back(cintemp);
	}
	if (input.size() != n) {
		cerr << "input error" << endl;
		return 0;
	}
	//transform the input to the standard form
	for (vector<string>::iterator it = input.begin(); it != input.end();++it) {
		string Temp = *it;
		string strTemp;
		int strIdx = 0;
		for (string::iterator strit = Temp.begin(); strit != Temp.end();++strit) {
			if (*strit != '-'&&*strit != 'Q'&&*strit != 'Z') {
				if (strIdx == 3) {
					strTemp.push_back('-');
					++strIdx;
				}
				if (*strit >= '0'&&*strit <= '9') {
					strTemp.push_back(*strit);
					++strIdx;
				}
				else {
					strTemp.push_back(look_up_table[*strit]);
					++strIdx;
				}
			}
		}
		if (table.find(strTemp) != table.end()) {
			++table[strTemp];
		}
		else {
			table[strTemp] = 1;
		}
	}
	bool ifdup = false;
	for (map<string, int>::iterator it = table.begin(); it != table.end(); ++it) {
		if (it->second > 1) { 
			cout << it->first << " " << it->second << endl; 
			ifdup = true;
		}
	}
	if (!ifdup) {
		cout << "No duplicates." << endl;
	}
	return 0;
}