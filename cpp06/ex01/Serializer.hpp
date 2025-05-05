#pragma once

#include <iostream>
#include <stdint.h>

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
