#include <iostream>
#include <iomanip>

void print_matrix(int** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << std::setw(4) << matrix[i][j];
        std::cout << '\n';
    }
}

void fill_matrix(int** matrix, int n, int m)
{
    int c = 0;
    int move_to = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            if ((i + j) % 2)
                matrix[i][j] = 0;
            else
                matrix[i][j] = ++c;
        }
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    int** matrix = new int*[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    fill_matrix(matrix, n, m);
    print_matrix(matrix, n, m);

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}