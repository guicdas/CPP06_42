#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base( void ){
	std::cout << "Base destroyed!\n\n";
}

Base * generate(void){
	int	randomClass = rand() % 3 + 1;
	if (randomClass == 1)
		return (new A());
	else if (randomClass == 2)
		return (new B());
	else if (randomClass == 3)
		return (new C());
	else
		std::cout << "std::rand() Bad Usage!\n";
	return (NULL);
}

void	identify(Base *p){
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Base *p points to\tA" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Base *p points to\tB" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Base *p points to\tC" << std::endl;
	else
		std::cerr << "Something went wrong!\n";

}

void	identify(Base& p){
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "Base &p points to\tA: " << &a << std::endl;
		return ;
	}
	catch (const std::exception& e){(void) e;}
	
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "Base &p points to\tB: " << &b << std::endl;
		return ;
	}
	catch (const std::exception& e){(void) e;}

	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "Base &p points to\tC: " << &c << std::endl;
		return ;
	}
	catch (const std::exception& e){(void) e;}
	std::cerr << "No Type identified!\n";
}