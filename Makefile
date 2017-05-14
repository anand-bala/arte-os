include mk/config.mk


SOURCES +=
CFLAGS +=
LDFLAGS +=

OBJECTS += $(patsubst %.c, %.o, $(filter %.c, $(SOURCES)))
OBJECTS += $(patsubst %.s, %.o, $(filter %.s, $(SOURCES)))
OBJECTS += $(patsubst %.S, %.o, $(filter %.S, $(SOURCES)))

BUILD_DIR := build/

EXECUTABLE := $(BUILD_DIR)kernel.elf
LIST := $(BUILD_DIR)kernel.list
MAP := $(BUILD_DIR)kernel.map
BIN := $(BUILD_DIR)kernel.bin

all: $(BIN) $(LIST)

$(BIN) : $(EXECUTABLE)
	$(TARGET)objcopy $(EXECUTABLE) -O binary $(BIN)

$(LIST) : $(EXECUTABLE)
	$(TARGET)objdump -d $(EXECUTABLE) > $(LIST)

$(EXECUTABLE): $(OBJECTS)
	$(TARGET)gcc $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

%.o: %.c
	$(TARGET)gcc $(CFLAGS) -c $< -o $@

%.o: %.s
	$(TARGET)gcc $(CFLAGS) -c $< -o $@

%.o: %.S
	$(TARGET)gcc $(CFLAGS) -c $< -o $@


clean_o:
	rm -f $(OBJECTS)

clean: clean_o
	rm -f $(EXECUTABLE)


emulate: $(EXECUTABLE)
	qemu-system-arm -M versatilepb -cpu arm1176 -m 128M -nographic -kernel $(EXECUTABLE)

emulate_dbg: $(BIN)
	qemu-system-arm -M versatilepb -cpu arm1176 -m 128M -nographic -s -S -kernel $(EXECUTABLE)


