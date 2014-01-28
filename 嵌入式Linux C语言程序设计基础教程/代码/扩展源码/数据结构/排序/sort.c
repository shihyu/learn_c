#include <stdio.h>

#define N 9

void select_sort(int s[])
{
	int i, j, temp, min;

	for (i=0; i<N-1; i++)
	{
		min = i;
		for (j=i+1; j<N; j++)
		{
			if (s[j] < s[min]) min = j;
		}
		temp = s[i];
		s[i] = s[min];
		s[min] = temp;
	}

	return;
}

void bubble_sort(int s[])
{
	int i, j, temp, flag;

	for (i=N-1; i>=1; i--)
	{
		flag = 0;
		for (j=0; j<i; j++)
		{
			if (s[j] > s[j+1]) 
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
				flag = 1;
			}
		}
		if ( ! flag ) break;
	}

	return;
}

void quick_sort(int s[], int low, int high)
{
	int i, j, key;

	i = low;
	j = high;
	key = s[low];
	while (i < j)
	{
		while ((i < j) && (s[j] >= key)) j--;
		if (i < j) s[i] = s[j];
		while ((i < j) && (s[i] <= key)) i++;
		if (i < j) s[j] = s[i];
	}
	s[i] = key;
	if (i-1 > low) quick_sort(s, low, i-1);
	if (i+1 < high) quick_sort(s, i+1, high);

	return;
}

int main()
{
	int i, s[N] = {24, 56, 17, 9, 33, 80, 44, 23, 66};

	//select_sort(s);
	//bulb_sort(s);
	quick_sort(s, 0, N-1);

	for (i=0; i<N; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");

	return 0;
}
