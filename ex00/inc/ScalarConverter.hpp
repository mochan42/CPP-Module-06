/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:33:14 by mochan            #+#    #+#             */
/*   Updated: 2023/04/01 13:19:27 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <limits> // for numeric_limits<char>::min() and numeric_limits<char>::max()
#include <string>
#include <cstring>
#include <cstdlib>
#include <cfloat> // for DBL_MIN, DBL_MAX

enum Types
{
	NOT_VALID	=	-1,
	CHAR		=	0,
	INT			=	1,
	FLOAT		=	2,
	DOUBLE		=	3,
	NANx		=	4,
	INFx		=	5,
};

class	ScalarConverter
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		ScalarConverter(); // Default constructor
		ScalarConverter(std::string const & setInput); // Parameterized constructor
		ScalarConverter(const ScalarConverter& src); // Default copy constructor
		~ScalarConverter(); // Destructor

		// OVERLOAD OPERATOR
		ScalarConverter& operator=(const ScalarConverter& src);

		// GETTERS - SETTERS
		std::string	getInput(void) const;
		void		setInput(std::string setInput);
		Types		getType(void) const;
		void		setType(Types setType);

		// MEMBER FUNCTIONS
		bool	isChar(std::string const & input);
		bool	isInt(std::string const & input);
		bool	isFloat(std::string const & input);
		bool	isDouble(std::string const & input);
		void	checkType(std::string const & input);
		void	createConversionsFromNotValid(void);
		void	createConversionsFromChar(std::string const & input);
		void	createConversionsFromInt(std::string const & input);
		void	createConversionsFromFloat(std::string const & input);
		void	createConversionsFromDouble(std::string const & input);
		void	createConversionsFromNANx(std::string const & input);
		void	createConversionsFromINFx(std::string const & input);
		void	createConversions(std::string const & input);
		void	convert(std::string const & input);
		
		class InputIsEmpty : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Input string is empty.");
				}
		};

	private:
		std::string	_input;
		Types		_type;
};

#endif