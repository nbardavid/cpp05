/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:21:41 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 09:44:29 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

#include "Bureaucrat.Class.hpp"

class Form {
public:
    Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    ~Form();
    Form& operator=(const Form& other);
	void beSigned(const Bureaucrat& b);
	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
private:
	const std::string _name;
	bool _sign;
	const int _gradeToSign;
	const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& b);

#endif
