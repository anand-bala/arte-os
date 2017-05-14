mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(abspath $(dir $(mkfile_path)))

include $(current_dir)/arch/$(ARCH)/$(PLATFORM)/arch.mk

