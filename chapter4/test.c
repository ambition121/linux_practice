#include <string.h>
#include <stdio.h>
int main(void)
{
    char string[20];
    char *ptr, *pts, c = 'r';
    strcpy(string, "There are two rings");
    ptr = strrchr(string, c);
    pts = strchr(string, c);
    /*if (ptr)
	printf("The character %c is at position: %s\n", c, ptr);*/
    if(pts)
	printf("The character %c is at position: %s\n", c, pts);
    else
	printf("The character was not found\n");
    return 0;
}
