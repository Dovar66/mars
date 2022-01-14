#ifndef LOGUNCOMPRESSBUFFER_H_
#define LOGUNCOMPRESSBUFFER_H_

#include <string>
#include <stdint.h>

#include "log_base_buffer.h"
#include "mars/comm/ptrbuffer.h"
#include "mars/comm/autobuffer.h"

namespace mars {
namespace xlog {

class LogCrypt;

class LogUncompressBuffer : public LogBaseBuffer{
public:
    LogUncompressBuffer(void* _pbuffer, size_t _len, bool _is_compress, const char* _pubkey);
    ~LogUncompressBuffer();
    
public:
    virtual size_t Compress(const void* src, size_t inLen, void* dst, size_t outLen);
    virtual void Flush(AutoBuffer& _buff);

private:
    bool __Reset();
    char __GetMagicSyncStart();
    char __GetMagicAsyncStart();
};


}
}

#endif /* LOGBUFFER_H_ */
