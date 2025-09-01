#pragma once
#include <cstdio>

#ifndef NT_LOG_LEVEL
#define NT_LOG_LEVEL 1 // 0=quiet, 1=info, 2=debug
#endif

#define LOG_INFO(fmt, ...)  do { if (NT_LOG_LEVEL>=1) std::fprintf(stderr, "[I] " fmt "\n", ##__VA_ARGS__); } while(0)
#define LOG_DEBUG(fmt, ...) do { if (NT_LOG_LEVEL>=2) std::fprintf(stderr, "[D] " fmt "\n", ##__VA_ARGS__); } while(0)
