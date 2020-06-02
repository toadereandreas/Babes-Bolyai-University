#include "Validators.h"
#include <string>

void MovieValidator::validate(const Movie& m)
{
	std::string errors;
	if(m.getTitle().size() <= 0)
		errors += std::string("Invalid name of movie. It should have at least 1 character !\n");
	if(m.getLink().size() <= 0)
		errors += std::string("Invalid link. The link is empty!\n");
	if (m.getGenre().size() <= 0)
		errors += std::string("Invalid genre. The genre is empty!\n");
	if (m.getYear() <= 1850)
		errors += std::string("Invalid year given.\n");

	if (errors.size() > 0)
		throw MovieValidationException(errors);
}

MovieValidationException::MovieValidationException(std::string _message) : message{ _message }
{
}

const char* MovieValidationException::what() const noexcept
{
	return this->message.c_str();
}
