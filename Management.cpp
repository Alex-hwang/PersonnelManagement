#include "Management.h"

//Person类的实现
Person::Person(std::string id, std::string name, int age, bool isMale) : id(id), name(name), age(age), isMale(isMale) {}

void Person::setId(std::string id) {
	this->id = id;
}

void Person::setName(std::string name) {
	this->name = name;
}

void Person::setAge(int age) {
	this->age = age;
}

void Person::setIsMale(bool isMale) {
	this->isMale = isMale;
}

std::string Person::getId() {
	return this->id;
}

std::string Person::getName() {
	return this->name;
}

int Person::getAge() {
	return this->age;
}
bool Person::getIsMale() {
	return this->isMale;
}

std::string Person::getInformation(int num) {
	std::string info;
	switch (num) {
	case 1:
		info = "ID: " + this->id;
		break;
	case 2:
		info = "Name: " + this->name;
		break;
	case 3:
		info = "Age: " + std::to_string(this->age);
		break;
	case 4:
		return isMale ? "Male" : "Female";
	case 0:
		info = "ID: " + this->id + "\tName: " + this->name + "\tAge: " + std::to_string(this->age) + "\tGender: " + (this->isMale ? "Male" : "Female");
		break;
	}
	return info;
}

//Student类的实现
Student::Student(std::string id, std::string name, int age, bool isMale, std::string classNo) : Person(id, name, age, isMale), classNo(classNo) {}

void Student::setClassNo(std::string classNo) {
	this->classNo = classNo;
}

std::string Student::getClassNo() {
	return this->classNo;
}

std::string Student::getInformation(int num) {
	std::string info = Person::getInformation(num);
	if (num == 5) {
		info = "Class No: " + this->classNo;
	}
	else if (num == 0) {
		info = Person::getInformation(0) + "\tClass No: " + this->classNo;
	}
	return info;
}

//Teacher类的实现
Teacher::Teacher(std::string id, std::string name, int age, bool isMale, std::string department, std::string personnel, int salary) : Person(id, name, age, isMale), department(department), personnel(personnel), salary(salary) {}

void Teacher::setDepartment(std::string department) {
	this->department = department;
}

void Teacher::setPersonnel(std::string personnel) {
	this->personnel = personnel;
}

void Teacher::setSalary(int salary) {
	this->salary = salary;
}

std::string Teacher::getDepartment() {
	return this->department;
}

std::string Teacher::getPersonnel() {
	return this->personnel;
}

int Teacher::getSalary() {
	return this->salary;
}

std::string Teacher::getInformation(int num) {
	std::string info = Person::getInformation(num);
	switch (num) {
	case 5:
		info = "Department: " + this->department;
		break;
	case 6:
		info = "Personnel: " + this->personnel;
		break;
	case 7:
		info = "Salary: " + std::to_string(this->salary);
		break;
	case 0:
		info = Person::getInformation(0) + "\tDepartment: " + this->department + "\tPersonnel: " + this->personnel + "\tSalary: " + std::to_string(this->salary);
	}
	return info;
}

//Graduate类的实现
Graduate::Graduate(std::string id, std::string name, int age, bool isMale, std::string classNo, std::string tutor, std::string subject) : Student(id, name, age, isMale, classNo), tutor(tutor), subject(subject) {}

void Graduate::setTutor(std::string tutor) {
	this->tutor = tutor;
}
void Graduate::setSubject(std::string subject) {
	this->subject = subject;
}

std::string Graduate::getTutor() {
	return this->tutor;
}
std::string Graduate::getSubject() {
	return this->subject;
}

std::string Graduate::getInformation(int num) {
	std::string info = Student::getInformation(num);
	switch (num) {
	case 6:
		info = "Tutor: " + this->tutor;
		break;
	case 7:
		info = "Subject: " + this->subject;
		break;
	case 0:
		info = Student::getInformation(0) + "\tTutor: " + this->tutor + "\tSubject: " + this->subject;
		break;
	}
	return info;
}

//TeacherAssistant类的实现
TeacherAssistant::TeacherAssistant(std::string id, std::string name, int age, bool isMale, std::string classNo, std::string tutor, std::string subject, std::string course) : Graduate(id, name, age, isMale, classNo, tutor, subject), course(course) {}

