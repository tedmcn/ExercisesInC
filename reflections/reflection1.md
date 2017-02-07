  Our main takeaway from Sprint 1 was that we needed to allocate tasks more reasonably and effectively. We found that trying to divide up the tasks into 4 perfect chunks isn't realistic. Instead we are defining the few things that we need to get done and assigning them to multiple people to do independently (for research) or together (for things like coding). So far this has been effective and I think will make sense moving forward as it will be more code-heavy and it would be difficult to merge all of our seperate work together without errors.

  I think my team is doing well with the eduScrum guide and ceremonies having never seen anything like it before. I think the three of us from Brandeis are a bit unused to having such strict guidelines to follow for something that might otherwise be left up to us, such as the workflow and organization of eduScrum. That being said, I haven't always had the best experiences trying to do a group coding project, so I think there is a lot of value in the ritual of it all, although I can't say its been enough time to see it yet. I would say we were prepared for the sprint review, but personally I didn't understand the types of questions we were going to be asked or the amount of depth you were asking from us.

  At the beginning of the first Sprint, we were really at a loss for what type of project we were going to do because anything that sounded fun was too intense and anything that sounded reasonable or even easy was boring and trivial. We were planning on just doing the bouncing ball because it was done in a previous class. We eventually expanded on the bouncing ball project and incorperated the B-curve, which I think makes the project a lot more interesting.

[Exercises in C 1](../exercises/ex01)

[Exercises in C 2](../exercises/ex02)

[Reading Questions](../reading_questions/thinkos.md)


Question:

Consider the following pseudo-code:

        function foo(){
        int[] y;

        for(int i=1;i<11;i*2){
        y.add(i);
        }

        int[] x = array[3]; //Create array of size 3

        x=y;

        }

Assuming the code above is written in a compiled language, will this code compile? If not at what step of the compilation process will the code terminate?

The code will recieve an error during the 3rd step of compilation during the static checking. The above code create an array with 4 items in it and then tries to assign that whole array to an array with 3 indexes. This is from section 1.3 in Think OS.
