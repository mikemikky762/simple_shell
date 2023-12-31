#include "main.h"

/**
* add_rvar_node - Adds a variable at the end of a r_var list.
* @head: The head of the linked list.
* @lvar: The length of the variables.
* @val: The value of the variables.
* @lval: The length of the values.
* Return: The address of the updated head.
*/
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
r_var *new, *temp;

new = malloc(sizeof(r_var));
if (new == NULL)
return (NULL);

new->len_var = lvar;
new->val = val;
new->len_val = lval;

new->next = NULL;
temp = *head;

if (temp == NULL)
{
*head = new;
}
else
{
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = new;
}
return (*head);
}

/**
* free_rvar_list - Will frees an r_var list.
* @head: The head of the linked list.
* Return: void.
*/
void free_rvar_list(r_var **head)
{
r_var *temp;
r_var *curr;

if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}
