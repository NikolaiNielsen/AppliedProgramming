#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include "Vector.hpp"

template <class T>
class Matrix
{
private:
	std::vector<T> mData; // entries of matrix
	int mNumRows, mNumCols; // dimensions

public:
    // copy constructor
	Matrix(const Matrix& otherMatrix)
    {
        mNumRows = otherMatrix.mNumRows;
        mNumCols = otherMatrix.mNumCols;
        mData.reserve(mNumCols * mNumRows);

        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mData[getIndex(i, j)] = otherMatrix(i, j);
            }
        }
    }

	Matrix(int numRows, int numCols)
    {
        assert(numRows > 0);
        assert(numCols > 0);

        mNumRows = numRows;
        mNumCols = numCols;
        mData.reserve(mNumCols * mNumRows);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mData.push_back(0.0);
            }
        }
    }

	int GetNumberOfRows() const
    {
        return mNumRows;
    }

	int GetNumberOfColumns() const
    {
        return mNumCols;
    }

    int getIndex(int i, int j) const
    {
        // returns the row-major index for row i, column j:
        int rows = GetNumberOfRows();

        // We use zero-based indexing, so it's quite easy to implement
        int index = i * rows + j;

        return index;
    }

	T& operator()(int i, int j)
    {
        assert(i >= 0);
        assert(i < mNumRows);
        assert(j >= 0);
        assert(j < mNumCols);
        int index = getIndex(i, j);
        return mData[index];
    }

	T const& operator()(int i, int j) const
    {
        assert(i >= 0);
        assert(i < mNumRows);
        assert(j >= 0);
        assert(j < mNumCols);
        int index = getIndex(i, j);
        return mData[index];
    }

	// overloaded assignment operator
	Matrix& operator=(const Matrix& otherMatrix)
    {
        assert(mNumRows == otherMatrix.mNumRows);
        assert(mNumCols == otherMatrix.mNumCols);

        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mData[getIndex(i, j)] = otherMatrix(i, j);
            }
        }
        return *this;
    }

	Matrix operator-() const // unary -
    {
        Matrix mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = -mData[getIndex(i, j)];
            }
        }
        return mat;
    }

	Matrix operator+(const Matrix& m1) const // binary +
    {
        assert(mNumRows == m1.mNumRows);
        assert(mNumCols == m1.mNumCols);

        Matrix mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = mData[getIndex(i, j)] + m1(i, j);
            }
        }
        return mat;
    }

	Matrix operator-(const Matrix& m1) const // binary -
    {
        assert(mNumRows == m1.mNumRows);
        assert(mNumCols == m1.mNumCols);

        Matrix mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i, j) = mData[getIndex(i, j)] - m1(i, j);
            }
        }
        return mat;
    }

	// scalar multiplication
	Matrix operator*(double a) const
    {
        Matrix mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i, j) = a * mData[getIndex(i, j)];
            }
        }
        return mat;
    }

    // Print methodd
    void print() const
    {
        std::cout << "size: "
                  << "(" << mNumRows << "," << mNumCols << ")"
                  << ", data:\n";
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols - 1; j++)
            {
                std::cout << mData[getIndex(i, j)] << ", ";
            }
            std::cout << mData[getIndex(i, mNumCols - 1)] << "\n";
        }
    }
}; // class Matrix


//matrix-vector multiplications

// When creating template functions (ie, outside the main class definition,) we
// need to add a template of type T. And also, of course, specify the type we
// use in the functions.
template <typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
    int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);

	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += m(i, j) * v[j];
		}
	}

	return new_vector;
}

template <typename T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);

	int new_vector_length = m.GetNumberOfColumns();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += v[j] * m(j, i);
		}
	}

	return new_vector;
}


#endif
