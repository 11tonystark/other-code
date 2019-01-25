import serial
ser=serial.Serial('/dev/ttyUSB2',9600)

while(1):
		print(ser.readline())