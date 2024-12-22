# Colors
DEF_COLOR   = \033[0;39m
GRAY        = \033[0;90m
RED         = \033[0;91m
GREEN       = \033[0;92m
YELLOW      = \033[0;93m
BLUE        = \033[0;94m
MAGENTA     = \033[0;95m
CYAN        = \033[0;96m
WHITE       = \033[0;97m
ORANGE      = \033[38;5;222m
GREEN_BR    = \033[38;5;118m
YELLOW_BR   = \033[38;5;227m
PINK_BR     = \033[38;5;206m
BLUE_BR     = \033[38;5;051m
PINK_BRR     = \033[38;5;219m

# Text styles
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLINK       = \033[5m



NAME = phonebook

CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⠀              ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀    ⠀⠀⠀⠀⠀                  ⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
	chmod +x $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
