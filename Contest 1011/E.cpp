#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
class BigInteger
{    
    friend std::ostream& operator << (std::ostream &out, const BigInteger &num);    
    friend std::istream& operator << (std::istream &in, BigInteger &num);
     
public:    
    BigInteger(long long num = 0);
     
        // 利用表示非负整数的字符串构造对象    
        BigInteger(const std::string &numStr);
         
        BigInteger& operator = (long long num);
        // 利用表示非负整数的字符串赋值给对象    
        BigInteger& operator = (const std::string &numStr);
         
        // 加法运算    
        BigInteger operator + (const BigInteger &rhs) const;
     
        BigInteger& operator += (const BigInteger &rhs);
         
        // 减法运算，因为BigInteger只能表示非负整数，所以返回值为减法运算结果的绝对值    
        BigInteger operator - (const BigInteger &rhs) const;
         
        BigInteger& operator -= (const BigInteger &rhs);
         
        // 乘法运算    
        BigInteger operator * (const BigInteger &rhs) const;
     
        BigInteger& operator *= (const BigInteger &rhs);
         
        // 整除运算    
        BigInteger operator / (const BigInteger &rhs) const;
     
        BigInteger& operator /= (const BigInteger &rhs);
         
        // 求余运算    
        BigInteger operator % (const BigInteger &rhs) const;
     
        BigInteger& operator %= (const BigInteger &rhs);
         
        bool operator > (const BigInteger &rhs) const;
         
        bool operator >= (const BigInteger &rhs) const;
         
        bool operator < (const BigInteger &rhs) const;
         
        bool operator <= (const BigInteger &rhs) const;
         
        bool operator == (const BigInteger &rhs) const;
         
        bool operator != (const BigInteger &rhs) const;
 
// 该部分可以用pimpl惯用法进行信息隐藏
private:    
    // 该函数假设 lhs >= rhs    
    static BigInteger sub(const BigInteger &lhs, const BigInteger &rhs);
     
        // 利用长除法进行除法运算    
        static BigInteger divide(BigInteger &lhs, const BigInteger &rhs);
         
        // 去掉最高位的0    
        static void removeHighestZero(BigInteger &num);
         
        // 格式化各数位，使其符合进制    
        static void formatBits(BigInteger &num);
 
private:    
    // 采用BASE进制记录任意大小的非负整数    
    // BASE为10的指数，因乘法运算具体实现的限制，BASE的值不要超过10^4    
    static const int BASE = 10000;    
    static const int WIDTH = 4;
         
        // BASE进制各数位，从低位到高位对应数组从左到右     
        std::vector<int> m_bits;
         
};
 
std::ostream& operator << (std::ostream &out, const BigInteger &num);
 
std::istream& operator >> (std::istream &in, BigInteger &num);
 
BigInteger::BigInteger(long long num)
{    
    *this = num;
}
 
// 利用表示非负整数的字符串构造对象
BigInteger::BigInteger(const string &numStr)
{    
    *this = numStr;
}
 
BigInteger& BigInteger::operator = (long long num)
{    
    m_bits.clear();    
    do   
    {        
        m_bits.push_back(num % BASE);        
        num /= BASE;    
    } while (num > 0);    
    return *this;
}
 
// 利用表示非负整数的字符串赋值给对象
BigInteger& BigInteger::operator = (const string &numStr)
{    
    m_bits.clear();    
    int bit, len = (numStr.length() - 1) / WIDTH + 1;    
    for (int i = 0; i < len; i++)    
    {        
        int end = numStr.length() - i * WIDTH;        
        int start = max(0, end - WIDTH);            
        sscanf(numStr.substr(start, end - start).c_str(), "%d", &bit);        
        m_bits.push_back(bit);    
    }    
    return *this;
}
 
// 加法运算
BigInteger BigInteger::operator + (const BigInteger &rhs) const
{    
    BigInteger result;    
    result.m_bits.clear();
     
        for (int i = 0, carry = 0; ; i++)    
        {        
            if (i >= m_bits.size() && i >= rhs.m_bits.size() && carry == 0)            
                break;        
            int num = carry;        
            if (i < m_bits.size())            
                num += m_bits[i];        
            if (i < rhs.m_bits.size())            
                num += rhs.m_bits[i];           
            result.m_bits.push_back(num % BASE);        
            carry = num / BASE;    
        }    
        return result;
}
 
