// TODO
// - look up pointer arithmetic
// - implement check in setValue for whether value already exists
// - Make sure to place value and index in correct location - and not just at
//   the back.
// - add test for setValues (set new value and check it's in the right place.
//   Set old value, check it updates)
// - Implement addition and subtraction (run through second vector and add
//   elements to values if they're not present in first vector; add/subtract
//   values if indices is present in both vectors)
// - Look up documentation for std::vector (look for find methods)

#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP

#include "Vector.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <algorithm>

template<class T> class SparseVector{
private:
	std::vector<unsigned int> mIndices;
    std::vector<T> mValues;
    unsigned int mDimension;

public:
	//creates an empty vector of dimensionality 0.
	SparseVector()
    {
        mDimension = 0;
    }
	// Creates a vector of dimensionality dim. It starts with 0 nonzero elements
	// which need to be set using setValue
	SparseVector(unsigned int dim)
    {
        mDimension = dim;
    }

	// assignment operators and copy constructor should be automatically
	// generated by the compiler when using a std::vector for internal storing.
	// However, test that assignment works!

	// sets the value v_i of the vector. if it does not exist it is added
	void setValue(unsigned int index, T value)
    {
        // std::vector<T>::iterator lower;
        mIndices.push_back(index);
        mValues.push_back(value);
    }

	// returns the value v_i of the vector. Returns 0 if the value is not
    // stored
	T getValue(unsigned int index) const
    {

        // std::vector<unsigned int>::iterator lower;
        auto lower = std::lower_bound(mIndices.begin(), mIndices.end(), index);
        auto position = lower - mIndices.begin();
        std::cout << "Index " << index << " has position " << position << "\n";

        if ((unsigned int)(position) == nonZeroes())
        {
            return (T)(0);
        }
        else if ((unsigned int)(position) == 0)
        {
            return (T)(0);
        }
        else
        {
            return mValues[position];
        }
        
            

        // // Make sure we're trying to reach an actual element. We don't need the
        // // <0 check, since we're using unsigned integers.
        // assert (index < mDimension);
        // // If there are no indices, return 0 immediately (to avoid an infinite
        // // for loop)
        // if (nonZeroes() == 0)
        // {
        //     // Problem with 0 maybe not being of class T? Let's cast it
        //     return (T)(0);
        // }
        // // run through indices to check if index is non-zero
        // for (int i=0; i<nonZeroes(); i++)
        // {
        //     if (index == mIndices[i])
        //     {
        //         return mValues[i];
        //     }
        // }
        // // if we didn't return anything yet, the value is not non-zero.
        // return (T)(0);
    }

	// returns the dimensionality of the vector
	unsigned int size() const
    {
        return mDimension;
    }

	// returns the number stored elements
	unsigned int nonZeroes() const
    {
        return mIndices.size();
    }
	// returns the index of the ith stored nonzero entry (in increasing order)
	unsigned int indexNonZero(unsigned int i) const
    {
        assert(i < nonZeroes());
        return mIndices[i];
    }
	// returns the value of the ith stored nonzero entry (in increasing order)
	T valueNonZero(unsigned int i) const
    {
        assert(i < nonZeroes());
        return mValues[i];
    }

	// adds x to the current vector
	SparseVector<T>& operator+= (SparseVector<T> const& x);
	// subtracts x from the current vector
	SparseVector<T>& operator-= (SparseVector<T> const& x);

    // printer
    void print() const
    {
        std::cout << "size: " << size() << "\nNumber of non-zero elements: "
                  << nonZeroes() << "\n";
        if (nonZeroes() > 0)
        {
            std::cout << "index, values of non zeros:\n";
            for (unsigned int i = 0; i < nonZeroes(); i++)
            {
                std::cout << indexNonZero(i) << ", " << valueNonZero(i) 
                          << "\n";
            }
        }
    }
};


// computes z= x+y, equivalent to z=x, z+=y
template<class T>
SparseVector<T> operator+(SparseVector<T> const& x, SparseVector<T> const& y);

// computes z= x-y, equivalent to z=x, z-=y
template<class T>
SparseVector<T> operator-(SparseVector<T> const& x, SparseVector<T> const& y);


// computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
template<class T>
Vector<T> operator* (Matrix<T> const& A, SparseVector<T> const& x);

// computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
template<class T>
Vector<T> operator* (SparseVector<T> const& x, Matrix<T> const& A);


#endif
