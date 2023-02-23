# CS 120 Module 2 Applied Project: Randomization

For this project, you will design and implement a C++ program that creates and evaluates
randomization algorithms.

## Requirements

- You must work in a team of 2-4 people of your choosing for this project.
- All of your programming files should be in a private GitHub repository in the course
  organization.
    - Your repository must be named with the convention: M2AP-netid1-netid2[-netid3-
      netid4], where netidX is your UVM NetID username.
    - Have one team member create the repository and add the other members as collaborators
      (on GitHub, go to Settings —> Manage Access and add the others’ GitHub usernames).
- Your repository should have a .gitignore file, a README file, and a CMakeLists.txt.

- In a header file, write a template class that holds a vector of the template type. Write all of the
  code for this class in the header file. Do not create a corresponding .cpp file. The class must
  have methods to do the following:
    - Randomize the vector.
        - Each team member must write their own randomize method and they must be significantly
          different from each other. They must all be included in the class and the method names
          should include the author’s netid or initials.
            - Your can get individual bonus points if you choose not to use the built-in
              (pseudo-)random number generators and your randomize algorithm is still effective.
            - You can lose individual points if your randomize method uses the built-in shuffle
              function.
    - Sort the vector.
        - You are allowed to reuse code from Data Structures & Algorithms, or use the built-in C++
          sort function, for this method.
    - Find an item in the vector.
    - Overload the << operator to print the vector of items.
    - You can add other functionality as needed.

- The goal of your main program is to determine which of the randomize algorithms work
  well. This means you need to agree as a team on some quantitative metric to determine the
  effectiveness of a randomizing algorithm, test each randomize method according to your
  metric, and report in your README about your results.
    - Your team can get bonus points if your metric is especially creative and impressive.
- Your testing and explanation in your main program and README.md file should be thorough
  and correctly determine if an algorithm randomizes well.
- All of the above must be pushed to your GitHub repository.
- Every teammate must submit the URL of the GitHub repository.

## Grading

The project is out of 50 points.

- 5 pts Declare and define one template class in a header file as described above.
- 15 pts (Individual pts) Write a custom randomization algorithm that is effective according to the
  metric.
- 20 pts The concept and execution of the metric as the main program are correct.
- 10 pts The README file contains a professional report of the results as described above.

It is expected that your program will compile, run, and have good style. If your project does not,
you may receive point deductions.

## Brainstorming

- Relative frequency test overall (all outcomes should occur roughly as many times as each other, given enough trials)
- Relative frequency PER each index of the vector, to see if any one index in particular is inappropriately skewed (
  would theoretically require many more trials to be as accurate as the previous test)
- Some sort of visual test(?) if we could manage some sort of visual (even printed to console), a particularly egregious
  error in our randomization algorithm may be apparent (though we would be cautious not to declare something as a
  pattern with certainty)
- Testing for lots of 0s or 1s in a row on a shuffled vector of equally-many 0s and 1s (like, a sequence of 10
  consecutive 1s or 0s is to be expected, but at a very specific frequency, so we could test consecutive sequences of
  length 1-50 or something, just to see if the frequency is at all out-of-whack)

- This might all require an IMMENSE amount of memory. lol. We'll see. And will hopefully clean as we go.
- Oooooh checking for linear independence? That's a cool idea, I did that in a class. That could be cool. Hm.

Some ideas for random testing suites from (
this source.)[https://medium.com/unitychain/provable-randomness-how-to-test-rngs-55ac6726c5a3]