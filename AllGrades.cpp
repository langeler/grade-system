#include "AllGrades.h"

AllGrades::AllGrades(string data_dir)
{
	// Set the grade file
	_data_dir = data_dir;

	// Create the filenames for the data files
	string gradeFile = _data_dir + "/grade.txt";

	// A string to hold the lines we read from the grade file
	string line;

	// Open the grades file
	ifstream grade_file(gradeFile.c_str());
	vector<pair<int, string> > data;
	pair<int, string> name;

	// Read the grade file
	if (grade_file.is_open())
	{
		while (getline(grade_file, line))
		{
			// Create a new Grade object
			Grade new_grade;

			// We split up each line, and load it into a Grade object
			size_t pos = 0;
			string token;

			// We need to track the order so we put them in the right place
			// in the Grade object
			int loc = 0;
			while (((pos = line.find("|")) != string::npos))
			{
		    	token = line.substr(0, pos);
		    	line.erase(0, pos + 1);
		    	switch (loc)
		    	{
		    		case 0:
		    			new_grade.ID(atoi(token.c_str()));
		    			break;
		    		case 1:
		    			new_grade.CourseID(atoi(token.c_str()));
		    			data = GetCourseName(new_grade.CourseID());
		    			new_grade.CourseName(data[1].second);
		    			new_grade.SubjectID(data[0].first);
		    			new_grade.SubjectName(data[0].second);
		    			break;
		    		case 2:
		    			new_grade.TheGrade(atoi(token.c_str()));
		    			break;
		    		case 3:
		    			new_grade.StudentID(atoi(token.c_str()));
		    			name = GetName(new_grade.StudentID(), "/people.txt");
		    			new_grade.StudentName(name.second);
		    			break;
		    		case 4:
		    			new_grade.CoursePermID(atoi(token.c_str()));
		    			name = GetTeacherName(new_grade.CoursePermID());
		    			new_grade.TeacherID(name.first);
		    			new_grade.TeacherName(name.second);
		    			break;
		    	}
		    	loc++;
			}
			_grades.push_back(new_grade);
		}
		grade_file.close();
	}
	else cout << "Unable to open the grade file!\n";
}

AllGrades::~AllGrades()
{
}

vector<pair<int, string> > AllGrades::GetCourseName(int cid)
{
	string courseFile = _data_dir + "/course.txt";

	// Open the course file
	string line;
	ifstream course_file(courseFile.c_str());
	bool get_it = false;
	vector<pair<int, string> > data;
	pair<int, string> ret;

	if (course_file.is_open())
	{
		while (getline(course_file, line))
		{
			size_t pos = 0;
			string token;

			int loc = 0;
			while (((pos = line.find("|")) != string::npos))
			{
		    	token = line.substr(0, pos);
		    	line.erase(0, pos + 1);
		    	switch (loc)
		    	{
		    		case 0:
		    			if (atoi(token.c_str()) == cid) get_it = true;
		    			break;
		    		case 1:
		    			if (get_it)	data.push_back(GetName(atoi(token.c_str()), "/subject.txt"));
		    			break;
		    		case 2:
		    			if (get_it)
		    			{
		    				ret = make_pair(-1, token);
		    				data.push_back(ret);
		    			}
		    			break;
		    	}
		    	if (get_it && data.size() == 2) return data;

		    	loc++;
		    }
		}
	}
}

pair<int, string> AllGrades::GetName(int sid, string fname)
{
	string filename = _data_dir + fname;

	// Open the subject file
	string line;
	ifstream file(filename.c_str());
	bool get_it = false;
	pair<int, string> data;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			size_t pos = 0;
			string token;

			int loc = 0;
			while (((pos = line.find("|")) != string::npos))
			{
		    	token = line.substr(0, pos);
		    	line.erase(0, pos + 1);
		    	switch (loc)
		    	{
		    		case 0:
		    			if (atoi(token.c_str()) == sid) get_it = true;
		    			break;
		    		case 1:
		    			if (get_it)
		    			{
		    				data = make_pair(sid, token);
		    				return data;
		    			}
		    	}
		    	loc++;
		    }
		}
	}
}

pair<int, string> AllGrades::GetTeacherName(int pid)
{
	string filename = _data_dir + "/course_permission.txt";

	// Open the subject file
	string line;
	ifstream file(filename.c_str());
	bool get_it = false;
	int teacher_id = -1;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			size_t pos = 0;
			string token;

			int loc = 0;
			while (((pos = line.find("|")) != string::npos))
			{
		    	token = line.substr(0, pos);
		    	line.erase(0, pos + 1);
		    	switch (loc)
		    	{
		    		case 0:
		    			if (atoi(token.c_str()) == pid) get_it = true;
		    			break;
		    		case 1:
		    			if (get_it) teacher_id = atoi(token.c_str());
		    			break;
		    		case 2:
		    			break;
		    	}

		    	if (get_it && teacher_id != -1)
		    		return (GetName(teacher_id, "/people.txt"));
		    	loc++;
		    }
		}
	}

	pair<int, string> error;
	error = make_pair(-1, "Error");

	return error;
}

void AllGrades::SetGrade(int student_id, int teacher_id, int course_id, int grade)
{
	bool student = false;
	bool teacher = false;
	bool course = false;

	for (vector<Grade>::iterator g = _grades.begin(); g != _grades.end(); ++g)
	{
		if ((*g).StudentID() == student_id)
		{
			student = true;
			if ((*g).TeacherID() == teacher_id)
			{
				teacher = true;
				if ((*g).CourseID() == course_id)
				{
					course = true;
				}
			}
		}

		// The only way this happens is if the student is in the course
		// and the teacher has permission to set the grade
		if (student && teacher && course)
		{
			(*g).TheGrade(grade);
			cout << "Grade set successfully!\n";
			break;
		}
	}
}

void AllGrades::DisplayGrades(int student_id)
{
	cout << "Student" << "\t\t" << "Teacher" << "\t\t"
		<< "Subject" << "\t\t" << "Course" << "\t\t" << '\n';

	for (vector<Grade>::iterator g = _grades.begin(); g != _grades.end(); ++g)
	{

		if (student_id == -1 || (*g).StudentID() == student_id)
		{
			cout << (*g).StudentName() << '(' << (*g).StudentID() << ")\t"
			<< (*g).TeacherName() << '(' << (*g).TeacherID() << ")\t"
			<< (*g).SubjectName() << '(' << (*g).SubjectID() << ")\t"
			<< (*g).CourseName() << '(' << (*g).CourseID() << ")\t"
			<< "Grade: " << (*g).TheGrade() << '\n';
		}
	}
}

void AllGrades::SaveGrades()
{
	string gradeFile = _data_dir + "/grade.txt";
	if (remove (gradeFile.c_str()) != 0)
	{
		/*It's OK, we just need to make room for the new file*/
	}
	ofstream grade_file;
	grade_file.open(gradeFile.c_str());

	for (vector<Grade>::iterator g = _grades.begin(); g != _grades.end(); ++g)
	{
		grade_file << (*g).ID() << '|' << (*g).CourseID() << '|' <<
		(*g).TheGrade() << '|' << (*g).StudentID()  << '|' <<
		(*g).CoursePermID()  << "|\n";
	}

	grade_file.close();
}