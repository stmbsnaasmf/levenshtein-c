#include <stdio.h>
#include <string.h>

//11:28:00 pm - 12:18:00 am

int getStringLength(char* str);
int lev(char* a, char* b);
char* tail(char* str);
int min(int x, int y, int z);

int main(void)
{
//	char a[] = "kitten";
//	char b[] = "sitting";

//	char a[] = "book";
//	char b[] = "back";

	char a[] = "qwertyuiop";
	char b[] = "zxcvbnm";
	
//	printf("%s\n", tail(a));

//	printf("%d\n", min(10, 20, 30));
//	printf("%d\n", min(10, 30, 20));
//	printf("%d\n", min(20, 10, 30));
//	printf("%d\n", min(30, 10, 20));
//	printf("%d\n", min(30, 20, 10));
//	printf("%d\n", min(10, 20, 30));
	
	printf("The levenshtein distance between \"%s\" and \"%s\" is %d.\n", a, b, lev(a, b));
  
	return 0;
}

int lev(char* a, char* b)
{
	if (0 == getStringLength(b))
	{
		return getStringLength(a);
	}
	else if (0 == getStringLength(a))
	{
		return getStringLength(b);
	}
	else if (a[0] == b[0])
	{
		return lev(tail(a), tail(b));
	}
	else
	{
		char a0[getStringLength(a) + 1]; char a1[getStringLength(a) + 1]; char a2[getStringLength(a) + 1];
		strcpy(a0, a); strcpy(a1, a); strcpy(a2, a); 
		
		char b0[getStringLength(b) + 1]; char b1[getStringLength(b) + 1]; char b2[getStringLength(b) + 1];
		strcpy(b0, b); strcpy(b1, b); strcpy(b2, b); 

		return 1 + min(lev(tail(a0), b0), lev(a1, tail(b1)), lev(tail(a2), tail(b2)));
		
//		return 1 + min(lev(tail(a), b), lev(a, tail(b)), lev(tail(a), tail(b)));  //WRONG!!!
	}
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

int min(int x, int y, int z)
{
	int arr[3] = {x, y, z};
	
	int minimum = arr[0];
	for (int i = 1; i < 3; i++)
	{
		if (minimum > arr[i])
		{
			minimum = arr[i];
		}
	}
	
//	printf("Min (%d, %d, %d) = %d\n", x, y, z, minimum);
	
	return minimum;
}

int getStringLength(char* str)
{
    int length = 0;
    int index = 0;

    //while (str[index++] != '\0')
    while (str[index] != '\0')
    {
        index++;
        length++;
    }
    
// 	printf("gsl (%s) = %d\n", str, length);

    return length;
}
