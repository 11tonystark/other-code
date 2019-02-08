import serial
ser=serial.Serial('/dev/ttyUSB1',9600)

while(1):
		##print(ser.readline())
		#ser.write("012TR<\r><\n>")
		ser.write("<012>TR<\r><\n>".encode())
		print(ser.readline())
