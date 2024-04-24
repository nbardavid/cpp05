/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.Class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:30:13 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 13:35:08 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_CLASS_HPP
# define PRESIDENTIAL_CLASS_HPP

#include "Form.Class.hpp"

class PresidentialPardonForm:public Aform {
public:
    PresidentialPardonForm();
	PresidentialPardonForm(const std::string &name);
    PresidentialPardonForm(const PresidentialPardonForm& other);
	virtual	~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	void execute(Bureaucrat const & executor);
	std::string getTarget() const;
private:
	const std::string _target;
};

#endif
