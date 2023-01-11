# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
//si option != 0 il cherchera endl
size_t	ft_strlen_or_findendl(char *s, int option)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (option && s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*pt;
	size_t			totalsize;
	unsigned char	*cast;

	if (!nmemb && !size)
		return (NULL);
	else if (!nmemb || !size)
		return (malloc(0));
	totalsize = size * nmemb;
	if (totalsize / size != nmemb)
		return (NULL);
	pt = malloc(totalsize);
	if (!pt)
		return (NULL);
	cast = (unsigned char *)pt;
	while (totalsize--)
		cast[totalsize] = 0;
	return (pt);
}

static char	*ft_strdup(char *s, int option)
{
	char	*ptr;
	size_t	i;

	ptr = ft_calloc((ft_strlen_or_findendl(s, 0) + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	if (option)
		return (free(s), ptr);
	return (ptr);
}

//je free s2 lors de lallocation
char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*s;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2, 1));
	else if (!s2)
		return (ft_strdup(s1, 1));
	s = ft_calloc(ft_strlen_or_findendl(s1, 0) + \
	ft_strlen_or_findendl(s2, 0) + 1, sizeof(char));
    j = 0;
    i = 0;
	while (i < ft_strlen_or_findendl(s1, 0))
	{
		s[i] = s1[i];
		i++;
	}
	while (j < ft_strlen_or_findendl(s2, 0))
	{
		s[j + i] = s2[j];
		j++;
	}
	return (free(s1), free(s2), s);
}

char	*ft_strcutendl(char *str, char *after, size_t i)
{
	char	*before;
	size_t	i_endl;

	i_endl = ft_strlen_or_findendl(str, 1);
    if (!str[i_endl])
        return (str);
    before = ft_calloc((i_endl + 2), sizeof(char));
    after = ft_calloc((ft_strlen_or_findendl(str, 0)) - i_endl + 1, sizeof(char));
    while (str[i])
    {
        if (i < i_endl)
            before[i] = str[i];
        if (i == i_endl)
        {
            before[i] = str[i];
            before[i + 1] = '\0';
        }
        if (i > i_endl)
            after[i - i_endl] = str[i];
        i++;
    }
    after[i - i_endl] = '\0';
    return (before);
}

int main()
{
    char *res;
    char *after = NULL;
    char *str;

    str  = "01234\n6789.";
    printf("after = %s\nstr = %s\n|FIN", after, str);
    res = ft_strcutendl(str, after, 0);
    printf("\nafter = %s\nstr = %s\nres = %s|FIN", after, str, res);
    free(after);
    free(res);
    return (0);
}