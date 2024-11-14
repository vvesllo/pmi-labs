#include <iostream>


void find_max_in_matrix(int** matrix, int n, int m, int* out_x, int* out_y)
{
    int max_value = matrix[0][0];
    *out_x = 0;
    *out_y = 0;
    for (int i = 0; i < n; i++) // move by Y
    {
        for (int j = 0; j < m; j++) // move by X
        {
            if (max_value < matrix[i][j])
            {
                max_value = matrix[i][j];
                *out_x = j;
                *out_y = i;
            }
        }
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    int** matrix = new int*[n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
    }

    int x, y;

    find_max_in_matrix(matrix, n, m, &x, &y);
    
    // сначала строка, а потом столбец
    std::cout << y << ' ' << x;

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}