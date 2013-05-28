#include <stdio.h>

int main(void){

	char str[100];

	char str1[] = "•¶Žš—ñ";
	char str2[] = "˜AŒ‹";
	char str3[] = "‚¨ŽèŒy";

	sprintf(str,"%s‚Ì%s‚¾‚Á‚Ä%s‚æ",str1,str2,str3);
	puts(str);
	return 0;
}