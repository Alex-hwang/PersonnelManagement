#include"Management.h"

int main() {
	std::vector<Student> students;
	std::vector<MaleProfessor> maleProfessors;
	std::vector<FemaleProfessor> femaleProfessors;
	std::vector<Graduate> graduates;
	std::vector<TeacherAssistant> teacherAssistants;

	std::vector<Student> readStudents;
	std::vector<MaleProfessor> readMaleProfessors;
	std::vector<FemaleProfessor> readFemaleProfessors;
	std::vector<Graduate> readGraduates;
	std::vector<TeacherAssistant> readTeacherAssistants;

	students.push_back(Student("2023001", "Tom", 20, true, "Class 1"));
	students.push_back(Student("2023002", "Jerry", 21, false, "Class 2"));
	students.push_back(Student("2023003", "Alice", 22, false, "Class 3"));
	students.push_back(Student("2023004", "Bob", 23, true, "Class 4"));
	students.push_back(Student("2023005", "Cathy", 24, false, "Class 5"));

	maleProfessors.push_back(MaleProfessor("2022001", "David", 40, true, "Department 1", "Personnel 1", 10000));
	maleProfessors.push_back(MaleProfessor("2022002", "Frank", 41, true, "Department 2", "Personnel 2", 11000));
	maleProfessors.push_back(MaleProfessor("2022003", "George", 42, true, "Department 3", "Personnel 3", 12000));

	femaleProfessors.push_back(FemaleProfessor("2021001", "Helen", 30, false, "Department 4", "Personnel 4", 13000));
	femaleProfessors.push_back(FemaleProfessor("2021002", "Ivy", 31, false, "Department 5", "Personnel 5", 14000));
	femaleProfessors.push_back(FemaleProfessor("2021003", "Jenny", 32, false, "Department 6", "Personnel 6", 15000));

	graduates.push_back(Graduate("2024001", "Kevin", 25, true, "Class 6", "Tutor1", "Subject1"));
	graduates.push_back(Graduate("2024002", "Lily", 26, false, "Class 7", "Tutor2", "Subject2"));
	graduates.push_back(Graduate("2024003", "Mary", 27, false, "Class 8", "Tutor3", "Subject3"));

	teacherAssistants.push_back(TeacherAssistant("2024004", "Nancy", 28, false, "Class 9", "Tutor4", "Subject4", "Math"));
	teacherAssistants.push_back(TeacherAssistant("2024005", "Oscar", 29, true, "Class 10", "Tutor5", "Subject5", "English"));
	teacherAssistants.push_back(TeacherAssistant("2024006", "Peter", 30, true, "Class 11", "Tutor6", "Subject6", "Physics"));

	saveToFile(teacherAssistants, graduates, maleProfessors, femaleProfessors, students, ("info.txt"));
	while (true) {
		std::cout << "1. 读取文件中的信息" << std::endl;
		std::cout << "2. 修改文件中的信息" << std::endl;
		std::cout << "0. 退出" << std::endl;
		std::cout << "请选择您的操作: ";

		int choice;
		std::cin >> choice;
		switch (choice) {
		case 0: {
			system("cls");
			std::cout << "感谢您的使用，再见！" << std::endl;
			return 0;
		}
		case 1: {
			system("cls");
			readFrom_File("info.txt");
			break;
		}
		case 2: {
			system("cls");
			modifyPerson("info.txt");
			break;
		}
		}
	}

	//调用函数保存文件
	//saveToFile(students, "student.txt");
	//saveToFile(maleProfessors, "maleProfessor.txt");
	//saveToFile(femaleProfessors, "femaleProfessor.txt");
	//saveToFile(graduates, "graduate.txt");
	//saveToFile(teacherAssistants, "teacherAssistant.txt");

	//从文件中读取数据
	//std::vector<Student> studentsFromFile = readFromFile<Student>("student.txt");
	//std::vector<MaleProfessor> maleProfessorsFromFile = readFromFile<MaleProfessor>("maleProfessor.txt");
	//std::vector<FemaleProfessor> femaleProfessorsFromFile = readFromFile<FemaleProfessor>("femaleProfessor.txt");
	//std::vector<Graduate> graduatesFromFile = readFromFile<Graduate>("graduate.txt");
	//std::vector<TeacherAssistant> teacherAssistantsFromFile = readFromFile<TeacherAssistant>("teacherAssistant.txt");

	//readFrom_File("info.txt");

	//modifyPerson("info.txt");

	return 0;
}