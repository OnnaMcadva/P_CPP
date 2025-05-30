# Colors
DEF_COLOR   = "\033[0;39m"
GRAY        = "\033[0;90m"
YELLOW      = "\033[0;93m"
GREEN       = "\033[0;92m"
RED         = "\033[0;91m"
BLUE        = "\033[0;94m"
MAGENTA     = "\033[0;95m"
CYAN        = "\033[0;96m"
WHITE       = "\033[0;97m"
ORANGE      = "\033[38;5;222m"
GREEN_BR    = "\033[38;5;118m"
YELLOW_BR   = "\033[38;5;227m"
PINK_BR     = "\033[38;5;206m"
BLUE_BR     = "\033[38;5;051m"
PINK_BRR    = "\033[38;5;219m"

# Text styles
BOLD        = "\033[1m"
UNDERLINE   = "\033[4m"
BLINK       = "\033[5m"

NAME = PmergeMe
DEBUG_NAME = PmergeMeDeb

CC = c++
CPP_FLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98

RM = rm -rf

FILES = main PmergeMe
DEBUG_FILES = main PmergeMeDeb

SRCS = $(addsuffix .cpp, $(FILES))
DEBUG_SRCS = $(addsuffix .cpp, $(DEBUG_FILES))

HDRS = $(wildcard *.hpp)

OBJS_DIR = obj
OBJ_DIRS = $(OBJS_DIR)
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))
DEBUG_OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(DEBUG_FILES)))

$(OBJS_DIR)/%.o: %.cpp $(HDRS)
	@printf $(GRAY)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CPP_FLAGS) -c -o $@ $<

all: $(NAME)
	@printf $(BOLD)$(GREEN_BR)"\n"
	@printf $(BOLD)$(GREEN_BR)"Now I know EVERYTHING about sorting\n"
	@printf $(BOLD)$(GREEN_BR)"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf $(BOLD)$(GREEN_BR)"⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀\n"
	@printf $(BOLD)$(GREEN_BR)"⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀\n"
	@printf $(BOLD)$(GREEN_BR)"⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀\n"
	@printf $(BOLD)$(GREEN_BR)"⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀\n"
	@printf $(BOLD)$(GREEN_BR)"⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀\n"
	@printf $(BOLD)$(GREEN_BR)"⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀\n\n"
	@printf $(BOLD)$(BLUE)"Ford-Johnson sorting algorithm is not a very well known algorithm.\n"
	@printf $(BOLD)$(BLUE)"It's neither fast, nor the best minimum sort algorithm, which is why\n"
	@printf $(BOLD)$(BLUE)"there are almost no good resources on this algorithm, between\n"
	@printf $(BOLD)$(BLUE)"scientific papers, hard to read computer science books, or obscure\n"
	@printf $(BOLD)$(BLUE)"threads on Reddit or Stack Overflow.\n"
	@printf $(BOLD)$(BLUE)"		🔧 🛠️ 🤖 💻\n\n"

$(NAME): $(OBJS)
	@printf $(GRAY)
	$(CC) $(CPP_FLAGS) -o $(NAME) $(OBJS)
	@printf $(DEF_COLOR)

debug: $(DEBUG_NAME)

$(DEBUG_NAME): $(DEBUG_OBJS)
	@printf $(GRAY)
	$(CC) $(CPP_FLAGS) -o $(DEBUG_NAME) $(DEBUG_OBJS)
	@printf $(DEF_COLOR)
	@printf $(BOLD)$(YELLOW)"\nDebug version (PmergeMeDeb) compiled!\n\n"
	@printf $(BOLD)$(GREEN_BR)
	@printf "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣴⣶⡿⠿⠿⠿⠿⠿⠿⠿⢷\n"
	@printf "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⡿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⠀⢀⣾⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⣰⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⢠⣾⣿⠿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⣴⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠈⠉    "$(BLUE)"Use ./PmergeMeDeb\n\n"

clean:
	@printf $(YELLOW)
	$(RM) $(OBJS_DIR) $(NAME) $(DEBUG_NAME)
	@printf $(DEF_COLOR)

fclean: clean

re: fclean all

.PHONY: all clean fclean re debug