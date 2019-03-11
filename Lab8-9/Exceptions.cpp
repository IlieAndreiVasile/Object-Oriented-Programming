#include "Exceptions.h"

FileException::FileException(const std::string & msg) : message(msg)
{
}

const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{""}
{
}

RepositoryException::RepositoryException(const std::string & msg): message{ msg }
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateTrenchCoatException::what()
{
	return "\n\tThere is another trench coat with the same presenter and title !\n";
}

const char * InexistentTrenchCoatException::what()
{
	return "\n\tThere are no trench coats with the given presenter and title !\n";
}