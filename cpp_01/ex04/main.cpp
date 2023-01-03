/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:12:54 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/02 19:27:32 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int	main(int argc, char** argv) {
	Replacer replace(argc, argv[1], argv[2], argv[3]);
	return (0);
}
