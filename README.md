# algo-composition-in-c

*REALLY* SIMPLE ALGORITHMIC COMPOSITION GENERATOR

## NEW IN VERSION 3: 
* ALLOW THE USER TO CHOOSE BETWEEN DAC WITH OR WITHOUT FILE RENDER
* ADD PERCUSSION AS THE COMPOSITION PROGRESS (HI-HAT STARTING FROM 2ND SECTION AND KICK STARTING FROM 3RD SECTION)
* iF FILE RENDER IS SELECTED, POSSIBILITY AT THE END TO PLAY A TIME-STRETCHED VERSION OF WHAT YOU JUST HEARD

## This program will ask the user 5 things
### Starting with: 
* the mode in which the composition will played (type 1-7)
* the playback speed in BPM (int)
* the length of the composition (in seconds) (float) 
* the number of sections he wants
* the number he wants each section to loop
* File render: with or without
### At the end:
* stop the program ?
* listen to a time-stretched version ? If yes, time stretch factor is asked.
* try again ?

Based on these parameters, the program will create and play a composition written into a .csd file.

Every time a section is generated, the same section will be saved (melody features such as notes duration and pitch) into an matrix. When looping, the program will pick up all the information it needs in order to recreate the same melody but pitched up an octave.

The program contains some instructions in order to intuitively react and handle the random musical features that are being generated.

For example: 
* Whenever the dominant will be played, the following note will always be the root.
* The composition is set to always start on the root and end on a full cadence.
* Some interesting algorithms are implemented to provide rythms based on the BPM user input.
* Starting from the second section, the hi hat will start playing; depending of the note value, the hi hat will be closed, slightly open or open.
* Starting from the third section the kick will start playing. 

After compiling, infos about your composition will be displayed.

At the end if the user want to hear the time-stretched version, a new .csd file will be created using the newly created .aif file with a sndwarp opcode

Note: 
If you want to make change to the code and recompile it => 
1. Go to the right directory 
2. $ make clean
3. $ make
4. $ ./exe 







