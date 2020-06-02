#pragma once
#include "Domain.h"

class MovieValidationException : public std::exception {
private:
	std::string message;
public:
	MovieValidationException(std::string _message);
	// Return the exception as a string
	const char* what() const noexcept override;
};

class MovieValidator {
public:
	// Validates a given movie
	static void validate(const Movie& m);
};