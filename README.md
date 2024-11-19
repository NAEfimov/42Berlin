# 42Berlin
42Berlin projects repos

--- ft_strtrim ---
Should we trim only one or all character from the 'set' in the beginning and the end of the string? 

--- ft_split ---
If we have two split charecters inside the row, should we add empty string to the array?

// Command to show all file name with '\' on the end.
ls -la | grep ft_ | grep -o -E '[^ ]+$' | sed 's/$/ \\/'

// Command to compile main.c with libft.a library
cc -Wall -Wextra -Werror main.c -L. -lft

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
