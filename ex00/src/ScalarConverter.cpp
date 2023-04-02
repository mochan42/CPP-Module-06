/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:24:59 by mochan            #+#    #+#             */
/*   Updated: 2023/04/02 16:02:59 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

//======== STATIC MEMBER VARIABLES INITIALIZATION ===============================================
// Provide definitions for static member variables outside the class definition in order for them
// to be initialized and stored in memory.
std::string	ScalarConverter::_input;
Types		ScalarConverter::_type;


//==== CALL PRIVATE CONSTRUCTORS ================================================================
// call the private constructors from within the class and return a pointer to the newly created
// object. 

ScalarConverter*	ScalarConverter::createInstance()
{
	return new ScalarConverter();
}

ScalarConverter*	ScalarConverter::createParameterizedInstance(std::string const & setInput)
{
	return new ScalarConverter(setInput);
}

ScalarConverter*	ScalarConverter::createDefaultCopyInstance(const ScalarConverter& src)
{
	return new ScalarConverter(src);
}


//==== GETTERS / SETTERS ========================================================================
std::string	ScalarConverter::getInput(void)
{
	return (_input);
}

void	ScalarConverter::setInput(std::string setInput)
{
	_input = setInput;
}
Types	 ScalarConverter::getType(void)
{
	return (_type);
}

void	ScalarConverter::setType(Types setType)
{
	_type = setType;
}


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


//======== MEMBER FUNCTIONS =====================================================================
bool	ScalarConverter::isChar(std::string const & input)
{
	bool	isChar = false;

	if (input.length() == 1)
		isChar = true;
	else
		isChar = false;
	return (isChar);
}

bool	ScalarConverter::isInt(std::string const & input)
{
	bool	isInt = false;
	char	*endptr;
	//strtol (not strtoi) is used to check for potential integer overflow.
	int longValue = std::strtol(input.c_str(), &endptr, 10); //endptr is a pointer where conversion to long ended (at the dot for instance).
	if (endptr == input.c_str() || *endptr != '\0') // 1: checks if conversion failed(empty string). 2:last character of the string is not null terminator
		isInt = false;
	else if (longValue < INT_MIN && longValue > INT_MAX) // check for INT overflow.
		isInt = false;
	else
		isInt = true;
	return (isInt);
}

bool ScalarConverter::isFloat(std::string const & input)
{
	bool isFloat = false;

	char* endptr;
	std::strtof(input.c_str(), &endptr); // endptr is a pointer where the conversion to float stopped.
	if (endptr == input.c_str() || *endptr != 'f') // 1: checks if conversion failed(empty string). 2: check that input is not the float 'f'.
		isFloat = false;
	else if (*endptr == 'f' && (endptr + 1 && *(endptr + 1) != '\0')) //Check that there are no characters after suffix f.
		isFloat = false;
	else
		isFloat = true;
	return (isFloat);
}

bool ScalarConverter::isDouble(std::string const & input)
{
	bool	isDouble = false;
	char*	endptr;
	size_t	pos;

	std::strtod(input.c_str(), &endptr); // endptr is a pointer where the conversion stopped.
	pos = input.find('.');
	if (pos == std::string::npos)
		isDouble = false;	
	else if (endptr == input.c_str() || *endptr != '\0') // 1: checks if conversion failed(emptys tring). 2:last character of the string is not null terminator
		isDouble = false;
	else
		isDouble = true;
	return (isDouble);
}

void	ScalarConverter::checkType(std::string const & input)
{
	if (input == "nan" || input == "nanf" )
		_type = NANx;
	else if (input == "-inf" || input == "inf" || input == "+inf" || input == "-inff" || input == "+inff" )
		_type = INFx;
	else if (isInt(input) == true)
		_type = INT;
	else if (isFloat(input) == true)
		_type = FLOAT;
	else if (isDouble(input) == true)
		_type = DOUBLE;
	else if (isChar(input) == true)
		_type = CHAR;
	else
		_type = NOT_VALID;
}

void	ScalarConverter::createConversionsFromNotValid(void)
{
	std::cout << RED << "Error: Input cannot be converted and needs to be of scalar type such as : char, int, float or double." << D << "\n";
}

void	ScalarConverter::createConversionsFromChar(std::string const & input)
{
	char c = input[0];
	std::cout << LIGRN << "===== Input to cast : " << BKLIGRN << input << D << LIGRN << " =====" << D << "\n";
	std::cout << BLU << "- into char\t: " << D << "\'" << c << "\'\n";
	std::cout << GREEN << "- into int\t: " << D << static_cast<int>(c) << "\n";
	std::cout << YELL << "- into float\t: " << D << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << "\n";
	std::cout << PU << "- into double\t: " << D << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
}

void	ScalarConverter::createConversionsFromInt(std::string const & input)
{
	std::cout << LIGRN << "===== Input to cast : " << BKLIGRN << input << D << LIGRN << " =====" << D << "\n";
	long int	longInt = strtol(_input.c_str(), NULL, 10);
	if (longInt > INT_MAX || longInt < INT_MIN)
	{
		std::cout << RED << "Error: Integer overflow" << D << "\n";
		return ;
	}
	int	i = longInt;
	if (i <= CHAR_MAX && i >= CHAR_MIN)
	{
		if (i >= 32 && i <= 127)
			std::cout << BLU << "- into char\t: "<< D << "\'" << static_cast<char>(i) << "\'\n";
		else
			std::cout << BLU << "- into char\t: "<< D << "Non displayable" << "\n";
	}
	else
		std::cout << BLU << "- into char\t: impossible" << "\n";
	std::cout << GREEN << "- into int\t: " << D << i << "\n";
	std::cout << YELL << "- into float\t: " << D << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << "\n";
	std::cout << PU << "- into double\t: " << D << std::fixed << std::setprecision(1) << static_cast<double>(i) << "\n";
}

void	ScalarConverter::createConversionsFromFloat(std::string const & input)
{
	std::cout << LIGRN << "===== Input to cast : " << BKLIGRN << input << D << LIGRN << " =====" << D << "\n";
	char *endptr;
	float	f = strtof(_input.c_str(), &endptr);
	if (f <= CHAR_MAX && f >= CHAR_MIN)
	{
		if (f >= 32 && f <= 127)
			std::cout << BLU << "- into char\t: "<< D << "\'" << static_cast<char>(f) << "\'\n";
		else
			std::cout << BLU << "- into char\t: "<< D << "Non displayable" << "\n";
	}
	else
		std::cout << BLU << "- into char\t: "<< D << "impossible" << "\n";
	if (f < INT_MIN || f > INT_MAX)
		std::cout << GREEN << "- into int\t: " << D << "impossible" << "\n";
	else
		std::cout << GREEN << "- into int\t: " << D << static_cast<int>(f) << "\n";
	std::cout << YELL << "- into float\t: " << D << std::fixed << std::setprecision(1) << f << "f" << "\n";
	std::cout << PU << "- into double\t: " << D << std::fixed << std::setprecision(1) << static_cast<double>(f) << "\n";
}

void	ScalarConverter::createConversionsFromDouble(std::string const & input)
{
	std::cout << LIGRN << "===== Input to cast : " << BKLIGRN << input << D << LIGRN << " =====" << D << "\n";
	double d = strtod(_input.c_str(), NULL);
	if (d <= CHAR_MAX && d >= CHAR_MIN)
	{
		if (d >= 32 && d <= 127)
			std::cout << BLU << "- into char\t: "<< D << "\'" << static_cast<char>(d) << "\'\n";
		else
			std::cout << BLU << "- into char\t: "<< D << "Non displayable" << "\n";
	}
	else
		std::cout << BLU << "- into char\t: "<< D << "impossible" << "\n";
	if (d < INT_MIN || d > INT_MAX)
		std::cout << GREEN << "- into int\t: " << D << "impossible" << "\n";
	else
		std::cout << GREEN << "- into int\t: " << D << static_cast<int>(d) << "\n";
	std::cout << YELL << "- into float\t: " << D << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << "\n";
	std::cout << PU << "- into double\t: " << D << std::fixed << std::setprecision(1) << d << "\n";
}

void	ScalarConverter::createConversionsFromNANx(std::string const & input)
{
	std::cout << LIGRN << "===== Input to cast : " << BKLIGRN << input << D << LIGRN << " =====" << D << "\n";
	std::cout << BLU << "- into char\t: "<< D << "impossible" << "\n";
	std::cout << GREEN << "- into int\t: " << D << "impossible" << "\n";
	if (_input == "nanf")
	{
		float f = std::numeric_limits<float>::quiet_NaN();
		std::cout << YELL << "- into float\t: " << D << f << "f" << "\n";
		std::cout << PU << "- into double\t: " << D << static_cast<double>(f) << D << "\n\n";
	}
	else if (_input == "nan")
	{
		double d = std::numeric_limits<float>::quiet_NaN();
		std::cout << YELL << "- into float\t: " << static_cast<float>(d) << "f" << "\n";
		std::cout << PU << "- into double\t: " << d << D << "\n";
	}
}

void	ScalarConverter::createConversionsFromINFx(std::string const & input)
{
	std::cout << LIGRN << "===== Input to cast : " << BKLIGRN << input << D << LIGRN << " =====" << D << "\n";
	std::cout << BLU << "- into char\t: "<< D << "impossible" << "\n";
	std::cout << GREEN << "- into int\t: " << D << "impossible" << "\n";
	if (input == "-inff" || input == "+inff" )
	{
		float f = std::numeric_limits<float>::infinity();
		if (input.at(0) == '-')
			f = -f;
		std::cout << YELL << "- into float\t: " << D << f << "f" << "\n";
		std::cout << PU << "- into double\t: " << D << static_cast<double>(f) << D << "\n\n";
	}
	if (input == "-inf" || input == "inf" || input == "+inf")
	{
		double d = std::numeric_limits<float>::infinity();
		if (input.at(0) == '-')
			d = -d;
		std::cout << YELL << "- into float\t: " << static_cast<float>(d) << "f" << "\n";
		std::cout << PU << "- into double\t: " << d << D << "\n";
	}
}

void	ScalarConverter::createConversions(std::string const & input)
{
	switch (_type)
	{
	case -1:
		createConversionsFromNotValid();
		break;
	case 0:
		createConversionsFromChar(input);
		break;
	case 1:
		createConversionsFromInt(input);
		break;
	case 2:
		createConversionsFromFloat(input);
		break;
	case 3:
		createConversionsFromDouble(input);
		break;
	case 4:
		createConversionsFromNANx(input);
		break;
	case 5:
		createConversionsFromINFx(input);
		break;
	default:
		std::cout << RED << "Error: fatal" << D << "\n";
		break;
	}
}

void	ScalarConverter::convert(std::string const & input)
{
	checkType(input);
	createConversions(input);
}