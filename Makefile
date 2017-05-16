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
HEX := $(BUILD_DIR)kernel.hex
IMG := $(BUILD_DIR)kernel.img

all: $(BIN) $(LIST)

rebuild: clean all

$(BIN) : $(EXECUTABLE)
	$(TARGET)objcopy $(EXECUTABLE) -O ihex $(HEX)
	$(TARGET)objcopy $(EXECUTABLE) -O binary $(BIN)
	$(TARGET)objcopy $(EXECUTABLE) -O binary $(IMG)

$(LIST) : $(EXECUTABLE)
	$(TARGET)objdump -d $(EXECUTABLE) > $(LIST)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	@printf "[%10s] $@\n" "BUILDING"
	@$(TARGET)gcc $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

%.o: %.c
	@printf "[%10s] $<\n" "COMPILING"
	@$(TARGET)gcc $(CFLAGS) -c $< -o $@

%.o: %.s
	@printf "[%10s] $<\n" "COMPILING"
	@$(TARGET)gcc $(CFLAGS) -c $< -o $@

%.o: %.S
	@printf "[%10s] $<\n" "COMPILING"
	@$(TARGET)gcc $(CFLAGS) -c $< -o $@


clean_o:
	rm -f $(OBJECTS)

clean: clean_o
	rm -f $(EXECUTABLE)


emulate: $(EXECUTABLE)
	qemu-system-arm -M versatilepb -cpu arm1176 -m 128M -nographic -kernel $(EXECUTABLE)

emulate_dbg: $(BIN)
	qemu-system-arm -M versatilepb -cpu arm1176 -m 128M -nographic -s -S -kernel $(EXECUTABLE)


