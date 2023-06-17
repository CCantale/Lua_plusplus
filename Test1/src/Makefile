CC		=		g++
FLAGS		=		-Wall -Wextra -Werror

SRC		=		main.cpp \
				string_utils.cpp \
				Game/Game.cpp \
				Sprite/Sprite.cpp \
				Button/Button.cpp

SDLDIR		=		sdl2
OBJDIR		=		obj
OBJS		=		$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

INCL		=		-I$(SDLDIR)/include/SDL2 -Ilua_includes
LINK		=		-L$(SDLDIR)/lib -lSDL2 -lSDL2_image

OS		:=		$(shell uname -s)

ifeq ($(OS), Linux)
	NAME	:=		../linux_test
else ifeq ($(OS), Darwin)
	NAME	:=		../mac_test
else
	$(error Wrong operating system: $(OS))
endif



all: $(NAME)
	@echo "test successfully compiled!"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) liblua.a -o $(NAME) $(LINK) -ldl

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(INCL) $(FLAGS) -c $< -o $(addprefix $(OBJDIR)/, $(<:.cpp=.o))

clean:
	rm -rf $(OBJDIR)

fclean:
	rm $(NAME)

re: clean fclean
	make

.PHONY: all clean fclean re play

