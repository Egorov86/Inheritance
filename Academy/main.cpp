//Academy
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age  //брать
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age  //давать

class Human
{
	static const int HUMAN_TYPE_WIDTH = 10;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRS_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 5;
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

                                                      // Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "Hconstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	                                                 // METODS:
	virtual void info()const
	//void info()const
	{
		cout << last_name << " " << first_name << " " << age << " y/o " << endl;
	}
	virtual std::ostream& info(std::ostream& os)const // метод info будет возвращать std::ostream& по ссылке
		//void info()const // и принимать std::ostream& по ссылке и возвращать будет os и в os всt gfhfvtnhs 
	{
		return os << last_name << " " << first_name << " " << age << " y/o ";
	}
	virtual std::ofstream& info(std::ofstream& ofs) const
	{
		//ofs << strchr(typeid(*this).name(), ' ') + 1 << ":\t" << last_name << " " << first_name << " " << age;
		ofs.width(HUMAN_TYPE_WIDTH); ofs << left << std::string(strchr(typeid(*this).name(), ' ') + 1) << ":";
		ofs.width(LAST_NAME_WIDTH);  ofs << left << last_name;
		ofs.width(FIRS_NAME_WIDTH);  ofs << left << first_name;
		ofs.width(AGE_WIDTH);        ofs << left << age;
		return ofs;
	}
	// strchr(typeid(*this).name() - cортирован выводится только класс без слова класс.
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.info(ofs);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance  //брать
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance                                                     //давать
class Student :public Human
{
	static const int SPECIALITY_WIDTH = 25;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
		
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_gpoup(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	                                           // CONSTRUCTORS:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_gpoup(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	                                            // Methods:
	void info()const override // переопределить
	{
		Human::info();
		cout << speciality << " " << group << " " << rating << " " << attendance;
	}
	std::ostream& info(std::ostream& os)const override
	{
		return Human::info(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
	}
	std::ofstream& info(std::ofstream& ofs)const override
	{
		Human::info(ofs);
		ofs.width(SPECIALITY_WIDTH); ofs << speciality;
		ofs.width(GROUP_WIDTH);      ofs << group;
		ofs.width(RATING_WIDTH);     ofs << rating;
		ofs.width(ATTENDANCE_WIDTH); ofs << attendance;
		return ofs;
	}

};
/*std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	return os << (Human&)obj << " " << obj.get_speciality() << " " << obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendance();
}*/

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience  //брать
#define TEACHER_GIVE_PARAMETERS speciality, experience                                  //давать
class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 25;
	static const int EXPERIENCE_WIDTH = 5;
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	                                       // CONSTRUCTOR
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) : Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstruktor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestruktor:\t" << this << endl;
	}
	                                       // Metod
	void info()const override
	{
		Human::info();
		cout << speciality << " " << experience << " ";
	}
	std::ostream& info(std::ostream& os)const override
	{
		return Human::info(os) << " " << speciality << " " << experience;
	}
	std::ofstream& info(std::ofstream& ofs)const override
	{
		Human::info(ofs);
		ofs.width(SPECIALITY_WIDTH); ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH); ofs << experience;
		return ofs;
	}
};

/*std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	return os << (Human&) obj << " " << obj.get_speciality() << " " << obj.get_experience();
}*/

#define GRADUATE_TAKE_PARAMETERS  const std::string& speciality, int year_of_release
#define GRADUATE_GIVE_PARAMETERS speciality, year_of_release
class Graduate : public Student
{
	static const int SUBJECT_WIDTH = 25;
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	                                        //CONSTRUCTOR GRADUATE
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject) : 
		Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	                                      // Methods:
	void info() const override
	{
		Student::info();
		cout << subject << endl;
	}
	std::ostream& info(std::ostream& os) const override
	{
		return Student::info(os) << subject;  // return Student:: для непосредств родителя
	}
	std::ofstream& info(std::ofstream& ofs)const override
	{
		Student::info(ofs);
		ofs.width(SUBJECT_WIDTH); ofs << subject;
		return ofs;
	}
};

/*std::ostream& operator << (std::ostream& os, const Graduate& obj)
{
	return os << (Human&) obj <<  " " << obj.get_subject() << " " << endl;
}*/


void Print( Human* group[], const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}

}

void Clear(Human* group[], const int n)
{
	cout << "DESTRUCTOR_DELETE_OBJECTS:\t" << endl;  // На отладчике посмотрел что вызывается всегда ДЕСТРУКТОР из Базового класса Human и не вызываются из дочерних.
	for (int i = 0; i < n; i++)
	{
		delete group[i]; //добавляем в деструктор базового класса virtual.
	}
}
void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd = "notepad " + filename;
	system(cmd.c_str()); // C_str возвращ содержимое объекта std::string в виде обычной с-

}
void Load(Human* group[], const int n, const std::string& filename)
{
	std::ifstream fin("group.txt");
	if (fin.is_open())
	{
		const int SIZE = 256;
		char buffer[SIZE]{};

		while (!fin.eof())
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		std::string cmd = "notepad " + filename;
		system(cmd.c_str());
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found " << endl;
	}
}

//#define INHERITANCE_CHECK
#define PRINT_SAVE_LOAD_CLEAR
void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef INHERITANCE_CHECK


	Human human("Vercetty", "Tommy", 30);
	human.info();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97);
	student.info();

	Teacher teacher("Vannessa", "May", 48, "Chemistry", 18);
	teacher.info();
#endif // INHERITANCE_CHECK
	
#ifdef PRINT_SAVE_LOAD_CLEAR
	// Generalization:
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 80, 90, "How to catch Heisenberg"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98),
		new Teacher("Diaz", "Ricardo", 50, "Weapon distribution", 20),

	};
	cout << delimiter << endl;


	//Print(group, sizeof(group) / sizeof(group[0]));

	//Save(group, sizeof(group) / sizeof(group[0]), "group.txt");

	Load(group, sizeof(group) / sizeof(group[0]), "group.txt");

	Clear(group, sizeof(group) / sizeof(group[0]));


#endif // PRINT_SAVE_LOAD_CLEAR

}
