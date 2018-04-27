
int	is_anagram(char *a, char *b)
{
	int sum_a, sum_b, i, i2;

	sum_a = sum_b = 0;
	for (i = 0; a[i]; i++)
		sum_a += a[i];
	for (i2 = 0; b[i2]; i2++)
		sum_b += b[i2];
	return ((sum_a == sum_b && i == i2) ? 1 : 0);
}
