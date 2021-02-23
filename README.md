# kilobots_code

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

+ While this cycle is running, the robot emits its clock state at a rate of 1000 /`counter_delay` Hz. Robots picking up this message calculate the difference `delay` between the received clock state and their clock. If the received clock is ahead, they forward their clock by `correction_steps` steps. If the received clock state is behind, they reduce their clock state by `correction_steps` steps.

## Running the code

To run the code, you can use the online editor to compile it hex (https://www.kilobotics.com/editor). After this, you can upload and run the code as described here: https://www.kilobotics.com/documentation. Instead of using the online compiler, you can also use a local compiler. This is also described in the kilobots documentation: https://www.kilobotics.com/documentation.  


# Compiling locally 

https://diode.group.shef.ac.uk/kilobots/index.php/Getting_Started:_How_to_work_with_kilobots

Compiling code:

```
./compileCode.sh synced_flashing
```

** Notice: There is no extension `.c`!**