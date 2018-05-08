/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:31:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/08 12:43:05 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Contact::Contact(void){
	return;
}

Contact::~Contact(void){
	return;
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

	std::cout << "First Name: ";
	std::getline (std::cin, contacts[this->ncont].first_name);
	clear_eof();
	std::cout << "Last Name: ";
	std::getline (std::cin, contacts[this->ncont].last_name);
	clear_eof();
	std::cout << "Nickname: ";
	std::getline (std::cin, contacts[this->ncont].nickname);
	clear_eof();
	std::cout << "Login: ";
	std::getline (std::cin, contacts[this->ncont].login);
	clear_eof();
	std::cout << "Postal address: ";
	std::getline (std::cin, contacts[this->ncont].postal);
	clear_eof();
	std::cout << "Email address: ";
	std::getline (std::cin, contacts[this->ncont].email);
	clear_eof();
	std::cout << "Phone number: ";
	std::getline (std::cin, contacts[this->ncont].phone);
	clear_eof();
	std::cout << "Birthday date: ";
	std::getline (std::cin, contacts[this->ncont].birthday);
	clear_eof();
	std::cout << "Favourite meal: ";
	std::getline (std::cin, contacts[this->ncont].meal);
	clear_eof();
	std::cout << "Underwear color: ";
	std::getline (std::cin, contacts[this->ncont].underwear);
	clear_eof();
	std::cout << "Darkest secret: ";
	std::getline (std::cin, contacts[this->ncont].secret);
	clear_eof();

	std::cout << std::endl;
	std::cout << "Contact addedd to Phonebook." << std::endl;
	std::cout << std::endl;
	this->ncont++;

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

	for (int i=0; i < this->ncont; i++)
	{
		std::cout << " " << i << " |";

		len = std::min(9, static_cast<int>(contacts[i].first_name.size()));
		std::cout.write(contacts[i].first_name.c_str(), len);
		if (len == 9)
			std::cout << ".|";
		else
			std::cout << std::string(9 - len, ' ') << "|";

		len = std::min(9, static_cast<int>(contacts[i].last_name.size()));
		std::cout.write(contacts[i].last_name.c_str(), len);
		if (len == 9)
			std::cout << ".|";
		else
			std::cout << std::string(9 - len, ' ') << "|";

		len = std::min(9, static_cast<int>(contacts[i].nickname.size()));
		std::cout.write(contacts[i].nickname.c_str(), len);
		if (len == 9)
			std::cout << ".|";
		else
			std::cout << std::string(9 - len, ' ') << "|";

		std::cout << std::endl;
	}
}

int		Phonebook::SELECT(int index) {
	if (index < 0 || index >= this->ncont)
	{
		std::cout << "Invalid index." << std::endl;
		return 1;
	}

	contacts[index].printme();
	return 0;
}

void	Phonebook::test(void)
{
	if(this->ncont > 4)
		return;
	contacts[this->ncont].first_name = "LOOL";
	contacts[this->ncont].last_name = "OLO";
	contacts[this->ncont].nickname = "lolol";
	contacts[this->ncont].login = "lol";
	contacts[this->ncont].postal = "1516171819";
	contacts[this->ncont].email = "lol@lol.lol";
	contacts[this->ncont].phone = "1019101";
	contacts[this->ncont].birthday = "10/10/101";
	contacts[this->ncont].meal = "loL";
	contacts[this->ncont].underwear = "lOL";
	contacts[this->ncont].secret = "lolololololololololololololololol";
	this->ncont++;
	contacts[this->ncont].first_name = "Sudo";
	contacts[this->ncont].last_name = "Saudo";
	contacts[this->ncont].nickname = "sudo";
	contacts[this->ncont].login = "sudo";
	contacts[this->ncont].postal = "root";
	contacts[this->ncont].email = "sudo@root.local";
	contacts[this->ncont].phone = "0";
	contacts[this->ncont].birthday = "1974";
	contacts[this->ncont].meal = "sandwitch";
	contacts[this->ncont].underwear = "red";
	contacts[this->ncont].secret = "all yours";
	this->ncont++;
	contacts[this->ncont].first_name = "aaaaaa";
	contacts[this->ncont].last_name = "eeee";
	contacts[this->ncont].nickname = "iiiiii";
	contacts[this->ncont].login = "oooooooo";
	contacts[this->ncont].postal = "uuuuuu";
	contacts[this->ncont].email = "kkkkk";
	contacts[this->ncont].phone = "jjjjjj";
	contacts[this->ncont].birthday = "llllll";
	contacts[this->ncont].meal = "mmmmmm";
	contacts[this->ncont].underwear = "uuuuuu";
	contacts[this->ncont].secret = "wwwwwwww";
	this->ncont++;
}
