/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.Class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:18:15 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 12:47:26 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
#define BUREAUCRAT_CLASS_HPP

#include <string>
#include <exception>

class Aform;

class Bureaucrat {
public:
    Bureaucrat();
	Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);
	std::string getName() const;
	int getGrade() const;
	void Incremente();
	void Decremente();
	void signForm(Aform& f);
private:
	const std::string _name;
	int _grade;
};

class GradeTooHighException:public std::exception{
public:
	const char *what() const throw();
};

class GradeTooLowException:public std::exception{
public:
	const char *what() const throw();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
