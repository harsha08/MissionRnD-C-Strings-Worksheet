/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	if (str == nullptr || str == "")
		return '\0';
	int len = 0,count=0,i=0;
	while (str[len] != '\0')
	{
		if (str[len] == ' ')
		{
			i = len;
			while (str[i] == ' ' && str[i] != '\0')
			{
				count++;
				i++;
			}
			while (str[i] != '\0')
			{
				str[i - count] = str[i];
				i++;				
			}
			str[i - count] = '\0';
			count = 0;
			len--;
		}
		len++;
	}
}