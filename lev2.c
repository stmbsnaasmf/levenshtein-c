#include <stdio.h>

int stringLength(char* str);
char* tail(char* str);
int min(int x, int y, int z);
void stringCopy(char* destination, const char* source);

int lev(char* a, char* b)
{
	if (0 == stringLength(b)) return stringLength(a);
	if (0 == stringLength(a)) return stringLength(b);
	if (a[0] == b[0]) return lev(tail(a), tail(b));
	else
	{
		char a0[stringLength(a) + 1], a1[stringLength(a) + 1], a2[stringLength(a) + 1], 
		b0[stringLength(b) + 1], b1[stringLength(b) + 1], b2[stringLength(b) + 1];

		stringCopy(a0, a); stringCopy(a1, a); stringCopy(a2, a);
		stringCopy(b0, b); stringCopy(b1, b); stringCopy(b2, b);

		return 1 + min(lev(tail(a0), b0), lev(a1, tail(b1)), lev(tail(a2), tail(b2)));
//		return 1 + min(lev(tail(a), b), lev(a, tail(b)), lev(tail(a), tail(b)));
	}
}

int main()
{
	char a[] = "kitten\0";
	char b[] = "sitting\0";

	char c[] = "qwertyuiop\0";
	char d[] = "zxcvbnm\0";

//	char a0[stringLength(a) + 1]; stringCopy(a0, a);
//	printf("Original = %s, copy = %s\n", a, a0);

//	int x = 230, y = 3, z = 5;
//	printf("min(%d, %d, %d) = %d\n", x, y, z, min(x, y, z));

//	printf("Tail(%s) = %s", a, tail(a));

//	printf("Lenght of string %s is %d", a, stringLength(a));
	
	printf("The Levenshtien distance between \"%s\" and \"%s\" is %d.\n", a, b, lev(a, b));
	printf("The Levenshtien distance between \"%s\" and \"%s\" is %d.\n", c, d, lev(c, d));

	return 0;
}

void stringCopy(char* destination, const char* source)
{
	int index = 0;
	while (source[index] != '\0')
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = '\0';
}

int min(int x, int y, int z)
{
	int minimum = x;

	if (y < x)
	{
		minimum = y;
		if (z < y) minimum = z;
	}
	else if (z < x)
	{
		minimum = z;
		if (y < z) minimum = y;
	}
	
	return minimum;
}

char* tail(char* str)
{
	int index = 0;

	while (str[index] != '\0')
	{
		str[index] = str[index + 1];
		index++;
	}

	return str;
}

int stringLength(char* str)
{
	int length = 0;
	while (str[length] != '\0') length++;
	
	return length;
}
