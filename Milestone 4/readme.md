# Milestone 4
## Get the Robot to Navigate Simple Maze

I started with the same code as Milestone 2 & 3. Before I began trying to figure out how to make it stop once it reached the end, I decided to make one quick change. Instead of using the Jeopardy theme song, I went for the Windows XP start-up song while the robot calibrated. I may have driven my family members crazy by making them hear this each time the robot started the maze, but that's okay.

In any case, I added some Serial.println() into the code to see what each of the sensors were reading as it went through the maze and when it got to the very end. I noticed that only at the very end the left-most and right-most sensors output a value of 1000. I decided to create a while() within the loop(), so that once it reached the end the motors would stop as I set them both to 0. That seemed to do the trick!

I tried to make it so that the Windows XP shudown song played once it stopped, but since I used a while() to make the robot stop the first note of the song just repeats itself and the whole song is never played. :(