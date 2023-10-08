#!/usr/bin/python3
#
# This is a program to display the Arduino output as a diagram.
#
# Setup:
# pip install matplotlib
#
import os
import matplotlib.pyplot as plt
import re

MAX_DATA_POINTS = 1500

HERE = os.path.dirname(__file__) or "."
DATA_FILE = os.path.join(HERE, "data.txt")
pattern = re.compile(r"([0-9]+)%")

f = open(DATA_FILE)
y = []

def update_data():
    global y
    for line in f:
        data = pattern.findall(line)
        for d in data:
            y.append(int(d))
    print("data points:", len(y))
    y = y[-MAX_DATA_POINTS:]

plt.figure()

plt.xlabel("Minutes ago")
plt.ylabel("Moisture in %")
plt.title("Moisture level of the watering sensor")

def get_x():
    return [s / 60 for s in range(len(y), 0, -1)]

update_data()
line, = plt.plot(get_x(), y)
plt.gca().invert_xaxis()
# update plot
# from https://stackoverflow.com/a/39916933/1320237
while 1:
    line.set_data(get_x(), y)
    plt.draw()
    plt.pause(1)
    update_data()
