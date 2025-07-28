NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCDIR = .
OBJDIR = obj

SOURCES = main.cpp RPN.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# Colors for pretty output
GREEN = \033[92m
YELLOW = \033[93m
RED = \033[91m
BLUE = \033[94m
CYAN = \033[96m
RESET = \033[0m
BOLD = \033[1m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(CYAN)$(BOLD)[LINKING]$(RESET) Creating $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)[SUCCESS]$(RESET) $(NAME) compiled successfully! 🧮"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)[COMPILE]$(RESET) $< → $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)[CLEAN]$(RESET) Removing object files..."
	@$(RM) -r $(OBJDIR)

fclean: clean
	@echo "$(RED)[FCLEAN]$(RESET) Removing $(NAME)..."
	@$(RM) $(NAME)

re: fclean all

test: $(NAME)
	@echo "$(BLUE)$(BOLD)[TEST]$(RESET) Running RPN Calculator tests..."
	@bash tester_rpn.sh

.PHONY: all clean fclean re test