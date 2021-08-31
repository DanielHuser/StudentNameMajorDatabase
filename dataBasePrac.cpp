#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UniStudent
{
    public:
        string fullName;
        string major;
};

void PrintStudentInformation(UniStudent Person)
{
    cout << "Full Name: " << Person.fullName << "\n";
    cout << "Major: " << Person.major << "\n\n";
}

void PrintAllStudents(vector<UniStudent> StudentList)
{
    for (int i = 0; i < StudentList.size(); i++)
    {
        cout << "Student #" << i+1 << ":\n";
        PrintStudentInformation(StudentList.at(i));
    }

}

void SearchStudentMajor(string userMajor, vector<UniStudent> studentList)
{
    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList.at(i).major.find(userMajor) != string::npos)
        {
            PrintStudentInformation(studentList.at(i));
        }
    }
}

void SearchStudentName(string userName, vector<UniStudent> studentList)
{
    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList.at(i).fullName.find(userName) != string::npos)
        {
            PrintStudentInformation(studentList.at(i));
        }
    }
}

void ListAllMajors(vector<UniStudent> studentList)
{
    vector<string> majorList;
    for (int i = 0; i < studentList.size(); i++)
    {
        majorList.push_back(studentList.at(i).major);
            //Adds all of the majors from the class list;
    }

    for (int j = 0; j < majorList.size(); j++)
    {
        for (int k = j+1; k < majorList.size(); k++)
        {
            if (majorList.at(j) == majorList.at(k))
            {
                majorList.erase(majorList.begin() + k);
            }
        }
    }

    for (int l = 0; l < majorList.size(); l++)
    {
        cout << majorList.at(l) << "\n";
    }
}

int main ()
{
    vector<UniStudent> ClassList;

        UniStudent Chris;
            Chris.fullName = "Chris Redfield";
            Chris.major = "Computer Engineering";
            ClassList.push_back(Chris);

        UniStudent Meg;
            Meg.fullName = "Meg Griffin";
            Meg.major = "Music Theory";
            ClassList.push_back(Meg);

        UniStudent Charles;
            Charles.fullName = "Charles Smith";
            Charles.major = "Business";
            ClassList.push_back(Charles);

        UniStudent Kathy;
            Kathy.fullName = "Kathy Gordon";
            Kathy.major = "Computer Engineering";
            ClassList.push_back(Kathy);

        //PrintAllStudents(ClassList);
        //SearchStudentMajor("Engineering", ClassList);
        //SearchStudentName("Griffin", ClassList);
        ListAllMajors(ClassList);

        return 0;
}