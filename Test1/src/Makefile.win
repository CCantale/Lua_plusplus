CC			=		g++
FLAGS		=		-Wall -Wextra -Werror
INCLUDES	=		-I$(CURDIR)/lua_includes
LINKS		=		-Llib -lmingw32 -L.. -llua54 -lSDL2 -lSDL2main -lSDL2_image

NAME		=		../test

SRC			=		main.cpp \
					string_utils.cpp \
					Game/Game.cpp

#OBJDIR		=		obj
#OBJS		=		$(addprefix $(OBJDIR)\, $(SRC:.cpp=.o))

OBJS		=		$(SRC:.cpp=.o)


all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) $^ -o $(NAME) $(LINKS)
	@echo The executable is ready!

#$(OBJS): $(OBJDIR)/%.o: %.cpp
#	@mkdir $(@D) 2> NUL
#	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(addprefix $(OBJDIR)\, $(<:.cpp=.o))

%.o: %.cpp
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.cpp=.o)
	@echo Files successfully compiled.

clean:
	del /q /s *.o

fclean:
	del $(NAME).exe

re: clean fclean
	make

play:
	make
	$(NAME)

.PHONY: all clean fclean re play
