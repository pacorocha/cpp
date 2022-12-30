/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:42:16 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/29 23:21:49 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
#define REPLACER_H

#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Replacer
{
public:
    Replacer( char* filename, std::string str1, std::string str2 );
    ~Replacer( void );

	void	replaceString( void );
	int		countReps(std::string& needle, std::string& haystack);

private:
	char*		_filename;
	std::string	_str1;
	std::string	_str2;
};

#endif