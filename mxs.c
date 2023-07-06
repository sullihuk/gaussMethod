#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 51

void tdS (int q, double a[MAX_SIZE], double b[MAX_SIZE], double c[MAX_SIZE], double d[MAX_SIZE],double x[MAX_SIZE])
{
  double m;
  for (int i; i<q; i++)
  {
    m=a[i]/b[i-1];
    b[i] -= m*c[i-1];
    d[i] -= m*d[i-1];
  }
  x[q-1]=d[q-1]/b[q-1];
  for(int i=q-2; i>=0; i--)
  {
    x[i]=(d[i]-c[i]*x[i+1])/b[i];
  }
}

int main(int argc, char *argv[])
{
      
        double aa[MAX_SIZE];
        double bb[MAX_SIZE];
        double cc[MAX_SIZE];
        double dd[MAX_SIZE];
        double xx[MAX_SIZE];

    FILE *fi;
    fi = fopen("A2.txt", "r");
    // Проверка ошибки открытия файла
    if (fi==NULL) {
      printf("Файл не найден... \n ");
    return 0;
    }

    int t = 51,m = 101,v=0, yy;
      while (!feof(fi))
      {
        // читать элемент и
        int z = fscanf(fi,"%d",&yy);
        if(z!=1) break;
        // увеличивать счетчик.
        v++;
      }
    //fscanf(fi,"%d",&n);
    //fscanf(fi,"%d",&n);
        //printf("Dimension is: %d\n",n);
    double **b;
    // Выделение памяти под матрицу
    b = (double**)malloc(sizeof(double*)*t);
    for(int i=0;i<t;i++)
    b[i] = (double *)malloc(sizeof(double)*m);
      fseek(fi,0,SEEK_SET);
    // Чтение матрицы
    for(int i=0;i<t;i++)
      for(int j=0;j<t;j++){
      fscanf(fi,"%d",&yy);
      b[i][j] = (double)yy;
      }

    fclose(fi);
    printf("Прочитана матрица: \n");
    // Печать элементов матрицы
    /*for(int i=0;i<t;i++)
    {
      for(int j=0;j<t;j++)
      printf("%.2f ",b[i][j]);
      printf("\n");
    }*/

  FILE *f;
      f = fopen("B2.txt", "r");
      // Проверка ошибки открытия файла
      if (f==NULL) {
        printf("Файл не найден....");
      }
      int n=0,y;
      double *a;
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
      a = (double*)calloc(n, sizeof(double));
      // Указатель чтения-записи файла передвинуть в начало.
      fseek(f,0,SEEK_SET);
      // Читать n целых чисел из файла в массив.
      for(int i=0;i<n;i++){
        fscanf(f,"%d",&y);
        dd[i] = (double)y;
      }
      fclose(f);
      printf("Прочитан массив: \n");
      for(int i=0;i<n;i++)
        printf("%.2f\n",dd[i]);
        printf("Dimension is: %d\n",n);

        printf("Main\tUpper\tLower\tSolution\n");

      for(int i=0; i<n; i++)
      {
        for(int j=0; j<n; j++)
        {
          
          if(i==j)
          bb[i] = b[i][j];

          
          if(j == i-1){
            //aa[0] = 0;
            aa[i] = b[i][j];
          }
          if(j == i+1){
            //cc[n-1] = 0;
            cc[i] = b[i][j];
          }
        }
      }
      tdS(51, aa, bb, cc, dd, xx);
      for(int i = 0; i<n; i++)
        printf("%.2f\t%.2f\t%.2f\t%.3f\n",aa[i], bb[i], cc[i], xx[i]);

}
