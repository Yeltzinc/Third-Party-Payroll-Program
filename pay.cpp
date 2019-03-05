//step 4
#include "person.cpp"
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
//step 5 including a vector
#include<vector>
using namespace std;
//step 7 read data that read from input.txt and stores into employees vector.
void readData(vector<Person>&employees)
{
    //varaibles from the employees using given code.
    string firstName;
    string lastName;
    int employeeID;
    string companyName;
    float hoursWorked;
    float payRate;
    //opens file input
    ifstream input;
    input.open("input.txt");
    
    //reading file and copying it into person for amount of employees inside of the input.txt file.
    while(input>>firstName>>lastName>>employeeID>>companyName>>hoursWorked>>payRate)
    {
        //declaring p to save info to
        Person p;
        //setting the variables into p
        p.setFirstName(firstName);
        p.setLastName(lastName);
        p.setEmployeeId(employeeID);
        p.setCompanyName(companyName);
        p.setHoursWorked(hoursWorked);
        p.setPayRate(payRate);
        //pushes back into vector
        employees.push_back(p);
    }
    //saves vector size
    for(int i=0;i<employees.size();i++)
    {
        cout<<employees.at(i).fullName()<<endl;
    }
    //closes file
    input.close();
}



int main()
{
//creating a vector for employees.
    vector<Person> employees;
//step 6 vector that holds companyNames
    vector<string>companyNames;
//step 7 read data that read from input.txt and stores into employees vector.
    readData(employees);
    return 0;
    
}

