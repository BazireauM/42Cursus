NAME	=	push_swap

SRCS	=	main.c\
			src/parssing_utils.c\
			src/parssing.c\
			src/utils.c\
			src/init_stack.c\
			src/action.c\
			src/action2.c\
			src/action3.c\
			src/algo.c\
			src/algo_utils.c

LIBFTDIR	=	libft/

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

rm		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT)
			make -C $(LIBFTDIR)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

$(LIBFT) :
			make -C $(LIBFTDIR)

clean	:
			$(RM) $(OBJS)
			make -C $(LIBFTDIR) clean

fclean	:	clean
			$(RM) $(NAME) 	
			make -C $(LIBFTDIR) fclean

re		:	fclean $(NAME)
