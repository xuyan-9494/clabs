#include <stdio.h>
#define MAX 101

void reverse(int *input, int num) {
	if (num > 1) {
		int c = *(input + num - 1);
		*(input + num - 1) = *input;
		*input = c;
		reverse(input + 1, num - 2);
	}
}

int main() {
	int input[MAX];
	for (int i = 0; i < MAX; i++) {
		input[i] = '\0';
	}

	int len = 0;
	int c = getchar();
	while (c != '\n' && c != EOF) {
		input[len] = c;
		len++;
		if (len >= MAX) {
			printf("输入超过了最大长度!\n");
			return 0;
		}
		c = getchar();
	}

	reverse(input, len);

	printf("反转后的字符串为：\n");
	for (int i = 0; i < len; i++) {
		printf("%c", input[i]);
	}
	printf("\n");
}
