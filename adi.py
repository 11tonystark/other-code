import serial
ser=serial.Serial('/dev/ttyUSB0',38400)

while(1):
		print(ser.readline())