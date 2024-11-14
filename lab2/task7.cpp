#include <iostream>

int** matrix_transposition(int** matrix, int n, int m)
{
    int** matrix_T = new int*[m];
    for (int i = 0; i < m; i++)
    {
        matrix_T[i] = new int[n];
        for (int j = 0; j < n; j++)
            matrix_T[i][j] = matrix[j][i];
    }

    return matrix_T;
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
    int** matrix_T = matrix_transposition(matrix, n, m);
    print_matrix(matrix_T, m, n);

    for (int i = 0; i < n; i++) delete[] matrix[i];
    for (int i = 0; i < m; i++) delete[] matrix_T[i];
    delete[] matrix, matrix_T;
}