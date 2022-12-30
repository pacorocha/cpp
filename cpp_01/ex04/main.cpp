/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:12:54 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/29 22:32:24 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int	main(int argc, char** argv) {
	if (argc != 4) {
		std::cout << "Type ./sifl + filename + str1 + str2." << std::endl;
		return(1);
	}
	Replacer replace(argv[1], argv[2], argv[3]);
	return (0);
}
