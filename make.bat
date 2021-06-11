lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o src/hw-test.o src/hw-test.c
lcc -Wa-l -Wl-m -Wl-j -Wm-yn"HW-TEST" -DUSE_SFR_FOR_REG -o hw-test.gb src/hw-test.o