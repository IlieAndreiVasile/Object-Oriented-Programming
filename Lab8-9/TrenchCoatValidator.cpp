#include "TrenchCoatValidator.h"


using namespace std;

TrenchCoatException::TrenchCoatException(vector<string> _errors): errors{_errors}
{
}

vector<string> TrenchCoatException::getErrors() const
{
	return this->errors;
}

void TrenchCoatValidator::validate(const TrenchCoat& tc)
{
	vector<string> errors;
	if (tc.getSize() <= 0)
		errors.push_back("The size name cannot be 0\n");
	if (tc.getColour().size() < 1)
		errors.push_back("The colour name cannot be NULL\n");
	if (tc.getPrice() <= 0)
		errors.push_back("The price name cannot be less than 0\n");
	if (tc.getQuantity() <= 0)
		errors.push_back("The colour name cannot be less than 0\n");

	// search for "www" or "http" at the beginning of the source string
	int posWww = tc.getPhotograph().find("www");
	int posHttp = tc.getPhotograph().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The photograph source must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw TrenchCoatException(errors);
}