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


int op_write(const char *path, const char *buf, size_t size, off_t offset,
            struct fuse_file_info *fi)
{
    size_t un_offset = (size_t)offset;
    struct ext4_inode inode;
    size_t ret = 0;
    uint32_t extent_len;

    /* Not sure if this is possible at all... */
    ASSERT(offset >= 0);

    DEBUG("write(%s, buf, %zd, %zd, fi->fh=%d)", path, size, un_offset, fi->fh);
    int fd = create_file(path, O_RDWR);
    int inode_get_ret = inode_get_by_number(fd, &inode);

    if (inode_get_ret < 0) {
        return inode_get_ret;
    }
    return 0;
}
