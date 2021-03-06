/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:54:34 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 06:53:34 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

char const* PresidentialPardonForm::FORM_NAME_ = "Presidential";

PresidentialPardonForm::PresidentialPardonForm()
    : Form(this->FORM_NAME_, this->SIGN_GRADE_, this->EXEC_GRADE_) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : Form(this->FORM_NAME_, this->SIGN_GRADE_, this->EXEC_GRADE_, target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const& src)
    : Form(src) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& rhs) {
    if (this != &rhs) {
        Form::operator=(rhs);
    }
    return *this;
}

void PresidentialPardonForm::action() const {
    std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox"
              << std::endl;
}
