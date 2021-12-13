#include "libft.h"

static int	a_count(char const *str, char sep)
{
	int	count;

	count = 1;
	while (*str)
	{
		if (*str == sep)
			count = 0;
		while (*str && *str != sep)
			str++;
		if (*str && *str == sep)
			while (*str && *str == sep)
				str++;
		if (*str != 0x00)
			count++;
	}
	return (count);
}

static char	*copy_string(char **str, char sep)
{
	char	*newstr;
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while ((*str)[i] != sep && (*str)[i] != 0x00)
	{
		size++;
		i++;
	}
	newstr = (char *)malloc(sizeof(char) * size + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (**str != sep && **str != 0x00)
	{
		newstr[i++] = **str;
		(*str)++;
	}
	newstr[i] = 0x00;
	return (newstr);
}

/**
 * Split the string (*s) by the character (c)
 * Returns an array of the split strings
 * FREE REQ
 **/
char	**ft_split(char const *s, char c)
{
	char	*w;
	char	**out;
	size_t	i;

	if (!s)
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (a_count(s, c) + 1));
	if (!out)
		return (NULL);
	w = (char *)s;
	i = 0;
	while (*w)
	{
		while (*w == c)
			w++;
		if (*w == 0x00)
			break ;
		out[i] = copy_string(&w, c);
		if (!out[i])
			return (NULL);
		i++;
	}
	out[i] = NULL;
	return (out);
}
