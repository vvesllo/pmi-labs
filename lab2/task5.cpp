#include <iostream>

const char* check_matrix(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i]) return "NO";
        }
    }

    return "YES";
}

int main()
{
    int n;
    std::cin >> n;

    int** matrix = new int*[n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];
    }

    std::cout << check_matrix(matrix, n);
}