void TeacherAssistant::setCourse(std::string course) {
	this->course = course;
}

std::string TeacherAssistant::getCourse() {
	return this->course;
}

std::string TeacherAssistant::getInformation(int num) {
	std::string info = Graduate::getInformation(num);
	if (num == 8) {
		info = "Course: " + this->course;
	}
	else if (num == 0) {
		info = Graduate::getInformation(0) + "\tCourse: " + this->course;
	}
	return info;
}

//Professor类的实现
Professor::Professor(std::string id, std::string name, int age, bool isMale, std::string department, std::string personnel, int salary) : Teacher(id, name, age, isMale, department, personnel, salary) {}

void Professor::setDepartment(std::string department) {
	this->setDepartment(department);
}

void Professor::setPersonnel(std::string personnel) {
	Professor::setPersonnel(personnel);
}

void Professor::setSalary(int salary) {
	Professor::setSalary(salary);
}

std::string Professor::getDepartment() {
	return Professor::getDepartment();
}

std::string Professor::getPersonnel() {
	return Professor::getPersonnel();
}

int Professor::getSalary() {
	return Professor::getSalary();
}

std::string Professor::getInformation(int num) {
	std::string info = Teacher::getInformation(num);
	if (num == 0) {
		info = Teacher::getInformation(0);
	}
	return info;
}

//MaleProfessor类的实现
MaleProfessor::MaleProfessor(std::string id, std::string name, int age, bool isMale, std::string department, std::string personnel, int salary) : Professor(id, name, age, isMale, department, personnel, salary) {}

std::string MaleProfessor::getInformation(int num) {
	std::string info = Professor::getInformation(num);
	if (num == 0) {
		info = Professor::getInformation(0);
	}
	return info;
}

//FemaleProfessor类的实现
FemaleProfessor::FemaleProfessor(std::string id, std::string name, int age, bool isMale, std::string department, std::string personnel, int salary) : Professor(id, name, age, isMale, department, personnel, salary) {}

std::string FemaleProfessor::getInformation(int num) {
	std::string info = Professor::getInformation(num);
	if (num == 0) {
		info = Professor::getInformation(0);
	}
	return info;
}

//saveToFile函数的实现
template<typename T>
void saveToFile(const std::vector<T>& objects, const std::string& filename) {
	std::ofstream outFile(filename);
	if (outFile.is_open()) {
		for (auto object : objects) {
			outFile << object.getInformation(0) << std::endl;
		}
		outFile.close();
		std::cout << "信息已保存到文件 " << filename << " 中。" << std::endl;
	}
	else {
		std::cerr << "无法打开文件 " << filename << "，请检查文件是否存在或是否有写入权限。" << std::endl;
	}
}

// 显式实例化 saveToFile 函数
template void saveToFile<Student>(const std::vector<Student>& objects, const std::string& filename);
template void saveToFile<MaleProfessor>(const std::vector<MaleProfessor>& objects, const std::string& filename);
template void saveToFile<FemaleProfessor>(const std::vector<FemaleProfessor>& objects, const std::string& filename);
template void saveToFile<Graduate>(const std::vector<Graduate>& objects, const std::string& filename);
template void saveToFile<TeacherAssistant>(const std::vector<TeacherAssistant>& objects, const std::string& filename);

//loadFromFile函数的实现
template<typename T>
std::vector<T> readFromFile(const std::string& filename) {
	std::vector<T> objects;
	std::ifstream inFile(filename);
	if (inFile.is_open()) {
		T object;
		while (inFile >> object) {
			objects.push_back(object);
		}
		inFile.close();
	}
	else {
		std::cerr << "无法打开文件 " << filename << "，请检查文件是否存在或是否有读取权限。" << std::endl;
	}
	return objects;
}

// 显式实例化 readFromFile 函数
template std::vector<Student> readFromFile<Student>(const std::string& filename);
template std::vector<MaleProfessor> readFromFile<MaleProfessor>(const std::string& filename);
template std::vector<FemaleProfessor> readFromFile<FemaleProfessor>(const std::string& filename);
template std::vector<Graduate> readFromFile<Graduate>(const std::string& filename);
template std::vector<TeacherAssistant> readFromFile<TeacherAssistant>(const std::string& filename);