BigInteger& BigInteger::operator += (const BigInteger &rhs)
{    
    *this = *this + rhs;    
    return *this;
}
 
// 减法运算，因为BigInteger只能表示非负整数，所以返回值为减法运算结果的绝对值
BigInteger BigInteger::operator - (const BigInteger &rhs) const
{    
    // lhs > rhs， 则结果为 lhs - rhs；否则结果为 rhs - lhs    
    if (*this > rhs)        
        return sub(*this, rhs);    
    else        
        return sub(rhs, *this);
}
 
BigInteger& BigInteger::operator -= (const BigInteger &rhs)
{    
    *this = *this - rhs;    
    return *this;
}
 
// 乘法运算
BigInteger BigInteger::operator * (const BigInteger &rhs) const
{    
    BigInteger result;    
    result.m_bits.clear();    
    result.m_bits.resize(m_bits.size() + rhs.m_bits.size(), 0);
     
        for (size_t i = 0; i < m_bits.size(); i++)    
        {        
            for (size_t j = 0; j < rhs.m_bits.size(); j++)        
            {            
                // 由于int的精度限制，两者的乘积不能溢出，所以BASE的值不要超过10^4            
                int num = m_bits[i] * rhs.m_bits[j];            
                result.m_bits[i + j] += num;        
            }    
        }            
 
    formatBits(result);    
    removeHighestZero(result);    
    return result;
}
 
BigInteger& BigInteger::operator *= (const BigInteger &rhs)
{    
    *this = *this * rhs;    
    return *this;
}
 
// 整除运算
BigInteger BigInteger::operator / (const BigInteger &rhs) const
{    
    if (rhs == 0)        
        throw runtime_error("Divisor cannot be 0!");
         
        BigInteger temp = *this;    
        return divide(temp, rhs);
}
 
BigInteger& BigInteger::operator /= (const BigInteger &rhs)
{    
    *this = *this / rhs;    
    return *this;
}
 
// 求余运算
BigInteger BigInteger::operator % (const BigInteger &rhs) const
{    
    if (rhs == 0)        
        throw runtime_error("Divisor cannot be 0!");
         
        BigInteger result = *this;    
        divide(result, rhs);    
        return result;
}
 
BigInteger& BigInteger::operator %= (const BigInteger &rhs)
{    
    divide(*this, rhs);    
    return *this;
}        
 
bool BigInteger::operator > (const BigInteger &rhs) const
{    
    // 如果数位不相等    
    if (m_bits.size() != rhs.m_bits.size())        
        return m_bits.size() > rhs.m_bits.size();    
     
    // 数位相等则逐位进行比较    
    for (int i = m_bits.size() - 1; i >= 0; i--)    
    {        
        if (m_bits[i] != rhs.m_bits[i])            
            return m_bits[i] > rhs.m_bits[i];    
    }    
     
    return false;
}
 
bool BigInteger::operator >= (const BigInteger &rhs) const
{    
    return (*this > rhs || *this == rhs);
}
 
bool BigInteger::operator < (const BigInteger &rhs) const
{    
    return !(*this >= rhs);
}
 
bool BigInteger::operator <= (const BigInteger &rhs) const
{    
    return !(*this > rhs);
}
 
bool BigInteger::operator == (const BigInteger &rhs) const
{    
    return m_bits == rhs.m_bits;
}
 
bool BigInteger::operator != (const BigInteger &rhs) const
{    
    return m_bits != rhs.m_bits;
}
 
// 该函数假设 lhs >= rhsBigInteger 
BigInteger BigInteger::sub(const BigInteger &lhs, const BigInteger &rhs)
{    
    BigInteger result;    
    result.m_bits.clear();
     
        for (int i = 0, carry = 0; ; i++)    
        {        
            if (i >= lhs.m_bits.size() && i >= rhs.m_bits.size() && carry == 0)            
                break;        
            int num = carry;        
            if (i < lhs.m_bits.size())            
                num += lhs.m_bits[i];        
            if (i < rhs.m_bits.size())            
                num -= rhs.m_bits[i];        
            num += BASE;        
            result.m_bits.push_back(num % BASE);        
            carry = num / BASE - 1;    
        }
     
        removeHighestZero(result);    
        return result;
}
 
