#include "max_sum_in_matrix_library.hpp"

mymatrix::Matrix::Matrix() : sum(0), rows(0), coloms(0), two_dem_array(0) {}

mymatrix::Matrix::Matrix(size_t rows) : rows(rows), coloms(0), sum(0), two_dem_array(rows) {}

mymatrix::Matrix::Matrix(size_t coloms, size_t rows) : Matrix(rows)
{
    this->coloms = coloms;

    for (auto& element : two_dem_array)
    {
        element = std::vector<int>(coloms);
    }
}

mymatrix::Matrix::Matrix(const std::initializer_list<std::initializer_list<int>>& list) : Matrix(list.size() + 2)
{
    coloms = list.begin()->size() + 2;
    two_dem_array[0] = std::vector<int> (coloms);
    two_dem_array[rows - 1] = std::vector<int>(coloms);


    int cnt = 1;

    for (auto& element : list)
    {
        two_dem_array[cnt] = element;
        
        two_dem_array[cnt].push_back(0);
        two_dem_array[cnt].insert(two_dem_array[cnt].begin(), 0);
        cnt++;
    }


}

size_t mymatrix::Matrix::getRows() const { return rows; }

size_t mymatrix::Matrix::getColoms() const { return coloms; }

std::vector<int>& mymatrix::Matrix::operator[](size_t i) { return two_dem_array[i]; }

mymatrix::Matrix& mymatrix::Matrix::operator=(const mymatrix::Matrix& other)
{
    if (&other != this)
    {
        rows = other.rows;
        coloms = other.coloms;
        two_dem_array = other.two_dem_array;
        sum = 0;
    }

    return *this;
}

mymatrix::Matrix& mymatrix::Matrix::operator=(const std::initializer_list<std::initializer_list<int>>& list)
{
    if (list.size() + 2 != rows)
    {
        rows = list.size() + 2;
        two_dem_array = my_matrix(rows);
    }

    sum = 0;
    coloms = list.begin()->size() + 2;

    two_dem_array[0] = std::vector<int>(coloms);
    two_dem_array[rows - 1] = std::vector<int>(coloms);

    int cnt = 1;

    for (auto& element : list)
    {
        two_dem_array[cnt] = element;

        two_dem_array[cnt].push_back(0);
        two_dem_array[cnt].insert(two_dem_array[cnt].begin(), 0);
        cnt++;
    }

    return *this;
}

int mymatrix::Matrix::temp_sum(my_matrix& temp_arr, size_t i, size_t j)
{
    int t_sum = temp_arr[i][j];
    std::vector<my_pair> t(4);
    
    temp_arr[i][j] = 0;
    
    for(size_t k = 0; k != 4; ++k)
    {
        t[k] = { temp_arr[i + dy[k]][j + dx[k]] , {i + dy[k] , j + dx[k]} };
    }

    auto max_el = std::max_element(t.begin(), t.end());

    if (max_el->first == 0)
        return t_sum;
    
    return  t_sum + temp_sum(temp_arr, max_el->second.first, max_el->second.second);
}

int mymatrix::Matrix::max_sum()
{
    
    int sum_interm = 0;
    
    for (size_t i = 0; i != rows; ++i)
    {
        for (size_t j = 0; j != coloms; ++j)
        {
            if (two_dem_array[i][j] != 0)
            {
                my_matrix temp_array = two_dem_array;
                sum_interm = temp_sum(temp_array, i, j);

                if (sum_interm > sum)
                    this->sum = sum_interm;
            }
        }
    }
   
    return sum;
}

const int& mymatrix::Matrix::getSum() {return sum;}