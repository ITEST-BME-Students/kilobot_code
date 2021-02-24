# kilobots

## Hardware

### Charging

Each Kilobot has a built-in charger, which charges the onboard battery when +6 volts is applied to any of the legs, and GND is applied to the charging tab.

![](misc/charger.png) 


### Switching on/off

Turning the robots on, is done by placing the power jumper as shown below.

![](misc/power.png) 

### Using the programming wand

To program the robots, the wand should be in *normal mode*. The jumper should be in the position shown below.

![programmer](misc/programmer.png)

Running the kilogui should be done as follows,`sudo kilogui ` and the programming the robots requires these steps:

+ **Bootload**. LED turns blue.
+ **Upload**. LED flashed blue-yellow. Once the uploading is done, the LED flashes green.
+ **Run**  Often, I need to click this twice.



## Link to the API and manual

+ API: [https://www.kilobotics.com/docs/index.html]()
+ Manual: [http://ftp.k-team.com/kilobot/user_manual/old/Kilobot_UserManual.pdf]()

## Algorithm

The code works as follows (the square brackets refer to variable names in the code). 

+ Each robot’s main loop is started after a random initial delay (see `setup` function). This maximizes the probability of the robots being initially desynchronized. 

+ After this, each robot starts its internal clock `counter`, counting up to `counter_max`, each step taking 20 ms `counter_delay`. This implies that each cycle, on average, takes `t` seconds, t  = (counter_max * counter_delay) / 100.


+ The value of `counter_max` is set after each pulse (See `flash` function) in the range `[counter_max_lower, counter_max_upper]`. This simulates the noise in the cycle interval of individual, isolated fireflies. 
+ While this cycle is running, the robot emits its clock state at a rate of 1000 /`counter_delay` Hz. Robots picking up this message calculate the difference `delay` between the received clock state and their clock. If their internal clock is ahead of the received clock, they reduce their clock by `correction_steps` steps.

## Exercises

### Injecting noise

For this experiment, you place a number of robots in close proximity. Measure the time it takes for robots to synchronize their flashing. You should try and alter the amount of noise on individual cycle lengths by editing the following lines of code 

```c
int counter_max_lower = 95;
int counter_max_upper = 105;
```

Is there any level of noise beyond which synchronization does happen?

### Subgroups

For this experiment, you separate two groups of robots by at least five body diameters. This prevents communication between the groups. Each group will synchronize internally. Once this is established, you could bring the groups closer together. Does the complete group manage to sync? 

### Message delay

The signals fireflies use to synchronize (light flashes) travel almost instantaneously between individuals. However, other animals, such as some crickets, synchronize their behavior using acoustic signals. Over short distances, the delay between the emission and the reception of the signal will be short. However, as distance increases, the receiver will receive a time-delayed version of the emitted signal. This might interfere with the ability to synchronize clocks. 

Although the robots use light to communicate and can only communicate over short distances, we can simulate the effects of delayed reception of signals. To this end, you can comment and alter the line

```c
int simulated_delay = 0;
```

This line of code simulates a delayed reception of the clock information of a neighbor. Observe whether robots achieve synchronization. What does failure or success tell you about the sensitivity of this system to delays?


## Compiling locally 

https://diode.group.shef.ac.uk/kilobots/index.php/Getting_Started:_How_to_work_with_kilobots

Compiling code is done as follows.

```
./compileCode.sh synced_flashing
```

## Compiling online

To run the code, you can use the online editor to compile it hex (https://www.kilobotics.com/editor). After this, you can upload and run the code as described here: https://www.kilobotics.com/documentation.  

Note: Jan 2021. I don't get this to work any longer.