#include "BooleanMatrix.hpp"
#include "Matrix.hpp"

BooleanMatrix::BooleanMatrix(const BooleanMatrix& other):Matrix(other){}

BooleanMatrix::BooleanMatrix(int r, int c):Matrix(r, c){}

bool BooleanMatrix::replace(matrix_element_type e, int r, int c)
{
    if(r > row || c > columns)
        return false;
    matrix[ELEMENT_POS(r, c)] = e;
    return true;
}

BooleanMatrix BooleanMatrix::operator&(const BooleanMatrix& other)
{
    BooleanMatrix result(row, columns);
    for(int i = 0; i < row * columns; i++)
        result.Matrix::matrix[i] = Matrix::matrix[i] & other.Matrix::matrix[i];
    return result;
}

BooleanMatrix BooleanMatrix::operator|(const BooleanMatrix& other)
{
    BooleanMatrix result(row, columns);
    for(int i = 0; i < row * columns; i++)
        result.Matrix::matrix[i] = matrix[i] | other.Matrix::matrix[i];
    return result;
}

BooleanMatrix BooleanMatrix::BooleanProduct(const BooleanMatrix& other) const
{
    BooleanMatrix result(row, other.columns);
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= other.columns; j++)
        {
            result.Matrix::matrix[(i - 1) * other.columns + j - 1] = false;
            for(int k = 1; k <= other.row; k++)
            {
                result.Matrix::matrix[(i - 1) * other.columns + j - 1] = 
                result.Matrix::matrix[(i - 1) * other.columns + j - 1] |
                matrix[(i - 1) * columns + k - 1] & 
                other.Matrix::matrix[(k - 1) * other.columns + j - 1];
                
            }
        }
    }
    return result;
}


