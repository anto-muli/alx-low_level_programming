/**
 * binary_to_uint - convert a binary # to unsigned int
 * @x: points to a string of 0 and 1 characters
 *
 * Return: the converted # or 0 if there is one of more
 * chars in the string b that is not 0 or 1 og if b is null
 */
unsigned int binary_to_uint(const char *x)
{
	int a;
	unsigned int dec_val = 0;

	if (!x)
		return (0);

	for (a = 0; x[a]; a++)
	{
		if (x[a] < '0' || x[a] > '1')
			return (0);
		dec_val = 2 * dec_val + (x[a] - '0');
	}
	return (dec_val);
}
