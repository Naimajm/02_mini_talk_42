# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 13:46:22 by juagomez          #+#    #+#              #
#    Updated: 2024/11/20 13:47:02 by juagomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ARCHIVO MAKEFILE BASICO + BONUS PROYECTO 42 "PUSH_SWAP" -----------------------

# INTERFAZ GRAFICA -----------------------------------------
# ---------------------------------------------------
DEL_LINE            = \033[2K
ITALIC              = \033[3m
BOLD                = \033[1m
DEF_COLOR           = \033[0;39m
GRAY                = \033[0;90m
RED                 = \033[0;91m
GREEN               = \033[0;92m  
YELLOW              = \033[0;93m
BLUE                = \033[0;94m
MAGENTA             = \033[0;95m
CYAN                = \033[0;96m
WHITE               = \033[0;97m
BLACK               = \033[0;99m
ORANGE              = \033[38;5;209m
BROWN               = \033[38;2;184;143;29m
DARK_GRAY           = \033[38;5;234m
MID_GRAY            = \033[38;5;245m
DARK_GREEN          = \033[38;2;75;179;82m
DARK_YELLOW         = \033[38;5;143m

# NOMBRES -----------------------------------------
# ---------------------------------------------------

# NOMBRE SALIDA ARCHIVO COMPILADO
LIBRARY := push_swap.a
NAME := push_swap 

CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE_LIBRARY := ar -rcs # COMPRESION A 1 ARCHIVO -> LIBRERIAS .a
#$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 

# DIRECTORIOS -----------------------------------------
# ---------------------------------------------------
LIBFT_DIR := ./libft
LIBFT_ARCHIVE := libft.a

NAME_BONUS = checker
BONUS_DIR := ./bonus

# RECURSOS -----------------------------------------
# ---------------------------------------------------
# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA
SRC := init_split.c init_stack.c init_stack_utils.c \
	command_push.c command_rotate.c command_reverse_rotate.c command_swap.c \
	sort.c sort_node_init.c sort_node_move.c \
	main_push_swap.c main.c \

OBJ_FILES := $(SRC:%.c=%.o) # LISTA ARCHIVOS .O SEGUN ARCHIVO C

# RECETAS -----------------------------------------
# ---------------------------------------------------.

all: $(NAME)

# FUNCION PPAL -> CREACION ARCHIVO COMPILADO
$(NAME): $(LIBFT_ARCHIVE) $(LIBRARY)
	@echo "$(ORANGE)📌​ Compiling $(NAME)... $(DEF_COLOR)"
	$(CC) ${CFLAGS} $(LIBRARY) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) -o $(NAME)
	@echo "$(DARK_GREEN)$(NAME) has been created ✓$(DEF_COLOR)"

# FUNCION SECUNDARIA -> LIBRERIA 'push_swap.a' para exe 'push_swap' y 'checker' bonus
$(LIBRARY) : $(OBJ_FILES)
	@echo "$(ORANGE)📌​ Compiling $(LIBRARY)... $(DEF_COLOR)"
	$(MAKE_LIBRARY) $(LIBRARY) $^
	@echo "$(DARK_GREEN)$(LIBRARY) library created ✓ $(DEF_COLOR)"

# FUNCION LIBRERIA LIBFT -> CREACION ARCHIVO LIBRERIA
$(LIBFT_ARCHIVE):
	@echo "$(ORANGE)📌​ Compiling $(LIBFT_ARCHIVE) library... $(DEF_COLOR)"
	@cd ${LIBFT_DIR} && make
	@echo "$(DARK_GREEN) $(LIBFT_ARCHIVE) library created ✓ $(DEF_COLOR)"

## BONUS ---------------------------------------------------------

bonus: $(NAME_BONUS)

$(NAME_BONUS): 
	@echo "$(ORANGE)📌​ Compiling bonus...$(NAME_BONUS)... $(DEF_COLOR)"
	cd $(BONUS_DIR) && make
	@echo "$(DARK_GREEN)$(NAME_BONUS) has been created ✓$(DEF_COLOR)"

# RECETA BORRAR ARCHIVOS
clean:
	@echo "${ORANGE}🗑️​ Removing object files...${NAME}...${DEF_COLOR}"
	@rm -f $(OBJ_FILES)
	@echo "${ORANGE}🗑️​ Removing object files...${LIBFT_ARCHIVE}...${DEF_COLOR}"
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@cd $(BONUS_DIR) && $(MAKE) clean
	@echo "${DARK_GREEN}Cleaning objects ${NAME}...is done! ${DEF_COLOR}"

fclean: clean
	@echo "${ORANGE}🗑️ Removing files...${NAME} and $(LIBRARY)... ${DEF_COLOR}"
	@rm -f $(NAME)
	@rm -f $(LIBRARY)
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@cd $(BONUS_DIR) && $(MAKE) fclean
	@echo "${DARK_GREEN}Cleaning ${NAME} is done! ${DEF_COLOR}"

# RECOMPILACION -----------------------------------------
# ---------------------------------------------------
# FUNCION RECONSTRUCCION -> ELIMINACION ARCHIVOS '.o' + archivos biblioteca '.a'
# NUEVA COMPILACION CON RECETA $(NAME)
re: fclean all
	@make clean
	@echo "${DARK_GREEN}🗑️ Cleaning $(NAME) is done and 📌 $(NAME) has been created✓! ${DEF_COLOR}"	

.PHONY: all clean fclean re bonus
