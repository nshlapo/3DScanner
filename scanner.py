import serial
from math import *
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import time

ser= serial.Serial('/dev/ttyACM0')
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
X = []
Y = []
Z = []
now = time.time()
future = now + 15
plt.ion()
plt.show()
ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')
while True:
	if time.time() > future:
		break
	try:
		line = ser.readline()
		line = line[:-3]
		print line
		dis= line.split(',')
		#print dis
		theta = ((float(dis[0]))*math.pi)/180.0
		phi = ((float(dis[1])+10)*math.pi)/180.0
		# theta = ((float(dis[0])+60)*pi)/180.0
		# phi = ((float(dis[1])-10)*pi)/180.0
		r = float(dis[2])
		x = r*cos(theta)*cos(phi)
		y = r*sin(theta)*cos(phi)
		z = r*sin(phi)
		if z > 15:
			X.append(x)
			Y.append(y)
			Z.append(z)
			ax.scatter(x, y, z)
			plt.draw()
		else:
			pass
	except:
		pass
plt.ioff()
ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')
ax.scatter(X, Y, Z)
plt.show()

