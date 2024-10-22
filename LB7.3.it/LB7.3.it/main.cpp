#include <iostream>
#include <iomanip>
using namespace std;

void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void RemoveZeroRowsAndCols(int**& a, int& rowCount, int& colCount);
int FindFirstPositiveRow(int** a, const int rowCount, const int colCount);

int main()
{
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    cout << "Original Matrix:\n";
    Print(a, rowCount, colCount);

    RemoveZeroRowsAndCols(a, rowCount, colCount);
    cout << "Compressed Matrix (without zero rows and cols):\n";
    Print(a, rowCount, colCount);

    int firstPositiveRow = FindFirstPositiveRow(a, rowCount, colCount);
    if (firstPositiveRow != -1)
        cout << "First row with at least one positive element: " << firstPositiveRow << endl;
    else
        cout << "No row with positive elements found.\n";

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

void RemoveZeroRowsAndCols(int**& a, int& rowCount, int& colCount)
{
    bool* zeroRows = new bool[rowCount];
    bool* zeroCols = new bool[colCount];

    for (int i = 0; i < rowCount; i++)
    {
        zeroRows[i] = true;
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] != 0)
            {
                zeroRows[i] = false;
                break;
            }
        }
    }

    for (int j = 0; j < colCount; j++)
    {
        zeroCols[j] = true;
        for (int i = 0; i < rowCount; i++)
        {
            if (a[i][j] != 0)
            {
                zeroCols[j] = false;
                break;
            }
        }
    }

    int newRowCount = 0, newColCount = 0;
    for (int i = 0; i < rowCount; i++)
        if (!zeroRows[i]) newRowCount++;
    for (int j = 0; j < colCount; j++)
        if (!zeroCols[j]) newColCount++;

    int** newMatrix = new int* [newRowCount];
    for (int i = 0; i < newRowCount; i++)
        newMatrix[i] = new int[newColCount];

    int newRow = 0;
    for (int i = 0; i < rowCount; i++)
    {
        if (!zeroRows[i])
        {
            int newCol = 0;
            for (int j = 0; j < colCount; j++)
            {
                if (!zeroCols[j])
                {
                    newMatrix[newRow][newCol] = a[i][j];
                    newCol++;
                }
            }
            newRow++;
        }
    }

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    a = newMatrix;
    rowCount = newRowCount;
    colCount = newColCount;

    delete[] zeroRows;
    delete[] zeroCols;
}

int FindFirstPositiveRow(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] > 0)
                return i;
        }
    }
    return -1;
}
