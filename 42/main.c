#include "libft.h"
#include "ft_printf.h"

int main(void)
{

    char * ptr= "Hola mundo!";
    ft_printf("Hola mundo!");
    ft_printf("Valor: %lu\n", ft_strlen(ptr));
    return (0);
}