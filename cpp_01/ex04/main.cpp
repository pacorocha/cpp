/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:12:54 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/05 01:16:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <string.h>

bool printError(const char* error) {
	std::cerr << error << std::endl;
	return (false);
}

bool	validateInput(int argc, char** argv) {
	std::fstream	file;
	
	file.open(argv[1]);
	if (!file)
		return printError(FILE_ERROR);
	if (argc != 4) {
		printError(INPUT_ERROR);
		return(printError(WRONG_ARGUMENTS));
	}
	if (!argv[1])
		return (printError(FILE_ERROR));
	if (file.get(), file.eof())
		return (printError(FILE_EMPTY));
	file.close();
	if (strcmp(argv[2], "") == 0 && strcmp(argv[3], "") == 0)
		return (printError(EMPTY_STRINGS));
	return (true);
}

int	main(int argc, char** argv) {
	
	if (validateInput(argc, argv)) {
		Replacer replacer(argv[1], argv[2], argv[3]);
		replacer.replaceString();
	}
	return (0);
}
