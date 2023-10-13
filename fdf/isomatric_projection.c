/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isomatric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:23:55 by eushin            #+#    #+#             */
/*   Updated: 2023/10/11 14:23:56 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void rotate(double *x, double *y, double *z)
{
	double	prev_x;
	double	prev_y;
	double	theta;

	prev_x = *x;
	prev_y = *y;
	theta = M_PI / 6;

	*x = -prev_x * cos(theta) + prev_y * cos(theta);
	*y = prev_x * sin(theta) + prev_y * sin(theta) - *z;
	return ;
}

t_point	*iso(t_point *point)
{
	double	prev_x;
	double	prev_y;
	double	theta;

	prev_x = point->x;
	prev_y = point->y;
	theta = M_PI / 6;

	point->x = -prev_x * cos(theta) + prev_y * cos(theta);
	point->y = prev_x * sin(theta) + prev_y * sin(theta) - point->z;
	return (point);
}