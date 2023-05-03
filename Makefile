# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apanikov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 16:42:29 by apanikov          #+#    #+#              #
#    Updated: 2023/05/03 16:43:02 by apanikov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = server
NAMEC = client
NAMESB = server_bonus
NAMECB = client_bonus
SRCS = server.c 
SRCC = client.c
SRCSB = server_bonus.c 
SRCCB = client_bonus.c
OBJS = $(SRCS:%.c=%.o)
OBJC = $(SRCC:%.c=%.o)
OBJSB = $(SRCSB:%.c=%.o)
OBJCB = $(SRCCB:%.c=%.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
LIBFTA = $(LIBFT)/libft.a
LIBS = -L$(LIBFT) -lft

all: $(NAME) $(NAMEC) $(LIBFTA)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFTA) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(NAMEC): $(LIBFTA) $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) $(LIBS) -o $(NAMEC)

bonus : $(NAMESB) $(NAMECB) $(LIBFTA)

$(NAMESB): $(LIBFTA) $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) $(LIBS) -o $(NAMESB)

$(NAMECB): $(LIBFTA) $(OBJCB)
	$(CC) $(CFLAGS) $(OBJCB) $(LIBS) -o $(NAMECB)	

$(LIBFTA):
	@$(MAKE) -C $(LIBFT)

clean:
	$(RM) $(OBJS) $(OBJC) $(OBJSB) $(OBJCB)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME) $(NAMEC) $(NAMESB) $(NAMECB)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY : all clean fclean re bonus
