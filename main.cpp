#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T** createMatrix(int row, int col)
{
    T** arr = new T * [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new T[col];
    }
    return arr;
}

template<typename T>
void fillMatrix(T** arr, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}


template<typename T>
T** add_bottom_Matrix(T** arr, int &row, int col)
{
    
    T** arr_1 = new T * [row + 1];

    for (int i = 0; i < (row + 1); i++)//init new matrix
    {
        arr_1[i] = new T[col];
    }


    for (size_t i = 0; i < row; i++)//write from old to new matrix
    {
        for (size_t j = 0; j < col; j++)
        {
            arr_1[i][j] = arr[i][j];
        }
    }

    row += 1;//add 1 row

    for (size_t j = 0; j < col; j++)//write new row
    {
        arr_1[row - 1][j] = rand() % 10;
    }
    return arr_1;
}


template<typename T>
void printMatrix(T** arr, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void printMatrixAdress(T** arr, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        cout << (long long)&arr[i] << "->";
        for (size_t j = 0; j < col; j++)
        {
            cout << (long long)&arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));

    int col = 4;
    int row = 3;

    int** arr = createMatrix<int>(row, col);
    fillMatrix(arr, row, col);
    printMatrix(arr, row, col);

    int** arr_1 = add_bottom_Matrix<int>(arr, row, col);
    cout << endl << endl;
    printMatrix(arr_1, row, col);
    /*printMatrixAdress(arr, row, col);*/

    system("pause");
    return 0;
}