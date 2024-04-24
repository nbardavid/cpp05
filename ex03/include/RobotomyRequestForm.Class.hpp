/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.Class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:06:00 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 16:09:06 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_CLASS_HPP
# define ROBOTOMY_CLASS_HPP

#include "Form.Class.hpp"

class RobotomyRequestForm:public Aform {
public:
    RobotomyRequestForm();
	RobotomyRequestForm(const std::string &name);
    RobotomyRequestForm(const RobotomyRequestForm& other);
	virtual	~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	void execute(Bureaucrat const & executor);
	std::string getTarget() const;
private:
	const std::string _target;
};

#endif
