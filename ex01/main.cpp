#include "Serializer.hpp"

int main( void ){
	Data d1;
	d1.memberInt1 = 2;
	d1.memberInt2 = 55;

	std::cout <<"Data Values:\n\t1- " << d1.memberInt1 << "\t("<< &d1.memberInt1 << ")\n";
	std::cout <<"\t1- " << d1.memberInt2 << "\t("<< &d1.memberInt2 << ")\n";

	uintptr_t intPointer = Serializer::serialize(&d1);
	std::cout << "After Serialization..." << "\n\n";
	std::cout <<"Serialized data:\n\t1- " << intPointer << "\n\n";
	Data *dataPointer = Serializer::deserialize(intPointer);
	
	std::cout << "After Deserialization..." << "\n\n";
	std::cout <<"Data Values:\n\t1- " << dataPointer->memberInt1 << "\t("<< &dataPointer->memberInt1 << ")\n";
	std::cout <<"\t1- " << dataPointer->memberInt2 << "\t("<< &dataPointer->memberInt2 << ")\n";
}