// 进行除法运算，同时求得余数
BigInteger BigInteger::divide(BigInteger &lhs, const BigInteger &rhs)
{    
    if (lhs < rhs)          
        return 0;
     
        BigInteger result;    
        // 商的最大位数    
        int maxSize = lhs.m_bits.size() - rhs.m_bits.size();        
         
        // 从最高位到最低位逐位求商的各位数值    
        BigInteger multiple, product;    
        while (lhs >= rhs)    
        {        
            multiple.m_bits.clear();        
            multiple.m_bits.resize(maxSize + 1, 0);        
            multiple.m_bits[maxSize] = 1;
            product = rhs * multiple;
                     
            while (lhs >= product)        
            {            
                lhs -= product;            
                result += multiple;        
            }        
            maxSize--;    
        }    
        return result;
}
 
// 去掉最高位的0
void BigInteger::removeHighestZero(BigInteger &num)
{    
    while (num.m_bits.size() > 1 && num.m_bits.back() == 0)        
        num.m_bits.pop_back();
}
 
// 格式化各数位，使其符合进制
void BigInteger::formatBits(BigInteger &num)
{    
    int carry = 0;    
    for (size_t i = 0; i < num.m_bits.size(); i++)    
    {        
        int temp = num.m_bits[i] + carry;        
        num.m_bits[i] = temp % BASE;        
        carry = temp / BASE;    
    }
     
        while (carry != 0)    
        {        
            num.m_bits.push_back(carry % BASE);        
            carry /= BASE;    
        }
}
 
ostream& operator << (ostream &out, const BigInteger &num)
{    
    static string format = "%0" + to_string(BigInteger::WIDTH) +"d";    
    out << num.m_bits.back();    
    for (int i = num.m_bits.size() - 2; i >= 0; i--)    
    {        
        char buf[20];        
        sprintf(buf, format.c_str(), num.m_bits[i]);        
        out << buf;    
    }    
    return out;
}
 
istream& operator >> (istream &in, BigInteger &num)
{    
    string str;    
    if (!(in >> str))        
        return in;    
    num = str;    
    return in;
}
 
class SignedBigInteger
{    
    // 用来表示整数的符号，false代表非负，true代表负数    
    // 方便进行逻辑运算    
    typedef bool Sign;
         
        friend std::ostream& operator << (std::ostream &out, const SignedBigInteger &num);    
        friend std::istream& operator << (std::istream &in, SignedBigInteger &num);
         
public:    
    SignedBigInteger(long long num = 0);
     
        // 利用表示整数的字符串构造对象，字符串首字符可以带有符号      
        SignedBigInteger(const std::string &numStr);
         
        SignedBigInteger& operator = (long long num);
         
        // 利用表示整数的字符串赋值给对象    
        SignedBigInteger& operator = (const std::string &numStr);
         
        // 相反数运算    
        SignedBigInteger operator - () const;
     
        // 加法运算    
        SignedBigInteger operator + (const SignedBigInteger &rhs) const;
     
        SignedBigInteger& operator += (const SignedBigInteger &rhs);
     
        // 减法运算    
        SignedBigInteger operator - (const SignedBigInteger &rhs) const;
         
        SignedBigInteger& operator -= (const SignedBigInteger &rhs);
        // 乘法运算    
        SignedBigInteger operator * (const SignedBigInteger &rhs) const;
     
        SignedBigInteger& operator *= (const SignedBigInteger &rhs);
         
        // 整除运算    
        SignedBigInteger operator / (const SignedBigInteger &rhs) const;
         
        SignedBigInteger& operator /= (const SignedBigInteger &rhs);
         
        // 求余运算    
        SignedBigInteger operator % (const SignedBigInteger &rhs) const;
         
    SignedBigInteger& operator %= (const SignedBigInteger &rhs);
         
        bool operator > (const SignedBigInteger &rhs) const;
         
