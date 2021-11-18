/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:08:59 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 06:56:39 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
    : name_("Form"),
      signed_(false),
      exec_grade_(Form::LOWEST_GRADE_),
      sign_grade_(Form::LOWEST_GRADE_),
      target_("") {
    this->checkGrade(sign_grade_);
    this->checkGrade(exec_grade_);
}

Form::Form(std::string const& name, int grade_sign, int grade_exec)
    : name_(name),
      signed_(false),
      exec_grade_(grade_exec),
      sign_grade_(grade_sign),
      target_("") {
    this->checkGrade(grade_sign);
    this->checkGrade(grade_exec);
}

Form::Form(std::string const& name, int grade_sign, int grade_exec,
           std::string const& target)
    : name_(name),
      signed_(false),
      exec_grade_(grade_exec),
      sign_grade_(grade_sign),
      target_(target) {
    this->checkGrade(grade_sign);
    this->checkGrade(grade_exec);
}

Form::Form(Form const& src)
    : name_(src.getName()),
      signed_(src.getSigned()),
      exec_grade_(src.getExecGrade()),
      sign_grade_(src.getSignGrade()),
      target_(src.getTarget()) {}

Form::~Form() {}

Form& Form::operator=(Form const& rhs) {
    if (this != &rhs) {
        this->signed_ = rhs.getSigned();
    }
    return *this;
}

std::string const Form::getName() const { return this->name_; }
bool Form::getSigned() const { return this->signed_; }
int Form::getSignGrade() const { return this->sign_grade_; }
int Form::getExecGrade() const { return this->exec_grade_; }
std::string const Form::getTarget() const { return this->target_; }

void Form::beSigned(Bureaucrat const& src) {
    if (src.getGrade() > this->sign_grade_) {
        throw Form::GradeTooLowException();
    }
    this->setSigned(true);
}

void Form::execute(Bureaucrat const& executer) const {
    if (this->getSigned() == false) {
        throw Form::NotSignedException();
    }
    if (executer.getGrade() > this->getExecGrade()) {
        throw Form::GradeTooLowException();
    }
    this->action();
}

void Form::setSigned(bool sign) { this->signed_ = sign; }

void Form::checkGrade(int grade) const {
    if (grade > Form::LOWEST_GRADE_) {
        throw Form::GradeTooLowException();
    }
    if (grade < Form::HIGHEST_GRADE_) {
        throw Form::GradeTooHighException();
    }
}

char const* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high for form";
}

char const* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low for form";
}

char const* Form::NotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& ostream, Form const& rhs) {
    ostream << "Form " << rhs.getName() << " ";
    ostream << (rhs.getSigned() ? "" : "not ");
    ostream << "signed";
    ostream << " (Sign grade: " << rhs.getSignGrade();
    ostream << ", Execute grade: " << rhs.getExecGrade();
    ostream << ")" << std::endl;
    return ostream;
}
