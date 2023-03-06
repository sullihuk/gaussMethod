#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define row 5 //Установка константы количества уравнений/переменных в системе

void beTriangleMatrix (double system[row][row+1]); // Инициализация методов
void checkerZero (double system[row][row+1]);
void reverseSubs (double system[row][row+1]);
void printer (double system[row][row+1]);

void checkerZero (double system[row][row+1]) // Метод избавляется от нулей на осевых элементах
{

	for (int i=0; i<row; i++) // Цикл пробегает по всем уравнениям системы
	{
		for(int j=0; j<row+1; j++) // Цикл пробегает по всем коэффициентам каждого уравнения
		{
			while (i==j && system[i][j]==0 && i!=row-1) // Если номер уравнения в системе равен номеру коэффициента, а коэффициент в свою очередь равен нулю, то к каждому коэффициенту прибавляется соотоветствующий коэффициент следующего в системе уравнения, умноженный на -1 (элементарные преобразования системы линейных уравнений)
			{
				for(j=0; j<row+1; j++)
				{
					system[i][j] += (system[i+1][j])*(-1);
				}
			}

			while (i==j && system[i][j]==0 && i==row-1) // Т.к. для последнего уравнения в системе нет следующего, что очевидно, к соответствующим коэффициентам последнего прибавляются коэффициенты предыдущего, также умноженные на -1, что не противоречит правилам элементарных преобразований 
			{
				for(j=0; j<row+1; j++)
				{
					system[i][j] += (system[i-1][j])*(-1);
				}
				
			}
		}
	}
}
			
void beTriangleMatrix (double system[row][row+1]) //Метод получает на вход матрицу и преобразует ее к т.н. треугольному (сверху) виду
{
	double chval; // Инициализация переменной для замены частного коэффициентов. 
	//size_t i,j,k; //Инициализация переменных-счетчиков: количество строк, столбцов расширенной матрицы, количество шагов исключения переменных соответственно.


	for (int k=0; k<row; k++)// Цикл назначает номер шага исключения переменной
	{

		for (int i=k+1; i<row; i++)// Цикл пробегает по всем уравнениям системы, при том, что номер уравнения системы равен номеру шага исключения увеличенного на единицу, т.е. следующего

		{	
		
			double chval = system[i][k]/system[k][k];//Вспомогательная переменная назначается как результат деления коэффициента следующего уравнения на соответсвующий коэффициент текущего уравнения 
			for (int j=k+1; j<=row; j++)// Цикл пробегает по всем коэффициентам текущего уравнения(строки)
				system[i][j] -= system[k][j]*chval;// Каждый последующий коэффициент уравнения равен разнице между соответствующим коэффициентом на предыдущим шаге и коэффициентом на текущем шаге помноженным на вспомогательную переменную значение которой описано при ее назначении см. соответствующий комментарий
		
			system[i][k]=0;// Коэффициенты не учавствующие в последующем расчете приравниваются к нулю
		}
	}
}

void reverseSubs (double system[row][row+1])// Метод реализует метод обратной подстановки. Параметром является какая-либо матрица.
{	
	double unvar[row]; //Инициализация массива значений искомых переменных.
	char solution[]="xyzpq"; //Инициализация массива искомых переменных.

	for(int i=row-1; i>=0; i--) // Цикл решает систему уравнений методом обратной подстановки опираясь на значение последней переменной назначенной ранее
	{
		unvar[i] = system[i][row];// Назначение неизвестной переменной с номером, который соответствует номеру уравнения (счет уравнений ведется снизу вверх, что следует из названия метода)
		for(int j=i+1; j<row; j++)// Цикл вычисляет вспомогательное значение на основе предыдущих значений и соответствующих значений треугльной матрицы 
		{	
			unvar[i] -= system[i][j]*unvar[j]; // В теле цикла назначенное значение переназначается. В данном случае это значение является вспомогательным.
		}	
		unvar[i] /= system[i][i]; // Окончательное вычисление и присвоение соответсующего значения в массиве(наполнение массива вычисленными значениями)
	}
	
	for(int i=0; i<row; i++)//Цикл выводит на экран вычисленные значения переменных
		printf("%c = %.2f\n", solution[i], unvar[i]);
}

void printer (double system[row][row+1]) //Метод выводит на экран матрицу, поступающую на вход как параметр метода

{	

	for (int i=0; i<row; i++)// Цикл выводит на экран значения матрицы, если значение на диагонали равно нулю оно выделяется квадратными скобками.
	{
		printf("string[%d] ", i+1);
		for (int j=0; j<row+1; j++)
		{
			if (system[i][j] ==0 && i==j)
			{ printf(" [%.2f]",system[i][j]);
			}	else {
			printf(" %.2f ",system[i][j]);
			}
		}
		puts("");
	}
	
	puts("");
}

int main ()
{	
	
	double rate[row][row+1] = {      // Матрица заданной системы уравнений, предствленная в виде многомерного массива. Вариант 9. 
		{0, 4, 6, 0, 5, 20},
		{-2, -2, 0, 4, 4, -10}, 
		{5, -1, -1, 5, 5, 34}, 
		{-3, -1, 1, 5, 2, -2}, 
		{2, 6, 5, -2, 0, 37}
	};

	printf("Дано: \n");
	printer(rate); //Вывод на экран первоначальной матрицы 
	printf("Удаление нулей на диагонали матрицы:\n");
	checkerZero(rate); // Преобразование матрицы к виду: без нулей на осевых элементах 
	printer(rate);//Вывод на экран прeобразованной матрицы 
	printf("Преобразование матрицы к треугольному виду:\n");
	beTriangleMatrix(rate);// Преобразование матрицы к треугольному виду
	printer(rate);//Вывод на экран треугольной матрицы 
	printf("Ответ:\n");
	reverseSubs(rate);//Метод обратной подстановки и вывод на экран значений соответствующих переменных, решенной системы линейных уравнений 

	
}
	
