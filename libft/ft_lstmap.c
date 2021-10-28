#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_lst;
    t_list  *new_elem;

    if (!lst || !f || !del)
        return (NULL);
    if (!(new_lst = ft_lstnew(f(lst->content))))
        return (NULL);
    lst = lst->next;
    while (lst)
    {
        if (!(new_elem = ft_lstnew(f(lst->content))))
        {
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&new_lst, new_elem);
        lst = lst->next;
    }
    return (new_lst);
}
