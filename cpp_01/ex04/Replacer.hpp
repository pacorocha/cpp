/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:42:16 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/05 17:26:51 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
#define REPLACER_H

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#define INPUT_ERROR "Type: ./sifl \"filename\" \"string 1\" \"string 2\""
#define WRONG_ARGUMENTS "ERROR: must type at least 3 arguments."
#define FILE_ERROR "ERROR: Input file does not exist."
#define FILE_EMPTY "ERROR: Input file is empty"
#define EMPTY_STRINGS "ERROR: Both strings can't be empty."
#define	EMPTY_ORIGINAL_STRING "ERROR: String to be replaced can't be empty."

class Replacer
{
public:
    Replacer(char* filename, std::string str1, std::string str2);
    ~Replacer( void );

	void	replaceString( void );
	int		countReps(std::string& needle, std::string& haystack);

private:
	char*		_filename;
	std::string	_str1;
	std::string	_str2;
};

#endif
