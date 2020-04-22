# Milestone 1
## Get the Robot to Move

I started by downloading the Zumo Shield Arduino library. I took a look at the "ZumoMotorExample" to understand and familiarize myself with how to control the motors. From this, I simplified the code way down so that I was just left with a couple of lines that set the left and right motor speeds. I decided to create a forward drive and stop function, so that I could put them in the loop() instead of setting the speeds in the loop(). 

Took a couple of tries, but I found the appropriate left and right motor speeds so that the robot moved forward in a straight line. When I set both speeds to 200, the robot drifted towards the left. This is why the speed for the right motor is slightly lower than the speed for the left motor. 
