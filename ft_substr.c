#include "ds.h"

char	*ft_substr(char const *s, int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	i = (size_t) start;
	str = malloc(sizeof(char [len + 1]));
	if (!str)
		return (NULL);
	while (i < len + start && s[i])
	{
		str[i - start] = s[i];
		i++;
	}
	str[i - start] = '\0';
	return (str);
}
