#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>


namespace utils
{
	/* This could easily have been just a typedef */
	class intvector : public std::vector<int>
	{
		public:
			void release()
			{
				std::vector<int>::clear();
			}
	};

	/* Hell of a class */
	class hell : public intvector
	{
		public:
			void hellfunction()
			{
				intvector::release();
			}
	};
}

namespace interfaces
{
	class human_being
	{
		public:
			human_being(const std::string& iName) : 
				_name(iName) {};

			~human_being() {};

			/* If two human beings have sex, another human being is born! */
			virtual human_being make_sex(const human_being& iPartner)
			{
				std::cout << _name << " and " << iPartner._name << " are having sex... \n";
				human_being aRetValue(std::string(_name + " " + iPartner._name));
				std::cout << aRetValue._name << " is born!!\n";
				return aRetValue;
			};

			virtual const std::string& get_name()
			{
				return _name;
			}

		protected:
			std::string _name;
	};

	/* An interface */
	class male: public human_being
	{
		public:
			male() : human_being("Alfredo") {};
			virtual ~male() {};
			virtual void yell_penis_size() = 0;
	};

	class female: public human_being
	{
		public:
			female() : human_being("Gertrude") {};
			virtual ~female() {};
			virtual void complain() = 0;
	};



	/* Another interface */
	class worker
	{
		public:
			virtual int  get_salary() = 0;
			virtual void set_salary(int iSalary) = 0;
			virtual void yell_salary() = 0;
	};

	class unemployed
	{
		public:
			virtual void complain_of_not_having_salary() = 0;
	};

}

namespace implementors
{
	/* A boy is usually a male unemployed */
	class boy: 
		public interfaces::male, 
		public interfaces::unemployed
	{
		public:
			boy(int penis_size, const std::string& complain) :
				_psize(penis_size), _complain(complain) {};
			~boy() {};

			virtual void yell_penis_size()
			{
				std::cout << "I'm just a boy and my penis size is: " << _psize << std::endl;
			}

			virtual void complain_of_not_having_salary()
			{
				std::cout << _complain << std::endl;
			}

		private:
			int         _psize;
			std::string _complain;

	};

	/* A girl is usually a female and a worker */
	class girl:
		public interfaces::female,
		public interfaces::worker
	{
		public:
			girl() {};
			~girl() {};

			virtual void complain()
			{
				std::cout << " Since I'm a girl, I complain . " << std::endl;
			}

			virtual int get_salary()
			{
				return _salary;
			}

			virtual void set_salary(int iSalary)
			{
				_salary = iSalary;
			}

			virtual void yell_salary()
			{
				std::cout << "Since I'm a cool girl, my salary is: " << _salary << std::endl;
			}

		private:
			int _salary;
	};
}


int main ()
{
	implementors::boy aBoy(14, "Well, I'm just a boy");
	implementors::girl aGirl;

	aBoy.yell_penis_size();
	aBoy.complain_of_not_having_salary();

	aGirl.set_salary(1500);
	aGirl.yell_salary();
	aGirl.complain();


	interfaces::human_being aDaughter = aGirl.make_sex(aBoy);

	std::cout << " And indeed, " << aDaughter.get_name() << " is effectively born\n";

	exit(EXIT_SUCCESS);
}


