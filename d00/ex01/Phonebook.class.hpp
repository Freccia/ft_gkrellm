/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:21:56 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/08 16:29:46 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <iomanip>

class	Contact {

public:
	Contact(void);
	~Contact(void);
	void	printme(void);
	void	clear_eof(void);
	void	ADD(void);
	std::string getFirstname(void);
	std::string getLastname(void);
	std::string getNickname(void);
	void	test1(void);
	void	test2(void);
	void	test3(void);

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal;
	std::string email;
	std::string phone;
	std::string birthday;
	std::string meal;
	std::string underwear;
	std::string secret;
};

class Phonebook {

public:
	Phonebook(void);
	~Phonebook(void);
	Contact contacts[8];
	void	clear_eof(void);
	int		ncont;
	void	SEARCH(void);
	int		ADD(void);
	int		SELECT(int index);
	void	test(void);
};

#endif
