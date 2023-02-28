#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *s, int i, void (*ft)(T&))
{
	int j = 0;
	while (j < i)
	{
		ft(s[j]);
		j++;
	}
}

#endif