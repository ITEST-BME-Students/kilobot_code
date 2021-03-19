# Descriptions of videos

## Experiment 01: Base case

These videos show 21 robots organized in a dense cluster. They run the default algorithm (see here: [https://github.com/ITEST-BME/kilobot_code]()).

## Experiment 02 - 04: Varying cycle length

These videos show 21 robots organized in a dense cluster. They run the default algorithm. However, the length of the cycle of each robot varies from cycle to cycle. In other words, in isolation, each robot's flashing rhythm would differ slightly, and the rhythm would change from cycle to cycle. The variation in cycle length increases from batch 02 to 04.

## Experiment 05 - 07: Varying group size
 
 For experiments 05-07, the algorithm used in the base case was restored. The cycle lengths of all robots were fixed to the same value. In these experiments, the group size was gradually reduced.
 
## Experiment 08: Varying group shape

Experiment 08 shows the robots' behavior when laid out in a rectangle.

## Experiment 09: Merging subgroups

This experiment observes what happens when the robots are initially separated into two isolated groups. A piece of board is placed between the groups to ensure they can not communicate. After the groups have synced, they are brought into contact.

# Questions

Considering the videos as experimental data, please answer the following questions.

**Question 1: noise on the robots' internal cycles**

We saw that individual beetles have a "free-running rhythm." Solitary beetles flash at a steady pace. Some of the videos described have been recorded varying the internal cycle of the robot's flashing.  In particular, experiments 02 to 04 have increasing levels of noise on the individual robots' cycles. These three experiments can be compared with the base case in experiment 01, yielding four conditions in total.

+ (a) For each condition, determine the average it takes for the robots to attain synchronized flashing. If the robots do not achieve sync, this data point should not be included in the average.

+ (b) In addition to the average time to sync, determine how many times the robots successfully synchronize their flashing (i.e., success rate out of three trials).

+ (c) Formulate a 1-2 sentence conclusion based on the data you tabulated for (a) and (b).

**Question 2: group size**

Experiments 05 - 07 vary the group size. Use these clips to answer the following questions.

+ (a) Does the time to achieve synchronized flashing depend on the size of the group? 

+ (b) If so, do larger or smaller groups synchronize more quickly.

+ (c) Try and formulate a hypothesis about why the time to sync depends (not) on the group size.


**Question 3: group layout**

Experiment 08 changes the spatial layout of the robots. Compare the behavior in these clips with that of the base case (experiment 01).

+ (a) Formulate a 1-2 sentence conclusion about the effect of group shape on the robots' ability to achieve synchronization.
