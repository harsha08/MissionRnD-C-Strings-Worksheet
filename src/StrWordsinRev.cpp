/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_rev(char *str, int strt,int end)
{
	int i = end, j = strt;
	while (i >= j)
	{
		char t = str[i];
		str[i] = str[j];
		str[j] = t;
		j++; i--;
	}
}

void str_words_in_rev(char *input, int len){
	str_rev(input,0, len-1);
	int i = 0,l=0;
	while (input[i] == ' ' && input[i] != '\0')i++;
	while (input[i] != '\0')
	{
		if (i == 0 || input[i - 1] == ' ')
		{
			l = i;
			i++;
		}
		else if (input[i] == ' ')
		{
			while (input[i] == ' ' && input[i] != '\0')i++;
		}
		else if (input[i + 1] == ' ' || input[i + 1] == '\0')
		{
			str_rev(input, l, i);
			i++;
		}
		else
			i++;
	}
}
