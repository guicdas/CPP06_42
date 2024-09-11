#include "ScalarConverter.hpp"

static int	isException(const std::string& s)
{
	if (s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff")
		return (1);
	return (0);
}

static int	isChar(const std::string& s)
{
	if (s.length() == 1 && !isdigit(s[0]))
		return (1);
	//if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
		//return (1);
	return (0);
}

static int	isInt(const std::string& s)
{
	int		i;

	i = 0;
	if (s.length() == 0 && s.length() > 12)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	else
	{
		if (s.length() > 11)
			return (0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	isFloat(const std::string& s, size_t& dot)
{
	for (int i = dot - 1; i >= 0; i--)
	{
		if ((s[i] < '0' || s[i] > '9') && i != 0)
			return (0);
		if ((s[i] < '0' || s[i] > '9') && i == 0 && s[i] != '+' && s[i] != '-')
			return (0);
	}
	for (size_t i = dot + 1; i < s.length() ; i++)
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != 'f')
			return (0);
		if (s[i] == 'f' && i != s.length() - 1)
			return (0);
	}
	return (1);
}

int  whichType(const std::string& s)
{
    size_t  dot = s.find('.');
    size_t  f = s.find('f');
    if (dot == std::string::npos)
    {
        if (isException(s))
            return (1);
        if (isChar(s))
            return (2);
        if (isInt(s))
            return (3);
    }
    if (f != std::string::npos && dot != std::string::npos)
    {
        if (isFloat(s, dot))
        return (4);
    }
    else if (f == std::string::npos && dot != std::string::npos)
        return (5);
    return (0);
}

void	convertToCharacter(const std::string &s){
	char	c;
	
	c = 0;
	if (s.length() == 1)
		c = s[0];
	else
		c = s[1];
	if (c > 32 || c < 127)
	{
		std::cout << "'" << c << "'" << std::endl;
		std::cout << "int:\t" << static_cast<int>(c);
		std::cout << "\nfloat:\t" << static_cast<float>(c) << ".0";
		std::cout << "\ndouble:\t" << static_cast<double>(c) << ".0\n";
	}
	else
		std::cout << "Couldn't display character!\n" << std::endl;
}

void	convertToInt(const std::string &s){
(void)s;
}

void	convertToFloat(const std::string &s){
(void)s;
}

void	convertToDouble(const std::string &s){
(void)s;
}