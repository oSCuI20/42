int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	if (i == 0)
		return (i);
	while (i < size && s1[i] == s2[i])
		i++;
	return ((s1[i] & 0xff) - (s2[i] & 0xff));
}
