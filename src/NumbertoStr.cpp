/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <math.h>

void str_rev(char *str,int len)
{
	int i = len-1, j = 0;
	while (i >= j)
	{
		char t = str[i];
		str[i] = str[j];
		str[j] = t;
		j++; i--;
	}
}
void number_to_str(float number, char *str,int afterdecimal){
	int flag = 0;
	int num = 0, r = 0, i = 0, j = 0;
	float fractionpart=0.0, fp = 0.0;

	if (number < 0)
	{
		flag = 1;
		number = -(number);
	}
	
	num = floor(number);
	fractionpart = number - num;
	while (num != 0)
	{
		r = num % 10;
		num = num / 10;
		str[i++] = r + '0';
	}
	
	str_rev(str, i);
	if (afterdecimal > 0)
	{
		str[i++] = '.';
		while (afterdecimal >= 0)
		{
			fp = fractionpart * 10;
			r = (int)fp % 10;
			str[i++] = r + '0';
			fractionpart = fp-floor(fp);
			afterdecimal--;
		}
	}
	str[i++] = '\0';
	if (flag)
	{
		j = i;
		while (j > 0)
		{
			str[j] = str[j - 1];
			j--;
		}
		str[0] = '-';
	}
}
