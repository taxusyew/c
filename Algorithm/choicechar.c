#include <stdio.h>

// win 8.1
// vs2013

int main() {
	char * base = "abcdefghijklmnopqrstuvwxyz0123456789";
	int i = 0;
	int j = 0;
	int k = 0;

	int count = 0;
	for (i; i < 36; i++) {
		for (j= i+1; j < 36; j++)
		{
			for (k= j+1; k < 36; k++)
			{
				count++;
				printf("%c%c%c\n", base[i],base[j],base[k]);
			}
		}
	}
	printf("%d", count);
	return 0;
}