//重载>>运算符
std::istream& operator>>(std::istream& in, Student& student) {
	std::string id, name, classNo;
	int age;
	bool isMale;
	in >> id >> name >> age >> isMale >> classNo;
	return in;
}

std::istream& operator>>(std::istream& in, Teacher& teacher) {
	std::string id, name, department, personnel;
	int age, salary;
	bool isMale;
	in >> id >> name >> age >> isMale >> department >> personnel >> salary;
	return in;
}

std::istream& operator>>(std::istream& in, Graduate& graduate) {
	std::string id, name, classNo, tutor, subject;
	int age;
	bool isMale;
	in >> id >> name >> age >> isMale >> classNo >> tutor >> subject;
	return in;
}

std::istream& operator>>(std::istream& in, TeacherAssistant& teacherAssistant) {
	std::string id, name, classNo, tutor, subject, course;
	int age;
	bool isMale;
	in >> id >> name >> age >> isMale >> classNo >> tutor >> subject >> course;
	return in;
}

std::istream& operator>>(std::istream& in, Professor& professor) {
	std::string id, name, department, personnel;
	int age, salary;
	bool isMale;
	in >> id >> name >> age >> isMale >> department >> personnel >> salary;
	return in;
}

std::istream& operator>>(std::istream& in, MaleProfessor& maleProfessor) {
	std::string id, name, department, personnel;
	int age, salary;
	bool isMale;
	in >> id >> name >> age >> isMale >> department >> personnel >> salary;
	return in;
}

std::istream& operator>>(std::istream& in, FemaleProfessor& femaleProfessor) {
	std::string id, name, department, personnel;
	int age, salary;
	bool isMale;
	in >> id >> name >> age >> isMale >> department >> personnel >> salary;
	return in;
}

//saveToFile函数的实现
void saveToFile(std::vector<TeacherAssistant>& teacherAssistants, std::vector<Graduate>& graduates, std::vector<MaleProfessor>& maleProfessors, std::vector<FemaleProfessor> femaleProfessors, std::vector<Student>& students, std::string filename) {
	std::ofstream outFile(filename);
	if (outFile.is_open()) {
		for (std::vector<TeacherAssistant>::iterator it = teacherAssistants.begin(); it != teacherAssistants.end(); it++) {
			outFile << it->getInformation(0) << std::endl;
		}
		for (std::vector<Graduate>::iterator it = graduates.begin(); it != graduates.end(); it++) {
			outFile << it->getInformation(0) << std::endl;
		}
		for (std::vector<MaleProfessor>::iterator it = maleProfessors.begin(); it != maleProfessors.end(); it++) {
			outFile << it->getInformation(0) << std::endl;
		}
		for (std::vector<FemaleProfessor>::iterator it = femaleProfessors.begin(); it != femaleProfessors.end(); it++) {
			outFile << it->getInformation(0) << std::endl;
		}
		for (std::vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
			outFile << it->getInformation(0) << std::endl;
		}
		outFile.close();
		std::cout << "信息已保存到文件 " << filename << " 中。" << std::endl;
	}
	else {
		std::cerr << "无法打开文件 " << filename << "，请检查文件是否存在或是否有写入权限。" << std::endl;
	}
}

//readFromFile函数的实现
void readFrom_File(std::string filename) {
	std::cout << "从文件 " << filename << " 中读取信息：" << std::endl;
	std::ifstream inFile(filename);
	if (inFile.is_open()) {
		std::string line;
		while (std::getline(inFile, line)) {
			std::cout << line << std::endl;
		}
		inFile.close();
	}
	else {
		std::cerr << "无法打开文件 " << filename << "，请检查文件是否存在或是否有读取权限。" << std::endl;
	}
}

//findPerson函数的实现
void findPerson(std::string id, std::string filename) {
	std::cout << "查找编号为 " << id << " 的人员信息：" << std::endl;
	std::ifstream inFile(filename);
	if (inFile.is_open()) {
		std::string line;
		while (std::getline(inFile, line)) {
			if (line.find(id) != std::string::npos) {
				std::cout << line << std::endl;
			}
		}
		inFile.close();
	}
	else {
		std::cerr << "无法打开文件 " << filename << "，请检查文件是否存在或是否有读取权限。" << std::endl;
	}
}

