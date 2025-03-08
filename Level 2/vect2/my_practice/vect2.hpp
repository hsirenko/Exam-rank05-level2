#include <iostream>

class vect2 {
    private: 
        int x;
        int y;
    public:
        vect2() : x(0), y(0) {};
        vect2(int x, int y) : x(x), y(y) {};
        vect2(const vect2& src) : x(src.x), y(src.y) {};

        vect2& operator=(const vect2& src)
        {
            if (*this != src)
            {
                x = src.x;
                y = src.y;
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const vect2& v)
        {
            os << "{" << v[0] << ", " << v[1] << "}";
            return os;
        }

        int& operator[](int i)
        {
            return (i == 0 ? x : y);
        }

        int operator[](int i) const
        {
            return (i == 0 ? x : y);
        }

        vect2 operator--(int)
        {
            vect2 temp = *this;
            x--;
            y--;
            return temp;
        }

        vect2& operator--()
        {
            x--;
            y--;
            return *this;
        }

        vect2 operator++(int)
        {
            vect2 temp = *this;
            x++;
            y++;
            return temp;
        }

        vect2& operator++()
        {
            x++;
            y++;
            return *this;
        }

        vect2 operator+(const vect2& src) const //
        {
            return vect2(x + src.x, y + src.y);
        }

        vect2 operator-(const vect2& src) const //
        {
            return vect2(x - src.x, y - src.y);
        }

        vect2 operator*(int s) const //
        {
            return vect2(s * x, s * y);
        }

        vect2 operator-()
        {
            return vect2(-x, -y);
        }

        vect2& operator+=(const vect2& src)
        {
            x += src.x;
            y += src.y;

            return *this;
        }

        vect2& operator-=(const vect2& src)
        {
            x -= src.x;
            y -= src.y;

           return *this;
        }

        friend vect2 operator*(int s, const vect2& src)
        {
            return vect2(src.x * s, src.y * s);
        }

        vect2& operator*=(int s)
        {
            x *= s;
            y *= s;

            return *this;
        }

        bool operator==(const vect2 &src)
        {
            return (x == src.x && y == src.y);
        }

        bool operator!=(const vect2 &src)
        {
            return !(x == src.x && y == src.y);
        }
};



//15
// by val: * + - ++ -- -v
// by ref: += -= *= ++ -- 
// by val: * + - ++ -- -v
// by ref: += -= *= ++ -- 

//8 to go