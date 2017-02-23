  The big change we made from last sprint into this one was to migrate our communication from Facebook to Slack, which I think was a great step to keep us organized and on track. I suggested and pushed the change because I personally don't use facebook, but I think it also helped my teammates because having a different environment for work and play helps keep the two seperate.
  
  The obvious difficulty we are having right now is rallying and finishing the code we need for the project. I havn't been too sure how to approach this issue, and perhaps this is my own fault for not approaching it sooner, but I really havn't been able to get any help from my teammates. At first I thought that this level of coding was above their head so I didn't really mind taking a bit more of the load, but even when I try to delegate small tasks that would help move the code along, they don't get the work back to me. For example, the whole point of messing around with Blender was so that we could easily export the model of the curve instead of trying to model it with triangles in OpenGL code. Somehow, that whole side-project got derailed and they played around with Blender a lot, but they never sent the model to me. I ended up just exporting the model myself.

  I hate to sound so "woe is me", but I really tried to help them do the code. I set up an object framework so that they could fill in the simple little functions without necissarily having to worry about the big picture, but I havn't seen any progress on that. Furthermore, I know we, Prof. Downey, spoke specifically about team coding so that many people can get their hands dirty at once, but only recently did they all install a proper linux partition with the needed libraries. Even in regards to installing linux, I was trying to be very helpful, but in the first week or two of class when I offered the response I would get is "I'll figure it out at home".
  
  I think I'm going to try to force the four of us to meet this weekend so we can all actually code together.


  I didn't do any more of the Head First C examples because I have been focusing on our project code.

  [Reading Questions](../reading_questions/thinkos.md)

  ### Exam Question:

  Which of the following types of file systems would be most efficient for a computer which is editing movies?

1) iNode with a block size of 1KiB
2) iNode with a block size of 4KiB
3) iNode with a block size of 8KiB
4) FAT file system

3 because you want the largest size nodes since we are editing large movies (we don't have to worry so much about fragmentation), and we don't want a FAT file system because it would be too expensive to find the next page consistantly.

This was from 4.2 Disk Metadata.
