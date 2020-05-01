#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF

#include <string>
class Exception	{
	private:
		std::string mTag, mProblem;
	public:
		Exception(std::string tagString, std::string probString);
		void PrintDebug() const;
        void setProb(std::string prob);
        std::string getProb() const;
        void setTag(std::string tag);
        std::string getTag() const;
};

#endif //EXCEPTIONDEF
