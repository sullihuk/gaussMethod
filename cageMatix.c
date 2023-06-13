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
float determinant = 1;
float substMat[row/2][row/2], invP[row/2][row/2], invA[row/2][row/2], aA[row/2][row/2], bB[row/2][row/2], cC[row/2][row/2], dD[row/2][row/2], kK[row/2][row/2], lL[row/2][row/2], mM[row/2][row/2], nN[row/2][row/2], multyMat[row/2][row/2], aB[row/2][row/2],cA[row/2][row/2], cAB[row/2][row/2]; //Инициализация вспомогательных матриц для вычисления обратной матрицы
float detMat;
float detA;
float sMatrix[row][row];

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

void descrepancy(float system[row][row+1])// Метод вычисляет невязку с точностью до тысячной доли
{
  float sum;
  bool truFal;
  float bVal;
  for (int i=0; i<row; i++) // Цикл пробегает по всем уравнениям системы
	{
    sum = 0;
		for(int j=0; j<row; j++) // Цикл пробегает по коэффициентам каждого уравнения, кроме свободного члена b
		{
      sum += system[i][j]*unvar[j];//Собственно, вычисление невязки
      if (sum - system[i][j+1] <= 0.001)
        truFal = true;
      bVal = system[i][j+1];//Переменной присваивается значение свободного члена
    }
   if (truFal == true) 
      printf ("%f ~= %f -- Верно!\n", sum, bVal);//Если правые и левые части уравнения отличаются на одну тысячную или менее выводится сообщение о верности решения
  }
}

void printerCage(float matrix [row/2][row/2])//Метод выводит на экран матрицы/четвертинки, например клеточные матрицы
{
  for (int i = 0; i < row/2; i++) {

    printf("| ");
    for (int j = 0; j < row/2; j++) {
      printf("%.2f\t", matrix[i][j]);
    }
    printf("\b\b|");
    puts("");
  }
  puts("-----------------");

}

void determ(float system[row][row+1])// Метод вычисляет определитель матрицы методом Гаусса используя уже преобразованную, треугольную матрицу, хотя параметром может быть любая матрица соответствующей размерности, но тогда, значение переменной determinant не имеет смысла
{
  for (int i = 0; i<row; i++)
  {
	float multy;
      for( int j = 0; j<row; j++)
      {
        if (i == j )
        multy = system[i][j];
      }
      printf("%f\n", multy);
      determinant *= multy;
  }
}

void inverseCageMatrix (float system[row/2][row/2], float system2[row/2][row/2]) //Метод вычисляет обратные матрицыдля клеточных матриц. Очевидно, что метод должен выполнятся после вычисления определителя соотвествующей матрицы
{
  printf("Обратная клеточная матрица\n");
  for (int i = 0; i<row/2; i++)
  {
    for( int j = 0; j<row/2; j++)
    {
      if (i == j){//Условие вычисляет обратную матрицу для клеточной матрицы 
        system[i][j] = system2[row/2-1-i][row/2-1-j]/detMat;
      } else {
        system[i][j] = (system2[i][j]*(-1))/detMat;
	    }
    }
  }
}

void determinantCageMatrix (float system[row/2][row/2])
{
      detMat = 0;
      detMat = system[row/2-row/2][row/2-row/2]*system[row/2-1][row/2-1] - system[row/2-1][row/2-row/2]*system[row/2-row/2][row/2-1];
    
}

void createsCageMatrices(float system[row][row+1])
{
  
  for (int i = 0; i<row; i++)
  {
    for( int j = 0; j<row; j++)
    {
      if(i<row/2 && j<row/2) // Создание клеточной матрицы А
        aA[i][j] = system[i][j];
      
      if(i<row/2 &&  j>=row/2)// Создание клеточной матрицы B
        bB[i][j-row/2] = system[i][j];
      
      if(i>=row/2 && j<row/2)// Создание клеточной матрицы C
        cC[i-row/2][j] = system[i][j];

      if(i>=row/2 && j>=row/2)// Создание клеточной матрицы D
        dD[i-row/2][j-row/2] = system[i][j];
    }
  }
}

void multiplicationMatrix (float system[row/2][row/2], float system2[row/2][row/2])
{
  for (int i = 0; i<row/2; i++)
  {
    for(int j = 0; j<row/2; j++)
    {
      multyMat[i][j] = 0;
      for(int k = 0; k<row/2; k++)
      {
        multyMat[i][j] =multyMat[i][j]+system[i][k]*system2[k][j];
      }
    }
  }
}

