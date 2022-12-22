/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:23:09 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/22 16:40:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string str_to_upper(std::string src_str)
{
	for (size_t i = 0; i < src_str.length(); i++)
		src_str[i] = toupper(src_str[i]);
	return (src_str);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << str_to_upper(argv[i]);
			if (argc >= 2)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
