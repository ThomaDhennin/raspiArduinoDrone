# My Drone project

## Quick presentation

This project aims to create a drone from scratch and use a Raspberry pi 3 as flight controller and an Arduino as motor driver. The choice to add an Arduino was made because the raspberry is quite limited in terms of PWM signals and we need 4 PWM signals to drive the 4 motors. The final purpose of the drone is to be controlled by any computer peripherals that anyone can have at home (gamepad, mouse movements following, etc.). The software will be home made with Python and Arduino.

## First steps

The first steps, before buying drone frames and motors, is to simulate the four motors by LEDs. The goal is to have already the gamepad transmission and control the LEDs brightness with it.
