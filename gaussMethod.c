#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define row 5
#define column 6

/* Экспериментальный метод
void adder (float system[row][column])
{
	for(size_t i=0; i<row; i++)
	{
		for(size_t j=0; j<column; j++)
		{
			system[i][j] += system[i+1][j]*(-1);
			if (i==row-1)
			{
				system[i][j] += system[i-1][j]*(-1);
			}
		}
	}
}
*/ 

void checkerZero (float system[row][column]) // Метод избавляется от нулей на осевых элементах
{

		for (size_t i=0; i<row; i++) // Цикл пробегает по всем уравнениям системы
		{
			for(size_t j=0; j<column; j++) // Цикл пробегает по всем коэффициентам каждого уравнения
			{
				if (i==j && system[i][j]==0 && i!=row-1) // Если номер уравнения в системе равен номеру коэффициента, а коэффициент в свою очередь равен нулю, то к каждому коэффициенту прибавляется соотоветствующий коэффициент следующего в системе уравнения, умноженный на -1 (элементарные преобразования системы линейных уравнений)
				{
					for(j=0; j<column; j++)
					{
						system[i][j] += (system[i+1][j])*(-1);
					}
				}
					if (i==j && system[i][j]==0 && i==row-1) // Т.к. для последнего уравнения в системе нет следующего, что очевидно, к соответствующим коэффициентам последнего прибавляются коэффициенты предыдущего, также умноженные на -1, что не противоречит правилам элементарных преобразований 
					{
						for(j=0; j<column; j++)
						{
							system[i][j] += (system[i-1][j])*(-1);
						}
						
					}
						
				

			}

		}
		
}
			
void gaussMethod (float system[row][column])
{

	float x, y, z, p, q, free;
	size_t i;
	size_t j;
	
	float a11 = system[0][0];
	for (size_t j=0; j<column; j++)

		{
			system[0][j] /= a11;
			
		}

	for (size_t i=1; i<row; i++)
	{

		for (size_t j=0; j<column; j++)
		{
			
			if(i==j)
			{
				break;}
			else
			{
				system[i][j] = system[i-1][j] - (system[i][j]/system[i][j+1])*system[i-1][j+1];
			system[i][column-1]=system[i-1][column-1]-(system[i-1][column-1]/system[i][j+1])*system[i-1][j+1];
			}	
		}
	}
}

void printer (float system[row][column])
{
	for (size_t i=0; i<row; i++)
	{
		printf("string[%d] ", i+1);
		for (size_t j=0; j<column; j++)
		{
			printf(" %.2f ",system[i][j]);
		}
		puts("");
	}
	puts("");
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
	//adder(rate);

	checkerZero(rate);
	printer(rate);
	gaussMethod(rate);
	printf("%f", rate[0][0]);
	puts("");
	printer(rate);
	
}
	
	
