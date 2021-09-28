GNL1_PATH = ./GNLinked
GNL2_PATH = ../GNL				#put here the path for our GNL
SRC_GET = get_next_line.c get_next_line_utils.c
NAME = libgnl.a
NAME2 = libgnl2.a
OBJS_GET = $(SRC_GET:.c=.o)
PATH_BENCH = ./benchmark/
PATH_UTILS = ./utils/
SRC_BENCH = main.c $(PATH_BENCH)bench_time.c $(PATH_BENCH)bench_print.c \
			$(PATH_UTILS)ft_utils_function.c \
			$(PATH_UTILS)write_file.c $(PATH_UTILS)color.c


b: bench-start  $(NAME) $(NAME2) $(SRC_BENCH)
	@gcc -I $(GNL1_PATH) $(SRC_BENCH) $(NAME) -D BUFFER_SIZE=1 -D GNL=0 && ./a.out
	@gcc -I $(GNL1_PATH) $(SRC_BENCH) $(NAME) -D BUFFER_SIZE=5 -D GNL=1 && ./a.out
	@gcc -I $(GNL1_PATH) $(SRC_BENCH) $(NAME) -D BUFFER_SIZE=42 -D GNL=2 && ./a.out
	@gcc -I $(GNL1_PATH) $(SRC_BENCH) $(NAME) -D BUFFER_SIZE=10000000 -D GNL=3 && ./a.out
	@gcc -I $(GNL2_PATH) $(SRC_BENCH) $(NAME2) -D BUFFER_SIZE=1 -D GNL=4 && ./a.out
	@gcc -I $(GNL2_PATH) $(SRC_BENCH) $(NAME2) -D BUFFER_SIZE=5 -D GNL=5 && ./a.out
	@gcc -I $(GNL2_PATH) $(SRC_BENCH) $(NAME2) -D BUFFER_SIZE=42 -D GNL=6 && ./a.out
	@gcc -I $(GNL2_PATH) $(SRC_BENCH) $(NAME2) -D BUFFER_SIZE=10000000 -D GNL=7 && ./a.out &&  gcc -I $(GNL1_PATH) $(SRC_BENCH) $(NAME) -D GNL=-1 -o run_bench && ./run_bench | awk '{if (system("sleep .1 && exit 2") != 2) exit; print}'
	@make clean


$(NAME):
	@cd $(GNL1_PATH) && gcc -c $(SRC_GET) && ar rcs $(NAME) $(OBJS_GET) && rm $(OBJS_GET) && mv $(NAME) $(PWD)

$(NAME2):
	@cd $(GNL2_PATH) && gcc -c $(SRC_GET) && ar rcs $(NAME2) $(OBJS_GET) && rm $(OBJS_GET) && mv $(NAME2) $(PWD)

bench-start:
	@tput setaf 3 && echo [bench_mark]

reset:
	@cd ./outputs && rm -f *

clean: 
	@rm -f $(NAME) $(NAME2)

.PHONY: all reset b  bench-start clean