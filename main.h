#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Declaration of the "environment" as an array of pointers to strings. */
extern char **environ;

/**
 * struct data - Struct that holds essential runtime data.
 * @av: Argument vector.
 * @input: User-provided command line input.
 * @args: Tokenized arguments.
 * @status: Last shell status.
 * @counter: Line counter.
 * @_environ: Environment variables.
 * @pid: Process ID of the shell.
 */
typedef struct data
{
    char **av;
    char *input;
    char **args;
    int status;
    int counter;
    char **_environ;
    char *pid;
} data_shell;

/**
 * struct sep_list_s - Single linked list to store separators.
 * @separator: Separator character (;, |, or &).
 * @next: Pointer to the next node.
 * Description: Used for managing command line separators.
 */
typedef struct sep_list_s
{
    char separator;
    struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - Single linked list to store command lines.
 * @line: Command line.
 * @next: Pointer to the next node.
 * Description: Used for storing command lines.
 */
typedef struct line_list_s
{
    char *line;
    struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - Single linked list to store variables.
 * @len_var: Length of the variable name.
 * @val: Value of the variable.
 * @len_val: Length of the value.
 * @next: Pointer to the next node.
 * Description: Used for managing runtime variables.
 */
typedef struct r_var_list
{
    int len_var;
    char *val;
    int len_val;
    struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command arguments.
 * @name: The name of the builtin command (e.g., cd, exit, env).
 * @f: Pointer to the corresponding function.
 */
typedef struct builtin_s
{
    char *name;
    int (*f)(data_shell *datash);
} builtin_t;

/* Function prototypes for various parts of the code. */

/* Functions related to linked lists. */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* String manipulation functions. */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
void rev_string(char *s);

/* Memory management functions. */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* Syntax error checking functions. */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int check_syntax_error(data_shell *datash, char *input);

/* Main shell loop functions. */
char *without_comment(char *in);
void shell_loop(data_shell *datash);

/* Reading user input functions. */
char *read_line(int *i_eof);

/* Command line splitting functions. */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* Variable replacement functions. */
void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);

/* Reading lines from input. */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* Executing shell commands. */
int exec_line(data_shell *datash);
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* Environment variable functions. */
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* Environment manipulation functions. */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

/* Directory change functions. */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

/* Built-in command lookup function. */
int (*get_builtin(char *cmd))(data_shell *datash);

/* Exit shell function. */
int exit_shell(data_shell *datash);

/* Additional utility functions. */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* Error message functions. */
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);

/* Error handling functions. */
int get_error(data_shell *datash, int eval);

/* Signal handling function. */
void get_sigint(int sig);

/* Help message functions. */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

#endif
