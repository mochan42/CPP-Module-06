/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:33:14 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 21:41:06 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class	ScalarConverter
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		ScalarConverter(); // Default constructor
		ScalarConverter(std::string const & setInput); // Parameterized constructor
		ScalarConverter(const ScalarConverter& other); // Default copy constructor
		~ScalarConverter(); // Destructor

		// OVERLOAD OPERATOR
		ScalarConverter& operator=(const ScalarConverter& src);

		// GETTERS - SETTERS
		std::string	getInput(void) const;
		void		setInput(std::string setInput);

		// MEMBER FUNCTIONS
		
		
		class InputIsEmpty : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Input string is empty.");
				}
		};

	private:
		std::string	input;
};


#endif