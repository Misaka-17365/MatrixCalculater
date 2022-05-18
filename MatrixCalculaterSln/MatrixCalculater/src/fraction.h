#ifndef __FRACTION_H__
#define __FRACTION_H__

#include<iostream>

class fraction
{
private:
    int prime_number[172] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
        67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
        181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,
        311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,
        443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587,
        593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727,
        733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877,
        881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021 };
    int numerator, denominator;

public:
    // ���캯������ʼ��
    /*fraction(void)
    {
        this->numerator = 0;
        this->denominator = 1;
    }
    fraction(int nu)
    {
        this->numerator = nu;
        this->denominator = 1;
    }*/
    fraction(int nu = 0, int de = 1)
    {
        this->numerator = nu;
        this->denominator = de;
    }
    // Լ��
    void simplify()
    {
        for (int i = 0; ; )
        {
            // ��ĸ��1������Ҫ����
            if (denominator == 1)
            {
                return;
            }
            // ��ĸ��0��������
            if (denominator == 0)
            {
                std::cerr << "error" << std::endl;
            }
            // ȷ��������
            if (numerator < prime_number[i] || denominator < prime_number[i])
            {
                return;
            }
            // �����Ƿ�ɳ�
            if (numerator % prime_number[i])
            {
                i++;
                continue;
            }
            // ��ĸ�Ƿ�ɳ�
            if (denominator % prime_number[i])
            {
                i++;
                continue;
            }
            // Լ��
            numerator /= prime_number[i];
            denominator /= prime_number[i];

            if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0))
            {
                numerator = -numerator;
                denominator = -denominator;
            }
        }
    }
    // ���أ������������
    friend std::istream& operator>>(std::istream& is, fraction& fr)
    {
        char str[20];
        int position;
        bool is_fraction = false, is_decimal = false, is_negative = false;

        for (int i = 0;; i++)
        {
            // ��ȡԭʼ����
        re_get:
            std::cin.get(str[i]);
            if (str[0] == ' ' || str[0] == '\t' || str[0] == '\n')
            {
                goto re_get;
            }
            if (str[0] == '-')
            {
                is_negative = !is_negative;
                goto re_get;
            }
            if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            {
                str[i] = '\0';
                break;
            }
        }
        // ȷ������orС���Լ������ߺ�С�����λ��
        for (int i = 0; ; i++)
        {
            if (str[i] == '.')
            {
                position = i;
                is_decimal = true;
                break;
            }
            if (str[i] == '/')
            {
                position = i;
                is_fraction = true;
                break;
            }
        }
        // ��ʽ������
        if (is_fraction)
        {
            int numerator = 0, denominator = 0;

            for (int t = 0; t < position; t++)
            {
                numerator = numerator * 10 + (str[t] - '0');
            }
            for (int t = position + 1; t < strlen(str); t++)
            {
                denominator = denominator * 10 + (str[t] - '0');
            }

            fr.numerator = numerator;
            fr.denominator = denominator;
            fr.simplify();
        }
        if (is_decimal)
        {
            int int_part = 0, dec_part = 0;
            int n = 1;
            fraction tmp;
            for (int t = 0; t < position; t++)
            {
                int_part = int_part * 10 + (str[t] - '0');
            }
            for (int t = position + 1; t < strlen(str); t++)
            {
                dec_part = dec_part * 10 + (str[t] - '0');
            }
            for (int t = 0; t < strlen(str) - position - 1; t++)
            {
                n *= 10;
            }
            tmp.numerator = dec_part;
            tmp.denominator = n;
            tmp.simplify();
            fr = (fraction)int_part + tmp;
        }
        if (!is_decimal && !is_fraction)
        {
            int int_part = 0;
            for (int t = position + 1; t < strlen(str); t++)
            {
                int_part = int_part * 10 + (str[t] - '0');
            }
            fr.numerator = int_part;
            fr.denominator = 1;
        }
        if (is_negative)
        {
            fr.numerator = -fr.numerator;
        }
        fr.simplify();
        return is;
    }
    // ���أ�����������
    friend std::ostream& operator<<(std::ostream& os, fraction fr)
    {
        if (fr.denominator == 1)
        {
            std::cout << fr.numerator;
            return os;
        }
        std::cout << fr.numerator << "/" << fr.denominator;
        return os;
    }
    // ���أ��Ⱥţ�����תΪ������
    fraction operator=(int in)
    {
        this->numerator = in;
        this->denominator = 1;
        return *this;
    }
    // ǿ��ת�ͣ�double
    operator double()
    {
        return (double)this->numerator / (double)this->denominator;
    }
    // ���أ��Ⱥ�
    fraction operator=(fraction fr)
    {
        this->numerator = fr.numerator;
        this->denominator = fr.denominator;
        return *this;
    }
    // ���أ��ӷ�
    fraction operator+(fraction fr)
    {
        fraction tmp;
        tmp.numerator = this->numerator * fr.denominator + this->denominator * fr.numerator;
        tmp.denominator = this->denominator * fr.denominator;
        tmp.simplify();
        return tmp;
    }
    // ���أ�����
    fraction operator-(fraction fr)
    {
        fraction tmp;
        tmp.numerator = this->numerator * fr.denominator - this->denominator * fr.numerator;
        tmp.denominator = this->denominator * fr.denominator;
        tmp.simplify();
        return tmp;
    }
    // ���أ��˷�
    fraction operator*(fraction fr)
    {
        fraction tmp;
        tmp.numerator = this->numerator * fr.numerator;
        tmp.denominator = this->denominator * fr.denominator;
        tmp.simplify();
        return tmp;
    }
    // ���أ�����
    fraction operator/(fraction fr)
    {
        fraction tmp;
        tmp.numerator = this->numerator * fr.denominator;
        tmp.denominator = this->denominator * fr.numerator;
        tmp.simplify();
        return tmp;
    }
};

typedef fraction frac;

#endif // !__FRACTION_H__


