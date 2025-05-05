#include "Serializer.hpp"


int	main(void)
{
	Data *data = new Data;
	data->name = "joe";

	std::cout << "original data in struct: " << data->name << "\n";
	uintptr_t raw_data = Serializer::serialize(data);
	std::cout << "raw data looks like: " << raw_data << "\n";

	Data *des_data = Serializer::deserialize(raw_data);
	std::cout << "deserialized data is: " << des_data->name << "\n";

	delete data;
}