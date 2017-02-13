//
// combinaisons.cpp for Project-Master in /home/veyssi_b/rendu/tek2/Math/201yams
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb 13 17:43:46 2017 Baptiste Veyssiere
// Last update Mon Feb 13 19:36:22 2017 Baptiste Veyssiere
//

#include <math.h>
#include <iostream>
#include <iomanip>

int	Cp(int p, int k)
{
  int	tab[6][6] =
    {
      {1, 0, 0, 0, 0, 0},
      {1, 1, 0, 0, 0, 0},
      {1, 2, 1, 0, 0, 0},
      {1, 3, 3, 1, 0, 0},
      {1, 4, 6, 4, 1, 0},
      {1, 5, 10, 10, 5, 1}
    };

  return (tab[p][k]);
}

int	factoriel(int nbr)
{
  int	res;

  res = 1;
  for (int i = 2; i <= nbr; i++)
    res *= i;
  return (res);
}

void	pair(int dices[5], int nbr)
{
  int	n;
  int	p;
  double	proba;

  n = 2;
  p = 5;
  for (int i = 0; i < 5; i++)
    if (dices[i] == nbr)
      {
	--n;
	--p;
      }
  if (n < 1)
    proba = 100.0;
  else
    {
      proba = 0.0;
      for (int k = n; k <= p; k++)
	proba += Cp(p, k) * pow((double)1 / 6, k) * pow((1 - ((double)1 / 6)), (p - k));
      proba *= 100;
    }
  std::cout << "chances to get a " << nbr << " pair: " << std::fixed << std::setprecision(2) << proba << "%" << std::endl;
}

void	three(int dices[5], int nbr)
{
  int	n;
  int	p;
  double	proba;

  n = 3;
  p = 5;
  for (int i = 0; i < 5; i++)
    if (dices[i] == nbr)
      {
	--n;
	--p;
      }
  if (n < 1)
    proba = 100.0;
  else
    {
      proba = 0.0;
      for (int k = n; k <= p; k++)
	proba += Cp(p, k) * pow((double)1 / 6, k) * pow((1 - ((double)1 / 6)), (p - k));
      proba *= 100;
    }
  std::cout << "chances to get a " << nbr << " three-of-a-kind: " << std::fixed << std::setprecision(2) << proba << "%" << std::endl;
}

void	four(int dices[5], int nbr)
{
  int	n;
  int	p;
  double	proba;

  n = 4;
  p = 5;
  for (int i = 0; i < 5; i++)
    if (dices[i] == nbr)
      {
	--n;
	--p;
      }
  if (n < 1)
    proba = 100.0;
  else
    {
      proba = 0.0;
      for (int k = n; k <= p; k++)
	{
	  proba += (double)Cp(p, k) * pow((double)1 / 6, k) * pow((1 - ((double)1 / 6)), (p - k));
	}
      proba *= 100;
    }
  std::cout << "chances to get a " << nbr << " four-of-a-kind: " << std::fixed << std::setprecision(2) << proba << "%" << std::endl;
}

void	yams(int dices[5], int nbr)
{
  int	n;
  int	p;
  double	proba;

  n = 5;
  p = 5;
  for (int i = 0; i < 5; i++)
    if (dices[i] == nbr)
      {
	--n;
	--p;
      }
  if (n < 1)
    proba = 100.0;
  else
    proba = pow((double)1 / 6, n);
  proba *= 100;
  std::cout << "chances to get a " << nbr << " yams: " << std::fixed << std::setprecision(2) << proba << "%" << std::endl;
}

void	straight(int dices[5], int nbr)
{
  int	n;
  int	p;
  double	proba;
  int	list[5] = {1, 2, 3, 4, 5};


  if (nbr == 6)
    list[0] = 6;
  n = 5;
  p = 5;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      if (dices[i] == list[j])
      {
	--n;
	--p;
	list[j] = 0;
      }
  if (n < 1)
    proba = 100.0;
  else
    {
      proba = factoriel(n) * pow(((double)1 / 6), n);
      proba *= 100;
    }
  std::cout << "chances to get a " << nbr << " straight: " << std::fixed << std::setprecision(2) << proba << "%" << std::endl;
}

void	full(int dices[5], int nbr1, int nbr2)
{
  int	n1;
  int	n2;
  int	p;
  double	proba;

  n1 = 3;
  n2 = 2;
  p = 5;
  for (int i = 0; i < 5; i++)
    if (dices[i] == nbr1 && n1 > 0)
      {
	--n1;
	--p;
      }
    else if (dices[i] == nbr2 && n2 > 0)
      {
	--n2;
	--p;
      }
  if (n1 == 0 && n2 == 0)
    proba = 100.00;
  else
    {
      proba = 0.00;
      proba += Cp(n1 + n2, n1) * pow(((double)1 / 6), p);
      proba *= 100;
    }
  std::cout << "chances to get a " << nbr1 << " full of " << nbr2 << ": "  << std::fixed << std::setprecision(2) << proba << "%" << std::endl;
}
