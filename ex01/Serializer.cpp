#include "Serializer.hpp"

Serializer::Serializer( void ){
	std::cout << "Serializer created by default!\n";
}

Serializer::Serializer( const Serializer &s ){
	std::cout << "Serializer Copy created!\n";
	*this = s;
}

Serializer& Serializer::operator=( const Serializer &s ){
	std::cout << "Serializer Copy created!\n";
	if (this != &s)
		*this = s;

	return (*this);
}

Serializer::~Serializer( void ){
	std::cout << "Serializer destroyed!\n";
}

uintptr_t Serializer::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}