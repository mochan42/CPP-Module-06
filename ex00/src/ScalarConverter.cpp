/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:24:59 by mochan            #+#    #+#             */
/*   Updated: 2023/03/31 23:23:53 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

//======== CONSTRUCTORS =========================================================================

ScalarConverter::ScalarConverter()
{
	std::cout << BLU << "Default constructor called from ScalarConverter" << D << "\n";
}

ScalarConverter::ScalarConverter(std::string const & setInput)
{
	std::cout << BLU << "Parameterized constructor called from ScalarConverter" << D << "\n";
	this->_input = setInput;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	std::cout << BLU << "Copy constructor called from ScalarConverter" << D << "\n";
	*this = src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	std::cout << BLU << "Copy assignment operator called from ScalarConverter" << D << "\n";
	this->_input = src._input;
	this->_type = src._type;
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
ScalarConverter::~ScalarConverter()
{
	std::cout << CY << "Destructor called from ScalarConverter" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
std::string	ScalarConverter::getInput(void) const
{
	return (this->_input);
}

void	ScalarConverter::setInput(std::string setInput)
{
	this->_input = setInput;
}
Types	ScalarConverter::getType(void) const
{
	return (this->_type);
}

void	ScalarConverter::setType(Types setType)
{
	this->_type = setType;
}

//======== MEMBER FUNCTIONS =====================================================================
bool	ScalarConverter::isChar(void)
{
	bool	isChar = false;

	if (this->_input.length() != 1)
		isChar = false;
	else
	{
		int intValue = std::atoi(this->_input.c_str());
		if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max())
			isChar = true;
		else
			isChar = false;
	}
	return (isChar);
}

bool	ScalarConverter::isInt(void)
{
	bool	isInt = false;
	char	*endptr;
	//strtol (not strtoi) is used to check for potential integer overflow.
	long	intValue = std::strtol(this->_input.c_str(), &endptr, 10); //endptr is a pointer where conversion ended (at the dot for instance).

	if (endptr == this->_input.c_str() || *endptr != '\0') // 1: checks if conversion failed(emptys tring). 2:last character of the string is not null terminator
		isInt = false;
	if (*endptr == '\0' && intValue >= INT_MIN && intValue <= INT_MAX) // 1: make sure there are no characters after the conversion ended. 2: check for INT overflow.
		isInt = true;
	else
	{
		isInt = false;
		// std::cout << "Error: Integer overflow\n";
	}
	return (isInt);
}

bool ScalarConverter::isFloat(void)
{
	bool isFloat = false;

	char* endptr;
	std::strtof(this->_input.c_str(), &endptr); // endptr is a pointer where the conversion stopped.
	if (endptr == this->_input.c_str() || *endptr != '\0') // 1: checks if conversion failed(emptys tring). 2:last character of the string is not null terminator
		isFloat = false;
	if (*endptr == 'f' && *(endptr + 1) == '\0') //1. check that there are no characters after suffix f.
		isFloat = true;
	return (isFloat);
}

bool ScalarConverter::isDouble(void)
{
	bool	isDouble = false;
	char*	endptr;
	double	doubleValue = std::strtod(this->_input.c_str(), &endptr); // endptr is a pointer where the conversion stopped.

	if (endptr == this->_input.c_str() || *endptr != '\0') // 1: checks if conversion failed(emptys tring). 2:last character of the string is not null terminator
		isDouble = false;
	else
	{
		int numDots = std::count(this->_input.begin(), this->_input.end(), '.'); // count the occurences of '.'
		if ((numDots <= 1 && numDots >= 0)  && doubleValue >= DBL_MIN && doubleValue <= DBL_MAX) // required to solve edge case 3f.14f when there are more than 1 "dot" as in f
			isDouble = true;
	}
	return isDouble;
}

void	ScalarConverter::checkType(void)
{
	if (this->_input == "nan" || this->_input == "nanf" )
		this->_type = NANx;
	else if (this->_input == "-inf" || this->_input == "+inf" || this->_input == "-inff" || this->_input == "+inff" )
		this->_type = INFx;
	else if (isChar() == true)
		this->_type = CHAR;
	else if (isInt() == true)
		this->_type = INT;
	else if (isFloat() == true)
		this->_type = FLOAT;
	else if (isDouble() == true)
		this->_type = DOUBLE;
	else
		_type = NOT_VALID;
}

void	ScalarConverter::convert(void)
{
	checkType();
	std::cout << getType() << "\n";
}

//=============== FUNCTIONS =====================================================================
