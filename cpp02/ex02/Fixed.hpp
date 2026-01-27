# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <math.h>

class Fixed
{
    private:
        int value;
        static const int frac_bit = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int value);
        Fixed(const float value);

        bool operator<(const Fixed &fixed) const;
        bool operator>(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;

        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator+(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;

        Fixed &operator=(const Fixed &fixed);

        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);

        static  Fixed &min(Fixed &f1, Fixed &f2);
        static  const Fixed &min(const Fixed &f1, const Fixed &f2);
        static  Fixed &max(Fixed &f1, Fixed &f2);
        static  const Fixed &max(const Fixed &f1, const Fixed &f2);
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream    &operator<<(std::ostream &os, const Fixed &c);
# endif