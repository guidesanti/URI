#include <stdio.h>

int s[1000000] = { 0 };
int s1[1000000] = { 0 };

int main() {
	int n = 0;
	int i = 0;
	int a = 0;
	unsigned long long t = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		t += s[i];
	}

	i = 0;
	while ((i >= 0) && (i < n) && (s[i] > 0)) {
		int v = s[i];
		if (!s1[i]) {
			s1[i]++;
			a++;
		}
		t--;
		s[i]--;
		if (v % 2) {
			i += 1;
		}
		else {
			i -= 1;
		}
	}

	printf("%d %llu\n", a, t);

	return 0;
}