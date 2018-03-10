from tkinter import *
import serial

class Drone:
	'''
	Class used to control a drone with a mouse or a gamepad.
	'''
	def __init__(self, arduinoPort=None):
		'''
		Open communication with arduino
		'''
