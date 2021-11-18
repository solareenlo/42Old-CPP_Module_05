/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:54:08 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/18 20:27:40 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef FORM_HPP_
#define FORM_HPP_

#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
    Form();
    Form(std::string const& name, int grade_sign, int grade_exec);
    virtual ~Form();
    Form(Form const& src);

    Form& operator=(Form const& rhs);

    std::string const getName() const;
    bool getSigned() const;
    int const getGradeRequiredToExecute() const;
    int const getGradeRequiredToSign() const;

    void beSigned(Bureaucrat const& bure);

 private:
    static const int HIGHEST_GRADE_ = 1;
    static const int LOWEST_GRADE_ = 150;

    std::string const name_;
    bool signed_;
    int const grade_required_to_execute_;
    int const grade_required_to_sign_;

    void checkGrade(int grade) const;

    class GradeTooHighException : public std::exception {
     public:
        char const* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        char const* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& ostream, Form const& rhs);

#endif  // FORM_HPP_
