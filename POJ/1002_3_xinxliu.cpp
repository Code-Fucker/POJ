//ACCEPTED
//´úÂëÀ´×Ôhttp://zhidao.baidu.com/link?url=wl4l23kja1QXjBXVCoqOqKO1Gt5PrtVETacM2uw5GGNnJARHxuyRfpLwA0k7rSe7j3dbwMGLeWOwPAFsdJJxsXOjE689wAjkm_oLQ1_ay8C

#include <stdio.h>
#define M 10000000
int i, n, k, j, b[M];
char s[99], c;
int main() {
	for (scanf("%d", &n); i++<n;) {
		scanf("%s", s);
		for (k = j = 0; s[j];) {
			c = s[j++];
			if (c != 81 && c != 90 && c != 45)
				k = k * 10 + (64<c ? (c - (80<c) - 59) / 3 : c - 48);

		}
		b[k]++;
	}
	for (i = 0; i<M; i++)if (1<b[i]) {
		n = i;
		s[3] = 45;
		for (k = s[8] = j = 0; j<7; j++) {
			s[6 - j + (j<4)] = n % 10 + 48;
			n /= 10;
		}

		printf("%s %d\n", s, b[i]);
	}
	if (k)printf("No duplicates.\n");
	return 0;
}