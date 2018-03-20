/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:22:18 by vvinogra          #+#    #+#             */
/*   Updated: 2018/03/11 20:00:04 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	play_music(t_wolf *wolf)
{
	int	r;

	srand(time(NULL));
	r = rand() % 3;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	if (r == 0)
		wolf->music = Mix_LoadMUS("music/bgmusic1.mp3");
	if (r == 1)
		wolf->music = Mix_LoadMUS("music/bgmusic2.mp3");
	if (r == 2)
		wolf->music = Mix_LoadMUS("music/bgmusic3.mp3");
	wolf->shoot_sound = Mix_LoadWAV("music/shootgun.wav");
	if (!wolf->music || !wolf->shoot_sound)
	{
		ft_putendl(Mix_GetError());
		exit(0);
	}
	Mix_Volume(0, 32);
	Mix_PlayMusic(wolf->music, -1);
	Mix_VolumeMusic(5);
}

int		mute_sound(int keycode, t_wolf *wolf)
{
	if (keycode == 46 && wolf->mute_sound == 0)
	{
		wolf->mute_sound = 1;
		Mix_HaltMusic();
	}
	else if (keycode == 46 && wolf->mute_sound == 1)
	{
		Mix_PlayMusic(wolf->music, -1);
		wolf->mute_sound = 0;
	}
	return (0);
}
