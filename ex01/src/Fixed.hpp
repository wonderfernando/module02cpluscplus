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
    private:
        int                 fixed_point;
        static const int    fractional_bits = 8;
};
std::ostream &operator<<(std::ostream& os, const Fixed &other);


# endif 