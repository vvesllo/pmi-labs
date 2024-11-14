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

void fill_spiral_matrix(int** matrix, int n, int m)
{
    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    int num = 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++)
            matrix[top][i] = num++;
        top++;

        for (int i = top; i <= bottom; i++)
            matrix[i][right] = num++;
        right--;


        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
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
            matrix[i][j] = 0;
    }

    fill_spiral_matrix(matrix, n, m);
    print_matrix(matrix, n, m);

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}