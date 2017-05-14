CFLAGS :=
SOURCES :=
LDFLAGS :=



ifndef PLATFORM
$(warning $$PLATFORM is not defined. Defaulting to bcm2835 - Raspberry Pi 0/1)
PLATFORM := bcm2835
ARCH := arm
endif

ifndef ARCH
$(warning $$ARCH is not defined. Defaulting to arm and bcm2835 - Raspberry Pi 0/1)
PLATFORM := bcm2835
ARCH := arm
endif

ifeq ($(realpath core/arch/$(ARCH)/$(PLATFORM)/arch.mk),)
$(error $(shell pwd))
$(error PLATFORM or ARCH does not exist)
endif

include core/core.mk
include user/user.mk
include modules/modules.mk

