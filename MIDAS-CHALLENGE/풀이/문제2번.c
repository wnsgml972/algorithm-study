#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct human {
	char first[20];
	char middle[20];
	char last[20];
	char email[100];
};

void changeCharacter(int *index, char *name) {
	int f = 0, j = 0;
	for (j = 0; j < *index; j++) {
		if (name[j] == '-') {
			for (f = j; f < *index; f++) {
				name[f] = tolower(name[f + 1]);
			}
			*index -= 1;
		}
		else {
			name[j] = tolower(name[j]);
		}
	}
}

int main() {
	int i = 0, j = 0, f = 0, index = 0, email_num = 0;
	char company_name[100];
	char company_email[100];
	struct human employee[1000];


	scanf("%s", company_name);
	while (company_name[i]) {
		company_name[i] = tolower(company_name[i]);
		i++;
	}

	i = 0;
	while (1) {
		if (getchar() == 10 && i>0) {
			break;
		}
		scanf("%s", employee[i].first);
		if (employee[i].first[0] == ',') {
			if (i>0)
				i++;
			continue;
		}
		index = strlen(employee[i].first);
		changeCharacter(&index, employee[i].first);


		if (employee[i].first[index - 1] == ',') {
			employee[i].first[index - 1] = NULL;
			i++;
			continue;
		}


		scanf("%s", employee[i].middle);
		index = strlen(employee[i].middle);
		changeCharacter(&index, employee[i].middle);

		if (employee[i].middle[index - 1] == ',') {
			employee[i].middle[index - 1] = NULL;
			strcpy(employee[i].last, employee[i].middle);
			memset(employee[i].middle, NULL, index);
			i++;
			continue;
		}

		if (getchar() == 10) {
			strcpy(employee[i].last, employee[i].middle);
			memset(employee[i].middle, NULL, index);
			i++;
			break;
		}

		scanf("%s", employee[i].last);
		if (employee[i].last[0] == ',') {
			strcpy(employee[i].last, employee[i].middle);
			memset(employee[i].middle, NULL, index);
			i++;
			continue;
		}
		index = strlen(employee[i].last);
		changeCharacter(&index, employee[i].last);
		if (employee[i].last[index - 1] == ',') {
			employee[i].last[index - 1] = NULL;
			i++;
			continue;
		}
	}

	strcpy(company_email, "@");
	strcat(company_email, company_name);
	strcat(company_email, ".com");
	for (j = 0; j < i; j++) {
		strcpy(employee[j].email, employee[j].last);
		index = strlen(employee[j].email);
		employee[j].email[index++] = employee[j].first[0];
		employee[j].email[index] = NULL;
		strcat(employee[j].email, company_email);

	}
	for (j = 0; j < i; j++) {
		email_num = 2;
		for (f = j + 1; f < i; f++) {
			if (strcmp(employee[f].email, employee[j].email) == 0) {
				memset(employee[f].email, 0, strlen(employee[f].email));
				strcpy(employee[f].email, employee[f].last);
				index = strlen(employee[f].email);
				employee[f].email[index++] = employee[f].first[0];
				employee[f].email[index++] = email_num + '0';
				strcat(employee[f].email, company_email);
				email_num++;

			}
		}
		printf("%s\n", employee[j].email);
	}
}