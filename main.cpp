//
// main.cpp for 201yams in /home/scutar_n/rendu/maths/201yams
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Feb 13 17:44:03 2017 Nathan Scutari
// Last update Mon Feb 13 19:03:52 2017 Nathan Scutari
//

#include <iostream>

int	parse_dice_values(std::string dice, int i)
{
  if (dice.length() != 1 || dice[0] < '0' || dice[1] > '6')
    {
      std::cerr << "Bad dice value: d" << i + 1 << ": syntax must be of the form: \"x\" where x >= 0 & <= 6" << std::endl;
      return (-1);
    }
  return (dice[0] - 48);
}

int	write_err(std::string err)
{
  std::cerr << err << std::endl;
  return (1);
}

char	*epur_str(char *str)
{
  int	space;
  int	i;
  int	y;

  space = 0;
  i = -1;
  y = -1;
  while (str[++i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  if (space)
	    {
	      str[++y] = ' ';
	      space = 0;
	    }
	  str[++y] = str[i];
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    space = 1;
	}
    }
  str[++y] = '\0';
  return (str);
}

int	get_ptr_ofs(std::string entry, int &w_end)
{
  int		i;
  std::string str[] =
    {
      "yams",
      "four",
      "three",
      "straight",
      "pair",
      "full"
    };
  i = -1;
  while (++i < 6)
    {
      if (entry.find(str[i]) == 0)
	{
	  w_end = str[i].size();
	  return (i);
	}
    }
  std::cerr << "Combination not known, use \"./201yams -h\" for help" << std::endl;
  return (-1);
}

int	get_arg(std::string entry, int arg_pos, int &arg1, int &arg2)
{
  if (entry[arg_pos] != '_' || entry[arg_pos + 1] < '1' || entry[arg_pos + 1] > '6')
    return (write_err("Bad combination : must be \"_x\" where x >= 1 & <= 6"));
  arg1 = entry[arg_pos + 1] - 48;
  if (entry[arg_pos - 1] == 't' && arg1 != 5 && arg1 != 6)
    return (write_err("Bad combination : straight combination only takes 5 or 6 as value"));
  if (entry[arg_pos - 1] == 'l')
    {
      if (entry[arg_pos + 2] != '_' || entry[arg_pos + 3] < '1' ||
	  entry[arg_pos + 3] > '6')
	return (write_err("Bad combination : must \"_x_y\" where x and y >= 1 & <= 6"));
      arg2 = entry[arg_pos + 3] - 48;
      arg_pos = arg_pos + 2;
    }
  if (arg_pos + 2 != entry.size())
    return (write_err("Bad combination : too much data"));
  return (0);
}

int	parse_exec(int *dice, std::string entry)
{
  /* void	(*ptr[])(int *, int) =
  {
    yams,
    four,
    three,
    straight,
    pair,
    };*/
  int	i;
  int	arg1;
  int	arg2;
  int	w_end;

  if ((i = get_ptr_ofs(entry, w_end)) == -1 ||
      get_arg(entry, w_end, arg1, arg2))
    return (1);
  /*  if (i == 5)
    full(dice, arg1, arg2);
  else
  ptr[i](dice, arg1);*/
  return (0);
}

int	parse_yams(char **av)
{
  int	i;
  int	dice[5];

  i = -1;
  while (++i < 5)
    if ((dice[i] = parse_dice_values(av[i + 1], i)) == -1)
      return (1);
  return (parse_exec(dice, epur_str(av[6])));
}

int	write_help()
{
  std::cout << "USAGE" << std::endl << "\t\t./201yams d1 d2 d3 d4 d5 c" << std::endl;
  std::cout << std::endl << "DESCRIPTION" << std::endl << "\t\td1\tvalue of the first die (0 if not thrown)" << std::endl << "\t\td2\tvalue of the second die (0 if not thrown)" << std::endl << "\t\td3\tvalue of the third die (0 if not thrown)" << std::endl << "\t\td4\tvalue of the fourth die (0 if not throw)" << std::endl << "\t\td5\tvalue of the fifth die (0 if not thrown)" << std::endl << "\t\tc\texpected combination" << std::endl;
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
    return (write_help());
  if (ac != 7 || av[1] == "" || av[2] == "" ||
      av[3] == "" || av[4] == "" || av[5] == "" ||
      av[6] == "")
    {
      write_err("Invalid argument number, use ./201yams -h for help");
      return (84);
    }
  if (parse_yams(av))
    return (84);
  return (0);
}
