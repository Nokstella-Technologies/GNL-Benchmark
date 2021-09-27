GET_PATH = ../GNL
GET_PATH_2 = ../GNLinked
SRC_GET = get_next_line.c get_next_line_utils.c
NAME = libgnl.a
NAME2 = libgnl2.a
OBJS_GET = $(SRC_GET:.c=.o)
PATH_BENCH = ./benchmark/
PATH_UTILS = ./utils/
SRC_BENCH = main.c $(PATH_BENCH)bench_time.c $(PATH_UTILS)ft_utils_function.c \
			$(PATH_UTILS)write_file.c $(PATH_UTILS)color.c


# OBJS_GET_COMPARE = get_next_line_compare.o
# GET_PATH_COMPARE =

bench: $(NAME) $(NAME2) $(SRC_BENCH)
	make reset
	gcc -I $(GET_PATH) $(SRC_BENCH) $(NAME) -D BUFFER_SIZE=1 -D GNL=1 && ./a.out
	gcc -I $(GET_PATH) $(SRC_BENCH) $(NAME) -D BUFFER_SIZE=5 -D GNL=1 && ./a.out
	gcc -I $(GET_PATH) $(SRC_BENCH) $(NAME) -D BUFFER_SIZE=42 -D GNL=1 && ./a.out
	gcc -I $(GET_PATH) $(SRC_BENCH) $(NAME) -D BUFFER_SIZE=10000000 -D GNL=1 && ./a.out
	gcc -I $(GET_PATH_2) $(SRC_BENCH) $(NAME2) -D BUFFER_SIZE=1 -D GNL=2 && ./a.out
	gcc -I $(GET_PATH_2) $(SRC_BENCH) $(NAME2) -D BUFFER_SIZE=5 -D GNL=2 && ./a.out
	gcc -I $(GET_PATH_2) $(SRC_BENCH) $(NAME2) -D BUFFER_SIZE=42 -D GNL=2 && ./a.out
	gcc -I $(GET_PATH_2) $(SRC_BENCH) $(NAME2) -D BUFFER_SIZE=10000000 -D GNL=2 && ./a.out && make clean && bahs BenchShow.sh


$(NAME):
	cd $(GET_PATH) && gcc -c $(SRC_GET) && ar rcs $(NAME2) $(OBJS_GET) && rm $(OBJS_GET) && mv $(NAME) $(OIDPWD)

$(NAME2):
	cd $(GET_PATH_2) && gcc -c $(SRC_GET) && ar rcs $(NAME2) $(OBJS_GET) && rm $(OBJS_GET) && mv $(NAME2) $(OLDPWD)


all:
	gcc main.c libft.a -D BUFFER_SIZE=1 && ./a.out
	gcc main.c libft.a -D BUFFER_SIZE=5 && ./a.out
	gcc main.c libft.a -D BUFFER_SIZE=42 && ./a.out
	gcc main.c libft.a -D BUFFER_SIZE=10000000 && ./a.out

reset:
	cd ./outputs && rm -f *

clean: 
	rm -f $(NAME) $(NAME2) a.out
.PHONY: all bench reset