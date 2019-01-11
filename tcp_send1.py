import socket
import time
import pygame
from pygame import joystick
import math
import serial
from time import sleep
import os

    
def map1(x,in_min,in_max,out_min,out_max):
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
def arm():
	
	_1u=j.get_button(6)
	_1d=j.get_button(7)
	_2u=j.get_button(8)
	_2d=j.get_button(9)
	_3u=j.get_button(10)
	_3d=j.get_button(11)
	_4u=j.get_button(4)
	_4d=j.get_button(2)
	_5u=j.get_button(5)
	_5d=j.get_button(3)
	_6u=j.get_hat(0)[1]
	_6d=j.get_hat(0)[0]
	data=0
	if _1u:
		#print('1up')
		data="nA"
	elif _1d:
		#print('1down')
		data="nB"

	elif _2u:
		#print('2up')
		data="nC"
	elif _2d:
		#print('2down')
		data="nD"
	elif _3u:
		#print('3up')
		data="nE"
	elif _3d:
		#print('3down')
		data="nF"
	elif _4u:
		#print('4up')
		data="nG"
	elif _4d:
		#print('4down')
		data="nH"
	elif _5u:
		#print('5up')
		data="nI"
	elif _5d:
		#print('5down')
		data="nJ"
	elif _6u:
		#print('6up')
		data="nK"
	elif _6d:
		#print('6down')
		data="nL"
	else: data="n "
	transmit.send(data)
	print(data)
def motorcode():
	x1=j.get_axis(0)
	y1=j.get_axis(1)
	gear=j.get_axis(3)
	hat=j.get_hat(0)
	
	gear=int(map1(gear,-1.0,1.0,9,0))
	x=map1(x1,-1.0,1.0,0.0,9999)
	y=map1(y1,-1.0,1.0,0.0,9999)

	zero=j.get_axis(2)

	if(zero>0.7):
		x=9999
		y=4999
	elif(zero<-0.7):
		x=0
		y=4999

	if hat[1]==1:
		y=0
	elif hat[1]==-1:
		y=9999
	if hat[0]==1:
		x=9999
	elif hat[0]==-1:
		x=0
	

	x=str(int(x)).zfill(4)
	y=str(int(y)).zfill(4)
	val="m"+str(gear)+"x"+str(x)+"y"+str(y)
	clear = lambda : os.system('tput reset')
	#clear()
	print(val)
	
	transmit.send(val)
	
	
	

	
	#print(ser.read())
	#print(ser.read(),ser.read(),ser.read(),ser.read())
	
	#print(ser.read(),ser.read(),ser.read(),ser.read())

count=0
TCP_IP = '192.168.1.7'
TCP_PORT = 5005
BUFFER_SIZE = 1024
MESSAGE = "Hello, World!"

transmit = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
transmit.connect((TCP_IP, TCP_PORT))



joystick.init()
pygame.display.init()
if pygame.joystick.get_count() == 0:
    print("No joystick detected")
    exit(0)
j=joystick.Joystick(0)
j.init()			
adx='a'
ady='b'
switch=True
active=True
while(1):

	pygame.event.pump()
	on=j.get_button(1)
	if on:
		sleep(0.2)
		if j.get_button(1):
			if active==True:
				active=False
				print('Idle')
			else:
				active=True
				print('Active')

	if active:
		change=j.get_button(0)
		if change:
			sleep(0.2)
			if j.get_button(0):
				if switch==True:
					switch=False
					print('Arm')
				else:
					switch=True
					print('Motor')

		if switch:
			motorcode()
		else:
			arm()