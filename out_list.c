
int i;

i = argc;
while (--i)
{
	printf("%d\n",(*lsta)->content);
	if ((*lsta)->next != NULL)
		*lsta = (*lsta)->next;
else
break;
}
ft_lstclear_end(lsta);
	