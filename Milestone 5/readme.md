# Milestone 5
## Get the Robot to Navigate Maze with Branching

It was at this moment (milestone) that I knew... I had some major fixing that needed to be done with the code. 

I started by working on how to get the robot to distinguish between left and right turns. Following the Milestone 3 tutorial, I began by creating a separate function for each turn type & relying on sensor values to detect which type of turn the robot had come across. I decided to implement the reactive approach, but found that the robot didn't make a clean, sharp turn. No matter how much I tinkered with the threshold values the robot made the turns by making two jerky turning motions. To make the turn more clean and create a turn that was a single motion, I followed the suggestion at the bottom of the tutorial and did a hybrid approach. I found that adding delay(90) fixed this turning issue!

After this, I moved onto figuring out how to record the path through the maze. I decided to create an array of integers (solution[]) in which 1 = left & 2 = right. This seemed to do the trick, but this is also where I realized that my turning code was not quite working. I found that when it was making a turn, the robot thought it was making multiple turns. For example, when it made a right turn it recorded making two right turns. This happened for some turns and for some turns it worked totally fine. I tried to debug this issue, but I couldn't figure out what was going on. 

I decided to leave it for the moment and tried to see if I could figure out how to get the robot to detect different types of intersections. I began by tackling u-turns, which was simple as I approached it with a ballistic approach. When I began working on how to get it to detect the other types of intersections I realized that the robot was recording turns twice for intersections that looked like "T"s. 

It was at this point that I realized that I did not know how to figure this out and relied on the solution code to complete the milestone. I have uploaded the code that I attempted to use with bits of my code mixed with its of your code. I had to rely on your solution code for the robot to work as it does in the video.


