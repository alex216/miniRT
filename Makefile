# shell
SHELL		= /bin/bash
UNAME		= $(shell uname)

# executable and archive files
NAME		= miniRT
LIBFT		= $(LIBFT_DIR)/libft.a

# compiler options
CFLAGS		= -Werror -Wextra -Wall
PROD_FLAGS	= -O3
DEV_FLAGS	= -O0 -g -fsanitize=address,undefined,integer
DEP_FLAGS	= -MMD -MP
INCLUDE		= -I $(INC_DIR) -I $(LIBFT_DIR)/include -I $(LIBMLX_DIR)
LD_FLAGS	= -L $(LIBFT_DIR) -L $(LIBMLX_DIR)
LD_LIBS		= -lft

# directories
SRC_DIR		= src
BUILD_DIR	= build
INC_DIR		= include
LIBFT_DIR	= libft

ifeq ($(UNAME), Linux)
	LIBMLX		= $(LIBMLX_DIR)/libmlx.a
	LIBMLX_DIR	= libmlx/linux
	LD_LIBS		+= -lmlx -lXext -lX11 -lm -lz
else ifeq ($(UNAME), Darwin)
	LIBMLX		= $(LIBMLX_DIR)/libmlx.dylib
	LIBMLX_DIR	= libmlx/macos
	LD_LIBS		+= -lmlx -framework openGL -framework AppKit
endif

# files
SRC			= $(SRC_DIR)/main.c #\

OBJ			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEP			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(SRC))
HEADER		= $(wildcard $(INC_DIR)/*.h $(SRC_DIR)/**/*.h)

# colors
RESET		= \033[0m
ORANGE		= \033[0;33m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[1;92m
YELLOW		= \033[1;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# rules
.PHONY: all
all: CFLAGS += $(PROD_FLAGS)
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(SRC) $(HEADER)
	@make _main CFLAGS="$(CFLAGS)"

.PHONY: _main
_main:
	@printf "$(BLUE)[$(NAME)]\t\t./$(NAME)$(RESET)\t\t$(WHITE)compling...$(RESET)\n"
	@make _build CFLAGS="$(CFLAGS)"

.PHONY: _build
_build: $(OBJ)
	@if [ $(UNAME) = "Darwin" ]; then \
		cp $(LIBMLX) . ; \
	fi
	@$(CC) $(OBJ) $(CFLAGS) $(LD_FLAGS) $(LD_LIBS) -o $(NAME)
	@printf "\n$(BLUE)[$(NAME)]\t\t./$(NAME)$(RESET)\t\t$(GREEN)compiled ✔$(RESET)\n"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEP_FLAGS) -c $< -o $@
	@printf "$(GREEN)─$(RESET)"

$(LIBFT):
	git submodule update --init
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

-include $(DEP)

.PHONY: clean
clean:
	-@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBMLX_DIR)
	@if [ $(UNAME) = "Darwin" ]; then \
		$(RM) $(shell basename $(LIBMLX)) ; \
	fi
	@$(RM) $(OBJ) $(DEP)
	@printf "$(BLUE)[$(NAME)]\t\tobject files$(RESET)\t$(GREEN)deleted ✔$(RESET)\n"

.PHONY: fclean
fclean: clean
	-@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@printf "$(BLUE)[$(NAME)]\t\t./$(NAME)$(RESET)\t\t$(GREEN)deleted ✔$(RESET)\n"

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	norminette $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)
