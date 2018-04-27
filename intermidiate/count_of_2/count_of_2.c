
int	count_of_2(int n)
{
	int i, tmp, count;

	count = 0;
	for (i = 0; i <= n; i++)
	{
		for (tmp = i; tmp > 0; tmp /= 10)
			if (tmp % 10 == 2)
				count++;
	}
	return (count);
}
