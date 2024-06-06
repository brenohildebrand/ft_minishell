# Notes

 valgrind --leak-check=full --trace-children=yes --show-leak-kinds=all --suppressions=readline.supp ./minishell

 memory stack available to pass as many args as you'd like

 code is non-destructive which means a mem_join function will not
 free anything for you, will not destroy what you give it

 functions that will alloc or free memory will need the mini reference and for convention will be have the prefix mini like
 mini_name_of_the_function
 
 Not using unsigned int for size on this project for simplicity
 using int itself. they have the same size anyways and I am not using the numbers the unsigned give to me

 contexts can be created and contexts can be destroyed but
 data structures cannot be created or destroyed. You will do it yourself. because the free can be whatever