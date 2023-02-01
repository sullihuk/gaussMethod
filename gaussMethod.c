#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define row 5
#define column 6

float checkerZero (float system[row][column])
{
	float sistema;

		for (size_t i=0; i<row; i++)
		{
			for(size_t j=0; j<column; j++)
			{
				if (i==j && system[i][j]==0)
				{
					system[i][j] += system[i+1][j]*(-1);
				
				}

			}

		}
		return 
		
}
			
void gaussMethod (float system[row][column])
{

	float x, y, z, p, q, free;
	size_t i;
	size_t j;
	float *hold;

	for (size_t i=0; i<row; i++)
	{
		printf("string[%d] ", i+1);
		for (size_t j=0; j<column; j++)
		{
			
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
	

	for (size_t i=0; i<row; i++)
	{
		printf("string[%d] ", i+1);
		for (size_t j=0; j<column; j++)
		{
			if (rate[i][j] ==0 && i==j)
			{ printf(" [%.2f]",rate[i][j]);
			}	else {
			printf(" %.2f ",rate[i][j]);
			}
		}
		puts("");
	}
	puts("");	
	for (size_t i=0; i!=row; i++)
	{
		printf("string[%d] ", i+1);
		for (size_t j=0; j<column; j++)
		{
			printf(" %.2f ",checkerZero(rate));
		}
		puts("");
	}
	printf(" %.2f ", checkerZero(rate));	
}
	
	
