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
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

template<typename T>
T** del_col_Matrix(T** arr, int row, int& col, int index)
{
    col -= 1; // del 1 col

    T** arr_1 = new T * [row];

    for (int i = 0; i < row; i++) // init new matrix
    {
        arr_1[i] = new T[col];
    }

    for (int i = 0; i < row; i++) // write from old to new matrix
    {
        for (int j = 0; j < col; j++)
        {
            if (j < index) {
                arr_1[i][j] = arr[i][j];
            }
            else {
                arr_1[i][j] = arr[i][j + 1];
            }
        }
    }

    // Delete old matrix
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return arr_1;
}

template<typename T>
void printMatrix(T** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void printMatrixAdress(T** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        cout << (long long)&arr[i] << "->";
        for (int j = 0; j < col; j++)
        {
            cout << (long long)&arr[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void deleteMatrix(T** arr, int row, int col = 1)
{
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int main()
{
    srand(time(0));

    int col = 4;
    int row = 3;
    int index;
    do
    {
        cout << "Enter index: ";
        cin >> index;
    } while (index < 0 || index > col);

    int** arr = createMatrix<int>(row, col);
    fillMatrix(arr, row, col);
    printMatrix(arr, row, col);

    int** arr_1 = del_col_Matrix<int>(arr, row, col, index);
    cout << endl << endl;
    printMatrix(arr_1, row, col);

    /*printMatrixAdress(arr, row, col);*/

    deleteMatrix(arr_1, row, col);

    system("pause");
    return 0;
}
