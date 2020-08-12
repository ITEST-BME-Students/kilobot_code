#include <kilolib.h>


// These are the parameters of the internal clock of each robot.
int counter = 0;
int counter_max = 100;
int counter_delay = 20;

// Flags that signal the reception and sending of messages.
int sent_message = 0;
int new_message = 0;

// Storage of communication.

int received_distance = 0;
int received_counter = 0;
int delta = 0;

message_t message;

// this seems a place holder to make sending the msg more eficient
message_t *tx_message(){return &message;}

void rx_message(message_t *message, distance_measurement_t *distance)
{
    // Set the flag on message reception.
    new_message = 1;
    received_distance = estimate_distance(distance);
    received_counter = message->data[0];
}


void tx_message_success() {
    sent_message = 1;
}

void flash(){
    set_color(RGB(1,1,0));
    delay(200);
    set_color(RGB(0,0,0));
    
}


void update_clock(){
    delta = received_counter - counter;
    if (delta < -2){delta=-2;} 
    if (delta > 2){delta= 2;} 
    counter = counter + delta;
}

void error_flash(){
    set_color(RGB(1,1,1));
    delay(100);
    set_color(RGB(1,1,1));
    
}


void message_sent(){
        if (sent_message){
        sent_message = 0;
        //set_color(RGB(1,0,0));
        //delay(50);
        //set_color(RGB(0,0,0));
    
    }
}

void message_received(){
        if (new_message){
        new_message = 0;
        //set_color(RGB(0,1,0));
        //delay(50);
        //set_color(RGB(0,0,0));
        update_clock();
    
    }
}


void setup() {
    // some dummy message
    message.type = NORMAL;
    message.data[0] = 0;
    message.crc = message_crc(&message);
    
    // put your setup code here, to be run only once
    // add some random delay here to ensure initiall desync
    delay(rand_hard()*10);
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
    kilo_message_tx_success = tx_message_success;
    kilo_message_tx = tx_message;
    kilo_message_rx = rx_message;
    // start program
    kilo_start(setup, loop);

    return 0;
}
