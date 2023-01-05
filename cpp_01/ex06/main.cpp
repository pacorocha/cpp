/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:30:17 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/05 17:30:19 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl harl;

	if (argc != 2)
	{
		std::cout << "You have to type 2 arguments" << std::endl;
		return (0);
	}
	harl.complain(argv[1]);
}
