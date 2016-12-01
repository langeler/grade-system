1. Compiling the program

Provided you have the GNU C++ compiler installed the following command will compile the project into the executable file cg. If you have a different C++ compiler just replace g++ with the call to your compiler and everything should work fine.

	g++ course-grader.cpp Grade.cpp AllGrades.cpp -o cg

2. Structure:

	Grade Class
		The Grade class holds a single course grade, including the teacher with permission to change the grade. The class consists of two files; Grade.h and Grade.cpp.

	AllGrades Class
		The AllGrades class loads the grade data from pipe "|" delimited text files into a vector of Grade objects. When creating a new instance of the AllGrades class you pass in the directory name where the data files are kept. The class will automatically parse the files and load them into a vector of Grade object. The AllGrades class has member functions for displaying the grades, setting grades, and saving the changes back to the data files.