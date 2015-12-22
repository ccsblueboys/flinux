/*
 * This file is part of Foreign Linux.
 *
 * Copyright (C) 2014, 2015 Xiangyan Sun <wishstudio@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <fs/zero.h>

static size_t zero_read(int tag, void *buf, size_t count)
{
	RtlZeroMemory(buf, count);
	return count;
}

static size_t zero_write(int tag, const void *buf, size_t count)
{
	return count;
}

struct virtualfs_char_desc zero_desc = VIRTUALFS_CHAR(mkdev(1, 10), zero_read, zero_write);
