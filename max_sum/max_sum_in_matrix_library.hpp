#pragma once
#include <vector>
#include <initializer_list>
#include <utility>
#include <algorithm>



namespace mymatrix
{
    class Matrix
    {
    public:

        Matrix();
        Matrix(size_t rows);
        Matrix(size_t coloms, size_t rows);
        Matrix(const std::initializer_list<std::initializer_list<int>>& list);

        
        size_t getRows() const;
        size_t getColoms() const;
        std::vector<int>& operator[](size_t i);

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(const std::initializer_list<std::initializer_list<int>>& list);
        const int& getSum();

        int max_sum();

    private:
        using my_matrix = std::vector<std::vector<int>>;
        using my_pair = std::pair<int, std::pair<size_t, size_t>>;

        int temp_sum(my_matrix& temp_arr, size_t i, size_t j);

        
        std::vector<int> dx = { 1, 0 ,-1, 0 };
        std::vector<int> dy = { 0, 1, 0, -1 };
        
        size_t rows;
        size_t coloms;
        int sum;
        my_matrix two_dem_array;
    };
}