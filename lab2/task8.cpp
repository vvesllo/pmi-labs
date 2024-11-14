#include <iostream>

int check_matrix(int** matrix, int n, int m, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
                count++;
            else if (matrix[i][j] == 1)
            {
                if (count >= k) return i+1;
                count = 0;
            }
        }
        if (count >= k) return i+1;
            count = 0;

    }

    return 0;
}

int main()
{
    int n, m, k;
    std::cin >> n >> m;

    int** matrix = new int*[n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
    }

    std::cin >> k;
    std::cout << check_matrix(matrix, n, m, k);

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}