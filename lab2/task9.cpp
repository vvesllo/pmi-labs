#include <iostream>

int** matrix_rotation(int** matrix, int n, int m)
{
    int** matrix_R = new int*[m];
    for (int i = 0; i < m; i++)
    {
        matrix_R[i] = new int[n];
        for (int j = 0; j < n; j++)
            matrix_R[i][j] = matrix[n - 1 - j][i]; 
            // matrix[n - 1 - j][i] == +90deg
            // matrix[j][m - 1 - i] == -90deg
    }

    return matrix_R;
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
    int** matrix_rotated = matrix_rotation(matrix, n, m);
    print_matrix(matrix_rotated, m, n);

    for (int i = 0; i < n; i++) delete[] matrix[i];
    for (int i = 0; i < m; i++) delete[] matrix_rotated[i];
    delete[] matrix, matrix_rotated;
}