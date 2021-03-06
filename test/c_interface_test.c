#include "codec_api.h"

// Cast to this function type to ignore other parameters.
typedef int (*Func)(void*);
#define CALL(p, m) (((Func)((*p)->m))(p))
// Check if the function return an expected number.
#define CHECK(n, p, m) check(n, CALL(p, m), #m)

typedef void(*CheckFunc)(int, int, const char*);

void CheckEncoderInterface(ISVCEncoder* p, CheckFunc check) {
  CHECK(1, p, Initialize);
  CHECK(2, p, Initialize2);
  CHECK(3, p, Uninitialize);
  CHECK(4, p, EncodeFrame);
  CHECK(5, p, EncodeFrame2);
  CHECK(6, p, EncodeParameterSets);
  CHECK(7, p, PauseFrame);
  CHECK(8, p, ForceIntraFrame);
  CHECK(9, p, SetOption);
  CHECK(10, p, GetOption);
}

void CheckDecoderInterface(ISVCDecoder* p, CheckFunc check) {
  CHECK(1, p, Initialize);
  CHECK(2, p, Uninitialize);
  CHECK(3, p, DecodeFrame);
  CHECK(4, p, DecodeFrame2);
  CHECK(5, p, DecodeFrameEx);
  CHECK(6, p, SetOption);
  CHECK(7, p, GetOption);
}
