
import serial                           # import the module 
ComPort = serial.Serial('/dev/ttyUSB0') # open ttyUSB0 

ComPort.baudrate = 9600                 # set Baud rate 
ComPort.bytesize = 8                    # Number of data bits = 8
ComPort.parity = 'N'                    # No parity
ComPort.stopbits = 1                    # Number of Stop bits = 1

#Write character 'A' to serial port                            
              # Convert Character to byte array
#data = bytearray('<012>TR<\r><\n>')
#No = ComPort.write('000PE=1\r\n')
No = ComPort.write('000PE=1\r\n')
data = ComPort.readline()
print(data)
#
#No1 = ComPort.write('000TR\r\n')
#data1 = ComPort.readline()
#print(data1)

No2 = ComPort.write('000T0\r\n')
data2 = ComPort.readline()
print('Moisture, Soil Electrical Conductivity (tc) ,Temp C ,Temp F, Soil Electrical Conductivity , Real Dielectric Permittivity, Imag Dielectric Permittivity,Real Dielectric Permittivity(tc), Imag Dielectric Permittivity(tc)')
print('as follows')
print('\n')
print(data2)

#No3 = ComPort.write('000T2\r\n')
#data3 = ComPort.readline()
#print(data3)

No4 = ComPort.write('000T3\r\n')
data4 = ComPort.readline()
print('F) Temp C , Temp F , Moisture Loss Tangent,Soil Electrical Conductivity (tc) Real Dielectric Permittivity, Real Dielectric Permittivity (tc), Imag Dielectric Permittivity, Imag Dielectric Permittivity (tc),Soil Electrical Conductivity, Diode Temperature ,Blank')
print('as follows')
print('\n')
print(data4)

No5 = ComPort.write('000T4\r\n')
data5 = ComPort.readline()
print('V1 , V2,V3, V4, V5 (volt hai mc)')
print('\n')
print(data5)




