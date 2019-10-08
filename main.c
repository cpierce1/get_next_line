#include "get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>

int main (){
	int file = open("./file", O_RDONLY);
	char **data = (char**)malloc(sizeof(char*)*1024);
	int i = 0;
	get_next_line(file, &data[i]);
	while (ft_strlen(data[i]) > 0){
		ft_putstr(data[i]);
		i++;
		get_next_line(file, &data[i]);
	}
	return 0;
}
