#include<iostream>
#include<string>
#include<fstream>
#include<regex>
#include<vector>

//定义人员类
class Person {
private:
	std::string id;
	std::string name;
	int age;
	bool isMale;
public:
	Person() {}
	~Person() {}
	Person(std::string id, std::string name, int age, bool isMale);
	virtual void setId(std::string id);
	virtual void setName(std::string name);
	virtual void setAge(int age);
	virtual void setIsMale(bool isMale);
	virtual std::string getId();
	virtual std::string getName();
	virtual int getAge();
	virtual bool getIsMale();
	virtual std::string getInformation(int num);
};

//定义学生类
class Student : public Person {
private:
	std::string classNo;
public:
	Student() {}
	~Student() {}
	Student(std::string id, std::string name, int age, bool isMale, std::string classNo);
	void setClassNo(std::string classNo);
	std::string getClassNo();
	std::string getInformation(int num);
};

//定义教师类
class Teacher : public Person {
private:
	std::string department;
	std::string personnel;
	int salary;
public:
	Teacher() {}
	~Teacher() {}
	Teacher(std::string id, std::string name, int age, bool isMale, std::string department, std::string personnel, int salary);
	virtual void setDepartment(std::string department);
	virtual void setPersonnel(std::string personnel);
	virtual void setSalary(int salary);
	virtual std::string getDepartment();
	virtual std::string getPersonnel();
	virtual int getSalary();
	virtual std::string getInformation(int num);
};

//定义教授类
class Professor : public Teacher {
public:
	Professor() {}
	~Professor() {}
	Professor(std::string id, std::string name, int age, bool isMale, std::string department, std::string personnel, int salary);

	virtual void setDepartment(std::string department) override;
	virtual void setPersonnel(std::string personnel) override;
	virtual void setSalary(int salary) override;
	virtual std::string getDepartment() override;
	virtual std::string getPersonnel() override;
	virtual int getSalary() override;
	virtual std::string getInformation(int num) override;
};

class MaleProfessor : public Professor {
public:
	MaleProfessor() {}
	~MaleProfessor() {}
	MaleProfessor(std::string id, std::string name, int age, bool isMale, std::string department, std::string personnel, int salary);

	virtual std::string getInformation(int num) override;  // 重写父类中的纯虚函数
};

class FemaleProfessor : public Professor {
public:
	FemaleProfessor() {}
	~FemaleProfessor() {}
	FemaleProfessor(std::string id, std::string name, int age, bool isMale, std::string department, std::string personnel, int salary);

	virtual std::string getInformation(int num) override;  // 重写父类中的纯虚函数
};
//定义研究生类
class Graduate : public Student {
	std::string tutor;
	std::string subject;
public:
	Graduate() {}
	~Graduate() {}
	Graduate(std::string id, std::string name, int age, bool isMale, std::string classNo, std::string tutor, std::string subject);
	void setTutor(std::string tutor);
	void setSubject(std::string subject);
	std::string getTutor();
	std::string getSubject();
	std::string getInformation(int num);
};

//定义助教类
class TeacherAssistant : public Graduate {
private:
	std::string course;
public:
	TeacherAssistant() {}
	~TeacherAssistant() {}
	TeacherAssistant(std::string id, std::string name, int age, bool isMale, std::string classNo, std::string tutor, std::string subject, std::string course);
	void setCourse(std::string course);
	std::string getCourse();
	std::string getInformation(int num);
};

template<typename T>
void saveToFile(const std::vector<T>& objects, const std::string& filename);

template<typename T>
std::vector<T> readFromFile(const std::string& filename);

//将信息保存到一个文件中
void saveToFile(std::vector<TeacherAssistant>& teacherAssistants, std::vector<Graduate>& graduates, std::vector<MaleProfessor>& maleProfessors, std::vector<FemaleProfessor>femaleProfesssors, std::vector<Student>& students, std::string filename);

//将文件中的信息打印出来
void readFrom_File(std::string filename);

//根据编号查找人员
void findPerson(std::string id, std::string filename);

//根据编号修改人员信息
void modifyPerson(std::string filename);
