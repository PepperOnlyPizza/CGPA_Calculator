#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std



struct course
{
	string class;
	string grade;
	int hours;
	double GPA;
};

double calcGPA (string grade)
{
	double GPA = 0;
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
		GPA = 2;
	else if (grade == "f" || grade == "F")
		GPA = 0;
	return GPA;
}

double calcGPA(vector<course> courses)
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

int main()
{
	vector<course> courses;
	int totalClasses = 0;
	bool done = false;
	
	while (!done)
	{
		string class;
		string grade;
		cout << "Type the subject name (if you are done, type \"done\": ";
		cin >> class;
		if (class == "done" || class == "Done"){done = true;}
		else
		{
			course index = new course;
			index.class = class;
			cout << endl << "How many credit hours did you take? ";
			cin >> index.hours;
			cout << endl << "What was your letter grade? ";
			cin >> index.grade;
			index.GPA = getGPA(index.grade);
			courses.push_back(index);
		}
	}
	
	CGPA = calcGPA(courses);
	
	for (course index : courses)
	{
		//
	}
	
	
	return 0;
}