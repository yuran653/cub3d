#
#

YELLOW			=	"\033[1;33m"
GREEN			=	"\033[1;32m"
END				=	"\033[0m"

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -w -g

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)
	@echo $(GREEN) "\n\tMiniLibX is compiled\n" ${END}

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app
	@echo $(YELLOW) "\n\tMiniLibX 'clean' status: DONE\n" ${END}

re: clean all
