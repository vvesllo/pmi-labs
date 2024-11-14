#include <iostream>
#include <cmath>

void fill_matrix(char** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == ceil(n/2) || j == ceil(n/2) || i == j || i == n-j-1) matrix[i][j] = '*';
        }
    }
}

void print_matrix(char** matrix, int n)
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
    char** matrix = new char*[n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new char[n];
        for (int j = 0; j < n; j++)
            matrix[i][j] = '.';
    }

    fill_matrix(matrix, n);
    print_matrix(matrix, n);
    
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}