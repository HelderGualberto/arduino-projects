import serial, time

with serial.Serial('/dev/cu.usbmodem141101', 2000000, timeout=10) as ser:
    c = 0;
    t_start = time.time()
    while(True):
        value = ser.readline()
        c += 1
        now = time.time()
        if (now - t_start) > 1.0:
            print(f"Rate: {c}/s - v: {value}")
            t_start = now
            c = 0
        
    