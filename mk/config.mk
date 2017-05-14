CFLAGS :=
SOURCES :=
LDFLAGS :=

PLATFORM := bcm2835
ARCH := arm

include src/core/core.mk
include src/user/user.mk
include src/modules/modules.mk