        bool operator >= (const SignedBigInteger &rhs) const;
         
        bool operator < (const SignedBigInteger &rhs) const;
         
        bool operator <= (const SignedBigInteger &rhs) const;
         
        bool operator == (const SignedBigInteger &rhs) const;
         
        bool operator != (const SignedBigInteger &rhs) const;
 
private:    
    void initBySignedStr(char sign, const std::string &numStr);
        // 将该对象表示的-0变为非负0    
        void nonnegativeZero();
         
private:    
    BigInteger m_value;    
    // 整数的符号    
    Sign m_sign;
     
};
 
std::ostream& operator << (std::ostream &out, const SignedBigInteger &num);
 
std::istream& operator >> (std::istream &in, SignedBigInteger &num);
 
using namespace std;
 
SignedBigInteger::SignedBigInteger(long long num)
{    
    *this = num;
}
 
// 利用表示整数的字符串构造对象，字符串首字符可以带有符号
SignedBigInteger::SignedBigInteger(const string &numStr)
{    
    *this = numStr;
}
 
SignedBigInteger& SignedBigInteger::operator = (long long num)
{    
    if (num >= 0)    
    {        
        m_sign = false;        
        m_value = num;    
    }    
    else   
    {        
        m_sign = true;        
        m_value = -num;    
    }    
    return *this;
}
 
static bool isDigit(char c)
{    
    if (c >= '0' && c <= '9')        
        return true;    
    return false;
}
 
// 利用表示整数的字符串赋值给对象，并没有对输入进行检查，所以需要按要求输入
// 如"123"，"+123"，"-123"，不能是空字符串以及单个符号
SignedBigInteger& SignedBigInteger::operator = (const string &numStr)
{    
    char c = numStr[0];    
    if (isDigit(c))    
    {        
        m_sign = false;        
        m_value = numStr;    
    }    
    else   
    {        
        initBySignedStr(c, numStr.substr(1));    
    }    
    return *this;
}
 
// 相反数运算
SignedBigInteger SignedBigInteger::operator - () const
{    
    SignedBigInteger result = *this;    
    result.m_sign = !result.m_sign;    
    result.nonnegativeZero();    
    return result;
}
 
// 加法运算
SignedBigInteger SignedBigInteger::operator + (const SignedBigInteger &rhs) const
{       
    SignedBigInteger result;
        // 两者都为正    
        if (m_sign == false && rhs.m_sign == false)    
        {        
            result.m_sign = false;        
            result.m_value = m_value + rhs.m_value;    
        }    
        // 两者都为负    
        else if (m_sign == true && rhs.m_sign == true)    
        {        
            result.m_sign = true;        
            result.m_value = m_value + rhs.m_value;    
        }    
        // lhs为正，rhs为负    
        else if (m_sign == false && rhs.m_sign == true)    
        {        
            result.m_value = m_value - rhs.m_value;        
            result.m_sign = (m_value > rhs.m_value) ? false : true;    
        }    
        // lhs为负，rhs为正    
        else   
        {        
            result.m_value = rhs.m_value - m_value;        
            result.m_sign = (m_value < rhs.m_value) ? false : true;    
        }        
        return result;
}
 
SignedBigInteger& SignedBigInteger::operator += (const SignedBigInteger &rhs)
{    
    *this = *this + rhs;    
    return *this;
}
 
// 减法运算
SignedBigInteger SignedBigInteger::operator - (const SignedBigInteger &rhs) const
{    
    return *this + (- rhs);
}
 
SignedBigInteger& SignedBigInteger::operator -= (const SignedBigInteger &rhs)
{    
    *this = *this - rhs;    
    return *this;
}
 
// 乘法运算
SignedBigInteger SignedBigInteger::operator * (const SignedBigInteger &rhs) const
{    
    SignedBigInteger result;    
    result.m_value = m_value * rhs.m_value;
             
    // 两者异号    
    if (m_sign ^ rhs.m_sign)        
        result.m_sign = true;    
    // 两者同号    
    else       
        result.m_sign = false;
                 
    result.nonnegativeZero();    
    return result;
}
 
SignedBigInteger& SignedBigInteger::operator *= (const SignedBigInteger &rhs)
{    
    *this = *this * rhs;    
    return *this;
}
 
