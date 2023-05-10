#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define row 4 //Установка константы количества уравнений/переменных в системе

void beTriangleMatrix (float system[row][row+1]); // Инициализация методов
void checkerZero (float system[row][row+1]);
void reverseSubs (float system[row][row+1]);
void printer (float system[row][row+1]);
float unvar[row]; //Инициализация массива значений искомых переменных.
float determinant;

void checkerZero (float system[row][row+1]) // Метод избавляется от нулей на осевых элементах
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
			
void beTriangleMatrix (float system[row][row+1]) //Метод получает на вход матрицу и преобразует ее к т.н. треугольному (сверху) виду
{
	float chval; // Инициализация переменной для замены частного коэффициентов. 
	//size_t i,j,k; //Инициализация переменных-счетчиков: количество строк, столбцов расширенной матрицы, количество шагов исключения переменных соответственно.


	for (int k=0; k<row; k++)// Цикл назначает номер шага исключения переменной
	{

		for (int i=k+1; i<row; i++)// Цикл пробегает по всем уравнениям системы, при том, что номер уравнения системы равен номеру шага исключения увеличенного на единицу, т.е. следующего

		{	
		
			float chval = system[i][k]/system[k][k];//Вспомогательная переменная назначается как результат деления коэффициента следующего уравнения на соответсвующий коэффициент текущего уравнения 
			for (int j=k+1; j<=row; j++)// Цикл пробегает по всем коэффициентам текущего уравнения(строки)
				system[i][j] -= system[k][j]*chval;// Каждый последующий коэффициент уравнения равен разнице между соответствующим коэффициентом на предыдущим шаге и коэффициентом на текущем шаге помноженным на вспомогательную переменную значение которой описано при ее назначении см. соответствующий комментарий
		
			system[i][k]=0;// Коэффициенты не учавствующие в последующем расчете приравниваются к нулю
		}
	}
}

void reverseSubs (float system[row][row+1])// Метод реализует метод обратной подстановки. Параметром является какая-либо матрица.
{	
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


void printer (float system[row][row+1]) //Метод выводит на экран матрицу, поступающую на вход как параметр метода

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

void auxilaryRate(float system[row][row+1], float auxilaryRate[row][row+1])
{
  for (int i=0; i<row; i++) // Цикл пробегает по всем уравнениям системы
	{
		for(int j=0; j<row+1; j++) // Цикл пробегает по всем коэффициентам каждого уравнения
		{
      auxilaryRate[i][j] = system[i][j];
    }
  }
}

void descrepancy(float system[row][row+1])
{
  float sum;
  bool truFal;
  float bVal;
  for (int i=0; i<row; i++) // Цикл пробегает по всем уравнениям системы
	{
    sum = 0;
		for(int j=0; j<row; j++) // Цикл пробегает по коэффициентам каждого уравнения, кроме свободного члена b
		{
      sum += system[i][j]*unvar[j];
      if (sum - system[i][j+1] <= 0.001)
        truFal = true;
      bVal = system[i][j+1];
    }
   if (truFal == true) 
      printf ("%f ~= %f -- Верно!\n", sum, bVal);
  }
}
void determ(float system[row][row+1])
{
  for (int i = 0; i<row; i++)
  {
      for( int j = 0; j<row; j++)
      {
        if (i == j )
        determinant = system[i][j];
        printf("%f\n",determinant);
        determinant *=determinant;
      }
  }


}

int main ()
{	
	float rateAu[row][row+1];//Инициализация первоначальной матрицы
	float rate[row][row+1] = {      // Матрица заданной системы уравнений, предствленная в виде многомерного массива. Вариант 6. 
		{3.2, 5.4, 4.2, 2.2, 11.4},
		{2.1, 3.2, 3.1, 1.1, 9.2}, 
		{1.2, 0.4, -0.8, -0.8, 0.4}, 
		{4.7, 10.4, 9.7, 9.7, 30.4}, 
	};

  auxilaryRate(rate, rateAu);//Вызов метода для сохранения первоначальной матрицы
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
  printer(rateAu); 
  descrepancy(rateAu);
  determ(rate);
  printf("Определитель |A|= %f\n", determinant);
	
}
	
