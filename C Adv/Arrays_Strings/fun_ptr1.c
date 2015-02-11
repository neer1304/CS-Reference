

int main()
{
	char s1[50], s2[50];
	
	printf("\nEnter 2 strings or 2 numbers: ");
	gets (s1);
	gets (s2);

	if (isdigit(*s1))
	{
		printf("\nTesting numbers for equality\n");
		check(s1, s2, compvalues);	
	}
	else
	{
		printf("\nTesting strings for equality\n");
		check(s1, s2, strcmp);	
	}

	return 0;
}

void check(char *a, char *b,
		int (*cmp) (const char *, const char *))
{
	if (!(*cmp)(a,b)) printf ("\nEqual\n");
	else prinf ("\nNot Equal\n");
}	

int compvalues (const char *a, const char *b)
{
	if (atoi(a) == atoi (b)) return 0;
	else return 1;
}

