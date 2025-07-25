# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: mgoretti <mgoretti@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/01/25 18:00:00 by mgoretti          #+#    #+#             #
#    Updated: 2025/01/25 18:00:00 by mgoretti         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = btc_class
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SOURCES = main_class.cpp BitcoinExchange.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m # No Color

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning executable...$(NC)"
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "$(GREEN)Running tests...$(NC)"
	./$(NAME) file.txt && echo "$(GREEN)Running test 2...$(NC)" && sleep 1.5 && ./$(NAME) test_edge_cases.txt

.PHONY: all clean fclean re test
