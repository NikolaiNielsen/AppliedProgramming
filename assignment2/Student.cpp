#include "Student.hpp"
#include <cassert>

void Student::SetLibraryFines(double amount)
{
    // We cannot have a negative fine - the library doesn't owe you money.
    assert (amount>=0);
    library_fines = amount;
}

double Student::GetLibraryFines() const
{
    return library_fines;
}

Student::Student()
{
    tuition_fees = 0;
    library_fines = 0;
    name = "unassigned";
}

Student::Student(std::string name, double fines, double fees)
{
    // use (*this) to refer to a given instance of the class. Then we can
    // differentiate between the class member "name" and the argument of the
    // constructor "name".
    (*this).name = name;
    tuition_fees = fees;
    library_fines = fines;
}

double Student::MoneyOwed() const
{
    return tuition_fees + library_fines;
}

void Student::print() const
{
    std::cout << "Student."
              << "\nname: " << name
              << "\ntuition fees: " << tuition_fees
              << "\nlibrary fines: " << library_fines
              << "\ntotal amount owed: " << MoneyOwed()
              << "\n\n";
}