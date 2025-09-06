# ifndef FIXED_HPP
    # define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed {
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed(int integer);
        Fixed(float value);
        Fixed &operator=(const Fixed &other);

        ~Fixed();
        float toFloat() const;
        int toInt() const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );


        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed &other);
        Fixed operator-(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator/(const Fixed &other);

        Fixed operator++();
        Fixed operator++(int);

    private:
        int                 fixed_point;
        static const int    fractional_bits = 8;
};

std::ostream &operator<<(std::ostream& os, const Fixed &other);


static Fixed& min(Fixed& a, Fixed& b);

static const Fixed& min(const Fixed& a, const Fixed& b);

static Fixed& max(Fixed& a, Fixed& b);

static const Fixed& max(const Fixed& a, const Fixed& b);

# endif 