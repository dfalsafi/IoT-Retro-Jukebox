/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "c:/Users/mahav/Labs/Project/FinalProject/src/FinalProject.ino"
#include "Particle.h"

void setup();
void loop();
#line 3 "c:/Users/mahav/Labs/Project/FinalProject/src/FinalProject.ino"
int ButtonPINRED = D4; //sets all of the pins for the buttons and speaker
int ButtonPINYELLOW = D3;
int ButtonPINGREEN = D2; 
int ButtonPINBLUE = D5;
int speakerPIN = D0; 

bool ButtonGreen = FALSE; //sets all of the button presses to false on start
bool ButtonYellow = FALSE;
bool ButtonRed = FALSE;
bool ButtonBlue = FALSE;

String wantSong = "No song selected"; //starts with no song selected

bool didItPlay = FALSE; //stores if the song played or not


//Stores all of the song notes and their durations
//There are 4 songs, Zelda, Rick, Shape, and Like
int zelda[] = {293,0,0,293,311,349,369,415,0,415,415,466,523,554,698,659,0,523};
int zeldaDurations[] = {16,16,16,16,16,16,16,2,8,8,16,16,16,1,4,8,8,2};


int rick[] = {293, 0, 330, 370, 293, 330, 330, 330, 370, 330, 220, 0, 247, 277, 
              293, 247, 0, 330, 370, 330, 220, 247, 293, 247, 370, 370, 330, 
              220, 247, 293, 247, 330, 330, 293, 220, 247, 293, 
              247, 293, 330, 277, 247, 220, 220, 330, 293};
int rickDuration[] = {2, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 2, 8, 8, 8, 8, 8, 8, 8, 3, 16, 16, 16, 16, 6,
                      6, 3, 16, 16, 16, 16, 6, 6, 3, 16, 16, 16, 16, 4, 8, 8, 16, 4, 8, 4, 2};


int shape[] = {277, 330, 277, 311, 277, 250, 277, 330, 330, 
               330, 330, 330, 330, 330, 330, 330, 330, 330, 
               330, 330, 370, 415, 415, 0, 
               494, 370, 415, 415, 415, 415, 
               370, 370, 370, 415, 370, 370, 330, 
               370, 370, 370, 370, 330, 277, 0};
int shapeDuration[] = {3, 3, 4, 3, 3, 8, 8, 4, 8, 8, 8, 4, 4, 8, 4, 4, 8, 8, 4, 4, 8, 
                       4, 2, 2, 8, 8, 8, 4, 4, 8, 8, 8, 8, 8, 4, 8, 8, 4, 8, 8, 8, 4, 2, 3};


int like[] = {659, 659, 659, 659, 523, 440, 0, 659, 
              659, 659, 659, 659, 523, 440, 0, 
              440, 659, 523, 523, 440, 523, 523, 
              587, 659, 523, 523, 440, 523, 
              523, 440, 392, 659, 523, 523, 440, 
              523, 523, 587, 587, 659, 523, 
              523, 440, 523, 523, 440, 784, 
              659, 659, 523, 523, 392, 392, 392, 392, 
              392, 587, 523, 523, 0, 784, 784, 659, 
              659, 523, 392, 392, 392, 392, 587, 523, 523};
int likeDuration[] = {8, 8, 8, 8, 8, 8, 4, 16, 16, 8, 8, 8, 
                      8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
                      4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 
                      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
                      8, 4, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 
                      4, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8};


//define the song values
#define song0 0 //this would be the zelda song
#define song1 1 //this is the Rick song
#define song2 2 //Shape song
#define song3 3 //Like song
#define noSong 4 //No song selected

int mode = noSong; //sets the song mode to no song on start

int setSong(String inputString); //declaring function for setting the song

void setup() {

    pinMode(ButtonPINRED, INPUT_PULLDOWN); //sets all of the ButtonPIN's to have an input pulldown meaning that when the button isn't pressed it grounds the circuit.
    pinMode(ButtonPINYELLOW, INPUT_PULLDOWN);
    pinMode(ButtonPINGREEN, INPUT_PULLDOWN);
    pinMode(ButtonPINBLUE, INPUT_PULLDOWN);
    
    Particle.variable("doYouWantThisSong", wantSong); //Cloud variable that store the song that is wanted to play
    Particle.function("setTheSong", setSong); //Cloud function that sets the song from the website
    
}


void loop() {
     ButtonRed = digitalRead(ButtonPINRED); //sets the variable state to whatever state the button is in. False if not pressed, true if pressed
     ButtonGreen = digitalRead(ButtonPINGREEN);
     ButtonYellow = digitalRead(ButtonPINYELLOW);
     ButtonBlue = digitalRead(ButtonPINBLUE);

      if(ButtonYellow == HIGH){ //if statements to see if the button is pressed
        wantSong = "Shape"; //sets the wanted song to the pressed button
      }
      if (ButtonRed == HIGH){
        wantSong = "Zelda";
      }
      if (ButtonGreen == HIGH){
        wantSong = "Rick";
      }
      if (ButtonBlue == HIGH){
        wantSong = "Like";
      }


    if (mode == song0 && didItPlay == FALSE){
    //all of these if else statements see what song wants to be played and playes it to the speaker

    // iterate over the notes of the melody:
    for (unsigned int thisNote = 0; thisNote < arraySize(zelda); thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1500 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1500/zeldaDurations[thisNote];
    tone(speakerPIN, zelda[thisNote],noteDuration);

    // to distinguish the notes, set a min time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPIN);
    }

    didItPlay = TRUE; //sets the song to played already so it only loops once.
        
  } else if (mode == song1 && didItPlay == FALSE){
    //Rick song
    for (unsigned int thisNote = 0; thisNote < arraySize(rick); thisNote++) {
    
    int noteDuration = 1500/rickDuration[thisNote];
    tone(speakerPIN, rick[thisNote],noteDuration);
    
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(speakerPIN);
    }

    didItPlay = TRUE; 
    
  } else if (mode == song2 && didItPlay == FALSE){
    //Shape song
    for (unsigned int thisNote = 0; thisNote < arraySize(shape); thisNote++) {
    
    int noteDuration = 1000/shapeDuration[thisNote];
    tone(speakerPIN, shape[thisNote],noteDuration);
    
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(speakerPIN);
    }
    
    didItPlay = TRUE;
    
  } else if (mode == song3 && didItPlay == FALSE){
    //Like song
    for (unsigned int thisNote = 0; thisNote < arraySize(like); thisNote++) {
    
    int noteDuration = 1500/likeDuration[thisNote];
    tone(speakerPIN, like[thisNote],noteDuration);
    
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(speakerPIN);
    }

    didItPlay = TRUE;

  }
  

  
}
//this function gets called when the html website sends inputs
int setSong(String inputString) { //It gets the argument that it sent and sets the song.
  if (inputString == "Zelda") {
        mode = song0; //sets the mode to the zelda song
        didItPlay = FALSE; //sets that the song hasn't played yet
        
        return 0; //returns with the song
    } else if (inputString == "Rick" ) {
        mode = song1;
        didItPlay = FALSE;
        
        return 1;
    } else if (inputString == "Shape") {
        mode = song2;
        didItPlay = FALSE;
        
        return 2;
    } else if (inputString == "Like"){
        mode = song3;
        didItPlay = FALSE;

        return 3;
    } else {
        return -1; //if the input was wrong, returns -1 for error
    }
}

