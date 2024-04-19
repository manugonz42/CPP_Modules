#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j = -1;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (!argv || !argv[1])
		return 0;
	while (argv[++j])
	{
		i = -1;
		while(j > 0 && argv[j][++i])
			std::cout << (char)std::toupper(argv[j][i]);
	}
	std::cout << std::endl;
	return 0;
}