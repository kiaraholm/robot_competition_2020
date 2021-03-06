# Milestone 2
## Get the Robot to Follow Line

To complete this milestone, I began by determining that I wanted to read the data using Option 1 from the Tutorial posted on GitHub. I copied & pasted the calibration code, but tweaked it a little bit so that it moved a little slower. I also decided that to keep myself entertained while it was calibrating I wanted to play the "Jeopardy" theme song, so I added that to the setup() portion of the code. 

I also decided to use Serial.println() and open the Serial monitor to see how the line sensors calibrated instead of using the Buzzer as it provides exact values. (I wanted to see that 2500 corresponded to the middle of the line).

After watching the 5 minute video, I started by implementing the bang-bang control. I got the robot to follow the line pretty well by lowering the tolerance for error (50) and setting the speeds so that the right and left wheels had larger differences when turning (i.e., 120 & 20). As I increased the speed, the robot definitely got more and more jerky. Even though I increased the speed, the robot was not that fast at following the line in comparison to when I decided to switch over to using PD control (See Bang-Bang Video).

As I wanted to see if I could get the robot to move a bit smoother & faster, I played around with the code for PD control. I tinkered with the derivative gain and there really is a sweet spot in terms of getting it to move smoothly and fast. Even by increasing the D-gain a little bit to 6 made the robot incredibly jerky (See PD Control Video 1). I decided to lower it to 1 as it allowed the robot to move quickly and in the smoothest fashion (See PD Control Video 2). I also changed the base speed for the right and left wheels as I realized while I was completing Milestone 1 that for the robot to move straight the right wheel needed to be slightly slower.

Also, putting a horiztonal piece of tape at the end of the line allows the robot turn around and come back! 
~ no more chasing after robots woohoo ~
