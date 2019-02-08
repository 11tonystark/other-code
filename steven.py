
import serial                           # import the module 

ComPort = serial.Serial('/dev/ttyUSB0') # open ttyUSB0 

ComPort.baudrate = 9600                 # set Baud rate 
ComPort.bytesize = 8                    # Number of data bits = 8
ComPort.parity = 'N'                    # No parity
ComPort.stopbits = 1                    # Number of Stop bits = 1

#Write character 'A' to serial port                            
                 # Convert Character to byte array
#data = bytearray('<012>TR<\r><\n>')                    
No = ComPort.write('024TR\r\n')
#No = ComPort.write('021TO\r\n')# Write data to serial port
data = ComPort.readline()               # Wait and read data from serial port
print(data)
#<addr>SN=?<CR><LF>

