# Компилятор и флаги
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Название программы
NAME = account_tests

# Исходные файлы
SRCS = Account.cpp tests.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Правила сборки
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

