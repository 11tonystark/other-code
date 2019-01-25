import serial
import time
import datetime

ts = time.time()
st = datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')
print st + ": Session started!"
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=0)
while True:
    try:
        if(not(ser.isOpen())):
            ser.open()
        cmd = ser.readline()
        ts = time.time()
        st = datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')
        print st + ": " + cmd
    except Exception as ex:
        error = "Exception is: " + ex.__str__()
        if(not(ser == None)):
            ser.close()
            ser = None
            ts = time.time()
            st = datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')
            print st + ": " + err