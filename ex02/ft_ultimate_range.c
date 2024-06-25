// #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (-1);
	else
	{
		i = -1;
		while (++i < max - min)
			tab[i] = min + i;
		*range = tab;
		return (i);
	}
}

int main()
{
    int *range;
    int size;
    int min = 5;
    int max = 10;

    size = ft_ultimate_range(&range, min, max);

    if (size == -1)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    else
    {
        int i = 0;
        while (i < size)
        {
            printf("%d ", range[i]);
            i++;
        }
        printf("\n");

        free(range); // تحرير الذاكرة بعد الاستخدام
    }

    return 0;
}