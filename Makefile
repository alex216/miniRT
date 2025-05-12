# OS detection
UNAME_S := $(shell uname -s)

# executable and archive files
NAME		= miniRT
LIBFT		= $(LIBFT_DIR)/libft.a
LIBMLX		= $(LIBMLX_DIR)/libmlx.a

# compiler options
CFLAGS		= -Werror -Wextra -Wall
PROD_FLAGS	= -O3
DEV_FLAGS	= -O0 -g -fsanitize=address,undefined,integer
DEP_FLAGS	= -MMD -MP
INCLUDE		= -I$(INC_DIR) -I$(LIBFT_DIR)/include -I$(LIBMLX_DIR)

# library paths and flags
LD_FLAGS	= -L$(LIBFT_DIR) -L$(LIBMLX_DIR)
LD_LIBS		= -lft -lmlx -lXext -lX11 -lm -lz
ifeq ($(UNAME_S),Darwin)
	LD_FLAGS	+= -L/usr/X11/lib
	INCLUDE		+= -I/usr/X11/include
endif

# directories
SRC_DIR		= src
BUILD_DIR	= build
INC_DIR		= include
LIBFT_DIR	= libft
LIBMLX_DIR	= libmlx

# files
SRC			=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/parser/parse_token.c \
				$(SRC_DIR)/parser/parse_line.c \
				$(SRC_DIR)/parser/parse_scene.c \
				$(SRC_DIR)/parser/parse_obj_cone.c \
				$(SRC_DIR)/parser/parse_obj_cylinder.c \
				$(SRC_DIR)/parser/parse_obj_plane.c \
				$(SRC_DIR)/parser/parse_obj_sphere.c \
				$(SRC_DIR)/parser/utils.c \
				$(SRC_DIR)/mlx_utils/constructor.c \
				$(SRC_DIR)/mlx_utils/destructor.c \
				$(SRC_DIR)/mlx_utils/handle_events.c \
				$(SRC_DIR)/mlx_utils/plot_pixel.c \
				$(SRC_DIR)/utils/ft_xlstnew.c \
				$(SRC_DIR)/utils/ft_atof.c \
				$(SRC_DIR)/scene/constructor.c \
				$(SRC_DIR)/scene/stub_init_scene.c \
				$(SRC_DIR)/scene/stub_add_objects.c \
				$(SRC_DIR)/scene/stub_lighting.c \
				$(SRC_DIR)/tracer/calc_lighting.c \
				$(SRC_DIR)/tracer/intersect_object.c \
				$(SRC_DIR)/tracer/trace_ray.c \
				$(SRC_DIR)/tracer/render.c \
				$(SRC_DIR)/utils/error.c \
				$(SRC_DIR)/vec3/arithmetic.c \
				$(SRC_DIR)/vec3/geometric.c \
				$(SRC_DIR)/vec3/metric.c \
				$(SRC_DIR)/viewport/init.c

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

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LD_FLAGS) $(LD_LIBS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) $(DEP_FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

-include $(DEP)

.PHONY: clean
clean:
	-@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBMLX_DIR)
	$(RM) $(OBJ) $(DEP)

.PHONY: fclean
fclean: clean
	-@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	norminette $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

include unit_test.mk