void substractionMat (float system[row/2][row/2], float system2[row/2][row/2])
{
  for (int i = 0; i<row/2; i++)
  {
    for(int j = 0; j<row/2; j++)
    {
      substMat[i][j] = system[i][j] + system2[i][j]*(-1);
    }
  }
}

void changeSign (float system[row/2][row/2])
{
  for (int i = 0; i<row/2; i++)
  {
    for(int j = 0; j<row/2; j++)
    {
      system[i][j] = system[i][j]*(-1);
    }
  }
}

void assingmentValuesMat(float system[row/2][row/2], float system2[row/2][row/2])//Метод присваивает значения элементам одной матрицы элементам второй. Необходим для промежуточных вычислений
{
  for (int i = 0; i<row/2; i++)
  {
    for(int j = 0; j<row/2; j++)
    {
      system[i][j] = system2[i][j];
    }
  }
}

void printerInverse(float k[row/2][row/2], float l[row/2][row/2], float m[row/2][row/2], float n[row/2][row/2])//Метод выводит на экран искомую обратную матрицу составленную из клеточных матриц. Параметрами метода являются какие-либо клеточные матрицы, размер которых, равен половине исходной матрицы
{
  for(int i=0; i<row; i++)
  {
    for(int j=0; j<row; j++)
    {
      if(i<row/2 && j<row/2)
        sMatrix[i][j] = k[i][j];
      else if (i<row/2 && j>=row/2)
        sMatrix[i][j] = l[i][j-row/2];
      else if (i>=row/2 && j<row/2)
        sMatrix[i][j] = m[i-row/2][j];
      else if (i>=row/2 && j>=row/2)
        sMatrix[i][j] = n[i-row/2][j-row/2];

        printf("%.2f\t", sMatrix[i][j]);
    }
    puts("");
  }
}


int main ()
{	
	float rateAu[row][row+1];//Инициализация первоначальной матрицы
	float rate[row][row+1] = {      // Матрица заданной системы уравнений, предствленная в виде многомерного массива. Вариант 6. 
		{3.2, 5.4, 4.2, 2.2, 11.4},
		{2.1, 3.2, 3.1, 1.1, 9.2}, 
		{1.2, 0.4, -0.8, -0.8, 0.4}, 
		{4.7, 10.4, 9.7, 9.7, 30.4} 
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
  printer(rateAu);// Вывод вспомогательной (первоначальной,т.к. матрица rate уже преобразована в треугольную) матрицы на экран 
  descrepancy(rateAu);//Вызов метода вычисляющего невязку. Проверка.
  determ(rate);//Вычисление определителя методом Гаусса.
  printf("Определитель |A|= %f\n", determinant);// Вывод на экран значения определителя для заданной матрицы
	createsCageMatrices(rateAu);//Вызов метода для создания клеточных матриц
  printerCage(aA);//Вызов методов для вывода клеточных матриц на экран
  printerCage(bB);//              --//--
  printerCage(cC);//              --//--
  printerCage(dD);//              --//--

  determinantCageMatrix(aA);// Вызов метода для вычисления определителя клеточной матрицы А
  inverseCageMatrix (invA, aA);//Вызов метода для обращения клеточной матрицы А
  printerCage(invA);// Вывод обратной клеточной матрицы на экран

  multiplicationMatrix(invA, bB); 
  assingmentValuesMat(aB, multyMat);
  printerCage(aB);

  multiplicationMatrix(cC, invA); 
  assingmentValuesMat(cA, multyMat);
  printerCage(cA);

  multiplicationMatrix(cA, bB); 
  assingmentValuesMat(cAB, multyMat);
  printerCage(cAB);

  substractionMat(dD, cAB);
  assingmentValuesMat(invP, substMat);
  printerCage(invP);
  determinantCageMatrix(invP);
  inverseCageMatrix (nN, invP);
  printerCage(nN);
  
  multiplicationMatrix(nN, cA); 
  assingmentValuesMat(mM, multyMat);
  changeSign(mM);
  printerCage(mM);

  changeSign(invA);
  multiplicationMatrix(invA, bB); 
  changeSign(invA);
  assingmentValuesMat(lL, multyMat);
  multiplicationMatrix(lL, nN); 
  assingmentValuesMat(lL, multyMat);
  printerCage(lL);

  multiplicationMatrix(invA, bB); 
  assingmentValuesMat(kK, multyMat);
  multiplicationMatrix(kK, mM); 
  assingmentValuesMat(kK, multyMat);
  substractionMat(invA, kK);
  assingmentValuesMat(kK, substMat);
  printerCage(kK);

  printerInverse(kK, lL, mM, nN);
}
	
