#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent()
{
    fullTime = true;
    name = "unassigned";
    tuition_fees = 0;
    // library_fines is a private member of Student, so we need to use the
    // public method to set them in the derived class.
    SetLibraryFines(0);
}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees,
                                 bool fullTime)
{
    // use (*this) to refer to a given instance of the class. Then we can
    // differentiate between the class member "name" and the argument of the
    // constructor "name".
    (*this).name = name;
    (*this).fullTime = fullTime;
    // library_fines is a private member of Student, so we need to use the
    // public method to set them in the derived class.
    SetLibraryFines(fines);
    tuition_fees = fees;
}

double GraduateStudent::MoneyOwed() const
{
    // Graduate students don't pay tuition, so we only return the library
    // fines.
    return GetLibraryFines();
}

void GraduateStudent::print() const
{
    std::cout << "Graduate Student.\n"
              << "\nname: " << name
              << "\ntuition fees: " << tuition_fees
              << "\nlibrary fines: " << GetLibraryFines()
              << "\ntotal amount owed: " << MoneyOwed()
              << "\nfull time: " << fullTime
              << "\n\n";
}