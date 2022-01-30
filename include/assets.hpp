#include "main.hpp"

#ifdef TESTS
#define DECLARE_FILE(name, prefix) extern "C" uint8_t _binary_##name##_start[]; extern "C" uint8_t _binary_##name##_end[]; struct prefix##name { static size_t getLength() { return _binary_##name##_end - _binary_##name##_start; } static uint8_t* getData() { return _binary_##name##_start; } };
DECLARE_FILE(de_json,)
DECLARE_FILE(en_json,)
DECLARE_FILE(es_json,)
DECLARE_FILE(fr_json,)
DECLARE_FILE(ja_json,)
DECLARE_FILE(ko_json,)
#endif
