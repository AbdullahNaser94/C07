// #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*array;
	unsigned int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	array = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

int main()
{
    int min = 5;
    int max = 10;
    int *range = ft_range(min, max);

    if (range)
    {
        int i = 0;
        while (i < (max - min))
        {
            printf("%d ", range[i]);
            i++;
        }
        printf("\n");
        free(range); // تحرير الذاكرة بعد الاستخدام
    }
    else
    {
        printf("Range is NULL\n");
    }

    return 0;
}