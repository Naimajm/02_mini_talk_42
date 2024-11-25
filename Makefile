# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 13:46:22 by juagomez          #+#    #+#              #
#    Updated: 2024/11/25 20:54:42 by juagomez         ###   ########.fr        #
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
NAME_SERVER := server
NAME_CLIENT := client

CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE_LIBRARY := ar -rcs # COMPRESION A 1 ARCHIVO -> LIBRERIAS .a
#$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 

# DIRECTORIOS -----------------------------------------
# ---------------------------------------------------
LIBFT_DIR := ./libft
LIBFT_ARCHIVE := libft.a

FT_PRINTF_DIR := ./ft_printf
FT_PRINTF_ARCHIVE := libftprintf.a

#NAME_BONUS = checker
#BONUS_DIR := ./bonus

# RECURSOS -----------------------------------------
# ---------------------------------------------------
# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA
SRC_SERVER := server.c \
print_bits.c
OBJ_FILES_SERVER := $(SRC_SERVER:%.c=%.o) # LISTA ARCHIVOS .O SEGUN ARCHIVO C

SRC_CLIENT := client.c \
print_bits.c
OBJ_FILES_CLIENT := $(SRC_CLIENT:%.c=%.o) # LISTA ARCHIVOS .O SEGUN ARCHIVO C

# RECETAS -----------------------------------------
# ---------------------------------------------------.

all: $(NAME_SERVER) $(NAME_CLIENT)

# FUNCION PPAL -> CREACION "server"
$(NAME_SERVER): $(OBJ_FILES_SERVER) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
	@echo "$(ORANGE)📌​ Compiling $(NAME_SERVER)... $(DEF_COLOR)"
	$(CC) ${CFLAGS} $(OBJ_FILES_SERVER) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) $(FT_PRINTF_DIR)/$(FT_PRINTF_ARCHIVE) -o $(NAME_SERVER)
	@echo "$(DARK_GREEN)$(NAME_SERVER) has been created ✓$(DEF_COLOR)"

# FUNCION PPAL -> CREACION "client"
$(NAME_CLIENT): $(OBJ_FILES_CLIENT) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
	@echo "$(ORANGE)📌​ Compiling $(NAME_CLIENT)... $(DEF_COLOR)"
	$(CC) ${CFLAGS} $(OBJ_FILES_CLIENT) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) $(FT_PRINTF_DIR)/$(FT_PRINTF_ARCHIVE) -o $(NAME_CLIENT)
	@echo "$(DARK_GREEN)$(NAME_CLIENT) has been created ✓$(DEF_COLOR)"

# FUNCION LIBRERIA LIBFT -> CREACION ARCHIVO LIBRERIA
$(LIBFT_ARCHIVE):
	@echo "$(ORANGE)📌​ Compiling $(LIBFT_ARCHIVE) library... $(DEF_COLOR)"
	@cd ${LIBFT_DIR} && make
	@echo "$(DARK_GREEN) $(LIBFT_ARCHIVE) library created ✓ $(DEF_COLOR)"

# FUNCION LIBRERIA LIBFT -> CREACION ARCHIVO LIBRERIA
$(FT_PRINTF_ARCHIVE):
	@echo "$(ORANGE)📌​ Compiling $(FT_PRINTF_ARCHIVE) library... $(DEF_COLOR)"
	@cd ${FT_PRINTF_DIR} && make
	@echo "$(DARK_GREEN) $(FT_PRINTF_ARCHIVE) library created ✓ $(DEF_COLOR)"

## BONUS ---------------------------------------------------------

bonus: $(NAME_BONUS)

$(NAME_BONUS): 
	@echo "$(ORANGE)📌​ Compiling bonus...$(NAME_BONUS)... $(DEF_COLOR)"
	cd $(BONUS_DIR) && make
	@echo "$(DARK_GREEN)$(NAME_BONUS) has been created ✓$(DEF_COLOR)"

# RECETA BORRAR ARCHIVOS
clean:
	@echo "${ORANGE}🗑️​ Removing object files...${NAME_SERVER} and ${NAME_CLIENT}...${DEF_COLOR}"
	rm -f $(OBJ_FILES_SERVER)
	rm -f $(OBJ_FILES_CLIENT)
	@echo "${ORANGE}🗑️​ Removing object files...${LIBFT_ARCHIVE} and ${FT_PRINTF_ARCHIVE}...${DEF_COLOR}"
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@cd $(FT_PRINTF_DIR) && $(MAKE) clean
#@cd $(BONUS_DIR) && $(MAKE) clean
	@echo "${DARK_GREEN}Cleaning objects ${NAME_SERVER} and ${NAME_CLIENT}...is done! ${DEF_COLOR}"

fclean: clean
	@echo "${ORANGE}🗑️ Removing files...${NAME_SERVER} and ${NAME_CLIENT}... ${DEF_COLOR}"
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)
	@echo "${ORANGE}🗑️ Removing files...${LIBFT_ARCHIVE} and ${FT_PRINTF_ARCHIVE}... ${DEF_COLOR}"
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@cd $(FT_PRINTF_DIR) && $(MAKE) fclean
#@cd $(BONUS_DIR) && $(MAKE) fclean
	@echo "${DARK_GREEN}Cleaning ${NAME_SERVER}, ${NAME_CLIENT}...is done! ${DEF_COLOR}"

# RECOMPILACION -----------------------------------------
# ---------------------------------------------------
# FUNCION RECONSTRUCCION -> ELIMINACION ARCHIVOS '.o' + archivos biblioteca '.a'
# NUEVA COMPILACION CON RECETA $(NAME)
re: fclean all
	@make clean
	@echo "${DARK_GREEN}🗑️ Cleaning $(NAME) is done and 📌 $(NAME) has been created✓! ${DEF_COLOR}"	

.PHONY: all clean fclean re bonus
