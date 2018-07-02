#include <stdio.h>
#include <memory.h>
#include <string.h>

int main() {
	char id[12];
	char password[16];
	int i = 0;
	int a_cnt = 0, b_cnt = 0, c_cnt = 0;
	char val1 = "", val2 = "", val3 = "";

	memset(id, 0, 12);
	memset(password, 0, 16);

	do {
		if (c_cnt > 0) {
			break;
		}
		c_cnt++;
		printf("input id > ");
		scanf("%s", id);

		for (i = 0; i < strlen(id); i++) {
			if ((id[i] >= 'a' && id[i] <= 'z')) {
				a_cnt++;
				continue;
			}
			if ((id[i] >= '0' && id[i] <= '9')) {
				b_cnt++;
			}
			else {
				memset(id, 0, 12);
				break;
			}
		}
		if (a_cnt < 1 || b_cnt < 1) {
			memset(id, 0, 12);
			a_cnt = 0;
			b_cnt = 0;
			continue;
		}
	} while (id[5] == NULL);

	c_cnt = 0;

	do {
		if (c_cnt > 0) {
			printf("F\n");
			c_cnt = 0;
			return 0;
		}
		c_cnt++;
		printf("input password > ");
		scanf("%s", password);

		for (i = 0; i < strlen(password); i++) {
			if (i >= 2) {
				val1 = password[0 + (i - 2)];
				val2 = password[1 + (i - 2)];
				val3 = password[2 + (i - 2)];

				if (val1 == val2 && val1 == val3 && val2 == val3) {
					memset(password, 0, 16);
					break;
				}
			}
			if ((password[i] >= 'a' && password[i] <= 'z')) {
				continue;
			}
			if (!(password[i] >= '0' && password[i] <= '9')) {
				memset(password, 0, 16);
				break;
			}
		}
	} while (password[7] == NULL);

	printf("T\n");
}