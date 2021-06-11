CC = lcc -Wa-l -Wl-m -Wm-yn"HW-TEST"
AS = lcc -c 
TARGET = hw-test.gb
OBJS = src/hw-test.o

all: $(TARGET)

%.s: %.ms
	maccer -o $@ $<

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

clean:
	rm *.map *.ihx *.gb ./src/*.asm ./src/*.o ./src/*.sym ./src/*.lst