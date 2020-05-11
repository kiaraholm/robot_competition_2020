# Milestone 6
## Get the Robot to Solve & Repeat w/ Memorized Path

To reduce the stored path into the simplest one, I attempted to implement the first suggestion in the tutorial which was to reduce each three-item sequence with a "U" into a single direction. 

To do this, I began by creating a list of the three-item sequences with "U"s that appeared in the stored path. Then, I determined the appropriate direction that the sequence should reduce to. I ended up with 7 distinct sequences that became either a "R", "L", or "U". I thought that I might need to somehow keep track of the "+" intersection and the individual branches, but by creating rules for each sequence that was not necessary. I'm not too sure if this worked because of the nature of the particular solution for this maze or if this would work for other mazes with "+" intersections. The image in this folder contains my thought process while trying to figure this portion out.

After this, I attempted to turn these rules into code for the path_reduce() function. I knew that I wanted to replace the first element of each three-item sequence with the appropriate reduced direction and then shift the remainder of the path after the sequence so that it started at the current position of the array (and to remove last two elements from the very end of the array). However, if I was iterating through the array this might be an issue. If the next item after the three-item sequence was a "U", then the function might miss it because of the way the array shifts & the for loop iterates through. 

I didn't know how to address this issue, so the uploaded code has part of my solution to the path_reduce(), but is incomplete. Gah.

Again, similarly to the last milestone, the uploaded video is of the robot completing the task using the solution code.