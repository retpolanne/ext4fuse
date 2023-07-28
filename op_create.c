/*
 * Copyright (c) 2010, Gerard Lledó Vives, gerard.lledo@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation. See README and COPYING for
 * more details.
 */


#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <inttypes.h>

#include "common.h"
#include "disk.h"
#include "inode.h"
#include "logging.h"
#include "ops.h"


int op_create(const char *path, mode_t mode, struct fuse_file_info *fi)
{
    struct ext4_inode inode;
    size_t ret = 0;
    uint32_t extent_len;

    DEBUG("create(%s, buf, fi->fh=%d)", path, fi->fh);
    int fd = create_file(path, mode);
    DEBUG("create file %s fd %d", path, fd);
    if (fd < 0) {
        return -1;
    }
    return 0;
}
