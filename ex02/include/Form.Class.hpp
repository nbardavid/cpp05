/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:21:41 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 13:04:17 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

#include "Bureaucrat.Class.hpp"

class Aform {
public:
    Aform();
	Aform(std::string name, int gradeToSign, int gradeToExecute);
    Aform(const Aform& other);
    ~Aform();
    Aform& operator=(const Aform& other);
	void beSigned(const Bureaucrat& b);
	virtual void execute(const Bureaucrat& b) = 0; 
	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
private:
	const std::string _name;
	bool _sign;
	const int _gradeToSign;
	const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const Aform& b);

#endif
