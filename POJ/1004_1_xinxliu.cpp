#include <stdio.h>
//为什么不能用double?
int main() {
	float sum = 0;
	for (int i = 0; i < 12; ++i) {
		float temp;
		scanf("%f",&temp);
		sum += temp;
	}
	printf("$%.2f\n", sum/12);
	return 0;
}