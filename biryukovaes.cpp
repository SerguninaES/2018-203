#include "biryukovaes.h"

/**
 * Введение в дисциплину
 */
void biryukovaes::lab1()
{
std::cout<<"Hello, world!";
	
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void biryukovaes::lab2()
{
int i, j, m, l;
    for(i=0;i<N;i++)
        {
          m=i;
          for(l=i+1; l<N; l++)
          if (abs(A[l][i])>abs(A[m][i]))
                m=l;
          swap(A[m],A[i]);
          swap(b[m],b[i]);
           b[i]/=A[i][i];
          for(j=N-1; j>i; A[i][j--]/=A[i][i]);
          A[i][i]=1;
          for(int j=i+1; j<N;j++){
          for(l=N-1;l>i;l--)
          A[j][l]-=A[i][l]*A[j][i];
          b[j]-=b[i]*A[j][i];
          A[j][i]=0;
          }
            cout<<endl;
          }
          x[N-1]=b[N-1];
          for ( int i = N - 2; i >= 0; i-- )
         {
           x[i] = b[i];
           for ( int j = i + 1; j < N; j++ ) {
              x[i] -= A[i][j] * x[j];
              }
          }
}



/**
 * Метод прогонки
 */
void biryukovaes::lab3()
{

    double* new_A = new double[N];
    double* new_b = new double[N];

    new_A[0] = A[0][1] / (-A[0][0]);
    new_b[0] = b[0] / A[0][0];

    for(int i = 1; i < N; i++)
    {
        new_A[i] = A[i][i+1] / (-A[i][i-1] * new_A[i-1] - A[i][i]);
        new_b[i] = (-b[i] + A[i][i-1] * new_b[i-1]) / ( -A[i][i-1] * new_A[i-1] - A[i][i]);
    }

    for(int i = N - 1; i >= 0; i--)
    {
        x[i] = new_A[i] * x[i+1] + new_b[i];
    }

    delete[] new_A;
    delete[] new_b;

}

/**
 * Метод простых итераций
 */
void biryukovaes::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void biryukovaes::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void biryukovaes::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void biryukovaes::lab7()
{

}


void biryukovaes::lab8()
{

}

void biryukovaes::lab9()
{

}


std::string biryukovaes::get_name()
{
  return "Biryukova E.S.";
}
