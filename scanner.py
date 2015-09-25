import serial
from math import *
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

ser= serial.Serial('/dev/ttyACM1')
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')

while True:
	try:
		line = ser.readline()
		line = line[:-3]
		dis= line.split(',')
		#print dis
		theta = float(dis[0])
		phi = float(dis[1])
		r = float(dis[3])
		x = r*cos(theta)
		y = r*sin(theta)
		z = r*sin(phi)
		ax.scatter(x,y,z)
		plt.show()
	except:
		pass

