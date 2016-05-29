#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

const int maxInput = 6;
const int maxLength = maxInput * 25 + 1;
const int INVALID_POS = -1;

void output(char* s,int dotPos,int n,int max) {
	const int length = max - 1;
	int offset;
	if (dotPos == INVALID_POS) {
		offset = 0;
	}
	else {
		offset = (5 - dotPos)*n;
	}
	//去除先导0
	bool startOutput = false;
	for (int i = length; i >= offset; --i) {
		if (startOutput) {
			cout << char(s[i] + '0');
		}
		else if (s[i] != '\0') {
			startOutput = true;
			cout << char(s[i] + '0');
		}
	}

	//去除后导0
	int endPoint = 0;
	for (int i = 0; i < offset; ++i) {
		if (s[i] != '\0') {
			endPoint = i;
			break;
		}
		else if (i == offset - 1) {
			if (startOutput == false) {
				cout << 0 << endl;;
				return;
			}
			else {
				cout << endl;
				return;
			}
		}
	}
	
	//打印小数点
	if (offset >= 1&& dotPos != INVALID_POS) {
		cout << ".";
		for (int i = offset - 1; i >= endPoint;--i) {
			cout << char(s[i] + '0');
		}
	}
	cout << endl;
}
int main() {
	char s[10];
	char result[maxLength];
	
	int n;
	while (cin >> s >> n) {
		//maxIndex = maxLen - 1;
		const int maxLen = n * maxInput + 1;
		//preprocessing
		memset(result, 0, maxLength);
		int dotPos = INVALID_POS;
		char b[maxInput + 1];
		memset(b, 0, 7);
		int bIndex = 0;
		for (int i = maxInput - 1; i >=0; --i) {
			if (s[i] == '.') {
				dotPos = i;
			}
			else{
				b[bIndex++] = s[i] - '0';
				
			}
		}
		//multiplication
		if (n == 1) {
			output(b, dotPos, n,maxLen);
		}
		else {
		//initialize result
			for (int i = 0; i < maxInput; ++i) {
				for (int j = 0; j < maxInput; ++j) {
					result[i + j] += b[i] * b[j];
				}
				for (int i = 0; i < maxInput * 2; ++i) {
					result[i + 1] += result[i] / 10;
					result[i] %= 10;
				}
			}
			
		//multiplication
			char result_copy[maxLength];
			memset(result_copy, 0, maxLength);
			for (int i = 0; i < n - 2; ++i) {
				
				for (int i = 0; i < maxLen; ++i) {
					result_copy[i] = result[i];
				}

				memset(result, 0, maxLength);
				for (int j = 0; j < maxInput; ++j) {
					for (int k = 0;k < maxLen; ++k) {
						result[j + k] += result_copy[k] * b[j];
					}

					for (int m = 0; m < maxLen; ++m) {
						result[m + 1] += result[m] / 10;
						result[m] %= 10;
					}
				}
			}
			output(result, dotPos, n, maxLen);
		}
	}
	return 0;
}