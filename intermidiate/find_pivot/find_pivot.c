
#include <stdio.h>

int	find_pivot(int *arr, int n)
{
	int sum, tmp, i;

	sum = tmp = 0;
	for (i = 0; i < n; i++)
		sum += arr[i];
	for (i = 0; i < n; i++)
	{
		if (tmp == sum - tmp - arr[i])
			return (i);
		tmp += arr[i];
	}
	return (-1);
}

