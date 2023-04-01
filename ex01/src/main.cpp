/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:01:19 by mochan            #+#    #+#             */
/*   Updated: 2023/04/01 16:18:58 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

int main()
{
	Data		dataTest;
	Data		*ptr1;
	Data		*ptr2;
	Serializer	Serializer1;
	dataTest.stringValue = "42 Wolfsburg"; 
	dataTest.intValue = 42;
	ptr1 = &dataTest;

	std::cout << YELL << "\n===== ptr1 stores dataTest at address\t: " << D << ptr1 << YELL << " ======" << D << "\n";
	
	std::cout << YELL << "intValue\t: " << D << (*ptr1).intValue << "\n";
	std::cout << YELL << "stringValue\t: " << D << (*ptr1).stringValue << "\n\n";
	
	uintptr_t dataTestMemoryAddress = Serializer1.serialize(ptr1);
	std::cout << BLA << "===== dataTest MemoryAddress as Integer\t: " << D << dataTestMemoryAddress << BLA << " =====" << D << "\n\n";
	
	ptr2 = Serializer1.deserialize(dataTestMemoryAddress);
	std::cout << PU << "===== ptr2 stores dataTest at address\t: " << D << ptr2 << PU << " ======" << D << "\n";
	std::cout << PU << "intValue\t: " << D << (*ptr2).intValue << "\n";
	std::cout << PU << "stringValue\t: " << D << (*ptr2).stringValue << "\n\n";

	if (ptr1 == ptr2)
		std::cout << GREEN << "Original pointer and pointer from deserialization are equal\n" << D << "\n";
	else
		std::cout << RED << "Original pointer and pointer from deserialization are different\n" << D << "\n";

	return (0);
}