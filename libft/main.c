/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:15:15 by riosorio          #+#    #+#             */
/*   Updated: 2023/03/30 17:37:33 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	print_list(t_list **s)
{
	t_list *pl;

	pl = *s;
	while (pl != NULL)
	{
		printf("content %d \n", pl->content);
		printf("next %d \n", pl->next);
		pl = pl->next;
	}
	printf(" ### That's all ###\n");
}

void	*del(void *a)
{

}

int	main(void)
{	
	printf("##########################\n");
	printf("##### Linked list ######## \n");
	printf("##########################\n");

	t_list	**new_llist;
	t_list *nuevo;
	nuevo = malloc(sizeof(t_list));
	nuevo->content = 15;
	nuevo->next = NULL;
	new_llist = &nuevo;
	t_list *nuevo1;
	nuevo1 = malloc(sizeof(t_list));
	nuevo1->content = 1;
	ft_lstadd_front(new_llist, nuevo1);
	t_list *nuevo2;
	nuevo2 = malloc(sizeof(t_list));
	nuevo2->content = -15;
	ft_lstadd_front(new_llist, nuevo2);
	t_list *nuevo3;
	nuevo3 = malloc(sizeof(t_list));
	nuevo3->content = 42;
	ft_lstadd_front(new_llist, nuevo3);
	t_list *nuevo4;
	nuevo4 = malloc(sizeof(t_list));
	nuevo4->content = 42;
	ft_lstadd_back(new_llist, nuevo4);
	t_list *nuevo5;
	nuevo5 = NULL;
	ft_lstadd_back(NULL, nuevo5);

	print_list(new_llist);
	printf("size %d\n", ft_lstsize(*new_llist));
	printf("last %d\n", ft_lstlast(*new_llist)->content);

	/*
	// memeset test
	char b[10];
	printf("mine C = $ len = 7 and void b = %s \n", (char*)ft_memset(b, '$', 10));
	printf("just before the return");
	char c[10];
	printf("orig C = $ len = 7 and void b = %s", memset(c, '$', 10)); 
	printf("just before the return \n");


	//char *str;

	//str2 = malloc(50 * sizeof(char));
	//`:w
	//str2 = "I am a developer";
	char str[50] = "I am a developer 2";
	printf("Current: %s \n", str);
	bzero(str, 6);
	printf("after ori: %s \n", str);
	char str2[50] = "I am a developer 2";
	printf("Current: %s \n", str2);
	ft_bzero(str2, 6);
	printf("after mine: %s \n", str2);


	char strm[70] = "I am going to climb and i hope everything goes well";
	printf("orig: %s \n src: %s \n dst: %s \n", strm, strm + 5, strm + 11);
	printf("result: %s \n",	(char*)memcpy(strm + 11, strm + 5, 6));
	printf("result: %s \n",	strm);

	printf("###############\n");
	char strmm[70] = "I am going to climb and i hope everything goes well";
	printf("orig: %s \n src: %s \n dst: %s \n", strmm, strmm + 5, strmm + 11);
	printf("result: %s \n",	(char*)ft_memcpy(strmm + 11, strmm + 5, 6));
	printf("result: %s \n",	strmm);


	printf("$$$$$$ strlcat $$$$$$\n");
	char strc[20] = "Hola ";
	char strc1[15] = "mucho gusto";
	printf("dest: %s \n src: %s \n final: %s \n, result: %lu", strc, strc1, strc, strlcat(strc, strc1, 10));
	
	printf("$$$$$ tolower toupper $$$$\n");
	printf("to upp: b = %c \n", (char)ft_toupper('b'));
	printf("to upp: B = %c \n", (char)ft_tolower('B'));
	
	printf("$$$$$$ str chr $$$$$$$$$$\n");
	char  strs[15] = "Find the first";
 	char c = 'i';
 	printf("first %p\n", ft_strchr(strs, c));
 	printf("last %p\n", ft_strrchr(strs, c));
 	printf("first ori %p\n", strchr(strs, c));
 	printf("last  ori%p\n", strrchr(strs, c));

	printf("$$$$$$$$$$ mem chr $$$$$$$$$ \n");
	char s1[25] = "Ricardo is a pika";
	printf("value: %s\n", ft_memchr(s1, 'i', 5));

	printf("$$$$$$$$$$$ str n str $$$$$$$$$\n");
	char hay[35] = "start serching in this sentence";
	char nee[3] = "e";
	printf("find this: %s on this: %s result %s \n", nee, hay, ft_strnstr(hay, nee, 1));
*/

	return (0);
}
