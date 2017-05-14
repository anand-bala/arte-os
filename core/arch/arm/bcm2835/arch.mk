mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(abspath $(dir $(mkfile_path)))
src_dir     := $(current_dir)/src

includes := $(abspath $(current_dir)/include)
srcs := $(wildcard $(src_dir)/*.c) $(wildcard $(src_dir)/*.s) $(wildcard $(src_dir)/*.S)


TARGET := arm-none-eabi-
CFLAGS += -I$(includes)
CFLAGS += -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles -g -Wl,-T,$(current_dir)/kernel.ld
SOURCES += $(srcs)

