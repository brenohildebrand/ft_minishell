/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lua_loadfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:09:16 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lua_loadfile(t_mini mini, t_lua_state lua_state, t_cstring path)
{
	if (luaL_loadfile(lua_state, path))
	{
		cstring_to_stderr("Oops!" 
						  "An error ocurred while loading the config file.\n");
		mini_quit(mini);
	}
}
