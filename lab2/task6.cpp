#include <iostream>
#include <cmath>

void print_matrix_diagonal_offset(int** matrix, int n, int k)
{
    for (int i = 0; i < n-abs(k); i++)
    {
        std::cout << matrix[i+abs(std::max(0, k))][i+abs(std::min(0, k))] << ' ';
    }
}

int main()
{
    int n, k;
    std::cin >> n;

    int** matrix = new int*[n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];
    }
    std::cin >> k;

    print_matrix_diagonal_offset(matrix, n, k);
}