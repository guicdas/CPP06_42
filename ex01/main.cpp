#include "Serializer.hpp"

int main( void ){
	Data d1;
	d1.memberInt1 = 2;
	d1.memberInt2 = 55;

	std::cout <<"Data Values:\n\t1- " << d1.memberInt1 << "\n\t2- " << d1.memberInt2 << "\n\n";
	std::cout <<"Data Members &:\n\t1- " << &d1.memberInt1 << "\n\t2- " << &d1.memberInt2 << "\n\n";

	uintptr_t intPointer = Serializer::serialize(&d1);
	Data *dataPointer = Serializer::deserialize(intPointer);
	
	std::cout << "After Serialization..." << "\n\n";
	std::cout << "Data Pointer Values:\n\t1- " << dataPointer->memberInt1 << "\n\t2- " << dataPointer->memberInt2 << std::endl;
	std::cout << "Data Pointer Members &:\n\t1- " << &dataPointer->memberInt1 << "\n\t2- " << &dataPointer->memberInt2 << "\n\n";
}