/* 
 * Mount handle
 *
 * Copyright (c) 2011, Joachim Metz <jbmetz@users.sourceforge.net>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _MOUNT_HANDLE_H )
#define _MOUNT_HANDLE_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include <libcstring.h>
#include <liberror.h>

#include "bdetools_fuse.h"
#include "bdetools_libbde.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct mount_handle mount_handle_t;

struct mount_handle
{
	/* The libbde input volume
	 */
	libbde_volume_t *input_volume;

	/* The nofication output stream
	 */
	FILE *notify_stream;
};

int mount_handle_initialize(
     mount_handle_t **mount_handle,
     liberror_error_t **error );

int mount_handle_free(
     mount_handle_t **mount_handle,
     liberror_error_t **error );

int mount_handle_signal_abort(
     mount_handle_t *mount_handle,
     liberror_error_t **error );

int mount_handle_set_recovery_password(
     mount_handle_t *mount_handle,
     const libcstring_system_character_t *string,
     liberror_error_t **error );

int mount_handle_open(
     mount_handle_t *mount_handle,
     const libcstring_system_character_t *filename,
     liberror_error_t **error );

int mount_handle_close(
     mount_handle_t *mount_handle,
     liberror_error_t **error );

int mount_handle_get_size(
     mount_handle_t *mount_handle,
     size64_t *size,
     liberror_error_t **error );

#if defined( HAVE_FUSE_H )

int mount_handle_fuse_open(
     const char *path,
     struct fuse_file_info *file_info );

int mount_handle_fuse_read(
     const char *path,
     char *buffer,
     size_t size,
     off_t offset,
     struct fuse_file_info *file_info );

int mount_handle_fuse_readdir(
     const char *path,
     void *buffer,
     fuse_fill_dir_t filler,
     off_t offset,
     struct fuse_file_info *file_info );

int mount_handle_fuse_fgetattr(
     const char *path,
     struct stat *stat_info,
     struct fuse_file_info *file_info );

#endif /* defined( HAVE_FUSE_H ) */

#if defined( __cplusplus )
}
#endif

#endif

