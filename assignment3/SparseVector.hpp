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
        // Make sure we're trying to reach an actual element. We don't need the
        // <0 check, since we're using unsigned integers.
        assert(index < mDimension);

        // Get the lower bound for the index.
        auto lower = std::lower_bound(mIndices.begin(), mIndices.end(), index);
        // The actual position is the lower bound minus the starting position
        // memory.
        auto position = lower - mIndices.begin();

        // We are guaranteed that we try to set a valid element.
        // Now there are two possibilities - either the element is already set
        // or it is not. 

        // First, if the position is equal to the number of non-zero values, we
        // are safe to put the index and value in the back of the pile (since
        // this means that the index is not stored in the vector yet)
        if (position == nonZeroes())
        {
            mValues.push_back(value);
            mIndices.push_back(index);
        }
        // Next, if 0 <= position < nonZeros() we have two possible cases.
        // 1) The mIndices[position] matches the index, and we already have a
        //    non-zero value stored for this index - so go ahead and change it.
        // 2) the index does not match the position - then we have no non-zero
        //    value stored for this index. Go ahead and insert it at that
        //    position.
        else if (mIndices[position] == index)
        {
            // case 1
            mValues[position] = value;
        }
        else
        {
            // case 2

            // Insert needs iterators, not integers. So create these
            auto val_pos = mValues.begin() + position;
            auto ind_pos = mIndices.begin() + position;
            mValues.insert(val_pos, value);
            mIndices.insert(ind_pos, index);
        }
        

        
    }

	// returns the value v_i of the vector. Returns 0 if the value is not
    // stored
	T getValue(unsigned int index) const
    {
        // Make sure we're trying to reach an actual element. We don't need the
        // <0 check, since we're using unsigned integers.
        assert(index < mDimension);

        // Get the lower bound for the index.
        auto lower = std::lower_bound(mIndices.begin(), mIndices.end(), index);
        // The actual position is the lower bound minus the starting position
        // memory.
        auto position = lower - mIndices.begin();
        // std::cout << "Index " << index << " value " << position << "\n";

        // If there are no indices stored, we return 0.
        if (nonZeroes() == 0)
        {
            return (T)(0);
        }
        // If the index is the same as the value of mIndices stored at
        // position, then it's safe to return the value at position.
        if (mIndices[position] == index)
        {
            return mValues[position];
        }
        // If something else happened, not caught in the two if statements, we
        // just return 0 as well (ie, if the index didn't match the stored
        // value in mIndices).
        return (T)(0);
        
        
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
	SparseVector<T>& operator+= (SparseVector<T> const& x)
    {
        // For each non-zero element in x we set the corresponding value in
        // this to the current value plus the value in x:
        // z_i = z_i + x_i
        int num_non_zeros = x.nonZeroes();
        for (int i=0; i<num_non_zeros; i++)
        {
            int index = x.indexNonZero(i);
            setValue(index, getValue(index)+x.valueNonZero(i));
        }
        return *this;
    }
	// subtracts x from the current vector
	SparseVector<T>& operator-= (SparseVector<T> const& x)
    {
        // For each non-zero element in x we set the corresponding value in
        // this to the current value minus the value in x:
        // z_i = z_i - x_i
        int num_non_zeros = x.nonZeroes();
        for (int i = 0; i < num_non_zeros; i++)
        {
            int index = x.indexNonZero(i);
            setValue(index, getValue(index) - x.valueNonZero(i));
        }
        return *this;
    }

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
SparseVector<T> operator+(SparseVector<T> const& x, SparseVector<T> const& y)
{
    SparseVector<T> z(x);
    return z+=y;
}

// computes z= x-y, equivalent to z=x, z-=y
template<class T>
SparseVector<T> operator-(SparseVector<T> const& x, SparseVector<T> const& y)
{
    SparseVector<T> z(x);
    return z-=y;
}


// computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
template<class T>
Vector<T> operator* (Matrix<T> const& A, SparseVector<T> const& x)
{
    // Create a dense vector v, identical to x.
    Vector<T> v(x.size());
    for (int i=0; i<x.nonZeroes(); i++)
    {
        v[x.indexNonZero(i)] = x.valueNonZero(i);
    }

    return A*v;
}

// computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
template<class T>
Vector<T> operator* (SparseVector<T> const& x, Matrix<T> const& A)
{
    // Create a dense vector v, identical to x.
    Vector<T> v(x.size());
    for (int i = 0; i < x.nonZeroes(); i++)
    {
        v[x.indexNonZero(i)] = x.valueNonZero(i);
    }
    return v*A;
}

#endif
