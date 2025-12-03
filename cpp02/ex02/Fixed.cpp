#include "Fixed.hpp"

/* CONSTRCUTOR */
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value * (1 << this->frac_bit);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int>(roundf(value * (1 << this->frac_bit)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/* ---FUNCTIONS--- */

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
};

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float   Fixed::toFloat(void) const
{
    return static_cast<float>(this->value) / (1 << this->frac_bit);
}

int Fixed::toInt(void) const
{
    return (this->value / (1 << this->frac_bit));
}

/* ---OVERLOAD--- */

std::ostream    &operator<<(std::ostream &os, const Fixed &c)
{
    os << c.toFloat();
    return (os);
}

bool    Fixed::operator<(const Fixed &f) const
{
    return (this->toFloat() < f.toFloat());
}

bool    Fixed::operator>(const Fixed &f) const
{
    return (this->toFloat() > f.toFloat());
}

bool    Fixed::operator<=(const Fixed &f) const
{
    return (this->toFloat() <= f.toFloat());
}

bool    Fixed::operator>=(const Fixed &f) const
{
    return (this->toFloat() >= f.toFloat());
}

bool    Fixed::operator==(const Fixed &f) const
{
    return (this->toFloat() == f.toFloat());
}

bool    Fixed::operator!=(const Fixed &f) const
{
    return (this->toFloat() != f.toFloat());
}

Fixed Fixed::operator-(const Fixed &f)
{
    return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator+(const Fixed &f)
{
    return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator*(const Fixed &f)
{
    return Fixed(this->toFloat() * f.toFloat());
}

Fixed &Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignement operator called" << std::endl;
	if (this != &f)
		this->value = f.getRawBits();
	return (*this);
}

Fixed &Fixed::operator++(void)
{
    ++this->value;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    --this->value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed copy(*this);
    this->value++;
    return (copy);
}

Fixed Fixed::operator--(int)
{
    Fixed copy(*this);
    this->value--;
    return (copy);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 > f2)
        return (f2);
    else
        return (f1);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1 > f2)
        return (f2);
    else
        return (f1);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1 < f2)
        return (f2);
    else
        return (f1);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1 < f2)
        return (f2);
    else
        return (f1);
}


