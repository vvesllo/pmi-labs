#include <iostream>

void fill_matrix(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            matrix[i][j] = abs(i - j);
    }
}

void print_matrix(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
}

int main()
{
    int n;
    std::cin >> n;

    int** matrix = new int*[n];

    
    fill_matrix(matrix, n);
    print_matrix(matrix, n);
}