#include "PhdStudent.hpp"

PhdStudent::PhdStudent(std::string name, double fines, double fees,
                       bool fullTime)
{
    // use (*this) to refer to a given instance of the class. Then we can
    // differentiate between the class member "name" and the argument of the
    // constructor "name".
    (*this).name = name;

    // library_fines is a private member of Student, so we need to use the
    // public method to set them in the derived class.
    SetLibraryFines(fines);
    tuition_fees = fees;
    (*this).fullTime = fullTime;
}

double PhdStudent::MoneyOwed() const
{
    // Phd students don't pay any library fees. Because they are a type of
    // graduate student, they also don't pay tuition. So they don't pay
    // anything.
    return 0;
}

void PhdStudent::print() const
{
    std::cout << "Phd Student.\n"
              << "\nname: " << name
              << "\ntuition fees: " << tuition_fees
              << "\nlibrary fines: " << GetLibraryFines()
              << "\ntotal amount owed: " << MoneyOwed()
              << "\nfull time: " << fullTime
              << "\n\n";
}