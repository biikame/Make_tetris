#include <stdio.h>

int main(void){

	char str[100];

	char str1[] = "������";
	char str2[] = "�A��";
	char str3[] = "����y";

	sprintf(str,"%s��%s������%s��",str1,str2,str3);
	puts(str);
	return 0;
}