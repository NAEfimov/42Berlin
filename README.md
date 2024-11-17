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
