/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:42:03 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/06 02:56:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(char* filename, std::string str1, std::string str2) :
	_filename(filename),
	_str1(str1),
	_str2(str2) {}

Replacer::~Replacer( void ) {}

void Replacer::replaceString( void ) {
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;
	std::string		tmp;
	size_t			str_pos;

	ifs.open(this->_filename, std::ios_base::in);
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
