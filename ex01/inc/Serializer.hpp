/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:01:08 by mochan            #+#    #+#             */
/*   Updated: 2023/04/02 16:05:34 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

struct Data {
	std::string	stringValue;
	int			intValue;
};

class	Serializer
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		Serializer(); // Default constructor
		Serializer(const Serializer& src); // Default copy constructor
		~Serializer(); // Destructor

		// OVERLOAD OPERATOR
		Serializer&	operator=(const Serializer& src);

		// GETTERS - SETTERS

		// MEMBER FUNCTIONS
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif