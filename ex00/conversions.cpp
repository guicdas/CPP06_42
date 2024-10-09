#include "ScalarConverter.hpp"

static int	isInt(const std::string& s)
{
	int	i;
	int	num;

	i = 0;
	if (s.length() == 0 || s.length() > 12)
		return (0);
	num = atoi(s.c_str());
	if (s[i] == '-')
	{
		if (num > 0)
			return (0);
		return (1);
	}
	if (num < 0)
		return (0);
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
        if (s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff")
            return (1);
        if ((s.length() == 1 && isprint(s[0] - 48)) || (s.length() == 3 && s[0] == '\'' && s[2] == '\''))
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

void	convertCharacter(const std::string &s){
	char	c;
	
	if (s[0] != '\'')
		c = s[0];
	else
		c = s[1];
	std::cout << "char:\t'" << c << "'" << std::endl;
	std::cout << "int:\t" << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(c) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(c) << std::endl;
}

void	convertInt(const std::string &s){
	int	num;

	num = atoi(s.c_str());
	if (isprint(num))
		std::cout << "char:\t'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char:\tNon displayable character!" << std::endl;
	std::cout << "int:\t" << num << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(num) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(num) << std::endl;
}

void	convertFloat(const std::string &s){
	float	num;

	num = strtof(s.c_str(), NULL);
	std::cout << "char:\t'" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int:\t" << static_cast<int>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(num) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double:\t" << num << std::endl;
}

void	convertDouble(const std::string &s){
	double	num;

	num = atof(s.c_str());
	std::cout << "char:\t'" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int:\t" << static_cast<int>(num) << std::endl;
	std::cout << "float:\t" << static_cast<float>(num);
	if (remainder(num, 1.0) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double:\t" << num;
	if (remainder(num, 1.0) == 0)
		std::cout << ".0";
}