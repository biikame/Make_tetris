#include <stdio.h>

int main(void){

	char str[100];

	char str1[] = "文字列";
	char str2[] = "連結";
	char str3[] = "お手軽";

	sprintf(str,"%sの%sだって%sよ",str1,str2,str3);
	puts(str);
	return 0;
}