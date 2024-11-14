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
    int c = 1;
    int x = 0, y = 0;

    for (int i = 0; i < m; ++i)
    {
        x = 0;
        y = i;
        
        while (y >= 0 && x < n)
        {
            matrix[x][y] = c++;
            x++;
            y--;
        }
    }

    for (int j = 1; j < n; ++j)
    {
        x = j;
        y = m - 1;

        while (x < n && y >= 0)
        {
            matrix[x][y] = c++;
            x++;
            y--;
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