//modifyPerson函数的实现
void modifyPerson(std::string filename) {
	std::cout << "修改人员信息：" << std::endl;
	std::string id;
	std::cout << "请输入要修改的人员编号：";
	std::cin >> id;
	std::ifstream inFile(filename);

	if (!inFile.is_open()) {
		std::cerr << "无法打开文件 " << filename << "，请检查文件是否存在或是否有读取权限。" << std::endl;
		return;
	}

	std::vector<std::pair<std::string, std::string>> lines;
	std::string line;

	//先把每一行的信息存储到lines中
	while (std::getline(inFile, line)) {
		lines.push_back(std::make_pair(line.substr(4, 7), line));
	}

	inFile.close();

	//查找要修改的人员信息
	bool found = false;
	for (std::vector<std::pair<std::string, std::string>>::iterator it = lines.begin(); it != lines.end(); it++) {
		if (it->first == id) {
			found = true;
			std::cout << "找到编号为 " << id << " 的人员信息：" << std::endl;
			std::cout << it->second << std::endl;
			std::string newLine = "";
			//判断这一行信息是哪个类的对象
			if (it->second.find("Course") != std::string::npos) {
				std::string id, name, classNo, tutor, subject, course;
				int age;
				bool isMale;
				std::cout << "请输入修改后的信息：(ID+Name+Age+Gender(Male/Female)+ClassNo+Tutor+Subject+Course)" << std::endl;
				std::cin >> id >> name >> age >> isMale >> classNo >> tutor >> subject >> course;
				newLine = "ID: " + id + "\tName: " + name + "\tAge: " + std::to_string(age) + "\tGender: " + (isMale ? "Male" : "Female") + "\tClass No: " + classNo + "\tTutor: " + tutor + "\tSubject: " + subject + "\tCourse: " + course;
			}
			else if (it->second.find("Subject") != std::string::npos) {
				std::string id, name, classNo, tutor, subject;
				int age;
				bool isMale;
				std::cout << "请输入修改后的信息：(ID+Name+Age+Gender(Male/Female)+ClassNo+Tutor+Subject)" << std::endl;
				std::cin >> id >> name >> age >> isMale >> classNo >> tutor >> subject;
				newLine = "ID: " + id + "\tName: " + name + "\tAge: " + std::to_string(age) + "\tGender: " + (isMale ? "Male" : "Female") + "\tClass No: " + classNo + "\tTutor: " + tutor + "\tSubject: " + subject;
			}
			else if (it->second.find("Salary") != std::string::npos) {
				std::string id, name, department, personnel;
				int age, salary;
				bool isMale;
				std::cout << "请输入修改后的信息：(ID+Name+Age+Gender(Male/Female)+Department+Personnel+Salary)" << std::endl;
				std::cin >> id >> name >> age >> isMale >> department >> personnel >> salary;
				newLine = "ID: " + id + "\tName: " + name + "\tAge: " + std::to_string(age) + "\tGender: " + (isMale ? "Male" : "Female") + "\tDepartment: " + department + "\tPersonnel: " + personnel + "\tSalary: " + std::to_string(salary);
			}
			else {
				std::string id, name, classNo;
				int age;
				bool isMale;
				std::cout << "请输入修改后的信息：(ID+Name+Age+Gender(Male/Female)+ClassNo)";
				std::cin >> id >> name >> age >> isMale >> classNo;
				newLine = "ID: " + id + "\tName: " + name + "\tAge: " + std::to_string(age) + "\tGender: " + (isMale ? "Male" : "Female") + "\tClass No: " + classNo;
			}
			it->second = newLine;
			break;
		}
	}

	if (!found) {
		std::cerr << "未找到编号为 " << id << " 的人员信息。" << std::endl;
		return;
	}

	//将修改后的信息写入文件
	std::ofstream outFile(filename);
	if (outFile.is_open()) {
		for (std::vector<std::pair<std::string, std::string>>::iterator it = lines.begin(); it != lines.end(); it++) {
			outFile << it->second << std::endl;
		}
		outFile.close();
		std::cout << "信息已保存到文件 " << filename << " 中。" << std::endl;
	}
	else {
		std::cerr << "无法打开文件 " << filename << "，请检查文件是否存在或是否有写入权限。" << std::endl;
	}
}