#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0, X = 0, i = 0, j = 0, N_len = 0, X_len = 0;
	int N_temp[20], X_temp[20], N_result[20], X_result[20];
	int cnt = 0;
	int temp_N_len = 0, temp_X_len = 0;

	do {
		printf("N: ");
		scanf("%d", &N);
	} while (!(N >= 100));

	do {
		printf("X: ");
		scanf("%d", &X);
	} while (!(X >= 8) || !(X<=128));

	for (i = 0; N > 0; i++)
	{
		N_temp[i] = N % 2;
		N /= 2;
	}
	for (j = i - 1; j >= 0; j--) {
		N_result[N_len++] = N_temp[j];

	}
	/* N result에 len의 길이만큼 2진수 넣음 */


	for (i = 0; X > 0; i++)
	{
		X_temp[i] = X % 2;
		X /= 2;
	}
	for (j = i - 1; j >= 0; j--) {
		X_result[X_len++] = X_temp[j];

	}
	/* X result에 len의 길이만큼 2진수 넣음 */


	temp_N_len = N_len;
	temp_X_len = X_len;
	/* 방법 1 */
	for (i = N_len-X_len; i >= 0; i--) {
		for (j = X_len-1; j >= 0; j--) {
			if (X_result[j] == N_result[i+j]) {
				cnt++;
			}
		}
		if (cnt == X_len) {
			for (j = X_len - 1; j >= 0; j--) {
				if (X_result[j] == N_result[i + j]) {
					N_len--;
				}
			}
		}
		cnt = 0;
	}

	cnt = 0;
	/* 방법 2 */
	for (i = 0; i <= temp_N_len - temp_X_len; i++) {
		for (j = 0; j <= temp_X_len - 1; j++) {
			if (X_result[j] == N_result[i + j]) {
				cnt++;
			}
		}
		if (cnt == temp_X_len) {
			for (j = 0; j <= temp_X_len - 1; j++) {
				if (X_result[j] == N_result[i + j]) {
					temp_N_len--;
				}
			}
		}
		cnt = 0;
	}

	if(N_len < temp_N_len)
		printf("%d\n", N_len);
	else
		printf("%d\n", temp_N_len);
}