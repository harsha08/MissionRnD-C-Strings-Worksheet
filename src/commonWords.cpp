/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int search(char *str1, char *str2)
{
	int i = 0, len1 = 0, len2 = 0,k=0,j=0;
	while (str1[len1] != '\0')len1++;
	while (str2[len2] != '\0')len2++;
	for (i = 0; str1[i] != '\0'; i++)
	{
		k = i;
		for (j = 0; str2[j] != '\0'; j++, k++)
		{
			if (str2[j] != str1[k])
				break;
		}
		if (j == len2)
		{
			return 1;
		}
		
	}
	return 0;
}

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	int i = 0, len1 = 0, len2 = 0, l = 0, k = 0,tot=-1;
	char tmp[31] = "", **result;
	result = (char **)malloc(10 * sizeof(char *));
	while (str1[i] == ' ' && str1[i] != '\0')i++;
	while (str1[i] != '\0')
	{
		if (i == 0 || str1[i - 1] == ' ')
		{
			l = i;
			i++;
		}
		else if (str1[i] == ' ')
		{
			while (str1[i] == ' ' && str1[i] != '\0')i++;
		}
		else if (str1[i + 1] == ' ' || str1[i + 1] == '\0')
		{
			k = 0;
			while (l <= i)
			{
				*(tmp + k) = str1[l];
				k++; l++;
			}
			tmp[k] = '\0';
			
			if (search(str2, tmp))
			{
				tot++;
				k = 0;
				result[tot] = (char *)malloc(31 * sizeof(char *));
				while (tmp[k] != '\0')
				{
					result[tot][k] = tmp[k];
					k++;
				}
				result[tot][k] = '\0';
			}
			i++;
		}
		else
			i++;
	}
	if (tot > 0)
	{
		return result;
	}
	else
	{
		return NULL;
	}
}