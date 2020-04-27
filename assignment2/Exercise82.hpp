#ifndef SUBMISSION_EXERCISE82_HPP_
#define SUBMISSION_EXERCISE82_HPP_

template<typename T>
T CalcAbs(T val) {
	T res = val;
    if (val < 0)
    {
        res = -res;
    }
    return res;
}


#endif /* SUBMISSION_EXERCISE82_HPP_ */
