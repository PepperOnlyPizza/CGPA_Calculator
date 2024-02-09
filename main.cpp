#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct course
{
	string subject;
	string grade;
	int hours;
	double GPA;
};

void enterCourses(vector<course> courses)
{
	bool done = false;
	while (!done)
	{
		course index;
		string subject;
		string grade;
		cout << "Type the subject name (if you are done, type \"done\"): ";
		cin >> subject;
		if (subject == "done" || subject == "Done"){done = true;}
		else
		{
			index.subject = subject;
			cout << "How many credit hours did you take? ";
			cin >> index.hours;
			cout << "What was your letter grade? ";
			cin >> index.grade;
			index.GPA = getGPA(index.grade); // cpp.sh thinks getGPA is na undeclared identifier???
			courses.push_back(index);
		}
		cout << endl;
	}
}

double getGPA(string grade)
{
	double GPA = 0.0;
	if (grade == "a+" || grade == "A+")
		GPA = 4.0;
	else if (grade == "a" || grade == "A")
		GPA = 3.75;
	else if (grade == "a-" || grade == "A-")
		GPA = 3.5;
	else if (grade == "b+" || grade == "B+")
		GPA = 3.25;
	else if (grade == "b" || grade == "B")
		GPA = 3.0;
	else if (grade == "b-" || grade == "B-")
		GPA = 2.75;
	else if (grade == "c+" || grade == "C+")
		GPA = 2.5;
	else if (grade == "c" || grade == "C")
		GPA = 2.25;
	else if (grade == "d" || grade == "D")
		GPA = 2.0;
	return GPA;
}

double getCGPA(vector<course> courses)
{
	double result = 0.0;
	int totalHours = 0;
	for (course index : courses)
	{
		result += (index.GPA * index.hours);
		totalHours += index.hours;
	}
	result /= totalHours;
	
	return result;
}

void printCourseGPA(vector<course> courses)
{
	for (course index : courses)
	{
		cout << endl << index.subject << ": " << endl
			<< "Credits: " << index.hours << endl
			<< "Grade: " << index.grade << endl
			<< "GPA: " << index.GPA << endl << endl;
	}
}

int main()
{
	vector<course> courses;
	enterCourses(courses);
	printCourseGPA(courses);
	double CGPA = getCGPA(courses);
	cout << "Your total GPA for the semester is: " << CGPA;
	return 0;
}