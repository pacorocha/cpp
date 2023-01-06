/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:29:18 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/06 17:40:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#pragma once

#include <iostream>
#include <string>

class Harl
{

public:
    Harl(void);
    ~Harl(void);

	void complain(std::string level);

private:
	static std::string	levels[4];
	
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
};

typedef void (Harl::*complains)();

#endif
