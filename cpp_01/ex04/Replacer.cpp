/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:42:03 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/29 23:21:35 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer( char* filename, std::string str1, std::string str2 ) :
	_filename(filename),
	_str1(str1),
	_str2(str2) {
	this->replaceString();
}

Replacer::~Replacer( void ) {}

void Replacer::replaceString( void ) {
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;
	size_t			str_pos;
	int				reps;

	ifs.open(this->_filename);
	ofs.open(std::string(this->_filename).append(".replace").c_str());
	while(std::getline(ifs, line)) {
		reps = countReps(this->_str1, line);
		while (reps > 0)
		{
			str_pos = line.find(this->_str1);
			if (str_pos != std::string::npos) {
				line.insert(str_pos + _str1.length(), _str2);
				line.erase(str_pos, _str1.length());
			}
			reps--;
		}
		ofs << line << std::endl;
	}
	ofs.close();
	ifs.close();
}

int Replacer::countReps(std::string& needle, std::string& haystack)
{
	int n = needle.length();
	int h = haystack.length();
	int r = 0;

	for (int i = 0; i <= h - n; i++) {
		int j;
		for (j = 0; j < n; j++)
			if (haystack[i + j] != needle[j])
				break;
		if (j == n) {
			r++;
		}
	}
	return (r);
}
