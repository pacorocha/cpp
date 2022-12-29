/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:58:28 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/28 19:57:00 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "Memory address of string is: " << &string << std::endl;
	std::cout << "Memory address of stringPTR is: " << &stringPTR << std::endl;
	std::cout << "Memory address of stringREF is: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of string is: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;

	return (0);
}
