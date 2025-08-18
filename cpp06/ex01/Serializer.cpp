#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called\n";
}

Serializer::Serializer(Serializer& cpy)
{
	std::cout << "serializer copy constructor called\n";
	*this = cpy;
}

Serializer& Serializer::operator=(Serializer& cpy)
{
	std::cout << "Serializer copy assignment operator called\n";
	(void)cpy;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "serializer destructor called\n";
}

uintptr_t Serializer::serialize(Data* data)
{
	return(reinterpret_cast<uintptr_t>(data));
}
Data* Serializer::deserialize(uintptr_t raw_data)
{
	return(reinterpret_cast<Data*>(raw_data));
}
