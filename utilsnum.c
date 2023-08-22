
void itoa(int n, char *res)
{
	int i = 0; isNeg = 0;
	int start = 0, end = 0;

	if (n == 0)
	{
		res[i++] = '0';
		res[i] = '\0';
		return;
	}

	if (n < 0)
	{
		isNeg = 1;
		n = -n;
	}

	while (n != 0)
	{
		int digit = n % 10;
		res[i++] = digit + '0';
		n = n / 10;
	}

	if (isNeg)
	{
		res[i++] = '-';
	}

	res[i] = '\0';

	for (start = 0, end = i - 1; start < end; start++, end--)
	{
		char temp = res[start];
		res[start] = res[end];
		res[end] = temp;
	}
}

void ftoa(float n, char *res, int dec)
{
	int ipart = (int)n;
	float fpart = n - (float)ipart;
	int i = 0;
	int start = 0, end = 0;

	while (ipart)
	{
		res[i++] = (ipart % 10) + '0';
		ipart = ipart / 10;
	}

	for (start = 0, end = i - 1; start < end; start++, end--)
	{
		char temp = res[start];
		res[start] = res[end];
		res[end] = temp;
	}

	if (dec != 0)
	{
		res[i] = '.';
		fpart = fpart * 10;
		
		for (int j = 0; j < dec; j++)
		{
			int temp = (int)fpart;
			res[++i] = temp + '0';
			fpart = (fpart - temp) * 10;
		}
	}
	res[++i] = '\0';
}
