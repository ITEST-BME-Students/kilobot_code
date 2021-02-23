#include "kilolib.h"

// These are the parameters of the internal clock of each robot.
int counter = 0;

int counter_max = 100;
int counter_max_lower = 99;
int counter_max_upper = 101;
int counter_delay = 10;
int correction_steps = 2;
int simulated_delay = 0;

// Flags that signal the reception and sending of messages.
int sent_message = 0;
int new_message = 0;

// Storage of communication.
message_t message;
int received_distance = 0;
int received_counter = 0;
int delta = 0;

// This is is the message transmission callback function. 
// Copy-pasted from example. Not sure what it does but
// this seems a place holder to make sending the msg more eficient
// DO NOT TOUCH - not sure why but these bits seems essential.
message_t message;
// this seems a place holder to make sending the msg more eficient
message_t *tx_message(){return &message;}

void rx_message(message_t *message, distance_measurement_t *distance)
{
    // Set the flag on message reception.
    new_message = 1;
    received_distance = estimate_distance(distance);
    received_counter = message->data[0];
    //set_color(RGB(0,0,1));
    //delay(50);
    //set_color(RGB(0,0,0));
}


// a random number generation function, I wrote based on this
// https://stackoverflow.com/questions/24216021/mapping-one-range-of-integers-to-another
int random_number(int output_start, int output_end){
    int output;    
    int input = rand_soft();
    int output_range = output_end - output_start;
    output = input % (output_range + 1);
    output = output + output_start;
    return output;
}


void tx_message_success() {
    sent_message = 1;
    //set_color(RGB(1,0,0));
    //delay(50);
    //set_color(RGB(0,0,0));
}

void flash(){
    set_color(RGB(1,1,0));
    delay(250);
    set_color(RGB(0,0,0));
    //set noisy counter_max for next loop.
    counter_max = random_number(counter_max_lower, counter_max_upper); 
    
}


void update_clock(){
    received_counter = received_counter + simulated_delay;
    signed char delta = counter - received_counter;
    if (delta > 2){deltas=-correction_steps;} 
    if (delta < 2){delta= 0;} 
    counter = counter + delta;
}

void error_flash(){
    set_color(RGB(1,1,1));
    delay(100);
    set_color(RGB(1,1,1));
    
}


void message_sent(){if (sent_message){sent_message = 0;}}

void message_received(){
        if (new_message){
        new_message = 0;
        update_clock();
    
    }
}


void setup() {
    // signal start of program
    set_color(RGB(1,0,0));
    delay(1000);
    set_color(RGB(0,0,0));

    // some dummy message
    message.type = NORMAL;
    message.data[0] = 0;
    message.crc = message_crc(&message);
    
    // put your setup code here, to be run only once
    
    //Seed the software random number generator. 
    //As per the api, the hardware number generator is slow and should be avoided
    rand_seed(rand_hard());
    // set first value of counter_max
    counter_max = random_number(counter_max_lower, counter_max_upper); 

    // add some random delay here to ensure initiall desync
    // the random number generator returns an 8 bit number, ie range 0-255
    delay(rand_soft()*10);
}

void loop() {
    // put your main code here, to be run repeatedly
    message_sent();
    message_received();
    message.data[0] = counter;
    message.crc = message_crc(&message); //be sure to recompile the crc
    if (counter > counter_max){flash();counter=0;}
    else {counter = counter + 1;}
    delay(counter_delay);
}

int main() {
    // initialize hardware
    kilo_init();
    kilo_message_tx_success = tx_message_success; // register tranmsission success callback
    kilo_message_tx = tx_message; // register message transmission calback
    kilo_message_rx = rx_message; // register message reception callback
    // start program
    kilo_start(setup, loop);

    return 0;
}
