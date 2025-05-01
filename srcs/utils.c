#include "so_long.h"


/// STRDUP

char *ft_strdup(const char *s){
int i = 0;
int j = 0;

while(s[i])
    i++;

char *array2 = malloc(sizeof(char) * i + 1);
    if(array2 == NULL)
        return NULL;

while(s[j]){
    array2[j] = s[j];
    j++;
}
array2[j] = '\0';
return array2;
}

/// ITOA 

static int	ft_count(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_write(char *str, int n, int sign, int j)
{
	int	i;

	i = j - 1;
	if (sign == 1)
		str[0] = '-';
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		j;
	char	*str;
	int		sign;

	j = 0;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	j = ft_count(n);
	if (n < 0)
	{
		n = n * -1;
		j = 1 + ft_count(n);
		sign = 1;
	}
	else
		j = ft_count(n);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	ft_write(str, n, sign, j);
	return (str);
}
