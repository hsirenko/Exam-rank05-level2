#include <iostream>
#include <algorithm>
#include <string>

class bigint
{
    private:
        std::string num;
        void remove_preceeding_zeros()
        {
            size_t i = 0;
            while (i < num.size() - 1 && num[i] == '0')
                i++;
            if (i > 0)
                num = num.substr(i);
        }
    public:
        bigint() : num("0") {}
        bigint(size_t n) : num(std::to_string(n)) {}
        bigint(const bigint& src) : num(src.num) {}
        bigint &operator=(const bigint& src)
        {
            if (*this != src)
                num = src.num;
            return *this;
        }

        bigint(const std::string& n)
        {
            if (n.empty() || !std::all_of(n.begin(), n.end(), ::isdigit))
                num = "0";
            else 
            {
                num = n;
                remove_preceeding_zeros();   
            }
        }

        std::string add_strings(const std::string& n1, const std::string& n2) const
        {
            std::string result;
            int carry = 0, i = n1.size() - 1, j = n2.size() - 1;
            while (i >= 0 || j >= 0 || carry)
            {
                int sum = (i >= 0 ? n1[i--] - '0' : 0) + (j >= 0 ? n2[j--] - '0' : 0) + carry;
                result.push_back(sum % 10 + '0');
                sum = carry / 10;
            }
            std::reverse(result.begin(), result.end());
            return result;
        }

        friend std::ostream& operator<<(std::ostream& os, const bigint& b)
        {
            return os << b.num;
        }

        bigint operator-(const bigint& src) const
        {
            (void) src;
            return bigint();
        }

        bigint operator+(const bigint& src) const
        {
            bigint result(add_strings(num, src.num));
            result.remove_preceeding_zeros();
            return result;
        }

        bigint& operator+=(const bigint& src)
        {
            *this = add_strings(num, src.num);
            remove_preceeding_zeros();
            return *this;
        }

        bigint operator++(int)
        {
            bigint tmp = *this;
            ++(*this);
            return tmp;
        }

        bigint& operator++()
        {
            return *this += bigint(1);
        }

        bigint operator<<(size_t shift) const
        {
            return bigint(num + std::string(shift, '0'));
        }

        bigint& operator<<=(size_t shift)
        {
            num += std::string(shift, '0');
            return *this;
        }

        bigint& operator>>=(const bigint& b)
        {
            if (bigint(num.size()) <= b)
                num = "0";
            else 
            {
                bigint i(0);
                while (i < b)
                {
                    num = num.substr(0, num.size() - 1);
                    ++i;
                }
            }
            return *this;
        }

        bool operator<(const bigint& src) const
        {
            if (num.size() < src.num.size())
                return 1;
            else if (num.size() > src.num.size())
                return 0;
            else
                return (num < src.num);
        }

        bool operator>(const bigint& src) const
        {
            return !(*this < src || *this == src);
        }

        bool operator>=(const bigint& src) const
        {
            return !(*this < src || *this == src);
        }

        bool operator<=(const bigint& src) const
        {
            return !(*this > src || *this == src);
        }

        bool operator==(const bigint& src) const
        {
            return (num == src.num);
        }

        bool operator!=(const bigint& src) const
        {
            return !(num == src.num);
        }
};