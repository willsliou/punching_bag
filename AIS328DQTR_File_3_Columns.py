# X-axis facing me. Bottom of bag. Right side.


import smbus
import time
from datetime import datetime

# Get I2C bus
bus = smbus.SMBus(1)

# AIS328DQTR address, 0x18(24)
# Select control register1, 0x20(32)
#       0x27(39)    Power ON mode, Data rate selection = 50Hz
#                   X, Y, Z-Axis enabled
bus.write_byte_data(0x18, 0x20, 0x27)
# AIS328DQTR address, 0x18(24)
# Select control register4, 0x23(35)
#       0x30(48)    Continuous update, Full-scale selection = +/-8G
bus.write_byte_data(0x18, 0x23, 0x30)

# open files
f= open("Accer_0.1_Left_Side_X_Away_2.txt","w+")
f.write("TimeNow\t\tX-Axis\tY-Axis\tZ-Axis\r\n")
counter = 100 # 6 second reads @ 0.1 reads
now = datetime.now()

while counter > 1:
    time.sleep(0.1)
    #time.sleep(0.5)
    # AIS328DQTR address, 0x18(24)
    # Read data back from 0x28(40), 2 bytes
    # X-Axis LSB, X-Axis MSB
    data0 = bus.read_byte_data(0x18, 0x28)
    data1 = bus.read_byte_data(0x18, 0x29)

    # Convert the data
    xAccl = data1 * 256 + data0
    if xAccl > 32767 :
        xAccl -= 65536

    # AIS328DQTR address, 0x18(24)
    # Read data back from 0x2A(42), 2 bytes
    # Y-Axis LSB, Y-Axis MSB
    data0 = bus.read_byte_data(0x18, 0x2A)
    data1 = bus.read_byte_data(0x18, 0x2B)

    # Convert the data
    yAccl = data1 * 256 + data0
    if yAccl > 32767 :
        yAccl -= 65536

    # AIS328DQTR address, 0x18(24)
    # Read data back from 0x2C(44), 2 bytes
    # Z-Axis LSB, Z-Axis MSB
    data0 = bus.read_byte_data(0x18, 0x2C)
    data1 = bus.read_byte_data(0x18, 0x2D)

    # Convert the data
    zAccl = data1 * 256 + data0
    if zAccl > 32767 :
        zAccl -= 65536

    # Output data to screen
    print "Acceleration in X-Axis : %d" %xAccl
    print "Acceleration in Y-Axis : %d" %yAccl
    print "Acceleration in Z-Axis : %d" %zAccl
    now = datetime.now()
    current_time = now.strftime("%H:%M:%S")
    print "Current Time =", current_time
    print "\n"
    f.write("%s\t%d\t%d\t%d\n" % (current_time, xAccl, yAccl, zAccl))
    counter -= 1

f.close()   
