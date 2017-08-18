#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int e[5];
	int ei = 0;
	int o[5];
	int oi = 0;

	for (i = 0; i < 15; i++) {
		int v = 0;

		scanf("%d", &v);
		
		if (v % 2) {
			o[oi++] = v;
			if (oi == 5) {
				for (j = 0; j < 5; j++) printf("impar[%d] = %d\n", j, o[j]);
				oi = 0;
			}
		} else {
			e[ei++] = v;
			if (ei == 5) {
				for (j = 0; j < 5; j++) printf("par[%d] = %d\n", j, e[j]);
				ei = 0;
			}
		}
	}
	if (oi) {
		for (j = 0; j < oi; j++) printf("impar[%d] = %d\n", j, o[j]);
	}
	if (ei) {
		for (j = 0; j < ei; j++) printf("par[%d] = %d\n", j, e[j]);
	}

	return 0;
}