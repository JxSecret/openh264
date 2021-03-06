include build/platform-msvc-common.mk
ASM = nasm
CFLAGS += -DMT_ENABLED
LDFLAGS += user32.lib
ifeq ($(ENABLE64BIT), Yes)
ASMFLAGS += -f win64
ASMFLAGS_PLATFORM = -DWIN64
CFLAGS += -DWIN64
else
ASMFLAGS += -f win32 -DPREFIX
CFLAGS += -DWIN32
endif

