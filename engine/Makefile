##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MODE=NORMAL

# color codes
_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

# Colors
_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m'
_IRED=$'\x1b[41m'
_IGREEN=$'\x1b[42m'
_IYELLOW=$'\x1b[43m'
_IBLUE=$'\x1b[44m'
_IPURPLE=$'\x1b[45m'
_ICYAN=$'\x1b[46m'
_IWHITE=$'\x1b[47m'

TEST_NAME	=	engine_tests

ENGINE_NAME	= starset.a

IDIR	= include/

ENGINE_DIR	= engine-src/

ENGINE_FILES	= core/calculation.c\
				  core/move_function.c\
				  core/renderer.c\
				  core/core_update.c\
				  core/read_core.c\
				  core/multithread.c\
				  core/rotation.c\
				  physics/math.c\
				  physics/collision.c\
				  physics/physics_collide.c\
				  component/terrain_scan.c\
				  creator/entities_creator.c\
				  creator/obstacle.c\
				  creator/create_component.c\
				  destroy/audio_destroy.c\
				  destroy/component_destroy.c\
				  destroy/entities_destroy.c\
				  tiny_lib/buffer.c\
				  tiny_lib/converter.c\
				  tiny_lib/gather.c\
				  tiny_lib/output.c\
				  tiny_lib/special.c


TEST	 = tests/test.c

FLAGS	+=-I $(IDIR) -Wall -Wextra -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g3

ENGINE		= $(addprefix $(ENGINE_DIR), $(ENGINE_FILES))

OBJS		= $(ENGINE:.c=.o)

engine: $(ENGINE_NAME)

$(ENGINE_NAME): $(OBJS)
		@ar rc $(ENGINE_NAME) $(OBJS)
		@echo -e "${_END}${_BOLD}${_UNDER}${_IGREY} \033[5m ] starset engine compilation complete ! [ ${_END}"

ifeq ($(MODE),DEBUG)
	@FLAGS+=-g3
else ifeq ($(MODE),SANITIZE)
	@FLAGS+=-g3 -fsanatize-adress
endif

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@printf "${_BOLD}${_YELLOW}# [ ENGINE STARTING.. ] ${END}${_GREY} % 31s${END}\n" $<

clean:
	@echo -e "${_BOLD}${_IRED}removing compilation files !${_END}"
	@rm -f $(OBJS) *.gcda *.gcno
	@rm -f $(ENGINE_NAME)
 
tests_run: fclean all
	@gcc -o $(TEST_NAME) $(TEST) $(LIB_NAME) $(CFLAGS) --coverage -lcriterion
	@echo -e "${_BOLD}${_IGREEN}program test compiled !${_END}\n"
	./$(TEST_NAME)
	@make clean

re:	fclean all

.PHONY: all clean fclean re
