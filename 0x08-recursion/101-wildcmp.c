#include "main.h"

/**
 * wildcmp - returns 1 after comparison
 * @s1: first string to compare
 * @s2: second string to compare; may contain the special character *
 *
 * Return: 1 if s1 and s2 are identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0') /* if both strings are empty */
		return (1);

	if (*s2 == '*')
	{
		if (*s1 == '\0' && *(s2 + 1) == '\0') /* if s2 only contains * */
			return (1);
		if (*s1 == '\0') /* compares s1 and s2 */
			return (wildcmp(s1, s2 + 1));
		/* compare s1 with s2 empty string, character */
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	}

	if (*s1 == *s2) /* if match compare the next */
		return (wildcmp(s1 + 1, s2 + 1));

	return (0); /* the characters don't match and there's no * to replace s2 */
}




