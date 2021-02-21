# Kilobot code

## Algorithm

The code works as follows (the square brackets refer to variable names in the code). 

+ Each robot’s main loop is started after a random initial delay. This maximizes the probability of the robots being initially desynchronized. After this, each robot starts its internal clock [counter], counting up to 100+-5 [counter_max], each step taking 20 ms [counter_delay]. This implies that each cycle, on average, takes 2 seconds). The exact number of steps is set after each pulse in the range 95-105. This simulates the noise in the cycle interval of individual, isolated fireflies. 

+ While this cycle is running, the robot emits its clock state at a rate of 2 Hz. Robots picking up this message calculate the difference [delay] between the received clock state and their clock. If the received clock is ahead, they forward their clock by two steps. If the received clock state is behind, they reduce their clock state by two steps.

## Running the code

To run the code, you can use the online editor to compile it hex (https://www.kilobotics.com/editor). After this, you can upload and run the code as described here: https://www.kilobotics.com/documentation. Instead of using the online compiler, you can also use a local compiler. This is also described in the kilobots documentation: https://www.kilobotics.com/documentation.  
