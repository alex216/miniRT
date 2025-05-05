# archives
NAME			= libft.a

# compiler options
CFLAGS			= -Wall -Wextra -Werror
INCLUDE			= -I$(INC_DIR)
ARFLAGS			= crs

# directories and source files
BUILD_DIR		= build
INC_DIR			= include

SRC				=

FILE_DIR		= ft_file
SRC				+= $(FILE_DIR)/file_to_lines.c

MATH_DIR		= ft_math
SRC				+= $(MATH_DIR)/ft_abs.c \
					$(MATH_DIR)/ft_chmax.c \
					$(MATH_DIR)/ft_chmin.c \
					$(MATH_DIR)/ft_max.c \
					$(MATH_DIR)/ft_min.c \
					$(MATH_DIR)/ft_swap.c \
					$(MATH_DIR)/ft_fabs.c \
					$(MATH_DIR)/ft_fchmax.c \
					$(MATH_DIR)/ft_fchmin.c \
					$(MATH_DIR)/ft_fmax.c \
					$(MATH_DIR)/ft_fmin.c \
					$(MATH_DIR)/ft_fswap.c

LIST_DIR		= ft_list
SRC				+= $(LIST_DIR)/ft_lstadd_back.c \
					$(LIST_DIR)/ft_lstadd_front.c \
					$(LIST_DIR)/ft_lstbefore.c \
					$(LIST_DIR)/ft_lstclear.c \
					$(LIST_DIR)/ft_lstdelone.c \
					$(LIST_DIR)/ft_lstiter.c \
					$(LIST_DIR)/ft_lstlast.c \
					$(LIST_DIR)/ft_lstmap.c \
					$(LIST_DIR)/ft_lstnew.c \
					$(LIST_DIR)/ft_lstsize.c

MEMORY_DIR		= ft_memory
SRC				+= $(MEMORY_DIR)/ft_bzero.c \
					$(MEMORY_DIR)/ft_calloc.c \
					$(MEMORY_DIR)/ft_memccpy.c \
					$(MEMORY_DIR)/ft_memchr.c \
					$(MEMORY_DIR)/ft_memcmp.c \
					$(MEMORY_DIR)/ft_memcpy.c \
					$(MEMORY_DIR)/ft_memmove.c \
					$(MEMORY_DIR)/ft_memset.c \
					$(MEMORY_DIR)/ft_xmalloc.c

OUTPUT_DIR		= ft_output
SRC				+= $(OUTPUT_DIR)/ft_putchar_fd.c \
					$(OUTPUT_DIR)/ft_putendl_fd.c \
					$(OUTPUT_DIR)/ft_putnbr_fd.c \
					$(OUTPUT_DIR)/ft_putstr_fd.c

PRINTF_DIR		= ft_printf
SRC				+= $(PRINTF_DIR)/configure_format_info.c \
					$(PRINTF_DIR)/ft_dprintf.c \
					$(PRINTF_DIR)/ft_printf.c \
					$(PRINTF_DIR)/ft_vdprintf.c \
					$(PRINTF_DIR)/ft_vprintf.c \
					$(PRINTF_DIR)/print_by_format.c \
					$(PRINTF_DIR)/print_integer/calc_digits_base.c \
					$(PRINTF_DIR)/print_integer/configure_integer_info.c \
					$(PRINTF_DIR)/print_integer/print_integer.c \
					$(PRINTF_DIR)/print_integer/putnbr_base.c \
					$(PRINTF_DIR)/print_string/print_char.c \
					$(PRINTF_DIR)/print_string/print_padding.c \
					$(PRINTF_DIR)/print_string/print_str.c

STRING_DIR		= ft_string
SRC				+= $(STRING_DIR)/ft_atoi.c \
					$(STRING_DIR)/ft_basename.c \
					$(STRING_DIR)/ft_free_strs.c \
					$(STRING_DIR)/ft_itoa.c \
					$(STRING_DIR)/ft_split.c \
					$(STRING_DIR)/ft_strchr.c \
					$(STRING_DIR)/ft_strcmp.c \
					$(STRING_DIR)/ft_strdup.c \
					$(STRING_DIR)/ft_striteri.c \
					$(STRING_DIR)/ft_strjoin.c \
					$(STRING_DIR)/ft_strlcat.c \
					$(STRING_DIR)/ft_strlcpy.c \
					$(STRING_DIR)/ft_strlen.c \
					$(STRING_DIR)/ft_strmapi.c \
					$(STRING_DIR)/ft_strncmp.c \
					$(STRING_DIR)/ft_strndup.c \
					$(STRING_DIR)/ft_strnstr.c \
					$(STRING_DIR)/ft_strrchr.c \
					$(STRING_DIR)/ft_strstr.c \
					$(STRING_DIR)/ft_strtol.c \
					$(STRING_DIR)/ft_strtrim.c \
					$(STRING_DIR)/ft_substr.c

TYPE_DIR		= ft_type
SRC				+= $(TYPE_DIR)/ft_isalnum.c \
					$(TYPE_DIR)/ft_isalpha.c \
					$(TYPE_DIR)/ft_isascii.c \
					$(TYPE_DIR)/ft_isblank.c \
					$(TYPE_DIR)/ft_isdigit.c \
					$(TYPE_DIR)/ft_isprint.c \
					$(TYPE_DIR)/ft_isspace.c \
					$(TYPE_DIR)/ft_tolower.c \
					$(TYPE_DIR)/ft_toupper.c

GNL_DIR			= get_next_line
SRC				+= $(GNL_DIR)/get_next_line.c \
					$(GNL_DIR)/get_next_line_utils.c

OBJ				= $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

# colors
RESET			= \033[0m
ORANGE			= \033[0;33m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

.PHONY: all
all: $(NAME)

$(NAME): $(SRC)
	@make _main

.PHONY: _main
_main:
	@echo "$(BLUE)[libft]\t\t$(NAME)$(RESET)\t\t$(WHITE)compling...$(RESET)"
	@make _build

.PHONY: _build
_build: $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $^
	@echo "\n$(BLUE)[libft]\t\t$(NAME)$(RESET)\t\t$(GREEN)compiled ✔$(RESET)"

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)─$(RESET)"

.PHONY: clean
clean:
	@$(RM) $(OBJ)
	@echo "$(BLUE)[libft]\t\tobject files$(RESET)\t$(GREEN)deleted ✔$(RESET)"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)[libft]\t\t$(NAME)$(RESET)\t\t$(GREEN)deleted ✔$(RESET)"

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	norminette $(FILE_DIR) $(INTEGER_DIR) $(LIST_DIR) $(MEMORY_DIR) $(OUTPUT_DIR) $(PRINTF_DIR) $(STRING_DIR) $(TYPE_DIR) $(GNL_DIR) $(INC_DIR)
