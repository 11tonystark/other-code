import serial
ser=serial.Serial('/dev/ttyUSB0',38400)

while(1):
		##print(ser.readline())
		#ser.write('000PE=1\r\n000TR\r\n')
		#ser.write("8788")
		print(ser.read(2))
