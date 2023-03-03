#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define row 5

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
void gaussMethod (float system[row][row+1]);
void checkerZero (float system[row][row+1]) // Метод избавляется от нулей на осевых элементах
{

		for (size_t i=0; i<row; i++) // Цикл пробегает по всем уравнениям системы
		{
			for(size_t j=0; j<row+1; j++) // Цикл пробегает по всем коэффициентам каждого уравнения
			{
				if (i==j && system[i][j]==0 && i!=row-1) // Если номер уравнения в системе равен номеру коэффициента, а коэффициент в свою очередь равен нулю, то к каждому коэффициенту прибавляется соотоветствующий коэффициент следующего в системе уравнения, умноженный на -1 (элементарные преобразования системы линейных уравнений)
				{
					for(j=0; j<row+1; j++)
					{
						system[i][j] += (system[i+1][j])*(-1);
					}
				}
					if (i==j && system[i][j]==0 && i==row-1) // Т.к. для последнего уравнения в системе нет следующего, что очевидно, к соответствующим коэффициентам последнего прибавляются коэффициенты предыдущего, также умноженные на -1, что не противоречит правилам элементарных преобразований 
					{
						for(j=0; j<row+1; j++)
						{
							system[i][j] += (system[i-1][j])*(-1);
						}
						
					}
			}
		}
}
			
void gaussMethod (float system[row][row+1])
{
	float x, y, z, p, q;
	float unvar[row]={x, y, z, p, q}; //Инициализация массива искомых переменных.
	//float chval; // Инициализация переменной для замены частного коэффициентов. 
	//size_t i,j,k; //Инициализация переменных-счетчиков: количество строк, столбцов расширенной матрицы, количество шагов исключения переменных соответственно.


	for (int k=0; k<row; k++)
	{

		for (int i=k+1; i<row; i++)
		{	
		
			float chval = system[i][k]/system[k][k];
			for (int j=k+1; j<=row; j++)
			
				system[i][j] -= system[i][j]*chval;
			
		
			system[i][k]=0;
		}
	}

/*unvar[row]=system[row][row+1]/system[row][row];

	for(size_t i=row-1; i>=1; i--)
	{
		unvar[i] = system[i][row+1];
		for(j=i+1; j<=row; j++)
		{
			unvar[i] -= system[i][j]*unvar[j];
		}
		unvar[i] /= system[i][i];
	}*/
}

void printer (float system[row][row+1])

{	

	puts("");
	for (size_t i=0; i<row; i++)
	{
		printf("string[%d] ", i+1);
		for (size_t j=0; j<row+1; j++)
		{
			if (system[i][j] ==0 && i==j)
			{ printf(" [%.2f]",system[i][j]);
			}	else {
			printf(" %.2f ",system[i][j]);
			}
		}
		puts("");
	}
}

int main ()
{
	float rate[row][row+1] = {
		{0, 4, 6, 0, 5, 20},
		{-2, -2, 0, 4, 4, -10}, 
		{5, -1, -1, 5, 5, 34}, 
		{-3, -1, 1, 5, 2, -2}, 
		{2, 6, 5, -2, 0, 37}
	};


	
	printer(rate);
	checkerZero(rate);
	printer(rate);
	gaussMethod(rate);
	printer(rate);
	
}
	
