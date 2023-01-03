/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:42:03 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/02 20:16:45 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(int args, char* filename, std::string str1, std::string str2) :
	_args(args),
	_filename(filename),
	_str1(str1),
	_str2(str2) {
	if (this->validateInput())
		this->replaceString();
}

Replacer::~Replacer( void ) {}

bool Replacer::printError(const char* error) {
	std::cerr << error << std::endl;
	return (false);
}

bool Replacer::validateInput(void)
{
	std::fstream file;

	if (this->_args != 4) {
		printError(INPUT_ERROR);
		return(printError(WRONG_ARGUMENTS));
	}
	file.open(this->_filename);
	if (!file)
		return (printError(FILE_ERROR));
	file.close();
	if (this->_str1.empty() && this->_str2.empty())
		return (printError(EMPTY_STRINGS));
	return (true);
}

void Replacer::replaceString( void ) {
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;
	std::string		tmp;
	size_t			str_pos;

	ifs.open(this->_filename);
	ofs.open(std::string(this->_filename).append(".replace").c_str());
	while(std::getline(ifs, line)) {
		while (line.find(_str1) != std::string::npos) {
			str_pos = line.find(_str1);
			tmp.append(line.substr(0, str_pos));
			tmp.append(_str2);
			line = line.substr(str_pos + _str1.size(), line.size());
		}
		tmp.append(line).push_back('\n');
	}
	ofs << tmp;
	ofs.close();
	ifs.close();
}
