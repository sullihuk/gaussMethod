#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
      
    FILE *fi;
    fi = fopen("A2.txt", "r");
    // Проверка ошибки открытия файла
    if (fi==NULL) {
      printf("Файл не найден... /n ");
    return 0;
    }

    int t = 51,m = 101;
    // Чтение размерности матрицы
    //fscanf(fi,"%d",&n);
    //fscanf(fi,"%d",&n);
        //printf("Dimension is: %d\n",n);
    int **b;
    // Выделение памяти под матрицу
    b = (int**)malloc(sizeof(int*)*t);
    for(int i=0;i<t;i++)
    b[i] = (int*)malloc(sizeof(int)*m);
      fseek(fi,0,SEEK_SET);
    // Чтение матрицы
    for(int i=0;i<t;i++)
      for(int j=0;j<t;j++)
      fscanf(fi,"%d",&b[i][j]);
    fclose(fi);
    printf("Прочитана матрица: \n");
    // Печать элементов матрицы
    for(int i=0;i<t;i++)
    {
      for(int j=0;j<t;j++)
      printf("%d ",b[i][j]);
      printf("\n");
    }

  FILE *f;
      f = fopen("B2.txt", "r");
      // Проверка ошибки открытия файла
      if (f==NULL) {
        printf("Файл не найден....");
        system("PAUSE");
        return 0;
      }
      int n=0,y;
      int *a;
      // пока не конец файла f
      while (!feof(f))
      {
        // читать элемент и
        int z = fscanf(f,"%d",&y);
        // если произошла ошибка при считывании, то закончить
        // выполнение цикла
        if(z!=1) break;
        // увеличивать счетчик.
        n++;
      }
// После окончания цикла в переменной n хранится
// количество целых чисел, записанных в файле.
// Выделить память под массив.
      a = ( int*)malloc(sizeof(int) *n);
      // Указатель чтения-записи файла передвинуть в начало.
      fseek(f,0,SEEK_SET);
      // Читать n целых чисел из файла в массив.
      for(int i=0;i<n;i++)
        fscanf(f,"%d",&a[i]);
      fclose(f);
      printf("Прочитан массив: \n");
      for(int i=0;i<n;i++)
        printf("%d\n",a[i]);
        printf("Dimension is: %d\n",n);
}
