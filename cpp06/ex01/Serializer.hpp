#pragma once

#include <iostream>

struct Data
{
	std::string	name;
};


class Serializer
{
public:
	Serializer();
	Serializer(Serializer& cpy);
	Serializer& operator=(Serializer& cpy);
	~Serializer();
	static uintptr_t serialize(Data* data);
	static Data* deserialize(uintptr_t raw_data);
};

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called\n";
}

Serializer::Serializer(Serializer& cpy)
{
	std::cout << "serializer copy constructor calledn\n";
	*this = cpy;
}

Serializer& Serializer::operator=(Serializer& cpy)
{
	std::cout << "Serializer copy assignment operator called\n";
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
