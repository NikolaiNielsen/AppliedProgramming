#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cassert>
#include <cmath>
#include <vector>
#include <iostream>

template <class T>
class Vector
{
private:
	std::vector<T> mData; // data stored in vector

public:
    // copy constructor
    Vector(const Vector& otherVector)
    {
        mData.reserve(otherVector.size());
        for (int i = 0; i < otherVector.size(); i++)
        {
            mData.push_back(otherVector.mData[i]);
        }
    }

	Vector(int size)
    {
        assert(size > 0);

        mData.reserve(size);
        for (int i = 0; i < size; i++)
        {
            mData.push_back(0.0);
        }
    }

	int size() const
    {
        return mData.size();
    }

	T& operator[](int i)
    {
        assert(i >= 0 && i < mData.size());
        return mData[i];
    }

	T const& operator[] (int i)const
    {
        assert(i >= 0 && i < mData.size());
        return mData[i];
    }

	// assignment operator
	Vector& operator=(const Vector& otherVector)
    {
        assert(mData.size() == otherVector.size());

        for (int i = 0; i < mData.size(); i++)
        {
            mData[i] = otherVector.mData[i];
        }
        return *this;
    }

    // overloading the unary - operator
	Vector operator-() const
    {
        Vector v(mData.size());
        for (int i = 0; i < mData.size(); i++)
        {
            v[i] = -mData[i];
        }
        return v;
    }

    // overloading the binary + operator
	Vector operator+(const Vector& v1) const
    {
        assert(mData.size() == v1.size());

        Vector v(mData.size());
        for (int i = 0; i < mData.size(); i++)
        {
            v[i] = mData[i] + v1.mData[i];
        }
        return v;
    }

    // overloading the binary - operator
	Vector operator-(const Vector& v1) const
    {
        assert(mData.size() == v1.size());

        Vector v(mData.size());
        for (int i = 0; i < mData.size(); i++)
        {
            v[i] = mData[i] - v1.mData[i];
        }
        return v;
    }

	// scalar multiplication
	Vector operator*(double a) const
    {
        Vector v(mData.size());
        for (int i = 0; i < mData.size(); i++)
        {
            v[i] = a*mData[i];
        }
        return v;
    }

	// p-norm method
	double CalculateNorm(int p = 2) const
    {
        double sum = 0.0;
        for (int i = 0; i < mData.size(); i++)
        {
            sum += pow(std::abs(mData[i]), p);
        }
        return pow(sum, 1.0 / ((double)(p)));
    }

    // Print method
    void print() const
    {
        std::cout << "Length: " << mData.size() << ", data:\n";
        for (int i = 0; i < mData.size() - 1; i++)
        {
            std::cout << mData[i] << ", ";
        }
        std::cout << mData[mData.size() - 1] << "\n";
    }
};


#endif
