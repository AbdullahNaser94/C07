// #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int	get_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*str_cpy(char *str, char *dest)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	unsigned int	i;
	char		*dest;

	i = get_len(src);
	dest = (char *)malloc(sizeof(char) * i);
	if (!(dest))
		return (NULL);
	return (str_cpy(src, dest));
}

int main() 
{
    char str[] = "Hello, World!";
    char *duplicate_str = ft_strdup(str);

    if (duplicate_str) 
    {
        printf("Original: %s\n", str);
        printf("Duplicate: %s\n", duplicate_str);
        free(duplicate_str);
    } 
    else 
    {
        printf("Memory allocation failed\n");
    }

    return 0;
}