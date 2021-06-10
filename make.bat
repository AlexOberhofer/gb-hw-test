lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o src/uptime.o src/uptime.c
lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o uptime.gb src/uptime.o