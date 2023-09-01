/**
 * binary_to_uint - converts a bin # to unsigned int
 * @b: points to a string of 0 and 1 chars
 *
 * Return: the converted # or 0 if there is one of morr
 * chars in the string b that is not 0 or 1 og if b is null
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (a = 0; b[a]; a++)
	{
		if (b[a] < '0' || b[a] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[a] - '0');
	}
	return (dec_val);
}
