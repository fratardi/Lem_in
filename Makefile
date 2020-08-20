# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 04:39:53 by tpacaud           #+#    #+#              #
#    Updated: 2020/05/12 23:05:16 by fratardi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = ./libft/libft.a

LIB_PATH = ./libft/

LIB_INC = ./libft/libft/includes

FT_PRINTF_INC = ./libft/ft_printf/includes

CC = clang

FLAGS = -Wall -Wextra -Werror

INC_PATH = includes

INC_NAME = lem_in.h

OBJ_DIR = ./objects

SRC_DIR = ./srcs

C = $(SRC_DIR)/read_file.c \
	$(SRC_DIR)/check_error.c \
	$(SRC_DIR)/check_error_sec.c \
	$(SRC_DIR)/matrice.c \
	$(SRC_DIR)/mod_rooms.c \
	$(SRC_DIR)/lm_room_check.c \
	$(SRC_DIR)/lm_mark_room.c \
	$(SRC_DIR)/init_lem.c \
	$(SRC_DIR)/lm_room_info.c \
	$(SRC_DIR)/lm_bfs.c \
	$(SRC_DIR)/lm_dfs.c \
	$(SRC_DIR)/lm_update.c \
	$(SRC_DIR)/lm_print.c \
	$(SRC_DIR)/skim.c \
	$(SRC_DIR)/init_mat.c \
	$(SRC_DIR)/annex.c \
	$(SRC_DIR)/saturated_matrice.c \
	$(SRC_DIR)/new_map.c \
	$(SRC_DIR)/formule.c \
	$(SRC_DIR)/skim_layer.c \
	$(SRC_DIR)/send.c \
	$(SRC_DIR)/send_annex.c \
	$(SRC_DIR)/send_next.c \
	$(SRC_DIR)/send_init.c \
	$(SRC_DIR)/distribute.c \
	$(SRC_DIR)/formule_init.c \
	$(SRC_DIR)/parsing_annex.c \
	$(SRC_DIR)/lm_flows.c \
	$(SRC_DIR)/lm_init_parse.c \
	$(SRC_DIR)/free.c \
	$(SRC_DIR)/free_anthill.c \
	$(SRC_DIR)/main.c

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

O = $(C:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(if $(findstring main, $@),@echo "\n--- Making \033[31mlem_in\033[00m ---")
	$(if $(findstring read_file, $@),@echo "\n--- Making \033[35mutils\033[00m ---")
	@$(CC) $(FLAGS) -I$(LIB_INC) -I$(FT_PRINTF_INC) -c $< -o $@ 
	@echo ">>> Making $@"

all : lib $(NAME) $(CHECKER)

$(NAME) : $(O) $(O_PUSHSWAP)
	@make -C ./libft
	@echo ">>> Making $(NAME) binary"
	@$(CC) $(FLAGS) $(O) $(LIB) -I$(LIB_INC) -I$(FT_PRINTF_INC) -o $(NAME)

lib :
	@make -C ./libft

clean :
	@rm -rf $(O)
	@echo "Cleaning Done (Removed .o)"

fclean : clean
	@rm -rf $(NAME) $(OBJ_DIR)
	@echo $(NAME) " Removed"
	@make fclean -C $(LIB_PATH)

re : fclean all

.PHONY : all lib clean flean re
