import serial
from time import time
import numpy as np
import matplotlib.pyplot as plt

with serial.Serial('/dev/cu.usbmodem141101', 2000000, timeout=10) as ser:
    c = 0
    t_start = time()
    samples = []
    while(True):
        try: 
            value = ser.readline()
            value = int(value[:-2].decode("UTF-8"))
        except:
            continue
        samples.append(value)
        if (time() - t_start) > 10:
            break
        c+=1
    print(f"RPS: {int(c/(time()-t_start))}")


plt.rcParams["figure.figsize"] = [7.50, 3.50]
plt.rcParams["figure.autolayout"] = True

while len(samples) < 50000:
    samples.append(0)

dt = 1/5000
y_axis = np.array(samples)
x_axis = np.arange(0, 10, dt)
fig, axs = plt.subplots()
axs.set_title("Signal")
axs.plot(x_axis, y_axis, color='C0')
axs.set_xlabel("Time")
axs.set_ylabel("Amplitude")

plt.show()
        