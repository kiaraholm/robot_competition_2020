# Milestone 4
## Get the Robot to Navigate Simple Maze

I started with the same code as Milestone 2 & 3. Before I began trying to figure out how to make it stop once it reached the end, I decided to make one quick change. Instead of using the Jeopardy theme song, I went for the Windows XP start-up song while the robot calibrated. I may have driven my family members crazy by making them hear this each time the robot started the maze, but that's okay.

In any case, I added some Serial.println() into the code to see what each of the sensors were reading through the Serial Monitor as the robot went through the maze and got to the very end. I noticed that only at the end the left-most and right-most sensors output a value of 1000. I decided to create a while loop within the loop(), so that once those sensors began outputting that value the motors would stop. 

Here is the code that does this:

  while (sensor_vals[0] == 1000 && sensor_vals[5] == 1000) {
    motors.setSpeeds(0, 0);
  }

I tried to make it so that the Windows XP shudown song played once it reached the end of the maze, but since I used a while loop the first note of the song just repeats itself and the whole song is never played. :(
