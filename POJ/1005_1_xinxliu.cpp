#include <iostream>
#include <math.h>

using namespace std;
const double pi = 3.14159265354;
int main() {
	int n;
	cin >> n;
	double x, y;
	int count = 0;
	for (int j = 0; j < n;++j ){
		cin >> x >> y;
		
		double r2 = pow(x, 2) + pow(y, 2);
		int i = 0;
		//double temp = i * 100 / pi;
		while (i * 100 / pi <= r2) {
			++i;

		}
		cout << "Property "<< j + 1 <<": This property will begin eroding in year " << i << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}