#include "log_uncompress_buffer.h"
#include <cstdio>
#include <time.h>
#include <algorithm>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdio.h>

#include "log/crypt/log_crypt.h"
#include "log/crypt/log_magic_num.h"
#include "log_base_buffer.h"


#ifdef WIN32
#define snprintf _snprintf
#endif

namespace mars {
namespace xlog {

LogUncompressBuffer::LogUncompressBuffer(void* _pbuffer, size_t _len, bool _isCompress, const char* _pubkey)
    :LogBaseBuffer(_pbuffer, _len, _isCompress, _pubkey) {

}

LogUncompressBuffer::~LogUncompressBuffer() {

}

void LogUncompressBuffer::Flush(AutoBuffer& _buff) {
    LogBaseBuffer::Flush(_buff);
}

bool LogUncompressBuffer::__Reset() {
    if (!LogBaseBuffer::__Reset()) {
        return false;
    }

    return true;
}

//因为本类不压缩，所以下面三个方法是空实现，无实际意义
size_t LogUncompressBuffer::Compress(const void* src, size_t inLen, void* dst, size_t outLen){
    return inLen;
}

char LogUncompressBuffer::__GetMagicSyncStart() {
    return 0;
}

char LogUncompressBuffer::__GetMagicAsyncStart() {
    return 0;
}
}
}
