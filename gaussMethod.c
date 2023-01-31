#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define row 5
#define column 6

void gaussMethod (float system[row][column])
{
	for (size_t i=0; i!=row; i++)
	{
		printf("string[%d] ", i+1);
		for (size_t j=0; j<column; j++)
		{
			if (i==j && rate[i][j]==0)
			{
				hold = rate[i];
				rate[i] = rate[i+1];
				rate[i+1]=hold;
			}
		}
	}
}

int main ()
{
	float rate[row][column] = {
		{0, 4, 6, 0, 5, 20},
		{-2, -2, 0, 4, 4, -10}, 
		{5, -1, -1, 5, 5, 34}, 
		{-3, -1, 1, 5, 2, -2}, 
		{2, 6, 5, -2, 0, 37}
	};
	float x, y, z, p, q, free;
	
	float *hold;
	
	float sumFunc(float x, float y, float z, float p, float q, float free)
	{
		if rate[0][0] == 0

	}
	size_t i;
	size_t j;

	for (size_t i=0; i!=row; i++)
	{
		printf("string[%d] ", i+1);
		for (size_t j=0; j<column; j++)
		{
			printf(" %.2f ",rate[i][j]);
		}
		puts("");
	}
	
		
}
	
	
