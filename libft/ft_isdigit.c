int	ft_isdigit(int c)
{
	return ((c & 0xff) >= '0' && (c & 0xff) <= '9');
}
