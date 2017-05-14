CFLAGS :=
SOURCES :=
LDFLAGS :=

PLATFORM := bcm2835
ARCH := arm

include core/core.mk
include user/user.mk
include modules/modules.mk

