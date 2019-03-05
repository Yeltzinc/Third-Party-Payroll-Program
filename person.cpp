#include "person.hpp"
Person::Person()
{
//default constructor
}
//setters
void Person::setFirstName(string first)
{
    //using given variables
    firstName=first;
}
void Person::setLastName(string last)
{
    lastName=last;
}
void Person::setEmployeeId(int id)
{
    employeeID=id;
}
void Person::setCompanyName(string coName)
{
    companyName=coName;
}
void Person::setPayRate(float prate)
{
    payRate=prate;
}
void Person::setHoursWorked(float hours)
{
    hoursWorked=hours;
}
//getters
string Person::getFirstName()
{
    return firstName;
}
string Person::getLastName()
{
    return lastName;
}
int Person::getEmployeeId()
{
    return employeeID;
}
string Person::getCompanyName()
{
    return companyName;
}
float Person::getPayRate()
{
    return payRate;
}
float Person::getHoursWorked()
{
    return hoursWorked;
}
//arithmitic functions
float Person::totalPay()
{
    return hoursWorked*payRate;
}
string Person::fullName()
{
    return firstName+" "+lastName;
}
