#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

void print_matrix(std::vector<std::vector<int>> matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << std::setw(4) << matrix[i][j];
        std::cout << '\n';
    }
}

void M1(std::vector<std::vector<int>> data, int n, int m)
{
    int max_x = -1;
    int max_y = -1;

    int count = 0;
    int max_count = 0;
        
    for (int i=0; i < n; i++)
    {
        count = 0;
        for (int j=0; j < m; j++) 
            count += data[i][j];

        if (std::max(count, max_count) == count)
        {
            max_count = count;
            max_y = i;
        }
    }
    for (int j=0; j < m; j++)
    {
        count = 0;
        for (int i=0; i < n; i++)
            count += data[i][j];

        if (std::max(count, max_count) == count)
        {
            max_count = count;
            max_x = j;
        }
    }

    for (int i = 0; i < n; i++)
        data[i][max_x] += 100;

    for (int i = 0; i < m; i++)
    {
        if (i != max_x) data[max_y][i] += 100;
    }
    

    std::cout <<  "max column: " << max_x+1 << '\n';
    std::cout << "max rows: " << max_y+1 << '\n';
    
    print_matrix(data, n, m);
}

void M2(std::vector<std::vector<int>> data, int n, int m)
{
    float max_length = 0;
    float length = 0;
    int dot_i1=0;
    int dot_j1=0;
    int dot_i2=0;
    int dot_j2=0;

    for (int i1=0; i1 < n; i1++)
    {
        for (int j1=0; j1 < m; j1++)
        {
            if (data[i1][j1] == 0) continue;
            
            for (int i2=i1; i2 < n; i2++)
            {
                for (int j2=j1; j2 < m; j2++)
                {
                    if (data[i2][j2] == 0) continue;
                    
                    length = std::sqrt(std::pow(i2 - i1, 2) + std::pow(j2 - j1, 2));

                    if (std::max(length, max_length) == length)
                    {
                        dot_i1 = i1;
                        dot_j1 = j1;

                        dot_i2 = i2;
                        dot_j2 = j2;

                        max_length = length;
                    }
                    length = 0;
                }
            }
            
        }
    }
    
    data[dot_i1][dot_j1] *= 5;
    data[dot_i2][dot_j2] *= 5;

    std::cout << "max length: " << max_length << '\n';

    print_matrix(data, n, m);
}

void M3(std::vector<std::vector<int>> data, int n, int m)
{   
    int max_area = 0;
    int area = 0;
    int left = 0, right = 0, up = 0, down = 0;
    int width = 0;
    bool is_rect = true;

    for (int top = 0; top < n; top++)
    {
        for (int bottom = top; bottom < n; bottom++)
        {
            width = 0;
            for (int col = 0; col < m; col++)
            {
                is_rect = true;

                for (int row = top; row <= bottom; row++)
                {
                    if (data[row][col] != 1)
                    {
                        is_rect = false;
                        break;
                    }
                }
                
                if (is_rect)
                {
                    area = ++width * (bottom - top + 1);
                    if (area > max_area)
                    {
                        max_area = area;
                        left = col - width + 1;
                        right = col;
                        up = top;
                        down = bottom;
                    }
                } 
                else width = 0;
            }
        }
    }

    std::cout << "rect: (x=" << left << ", y=" << up << ", w=" << right << ", h=" << down << ")\n";
    std::cout << "area: " << max_area << '\n';
}

void M4(std::vector<std::vector<int>> data, int n, int m)
{    
    float min_length = n * m;

    for (int i1=0; i1 < n; i1++)
    {
        for (int j1=0; j1 < m; j1++)
        {
            if (data[i1][j1] == 0) continue;
            
            for (int i2=i1; i2 < n; i2++)
            {
                for (int j2=j1; j2 < m; j2++)
                {
                    if (data[i2][j2] == 0 || (i1 == i2 && j1 == j2)) continue;
                    
                    min_length = std::min(min_length, (float)std::sqrt(std::pow(i2 - i1, 2) + std::pow(j2 - j1, 2)));
                }
            }
            
        }
    }

    std::cout << "min length: " << min_length << '\n';
    print_matrix(data, n, m);
}

void M5(std::vector<std::vector<int>> data, int n, int m)
{
}

int main()
{
    std::ifstream f("data.txt");
    int n, m;
    f >> n >> m;

    std::vector<std::vector<int>> data(n, std::vector<int>(m));
    std::string line;
    
    for (int i=0; i < n; i++)
    {
        f >> line;
        for (int j=0; j < m; j++)
            data[i][j] = line[j] - '0';
    }
    f.close();

    M1(data, n, m);
    M2(data, n, m);
    M3(data, n, m);
    M4(data, n, m);
    // M5(data, n, m);

}