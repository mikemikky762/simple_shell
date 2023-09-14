#include "main.h"

/**
* aux_help - Display information about the builtin help.
* Return: void
*/
void aux_help(void)
{
char *help = "help: help [-dms] [pattern ...]\n";
write(STDOUT_FILENO, help, _strlen(help));

help = "\tDisplay brief summaries of builtin commands.\n";
write(STDOUT_FILENO, help, _strlen(help));
}

/**
* aux_help_alias - Display information about the builtin alias.
* Return: void
*/
void aux_help_alias(void)
{
char *help = "alias: alias [-p] [name[=value]...]\n";
write(STDOUT_FILENO, help, _strlen(help));

help = "\tDefine or display aliases.\n";
write(STDOUT_FILENO, help, _strlen(help));
}

/**
* aux_help_cd - Display information about the builtin cd.
* Return: void
*/
void aux_help_cd(void)
{
char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";
write(STDOUT_FILENO, help, _strlen(help));

help = "\tChange the current working directory.\n";
write(STDOUT_FILENO, help, _strlen(help));
}
