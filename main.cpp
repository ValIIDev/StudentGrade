//
//Program excecution begins and ends here
//Credentials are name: VVK ; Pass: VVK ;
//Currently the program omits naughty strings such as:
// Peter
// 10 Peter
// 12 peter
// .. $# 23
// 5
// IT
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    string name;
    int mark;
};

int main()
{
    // Prompt the user to enter their username and password
    cout << "Enter your username: ";
    string username;
    getline(cin, username);
    cout << "Enter your password: ";
    string password;
    getline(cin, password);

    // Check the login
    if (username == "VVK" && password == "VVK")
    {
        cout << "Login successful!" << endl;

  cout << "=======================================" << endl;
    // Open the file "data.txt" for reading
    ifstream input("data.txt");

// Read the data from the file into a vector of Student objects
vector<Student> students;
string line;
while (getline(input, line))
{
    // Use a stringstream to extract the name and mark from the line
    stringstream ss(line);
    string name;
    int mark;
    if (ss >> name >> mark)
    {

        {
            students.push_back({ name, mark });
        }
    }
}

    // Check if the vector is empty
    if (students.empty())
    {
        cout << "~~~~No data found in the file.~~~" << endl;
        return 0;
    }

    // Calculate the average mark
    double total = 0;
    for (const auto& student : students)
    {
        total += student.mark;
    }
    double average = total / students.size();
    cout << "= Average mark: " << average << endl;

    // Find the worst result
    int worstResult = students[0].mark;
    for (const auto& student : students)
    {
        worstResult = min(worstResult, student.mark);
    }
    cout << "= Worst result: " << worstResult << endl;

    // Find the best result
    int bestResult = students[0].mark;
    for (const auto& student : students)
    {
        bestResult = max(bestResult, student.mark);
    }
    cout << "= Best result: " << bestResult << endl;
cout << "=======================================" << endl;
    // Find all results better than average
    cout << "Results better than average:" << endl;
    for (const auto& student : students)
    {
        if (student.mark > average)
        {
            cout << "" << endl;
            cout << student.name << " " << student.mark << endl;
          
        }
    }

    // Find all subjects with more than 8
cout << "=======================================" << endl;
    cout << "Subjects with more than 8:" << endl;
    for (const auto& student : students)
    {
        if (student.mark > 8)
        {
            cout << "" << endl;
            cout << student.name << endl;
        }
      
    }
cout << "=======================================" << endl;
    }
    else
    {
        cout << "Invalid username or password." << endl;
    }

    return 0;
}