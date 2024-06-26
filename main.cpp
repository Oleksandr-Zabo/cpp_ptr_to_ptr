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
T** shift_up_Matrix(T** arr, int row, int col, int shift)
{
    T** arr_1 = new T * [row];
    for (int i = 0; i < row; i++) // init new matrix
    {
        arr_1[i] = new T[col];
    }

    T** arr_2 = new T * [shift];
    for (int i = 0; i < shift; i++) // init top copy matrix
    {
        arr_2[i] = new T[col];
    }
    for (int i = 0; i < shift; i++) // write top from old to copy matrix
    {
        for (int j = 0; j < col; j++)
        {
            arr_2[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < (row - shift); i++) // write from old to new matrix
    {
        for (int j = 0; j < col; j++)
        {
            arr_1[i][j] = arr[i + shift][j];
        }
    }
    for (int i = (row - shift); i < row; i++) // write from copy to new matrix
    {
        for (int j = 0; j < col; j++)
        {
            arr_1[i][j] = arr_2[i - (row - shift)][j];
        }
    }

    // Delete old matrix
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    // Delete temporary matrix
    for (int i = 0; i < shift; i++)
    {
        delete[] arr_2[i];
    }
    delete[] arr_2;

    return arr_1;
}




template<typename T>
T** shift_down_Matrix(T** arr, int row, int col, int shift)
{
    T** arr_1 = new T * [row];
    for (int i = 0; i < row; i++) // init new matrix
    {
        arr_1[i] = new T[col];
    }

    T** arr_2 = new T * [shift];
    for (int i = 0; i < shift; i++) // init top copy matrix
    {
        arr_2[i] = new T[col];
    }
    for (int i = (row - shift), k = 0; i < row; i++, k++) // write top from old to copy matrix
    {
        for (int j = 0; j < col; j++)
        {
            arr_2[k][j] = arr[i][j];
        }
    }

    for (int i = 0; i < shift; i++) // write from copy to new matrix
    {
        for (int j = 0; j < col; j++)
        {
            arr_1[i][j] = arr_2[i][j];
        }
    }

    for (int i = 0; i < (row - shift); i++) // write from old to new matrix
    {
        for (int j = 0; j < col; j++)
        {
            arr_1[i + shift][j] = arr[i][j];
        }
    }
    

    // Delete old matrix
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    // Delete temporary matrix
    for (int i = 0; i < shift; i++)
    {
        delete[] arr_2[i];
    }
    delete[] arr_2;

    return arr_1;
}


template<typename T>
T** shift_right_Matrix(T** arr, int row, int col, int shift)
{
    T** arr_1 = new T * [row];
    for (int i = 0; i < row; i++) // init new matrix
    {
        arr_1[i] = new T[col];
    }

    T** arr_2 = new T * [row];
    for (int i = 0; i < row; i++) // init right copy matrix
    {
        arr_2[i] = new T[shift];
    }
    for (int i = 0; i < row; i++) // write right from old to copy matrix
    {
        for (int j = (col - shift), k = 0; j < col; j++, k++)
        {
            arr_2[i][k] = arr[i][j];
        }
    }

    for (int i = 0; i < row; i++) // write from copy to new matrix
    {
        for (int j = 0; j < shift; j++)
        {
            arr_1[i][j] = arr_2[i][j];
        }
    }

    for (int i = 0; i < row; i++) // write from old to new matrix
    {
        for (int j = 0; j < (col - shift); j++)
        {
            arr_1[i][j + shift] = arr[i][j];
        }
    }

    // Delete old matrix
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    // Delete temporary matrix
    for (int i = 0; i < row; i++)
    {
        delete[] arr_2[i];
    }
    delete[] arr_2;

    return arr_1;
}



template<typename T>
T** shift_left_Matrix(T** arr, int row, int col, int shift)
{
    T** arr_1 = new T * [row];
    for (int i = 0; i < row; i++) // init new matrix
    {
        arr_1[i] = new T[col];
    }

    T** arr_2 = new T * [row];
    for (int i = 0; i < row; i++) // init left copy matrix
    {
        arr_2[i] = new T[shift];
    }
    for (int i = 0; i < row; i++) // write left from old to copy matrix
    {
        for (int j = 0; j < shift; j++)
        {
            arr_2[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < row; i++) // write from old to new matrix
    {
        for (int j = shift; j < col; j++)
        {
            arr_1[i][j - shift] = arr[i][j];
        }
    }

    for (int i = 0; i < row; i++) // write from copy to new matrix
    {
        for (int j = 0; j < shift; j++)
        {
            arr_1[i][col - shift + j] = arr_2[i][j];
        }
    }

    // Delete old matrix
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    // Delete temporary matrix
    for (int i = 0; i < row; i++)
    {
        delete[] arr_2[i];
    }
    delete[] arr_2;

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

    int row;
    do
    {
        cout << "Enter rows (M): ";
        cin >> row;
    } while (row < 0);

    int col;
    do
    {
        cout << "Enter cols (N): ";
        cin >> col;
    } while (col < 0);


    int** arr = createMatrix<int>(row, col);
    fillMatrix(arr, row, col);
    printMatrix(arr, row, col);
    cout << endl;

    int** arr_1 = nullptr;
    int num_shift;
    int side;
    do
    {
        cout << "Side menu: \n1- up \n2- down \n3- right \n4- left \nEnter side: ";
        cin >> side;
    } while (side < 1 || side > 4);
    


    switch (side)
    {
        case 1:
        {
            do
            {
                cout << "Enter num of shift: ";
                cin >> num_shift;
            } while (num_shift < 0 || num_shift > row);

            arr_1 = shift_up_Matrix<int>(arr, row, col, num_shift);
        }break;

        case 2:
        {
            do
            {
                cout << "Enter num of shift: ";
                cin >> num_shift;
            } while (num_shift < 0 || num_shift > row);
            arr_1 = shift_down_Matrix<int>(arr, row, col, num_shift);
        }break;

        case 3:
        {
            do
            {
                cout << "Enter num of shift: ";
                cin >> num_shift;
            } while (num_shift < 0 || num_shift > col);
            arr_1 = shift_right_Matrix<int>(arr, row, col, num_shift);
        }break;

        case 4:
        {
            do
            {
                cout << "Enter num of shift: ";
                cin >> num_shift;
            } while (num_shift < 0 || num_shift > col);
            arr_1 = shift_left_Matrix<int>(arr, row, col, num_shift);
        }break;

       
    }

    
    cout << endl << endl;
    printMatrix(arr_1, row, col);

    /*printMatrixAdress(arr, row, col);*/

    deleteMatrix(arr_1, row, col);

    system("pause");
    return 0;
}
