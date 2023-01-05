/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:30:07 by jfrancis          #+#    #+#             */
/*   Updated: 2023/01/05 17:30:09 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#pragma once

#include <iostream>
#include <string>

class Harl
{

	typedef void (Harl::* complainsPointer)(void) const;

public:
    Harl(void);
    ~Harl(void);

	void complain(std::string level);

private:
	static	std::string levels[4];
	static	complainsPointer complains[4];
	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;
};

#endif


