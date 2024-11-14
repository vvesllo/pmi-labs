#include <iostream>


void swap_maxtrix_columns(int** matrix, int n, int a, int b)
{
    for (int i = 0; i < n; i++)
    {
        int _temp = matrix[i][a];
        matrix[i][a] = matrix[i][b];
        matrix[i][b] = _temp;
    }
}

void print_matrix(int** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
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

    int i, j;
    std::cin >> i >> j;

    swap_maxtrix_columns(matrix, n, i, j);
    print_matrix(matrix, n, m);
    
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}