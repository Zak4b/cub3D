NAME = libft.a
FLAGS = -Wall -Wextra -Werror -I.
OBJDIR = obj
SUB_DIRS = $(addprefix $(OBJDIR)/, char conversions ft_printf list mem strings)

SOURCES = \
		char/ft_isalpha.c \
		char/ft_isdigit.c \
		char/ft_isalnum.c \
		char/ft_isascii.c \
		char/ft_isprint.c \
		char/ft_isspace.c \
		char/ft_toupper.c \
		char/ft_tolower.c \
		strings/ft_count_word.c \
		strings/ft_strcmp.c \
		strings/ft_strncmp.c \
		strings/ft_strlen.c \
		strings/ft_strchr.c \
		strings/ft_strrchr.c \
		strings/ft_strdup.c \
		strings/ft_strlcpy.c \
		strings/ft_strlcat.c \
		strings/ft_strnstr.c \
		strings/ft_substr.c \
		strings/ft_strjoin.c \
		strings/ft_strnjoin.c \
		strings/ft_strtrim.c \
		strings/ft_split.c \
		strings/ft_strmapi.c \
		strings/ft_striteri.c \
		mem/ft_memset.c \
		mem/ft_bzero.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
		mem/ft_memchr.c \
		mem/ft_calloc.c \
		conversions/ft_atoi.c \
		conversions/ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		list/ft_lstnew.c \
		list/ft_lstadd_front.c \
		list/ft_lstadd_back.c \
		list/ft_lstadd_before.c \
		list/ft_lstadd_after.c \
		list/ft_lstsize.c \
		list/ft_lstfirst.c \
		list/ft_lstlast.c \
		list/ft_lstclear.c \
		list/ft_lstdelone.c \
		list/ft_lstclear.c \
		list/ft_lstiter.c \
		list/ft_lstmap.c \
		list/ft_lst_to_array.c \
		ft_printf/ft_printf.c \
		ft_printf/utils.c \
		ft_printf/conversions.c \
		get_next_line.c

OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(SUB_DIRS)

$(OBJDIR)/%.o: srcs/%.c | $(OBJDIR)
	@cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all