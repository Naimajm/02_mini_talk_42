# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 13:46:22 by juagomez          #+#    #+#              #
#    Updated: 2024/11/27 21:05:02 by juagomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR           = \033[0;39m
GRAY                = \033[0;90m
RED                 = \033[0;91m
GREEN               = \033[0;92m  
YELLOW              = \033[0;93m
BLUE                = \033[0;94m
MAGENTA             = \033[0;95m
CYAN                = \033[0;96m
ORANGE              = \033[38;5;209m
DARK_GRAY           = \033[38;5;234m
MID_GRAY            = \033[38;5;245m
DARK_GREEN          = \033[38;2;75;179;82m
DARK_YELLOW         = \033[38;5;143m

NAME_SERVER := server
NAME_CLIENT := client

CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE_LIBRARY := ar -rcs

LIBFT_DIR := ./libft
LIBFT_ARCHIVE := libft.a

FT_PRINTF_DIR := ./ft_printf
FT_PRINTF_ARCHIVE := libftprintf.a

SRC_SERVER := server.c 
OBJ_FILES_SERVER := $(SRC_SERVER:%.c=%.o)

SRC_CLIENT := client.c 
OBJ_FILES_CLIENT := $(SRC_CLIENT:%.c=%.o) 

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRC_SERVER_BONUS := server_bonus.c 
OBJ_FILES_SERVER_BONUS := $(SRC_SERVER_BONUS:%.c=%.o) 

SRC_CLIENT_BONUS := client_bonus.c 
OBJ_FILES_CLIENT_BONUS := $(SRC_CLIENT_BONUS:%.c=%.o) 

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_FILES_SERVER) $(OBJ_FILES_CLIENT) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
	@echo "$(ORANGE)📌​ Compiling $(NAME_SERVER) and $(NAME_CLIENT)... $(DEF_COLOR)"
	$(CC) ${CFLAGS} $(OBJ_FILES_SERVER) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) $(FT_PRINTF_DIR)/$(FT_PRINTF_ARCHIVE) -o $(NAME_SERVER)
	$(CC) ${CFLAGS} $(OBJ_FILES_CLIENT) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) $(FT_PRINTF_DIR)/$(FT_PRINTF_ARCHIVE) -o $(NAME_CLIENT)
	@echo "$(DARK_GREEN)$(NAME_SERVER) and $(NAME_CLIENT) has been created ✓$(DEF_COLOR)"

$(LIBFT_ARCHIVE):
	@echo "$(ORANGE)📌​ Compiling $(LIBFT_ARCHIVE) library... $(DEF_COLOR)"
	@cd ${LIBFT_DIR} && make
	@echo "$(DARK_GREEN) $(LIBFT_ARCHIVE) library created ✓ $(DEF_COLOR)"

$(FT_PRINTF_ARCHIVE):
	@echo "$(ORANGE)📌​ Compiling $(FT_PRINTF_ARCHIVE) library... $(DEF_COLOR)"
	@cd ${FT_PRINTF_DIR} && make
	@echo "$(DARK_GREEN) $(FT_PRINTF_ARCHIVE) library created ✓ $(DEF_COLOR)"

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJ_FILES_SERVER_BONUS) $(OBJ_FILES_CLIENT_BONUS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
	@echo "$(ORANGE)📌​ Compiling bonus...$(NAME_SERVER_BONUS) and $(NAME_CLIENT_BONUS)... $(DEF_COLOR)"
	$(CC) ${CFLAGS} $(OBJ_FILES_SERVER_BONUS) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) $(FT_PRINTF_DIR)/$(FT_PRINTF_ARCHIVE) -o $(NAME_SERVER_BONUS)
	$(CC) ${CFLAGS} $(OBJ_FILES_CLIENT_BONUS) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) $(FT_PRINTF_DIR)/$(FT_PRINTF_ARCHIVE) -o $(NAME_CLIENT_BONUS)
	@echo "$(DARK_GREEN)$(NAME_SERVER_BONUS) and $(NAME_CLIENT_BONUS) has been created ✓$(DEF_COLOR)"

clean:
	@echo "${ORANGE}🗑️​ Removing object files...${NAME_SERVER} and ${NAME_CLIENT}...${DEF_COLOR}"
	rm -f $(OBJ_FILES_SERVER) $(OBJ_FILES_CLIENT)

	@echo "${ORANGE}🗑️​ Removing object files...${NAME_SERVER_BONUS} and ${NAME_CLIENT_BONUS}...${DEF_COLOR}"
	rm -f $(OBJ_FILES_SERVER_BONUS) $(OBJ_FILES_CLIENT_BONUS)

	@echo "${ORANGE}🗑️​ Removing object files...${LIBFT_ARCHIVE} and ${FT_PRINTF_ARCHIVE}...${DEF_COLOR}"
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@cd $(FT_PRINTF_DIR) && $(MAKE) clean
	@echo "${DARK_GREEN}Cleaning objects ${NAME_SERVER} and ${NAME_CLIENT}...is done! ${DEF_COLOR}"

fclean: clean
	@echo "${ORANGE}🗑️ Removing files...${NAME_SERVER} and ${NAME_CLIENT}... ${DEF_COLOR}"
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

	@echo "${ORANGE}🗑️ Removing files...${NAME_SERVER_BONUS} and ${NAME_CLIENT_BONUS}... ${DEF_COLOR}"
	rm -f $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

	@echo "${ORANGE}🗑️ Removing files...${LIBFT_ARCHIVE} and ${FT_PRINTF_ARCHIVE}... ${DEF_COLOR}"
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@cd $(FT_PRINTF_DIR) && $(MAKE) fclean

	@echo "${DARK_GREEN}Cleaning ${NAME_SERVER}, ${NAME_CLIENT}...is done! ${DEF_COLOR}"

re: fclean all
	@make clean
	@echo "${DARK_GREEN}🗑️ Cleaning $(NAME_SERVER) and ${NAME_CLIENT} is done.${DEF_COLOR}"	
	@echo "${DARK_GREEN}📌 $(NAME_SERVER) and ${NAME_CLIENT} have been created✓! ${DEF_COLOR}"	

.PHONY: all clean fclean re bonus