// 整除运算
SignedBigInteger SignedBigInteger::operator / (const SignedBigInteger &rhs) const
{    
    // 在BigInteger除零异常上层再加一层，隐藏BigInteger的异常    
    if (rhs == 0)        
        throw runtime_error("Divisor cannot be 0!");
         
        SignedBigInteger result;    
        result.m_value = m_value / rhs.m_value;
         
        // 两者异号    
        if (m_sign ^ rhs.m_sign)    
        {        
            result.m_sign = true;        
            result -= 1;    
        }    
        // 两者同号    
        else   
        {        
            result.m_sign = false;    
        }        
     
    result.nonnegativeZero();    
    return result;
}
 
SignedBigInteger& SignedBigInteger::operator /= (const SignedBigInteger &rhs)
{    
    *this = *this / rhs;    
    return *this;
}
 
SignedBigInteger SignedBigInteger::operator % (const SignedBigInteger &rhs) const
{    
    if (rhs == 0)        
        throw runtime_error("Divisor cannot be 0!");
     
        SignedBigInteger result;    
        result.m_sign = rhs.m_sign;     
        result.m_value = m_value % rhs.m_value;
         
        // 两者异号    
        if (m_sign ^ rhs.m_sign)        
            result.m_value = rhs.m_value - result.m_value;
     
        result.nonnegativeZero();    
        return result;
}
 
SignedBigInteger& SignedBigInteger::operator %= (const SignedBigInteger &rhs)
{    
    *this = *this % rhs;    
    return *this;
}
 
bool SignedBigInteger::operator > (const SignedBigInteger &rhs) const
{    
    // 两者符号不同    
    if (m_sign ^ rhs.m_sign)    
    {        
        return (m_sign == false) ? true : false;    
    }    
    // 两者符号相同    
    else   
    {        
        if (m_sign == false)            
            return (m_value > rhs.m_value) ? true : false;        
        else           
            return (m_value < rhs.m_value) ? true : false;    
    }
}
 
bool SignedBigInteger::operator >= (const SignedBigInteger &rhs) const
{    
    return (*this > rhs || *this == rhs);
}
 
bool SignedBigInteger::operator < (const SignedBigInteger &rhs) const
{    
    return !(*this >= rhs);
}
 
bool SignedBigInteger::operator <= (const SignedBigInteger &rhs) const
{    
    return !(*this > rhs);
}
 
bool SignedBigInteger::operator == (const SignedBigInteger &rhs) const
{    
    return (m_sign == rhs.m_sign) && (m_value == rhs.m_value);
}
 
bool SignedBigInteger::operator != (const SignedBigInteger &rhs) const
{    
    return !(*this == rhs);
}
 
void SignedBigInteger::initBySignedStr(char sign, const string &numStr)
{    
    switch (sign)    
    {    
        case '+':        
            m_sign = false;        
            m_value = numStr;        
            break;    
        case '-':        
            m_sign = true;        
            m_value = numStr;        
            break;    
        default:        
            break;    
    }    
    nonnegativeZero();
}
 
// 将该对象表示的-0变为非负0
void SignedBigInteger::nonnegativeZero()
{    
    if (m_value == 0)        
        m_sign = false;
}
 
ostream& operator << (std::ostream &out, const SignedBigInteger &num)
{    
    if (num.m_sign == true)        
        out << '-';    
    out << num.m_value;    
    return out;
}
 
istream& operator >> (std::istream &in, SignedBigInteger &num)
{    
    string str;    
    if (!(in >> str))        
        return in;    
    num = str;    
    return in;
}
 
int main(){
    int nCount;
    SignedBigInteger iCurrentVotes;
    SignedBigInteger iCurrentMax=-1;
    SignedBigInteger iCurrentMaxID=0;
    cin>>nCount;
    for (int i=1;i<=nCount;++i){
        cin>>iCurrentVotes;
        if (iCurrentVotes>iCurrentMax){
            iCurrentMaxID=i;
            iCurrentMax=iCurrentVotes;
        }
    }
    cout<<iCurrentMaxID<<endl<<iCurrentMax<<endl;
    return 0;
}