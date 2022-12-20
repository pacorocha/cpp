/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:26:40 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/19 22:33:25 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact
{
public:
	Contact( void );
	~Contact();

	void	setId( int id );
	void	setFirstName( void );
	void	setLastName( void );
	void	setNickName( void );
	void	setPhoneNumber( void );
	void	setDarkestSecret( void );

	int			getId()	const;
	std::string	getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickname( void ) const;
	bool		isAlphabetic( std::string &str );
	std::string	getAlphaVar( std::string varname );
	bool		checkEmptyString(std::string str);

private:
	int			_id;
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif