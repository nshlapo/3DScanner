import serial
from math import *
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import time

ser= serial.Serial('/dev/ttyACM1')
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
# plt.ion()
# plt.show()
X = []
Y = []
Z = []
now = time.time()
future = now + 15
while True:
	if time.time() > future:
		break
	try:
		print 'Reading...'
		line = ser.readline()
		line = line[:-3]
		dis= line.split(',')
		#print dis
		theta = float(dis[0])
		phi = float(dis[1])
		r = float(dis[2])
		x = r*cos(theta)
		y = r*sin(theta)
		z = r*sin(phi)
		if z > 15:
			X.append(x)
			Y.append(y)
			Z.append(z)
		else:
			pass
	except:
		pass

ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')
ax.scatter(X, Y, Z)
plt.show()

