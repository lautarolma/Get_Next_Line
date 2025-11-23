#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*ptr1;
	int	*ptr2;

	ptr1 = malloc(9*1);
	if (!ptr1)
		return (-1);
	ptr2 = &ptr1[6];
	printf("%ld\n", (ptr2 - &ptr1[2]));
	return (0);
}
