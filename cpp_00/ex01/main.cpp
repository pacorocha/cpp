/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:22:02 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/15 23:59:07 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int	main(void)
{
	std::string cmd;

	while (1)
	{
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
				std::cout << "I'm adding a contact" << std::endl;
		else if (cmd == "SEARCH")
				std::cout << "I'm searching" << std::endl;
		else if (cmd == "EXIT")
				return (0);
		else
			std::cout << "RTFM! you can only type ADD, SEARCH or EXIT!" <<std::endl;
	}
	return (0);
}