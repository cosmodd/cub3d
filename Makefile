# SOURCES
SRCS	= srcs/main.c \
		srcs/maths/angles.c \
		srcs/maths/utils/abs.c \
		srcs/maths/utils/distance.c \
		srcs/maths/utils/in_range.c \
		srcs/maths/utils/min_max.c \
		srcs/maths/vector.c \
		srcs/maths/vector2.c \
		srcs/xutils/colors.c \
		srcs/xutils/images.c \
		srcs/xutils/polygons.c \

OBJS	= $(SRCS:.c=.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -Ofast
INCS	= -Iincludes -Iminilibx
LIBS	= -lz -Lminilibx -lmlx
OPTS	= -framework OpenGL -framework AppKit
C_OPTS	= $(CFLAGS) $(INCS)
BIN_OPT	= $(LIBS) $(OPTS) $(INCS) -fsanitize=address

# OTHER
NAME	= cub3d
RETURN	=

# COLORS
BG_RD	= \033[48;2;237;66;69m
BG_GR	= \033[48;2;0;194;60m
BG_BL	= \033[48;2;88;101;242m
FG_WH	= \033[38;2;255;255;255m
FG_BK	= \033[38;2;0;0;0m
BOLD	= \033[1m
NOCOL	= \033[0m

# CHARS
TICK	= ✓
PEN		= ✐
CROSS	= 𐄂

# MESSAGES
VALID	= $(BOLD)$(FG_WH)$(BG_GR) $(TICK)
INFO	= $(BOLD)$(FG_WH)$(BG_BL) $(PEN)
DEL		= $(BOLD)$(FG_WH)$(BG_RD) $(CROSS)

.c.o:
	@make -sC minilibx
	@$(CC) $(C_OPTS) -c $< -o $@
	@$(RETURN)
	@echo "\033[2K$(INFO) $(notdir $@) $(NOCOL)"
	$(eval RETURN = echo "\033[2A")

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[A\033[2K$(INFO) Object files compiled $(NOCOL)"
	@$(CC) $(BIN_OPT) $^ -o $@
	@echo "$(VALID) $@ $(NOCOL)"

clean:
	@make -sC minilibx clean
	@echo "$(DEL) minilibx cleaned $(NOCOL)"
	@rm -f $(OBJS)
	@echo "$(DEL) $(words $(OBJS)) obj files $(NOCOL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(DEL) $(NAME) binary $(NOCOL)"

re: fclean all

.PHONY: all clean fclean re
