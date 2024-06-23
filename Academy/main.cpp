//Academy
#include<iostream>
#include<string>
using namespace std;

#define delimitr "\n--------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
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
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	                                                 // METODS:
	virtual void info()const
	//void info()const
	{
		cout << last_name << " " << first_name << " " << age << " y/o " << endl;
	}
};

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Student :public Human
{
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
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}


};

class Teacher :public Human
{
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
	Teacher(HUMAN_TAKE_PARAMETERS, const std::string& speciality, unsigned int experience) : Human(HUMAN_GIVE_PARAMETERS)
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
	void info()const
	{
		Human::info();
		cout << speciality << " " << experience << " " << endl;
	}
};
class Graduate : public Human
{
	std::string speciality;
	int year_of_release;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_year_of_release()const
	{
		return year_of_release;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_year_of_release(int year_of_release)
	{
		this->year_of_release = year_of_release;
	}
	                                        //CONSTRUCTOR GRADUATE
	Graduate(HUMAN_TAKE_PARAMETERS, const std::string& speciality, int year_of_release) : Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_year_of_release(year_of_release);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	                                      // Metod
	void info()const
	{
		Human::info();
		cout << speciality << " " << year_of_release << " " << endl;
	}
};

//#define INHERITANCE_CHECK

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
	
	// Generalization:
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98),
		new Graduate("Arnold", "Schvarzenegger", 76, "Bodybuilder", 1967)
	};
	cout << delimitr << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info();
		cout << delimitr << endl;
	}
}
