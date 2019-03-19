//step 4
#include "person.cpp"
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
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
//step 8 getCompanies that passes both vectors by reference.
void getCompanies(vector<Person>&employees,vector<string>&companyNames)
{
    //gains the company size to start the loop
    for(int i=0;i<employees.size();i++)
    {
        int count=0;
        //if loop reaches the end of names then loop will activate and push the company name
        if(companyNames.empty())
        {
            //pushes back the company names to the last index
            companyNames.push_back(employees.at(i).getCompanyName());
        }
        for (int x=0;x<companyNames.size();x++)
        {
            if(employees.at(i).getCompanyName()==companyNames.at(x))
            {
                count++;
            }
        }
        if(count==0)
        {
            companyNames.push_back(employees.at(i).getCompanyName());
        }
    }
}
//step 9 total pay of the person who was paid the highest amount this statement.
void printHighestPaid(vector<Person>&employees)
{
    int index;
    float high=0.0;
    int i=0;
    //gets the size of the loop from the size of employees
    while(i<employees.size())
    {
        //compares the total pay of the first employee by comparing it to float value high.
        if(high<employees.at(i).totalPay())
        {
            //makes high equal to the first employee and then compares the first employee with the rest.
            high=employees.at(i).totalPay();
            //saves the index to index.
            index=i;
        }
        //increment
        i++;
    }
    //uses the index to output the information about the highest paid employee
    cout << "Highest Paid: " << employees.at(index).fullName() << endl;
    cout << "Employee ID: " << employees.at(index).getEmployeeId() << endl;
    cout << "Employer: " << employees.at(index).getCompanyName() << endl;
    cout << "Total Pay: $" <<  employees.at(index).totalPay() << endl;
}


int main()
{
//creating a vector for employees.
    vector<Person> employees;
//step 6 vector that holds companyNames
    vector<string>companyNames;
//step 7 read data that read from input.txt and stores into employees vector.
    readData(employees);
    //step 8 getCompanies that passes both vectors by reference.
    getCompanies(employees,companyNames);
    //step 9
    printHighestPaid(employees);
    return 0;
    
}

