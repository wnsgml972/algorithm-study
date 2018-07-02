#include <stdio.h>
#include <string.h>

//1 > 2 ? 3 : 4 > 5 ? 6 : 7
//33 != 1 ? 13 > 35 ? 4 >= 5 ? 0 : 4 == 2 ? 13 : 4 : 23 : 2
int three_command() {

}
int main() {
	char command[100];
	char command1[10];
	char command2[10];
	char command3[10];
	int i, tf_index = 0, question_index = 0;
	gets(command);
	for (i = 0; i < strlen(command); i++) {
		if (command[i] == '?' && question_index == 0)
			question_index = i;
		else if (command[i] == ':' && tf_index == 0)
			tf_index = i;
	}
	memcpy(command1, command, question_index);
	memcpy(command2, command + question_index + 1, tf_index - question_index);
	memcpy(command3, command + tf_index + 1, strlen(command) - tf_index);
	command1[question_index] = NULL;
	command2[tf_index - question_index] = NULL;
	command3[strlen(command) - tf_index] = NULL;
	printf("%s\n", command1);
	printf("%s\n", command2);
	printf("%s\n", command3);
	int a = 1 > 2 ? 3 : 6;
	printf("%d", a);

}