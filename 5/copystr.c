#include <stdio.h>

int main()
{
	char duplicate[20];
	const char *src = "Hello world!";
	char *dst = duplicate;
	while (*src != '\0')
	{
		printf("%c \n", *src);
		src++;	
	}

}
