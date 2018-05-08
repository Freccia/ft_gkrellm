/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:31:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/08 16:31:58 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Contact::Contact(void){
	return;
}

Contact::~Contact(void){
	return;
}

void	Contact::clear_eof(void){
	if(std::cin.eof()){
		std::cin.clear();
	}
}

std::string		Contact::getFirstname(void){
	return this->first_name;
}

std::string		Contact::getLastname(void){
	return this->last_name;
}

std::string		Contact::getNickname(void){
	return this->nickname;
}

void		Contact::ADD(){
	std::cout << "First Name: ";
	std::getline (std::cin, this->first_name);
	clear_eof();
	std::cout << "Last Name: ";
	std::getline (std::cin, this->last_name);
	clear_eof();
	std::cout << "Nickname: ";
	std::getline (std::cin, this->nickname);
	clear_eof();
	std::cout << "Login: ";
	std::getline (std::cin, this->login);
	clear_eof();
	std::cout << "Postal address: ";
	std::getline (std::cin, this->postal);
	clear_eof();
	std::cout << "Email address: ";
	std::getline (std::cin, this->email);
	clear_eof();
	std::cout << "Phone number: ";
	std::getline (std::cin, this->phone);
	clear_eof();
	std::cout << "Birthday date: ";
	std::getline (std::cin, this->birthday);
	clear_eof();
	std::cout << "Favourite meal: ";
	std::getline (std::cin, this->meal);
	clear_eof();
	std::cout << "Underwear color: ";
	std::getline (std::cin, this->underwear);
	clear_eof();
	std::cout << "Darkest secret: ";
	std::getline (std::cin, this->secret);
	clear_eof();
}

void	Contact::printme(void){
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Login: " << login << std::endl;
	std::cout << "Postal code: " << postal << std::endl;
	std::cout << "Email: " << email << std::endl;
	std::cout << "Phone: " << phone << std::endl;
	std::cout << "Birthday: " << birthday << std::endl;
	std::cout << "Favourite meal: " << meal << std::endl;
	std::cout << "Underwear color: " << underwear << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
	std::cout << std::endl;
}

void	Contact::test1(void)
{
	this->first_name = "Lady";
	this->last_name = "Oscar";
	this->nickname = "Mom";
	this->login = "ldoscar";
	this->postal = "78";
	this->email = "oscarlady@mail.com";
	this->phone = "04 55 66 883";
	this->birthday = "04/1972";
	this->meal = "rose";
	this->underwear = "white";
	this->secret = "I like gurlz";
}
void	Contact::test2(void)
{
	this->first_name = "Sudo";
	this->last_name = "Saudo";
	this->nickname = "Weed Dealer";
	this->login = "sudo";
	this->postal = "93";
	this->email = "sudo@93.fr";
	this->phone = "07 55 66 88 00";
	this->birthday = "420";
	this->meal = "pizza";
	this->underwear = "green";
	this->secret = "I sell drugz";
}
void	Contact::test3(void)
{
	this->first_name = "Paulette";
	this->last_name = "Lafont";
	this->nickname = "Mamie";
	this->login = "mamiepaulette";
	this->postal = "4040";
	this->email = "mamiepaulette@home.tk";
	this->phone = "09 88 22 33 45";
	this->birthday = "1/1/1900";
	this->meal = "cookies";
	this->underwear = "shuld not ask";
	this->secret = "My cookies's recipe";
}




Phonebook::Phonebook(void): ncont(0){
	return;
}

Phonebook::~Phonebook(void){
	return;
}

void	Phonebook::clear_eof(void){
	if(std::cin.eof()){
		std::cin.clear();
	}
}

int		Phonebook::ADD(void){
	if (this->ncont >= 8)
	{
		std::cout << "The Phonebook is full, sorry." << std::endl;
		return 1;
	}

	contacts[this->ncont].ADD();
	this->ncont++;

	std::cout << std::endl;
	std::cout << "Contact addedd to Phonebook." << std::endl;
	std::cout << std::endl;
	return 0;
}

void	Phonebook::SEARCH(){
	std::cout << " n |";
	std::cout << "first name|";
	std::cout << "last name |";
	std::cout << " nickname |" << std::endl;

	if (this->ncont <= 0)
		return;

	size_t len;
	std::string		first_name;
	std::string		last_name;
	std::string		nickname;

	for (int i=0; i < this->ncont; i++)
	{
		std::cout << " " << i << " |";

		first_name = contacts[i].getFirstname();
		len = std::min(9, static_cast<int>(first_name.size()));
		std::cout.write(first_name.c_str(), len);
		if (len == 9)
			std::cout << ".|";
		else
			std::cout << std::string(10 - len, ' ') << "|";

		last_name = contacts[i].getLastname();
		len = std::min(9, static_cast<int>(last_name.size()));
		std::cout.write(last_name.c_str(), len);
		if (len == 9)
			std::cout << ".|";
		else
			std::cout << std::string(10 - len, ' ') << "|";

		nickname = contacts[i].getNickname();
		len = std::min(9, static_cast<int>(nickname.size()));
		std::cout.write(nickname.c_str(), len);
		if (len == 9)
			std::cout << ".|";
		else
			std::cout << std::string(10 - len, ' ') << "|";

		std::cout << std::endl;
	}
}

int		Phonebook::SELECT(int index){
	if (index < 0 || index >= this->ncont)
	{
		std::cout << "Invalid index." << std::endl;
		return 1;
	}

	contacts[index].printme();
	return 0;
}

void	Phonebook::test(void){
	if (this->ncont > 4)
		return;
	contacts[this->ncont].test1();
	this->ncont++;
	contacts[this->ncont].test2();
	this->ncont++;
	contacts[this->ncont].test3();
	this->ncont++;
}
