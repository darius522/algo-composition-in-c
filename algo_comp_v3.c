//DARIUS PETERMANN
//ALGO_COMP.C
//FOR MORE INFOS: README


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//Will converte randomly generated int number to frequency in herz
float StepToHerz(int scale , int thisnote){
    float thisnotehz;
    
    switch(scale){
            
            //Ionian
        case(1):  switch(thisnote){
                printf("ionian\n");
            case 1: thisnotehz = 261.63; break; //C4
            case 2: thisnotehz = 293.66; break; //D4
            case 3: thisnotehz = 329.63; break; //E4
            case 4: thisnotehz = 349.23; break; //F4
            case 5: thisnotehz = 392.00; break; //G4
            case 6: thisnotehz = 440.00; break; //A4
            case 7: thisnotehz = 493.88; break; //B4
            case 8: thisnotehz = 523.25; break; //C5
                
        }
            break;
            
            //Dorian
        case(2):  switch(thisnote){
                printf("dorian\n");
            case 1: thisnotehz = 261.63; break; //C4
            case 2: thisnotehz = 293.66; break; //D4
            case 3: thisnotehz = 311.13; break; //Eb4
            case 4: thisnotehz = 349.23; break; //F4
            case 5: thisnotehz = 392.00; break; //G4
            case 6: thisnotehz = 440.00; break; //A4
            case 7: thisnotehz = 466.16; break; //Bb4
            case 8: thisnotehz = 523.25; break; //C5
        }
            break;
            
            //Phrygian
        case(3):  switch(thisnote){
                printf("phry\n");
            case 1: thisnotehz = 261.63; break; //C4
            case 2: thisnotehz = 277.18; break; //Db4
            case 3: thisnotehz = 311.13; break; //Eb4
            case 4: thisnotehz = 349.23; break; //F4
            case 5: thisnotehz = 392.00; break; //G4
            case 6: thisnotehz = 415.30; break; //Ab4
            case 7: thisnotehz = 466.16; break; //Bb4
            case 8: thisnotehz = 523.25; break; //C5
                
        }
            break;
            
            //Lydian
        case(4):  switch(thisnote){
                printf("lydian\n");
            case 1: thisnotehz = 261.63; break; //C4
            case 2: thisnotehz = 293.66; break; //D4
            case 3: thisnotehz = 329.63; break; //E4
            case 4: thisnotehz = 369.99; break; //F#4
            case 5: thisnotehz = 392.00; break; //G4
            case 6: thisnotehz = 440.00; break; //A4
            case 7: thisnotehz = 493.88; break; //B4
            case 8: thisnotehz = 523.25; break; //C5
                
        }
            break;
            
            //Mixolydian
        case(5):  switch(thisnote){
                printf("mixo\n");
            case 1: thisnotehz = 261.63; break; //C4
            case 2: thisnotehz = 293.66; break; //D4
            case 3: thisnotehz = 329.63; break; //E4
            case 4: thisnotehz = 349.23; break; //F4
            case 5: thisnotehz = 392.00; break; //G4
            case 6: thisnotehz = 440.00; break; //A4
            case 7: thisnotehz = 466.16; break; //Bb4
            case 8: thisnotehz = 523.25; break; //C5
                
        }
            break;
            
            //Aeolian
        case(6):  switch(thisnote){
                printf("aeolian\n");
            case 1: thisnotehz = 261.63; break; //C4
            case 2: thisnotehz = 293.66; break; //D4
            case 3: thisnotehz = 311.13; break; //Eb4
            case 4: thisnotehz = 349.23; break; //F4
            case 5: thisnotehz = 392.00; break; //G4
            case 6: thisnotehz = 415.30; break; //Ab4
            case 7: thisnotehz = 466.16; break; //Bb4
            case 8: thisnotehz = 523.25; break; //C5
                
        }
            break;
            
            //Locrian
        case(7):  switch(thisnote){
                printf("locrian\n");
            case 1: thisnotehz = 261.63; break; //C4
            case 2: thisnotehz = 277.18; break; //Db4
            case 3: thisnotehz = 311.13; break; //Eb4
            case 4: thisnotehz = 349.23; break; //F4
            case 5: thisnotehz = 369.99; break; //Gb4
            case 6: thisnotehz = 415.30; break; //Ab4
            case 7: thisnotehz = 466.16; break; //Bb4
            case 8: thisnotehz = 523.25; break; //C5
                
        }
            break;
    }
    return thisnotehz;
}


int main(int argc, char* argv[])
{
    //1. Defining variables
    int i = 0; //loop index
    int e = 0; //loop index
    int l = 0; //loop index
    int a = 0; //loop index
    int randnotes[256];//array filled with notes
    int x = 0; //# of notes defined by user
    int thisnote; //Note to be put in array
    float thisnotehz; //Cnnverted step to hz notes
    srand((unsigned)time(0)); // seed the random number generator with system clock
    int notediff; //Calculate the difference between current and previous note
    int flag = 2;
    FILE* csdPointer;
    char* csdFileName;
    int scale;
    float totaltime = 0;
    //float notelength = 0.2;
    int BPM; //BPM user input
    double notespeed; //In seconds
    int division; //Division for the notes (4th, 8th, 16th, 32th)
    int flagend;
    float time; //User input for compositiobn time
    float currenttime = 0;
    float notevalue; //Count the beat in the current measure
    float measurevalue = 0.0;
    int measurecount = 1.0;
    char scalename[12];
    float lpnoise;//Cutoff for lowpass noise = x := (c - a) * (z - y) / (b - a) + y
    float sequencespeed[256][256];//Array in which the first sequence will be written in
    float sequencehz[256][256];
    float hhtotaltime[256][256];//Array in which the first sequence will be written in
    float hhnotespeed[256][256];
    int loop;//User decides how many times he wants to listen to each sequence
    int notespeedformat, thisnotehzformat;
    int section; //Number of sections
    float notespeedhh; //For HH
    int divisionpercuarray[256]; //Random speed generator for HH
    int divisionpercu = 10;
    float totaltimehh;
    float notevaluehh;
    int notespeedhhformat;
    float openorclosed;
    int notespeedkickformat;
    int totalkicktimeformat;
    float kicktotaltime[256][256];//Array in which the first sequence will be written in
    float kicknotespeed[256][256];
    float notespeedkick;
    float totalkicktime;
    int dacorsf;

    
    
    
retry:
    printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    printf("Please enter the number corresponding to\n the mode in which the composition will be generated in\n");
    printf("Type 1 for Ionian\n");
    printf("Type 2 for Dorian\n");
    printf("Type 3 for Phrygian\n");
    printf("Type 4 for Lydian\n");
    printf("Type 5 for Mixlydian\n");
    printf("Type 6 for Aeolian\n");
    printf("Type 7 for Locrian\n");
    printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    printf("◕‿◕");
    printf("Type (1-7): ");
    scanf("%d", &scale);
    //Check user input
    if(scale < 1 || scale > 8){
        printf("\nError: Invalide scale type, try again.\n");
        goto retry;
    }
    printf("\nNow Please Enter the BPM of the Composition between 20 to 200 (int)\n\n!NOTE!\nFor best result a tempo between 30 and 100 is advised\n\n");
    printf("(͡ʘ ͜ʖ ͡ʘ)");
    printf("BPM (ie.50BPM): ");
    scanf("%d", &BPM);
    if(BPM < 20 || BPM > 200){
        printf("\nError: Invalide BPM, try again.\n");
        goto retry;
    }
    printf("\nNow Please Enter the time length of each sections(in seconds)(float)\n");
    printf("(づ｡◕‿‿◕｡)づ");
    printf("Time (ie.8sec): ");
    scanf("%f", &time);
    if(time < 0.0 || time > 1000.0){
        printf("\nError: Invalide time entry, try again.\n");
        goto retry;
    }
    printf("\nNow Please Enter the number of section you want(int)\n\n!NOTE!\nThe HiHat will start playing from the 2nd section, the kick drum from the 3rd\n\n");
    printf("(ಠ_ಠ)");
    printf("  Number of sections (ie.3): ");
    scanf("%d", &section);
    if(section < 0 || section > 100){
        printf("\nError: Invalide section entry, try again.\n");
        goto retry;
    }
    printf("\nNow Please Enter how many times you want to repeat each sections(int)(1-10)\n");
    printf("༼ つ ◕_◕ ༽つ");
    printf("  Number of loops (ie.2): ");
    scanf("%i", &loop);
    if(loop < 0 || loop > 100){
        printf("\nError: Invalide loop entry, try again.\n");
        goto retry;
    }
    printf("\nFinally would you like to render the composition into a soundfile\n(if you'd like to have a time-stretched version of it you'll have to answer YES)\n");
    printf("╚(ಠ_ಠ)=┐");
    printf("0 for NO, 1 for YES: ");
    scanf("%d", &dacorsf);
    if(dacorsf < 0 || dacorsf > 1){
        printf("\nError: Invalide entry, try again.\n");
        goto retry;
    }

    
    
    
    
        //4. .csd stuff
        /* NOW WRITING ON A .CSD FILE */
        csdFileName = "algo_comp_v3.csd";
        csdPointer = fopen(csdFileName, "w");
        if(csdPointer != NULL)
            
        {
            
            
            /* ; Initialize the global variables. */
            fprintf(csdPointer,"<CsoundSynthesizer>\n");
            fprintf(csdPointer,"sr = 44100\n");
            fprintf(csdPointer,"kr = 4410\n");
            fprintf(csdPointer,"ksmps = 10\n");
            fprintf(csdPointer,"nchnls = 2\n\n");
            
            /* ; ; Instrument. */
            
            fprintf(csdPointer,"<CsInstruments>\n");
            fprintf(csdPointer,"garvbL init 0\n");
            fprintf(csdPointer,"garvbR init 0\n\n");
            
            
            /*I1 = Melody*/
            fprintf(csdPointer,"instr 1\n");
            fprintf(csdPointer,"ims  = 1000\n");
            fprintf(csdPointer,"k1 linsegr 0, 0.002, 1, p3/4, 1, p3/4, 0\n");
            //fprintf(csdPointer,"k2 linsegr 0, 0.002, 1, 0.2, 0\n");
            fprintf(csdPointer,"a1 oscili 4000, p4, 1\n");
            fprintf(csdPointer,"out a1 * k1\n");
            fprintf(csdPointer,"garvbL = garvbL+(0.5*a1*k1)\n");
            fprintf(csdPointer,"garvbR = garvbR+(0.5*a1*k1)\n");
            fprintf(csdPointer,"endin\n\n");
            /*I2 = Noise HiHat*/
            fprintf(csdPointer,"instr 2\n");
            fprintf(csdPointer,"kamp = 200\n");
            fprintf(csdPointer,"kbeta linsegr 0.5, 0.001, 0, p5, 0.5\n");
            fprintf(csdPointer,"k1 linsegr 0,0.001,1, p5, 0\n");
            fprintf(csdPointer,"a1  noise kamp, kbeta\n");
            fprintf(csdPointer,"out a1*k1\n");
            fprintf(csdPointer,"garvbL = garvbL+(0.5*a1*k1)\n");
            fprintf(csdPointer,"garvbR = garvbR+(0.5*a1*k1)\n");
            fprintf(csdPointer,"endin\n\n");
            
            
            
            /*I3 = Bassdrum*/
            fprintf(csdPointer,"instr 3\n");
            fprintf(csdPointer,"k1 linseg 0, .0001, 1, 0.2, 0\n");
            fprintf(csdPointer,"k2 linseg 200, 0.05, 55\n");
            fprintf(csdPointer,"a1 oscili 3000, k2, 2\n");
            fprintf(csdPointer,"out a1 * k1\n");
            fprintf(csdPointer,"endin\n");
            
            /*I99*/
            fprintf(csdPointer,"instr 99\n");
            fprintf(csdPointer,"denorm garvbL\n");
            fprintf(csdPointer,"denorm garvbR\n");
            fprintf(csdPointer,"aoutL, aoutR reverbsc garvbL, garvbR, 0.95, 15000, 44100, 0.4\n");
            fprintf(csdPointer,"outs aoutL, aoutR\n");
            fprintf(csdPointer,"clear garvbL\n");
            fprintf(csdPointer,"clear garvbR\n");
            fprintf(csdPointer,"endin\n\n");
            
            //Write notes from the array into the csd file
            //Initialize i
            fprintf(csdPointer,"</CsInstruments>\n");
            fprintf(csdPointer,"<CsScore>\n\n");
            fprintf(csdPointer,"f 1  0 8192 10 1 1/3 1/5 1/7 1/9 1/11 1/13 1/15\n");
            fprintf(csdPointer,"f 2  0 8192 10 1\n");
            fprintf(csdPointer,"f 3  0 8192 10 1 0.6 0.5 0.4 0.3 0.2 0.1\n");
            
            //Almigthy loop
            while(a < section){
                printf("%d section\n", a);
                i = 0;
                totalkicktime = totaltime;
                //2. Writing into the array
                while(i < 256)
                {
                    
                    //Will generate numbers from 1 to 8
                    thisnote = ((rand() % 8) + 1);
                    randnotes[i] = thisnote;
                    notediff = randnotes[i] - randnotes[i-1];
                    //printf("%d and %d and %d\n", thisnote, notediff, i);
                    //Write into the kickdrum array
                    divisionpercuarray[i] = ((rand() % 6));
                    
                    //Make sure the random generator is not too random (max interval=5 semitones) aka drunk. If the different of the current and past random number is too big=>try again
                    if(notediff > 5 || notediff < (-5)){
                        flag = 1;
                    }else{
                        flag = 2;
                    }
                    if(i == 0){
                        flag = 2;
                    }
                    switch(flag){
                        case(1): break;//In case of interval>5 ->don't move on and rewrite in the array
                        case(2): i++;//In case of interval<5 ->move on
                    }
                }
                
                printf("check segment fault line 301\n");

        //while(i < x){
                int measurecountsection;
                i = 0;
                measurecountsection = 0;
            while(currenttime < time){
                thisnote = randnotes[i];
                
                
                //This code block gives the "intelligent" behavior of the program
                //I could definitely expand more on it.....
                //Will set the second to last note to the dominant and the last to the root
                if(currenttime >= (time - (120.0/BPM)) && (currenttime < (time-(70.0/BPM)))){
                    flagend = 2;
                    thisnotehz = 392.00;
                    
                    //Will set last note to C
                }else if(currenttime > (time-(60.0/BPM))){
                    flagend = 2;
                    thisnotehz = 261.63;
                    notespeed = 1.0;
                    
                    //To start comp. on C
                }else if(currenttime == 0){
                    thisnotehz = 261.63;
                    flagend = 2;
                    //Every note following G will be C
                }else if(thisnotehz == 392.00){
                    thisnotehz = 261.63;
                    flagend = 2;
                }else flagend = 1;
                
                
                //Converting step notes to hz for score
                
                if(flagend == 1){
                    thisnotehz = StepToHerz(scale, thisnote);
                }else if(flagend == 2){
                    goto score;
                }
                printf("check segment fault line 338\n");
            score:
                //3. Now calculating BPM in second according to the user inputs BPM and divsion
                //This code block will generate random note value (4, 8, 16)
                division = ((rand() % 7));
                switch(division){
                    case(0): notespeed = 60.0/BPM; notevalue = 1.0/4.0; break;
                    case(1): notespeed = 60.0/BPM; notevalue = 1.0/4.0; break;
                    case(2): notespeed = 60.0/(BPM*2); notevalue = 1.0/8.0; break;
                    case(3): notespeed = 60.0/(BPM*2); notevalue = 1.0/8.0; break;
                    case(4): notespeed = 60.0/(BPM*4); notevalue = 1.0/16.0; break;
                    case(5): notespeed = 60.0/(BPM*4); notevalue = 1.0/16.0; break;
                    //32th notes nly occur 1/7 times as opposed to other value because too messy otherwise
                    case(6): notespeed = 60.0/(BPM/2); notevalue = 1.0/2.0; break;
                    
                }
                //Make sure last note last longer
                if(currenttime == (time-(60.0/BPM))){
                    notespeed = 1.0;
                }
                printf("check segment fault line 357\n");
                //Write the first bass note
                /*if(measurecount == 1.0){
                 fprintf(csdPointer,"i3 %f %f %f\n",totaltime, (4*(60.0/BPM)), thisnotehz/4);
                }*/
                
                //KICK PART
                //Start section with a quarter note kick
                if(measurecountsection == 0){
                    totalkicktime = totaltime;
                }
                
                
                measurevalue+=notevalue;
                //When the note value hit one whole note, restart counter
                //and trigger new bass note that will be the same frequency as the first note of the measure being played
                if(measurevalue >= 1.0){
                 measurecount++;
                 measurecountsection++;
                 measurevalue = 0.0;
                }
                 //fprintf(csdPointer,"i3 %f %f %f\n",totaltime, (4*(60.0/BPM)), thisnotehz/4);
                 //}else if(totaltime == time - (4*(60.0/BPM))){
                 //fprintf(csdPointer,"i3 %f %f %f\n",totaltime, (1*(60.0/BPM)), thisnotehz/4);
                // }
                
                if(a >= 2){
                    printf("kick part 2\n");
                    divisionpercu = divisionpercuarray[i];
                    switch(divisionpercu){
                        case(0): notespeedkick = 60.0/(BPM); break;
                        case(1): notespeedkick = 60.0/(BPM); break;
                        case(2): notespeedkick = 60.0/(BPM*2); break;
                        case(3): notespeedkick = 60.0/(BPM*4); break;
                        case(4): notespeedkick = 60.0/(BPM*4); break;
                        case(5): notespeedkick = 60.0/(BPM*8); break;
                    }
                   
                    
                //kicktotaltime[i][totalkicktimeformat] = (totalkicktime * 1000);
                            

                fprintf(csdPointer,"i3 %f %f\n", totalkicktime,notespeedkick);
                }
                fprintf(csdPointer,"i1 %f %f %f\n",totaltime, notespeed, thisnotehz);
                
                
                //Awesome 4th play along notes
                //fprintf(csdPointer,"i1 %f %f %f\n",totaltime, notespeed/40, (thisnotehz*(4.0/3.0)));
                //Noise instrument, the pfiled for this one correspond to the cutoff frequence of the lp, in order to get the cutoff defined according to the frequency of instr 1 we need to rescale the thisnotehz into a (-1.;1) range. The formula as follow will do the job
                //lpnoise = ((thisnotehz - 261.63) * (2 - 0))/((523.25 - 261.63) + 0);
                //PERCUSSION SECTION
                totalkicktime+=notespeedkick;
                totaltime+=notespeed;
                currenttime+=notespeed;
                
                //Write sequence infos into the 2 dimensional arrays (*1000 en then /1000 becazse arrays can't contain float)
                kicknotespeed[i][notespeedkickformat] = (notespeedkick * 1000);
                sequencespeed[i][notespeedformat] = (notespeed * 1000);
                sequencehz[i][thisnotehzformat] = (thisnotehz * 1000);
                i++;
                printf("notespeedkick = %f\n", notespeedkick);
                printf("kicknotespeed in array = %f\n", kicknotespeed[i][notespeedkickformat]);
                printf(" notespeedformat = %f\n", sequencespeed[i][notespeedformat]);
                
            }
            //HI HAT PART
                
            if(a >= 1){
                printf("yooo 3\n");
                x = 0;
                totaltimehh = (totaltime-currenttime);
                int sixthflag = 0;
                do{
                    divisionpercuarray[x] = ((rand() % 4));
                    
                    //Create kewl generative pattern cuz it's kewl => Here: two sixteen+one eight
                    if(divisionpercu == 2)
                    {
                        divisionpercuarray[x] = 2;
                    }
                    if(divisionpercuarray[x-2] == 2 && divisionpercuarray[x-1] == 2){
                        divisionpercuarray[x] = 1;
                    }
                    //Here : Do sequence of 32th notes not exceding 4
                    if(divisionpercu == 3){
                        divisionpercuarray[x] = 3;
                        sixthflag++;
                    }
                    if(sixthflag == 4){
                        sixthflag = 0;
                        divisionpercuarray[x] = 0;
                    }
                     divisionpercu = divisionpercuarray[x];
                        //Make sure each measure start with quarter note
                  
                    switch(divisionpercu){
                        case(0): notespeedhh = 60.0/(BPM); notevalue = 1.0/4.0; openorclosed = 0.1; break;
                        case(1): notespeedhh = 60.0/(BPM*2); notevalue = 1.0/8.0; openorclosed = 0.05; break;
                        case(2): notespeedhh = 60.0/(BPM*4); notevalue = 1.0/16.0; openorclosed = 0.02; break;
                        case(3): notespeedhh = 60.0/(BPM*8); notevalue = 1.0/32.0; openorclosed = 0.02; break;
                        
                    }
                    //Make sure when section start, HH start at the same time as the rest
                    if(measurecountsection == 0){
                        totaltimehh = totaltime;
                    }

                    printf("divisionpercuarray = %d\n", divisionpercuarray[x]);
                    fprintf(csdPointer,"i2 %f %f 1 %f\n",totaltimehh, notespeedhh/100, openorclosed);
                    totaltimehh+=notespeedhh;
                    
                    //hhnotespeed[x][notespeedhhformat] = (notespeedhh * 1000);;// Array in which the HI HAT notespeed will be written in
                    x++;
                                    }while(totaltimehh+time < totaltime+((loop+1)*time));
            }
                
            
    
            printf("check segment fault line 389\n");
              currenttime = 0;
              l = 0;
  
    //Rwwrite melody transposed up from the array
    while(l < loop){
              e = 0;
        totalkicktime = totaltime;
                while(e < i){
                    notespeed = (sequencespeed[e][notespeedformat]/1000);
                    thisnotehz = (sequencehz[e][thisnotehzformat]/1000);
                    fprintf(csdPointer,"i1 %f %f %f\n",totaltime, notespeed, thisnotehz*2);
                    
                    if(a >= 2){
                        notespeedkick = (kicknotespeed[e][notespeedkickformat]/1000);
                        //totalkicktime = (kicktotaltime[e][totalkicktimeformat]/1000);
                        fprintf(csdPointer,"i3 %f %f\n", totalkicktime,notespeedkick);
                    }
                    totalkicktime+=notespeedkick;
                    totaltime+=notespeed;
                    e++;
                }
         l++;
           }
        a++;
    }
        printf("check segment fault line 411\n");
        //Composition infos
        switch(scale){
            case(1): strncpy (scalename, "Ionian", 12); break;
            case(2): strncpy (scalename, "Dorian", 12); break;
            case(3): strncpy (scalename, "Phrygian", 12); break;
            case(4): strncpy (scalename, "Lydian", 12); break;
            case(5): strncpy (scalename, "Mixolydian", 12); break;
            case(6): strncpy (scalename, "Aeolian", 12); break;
            case(7): strncpy (scalename, "Locrian", 12); break;
        }
        printf("\n\n\n\n\n\n");
        printf("BPM = %d,\nNumber of measures = %d\n", BPM, measurecount);
        printf("Runtime = %.2f\n", (time * (loop+1) * section));
        printf("Mode = %s\n", scalename);
        printf("\n\n\n\n\n\n");
        
        //Reverb opcode (+3.0 is for the tail to go on at the end)
        fprintf(csdPointer,"i99 0 %f\n",totaltime+10.0);
        fprintf(csdPointer,"</CsScore>\n");
        fprintf(csdPointer,"</CsoundSynthesizer>\a");
        /* score end */
        fclose(csdPointer);
        
        /* Playing .csd file */
        char commandline [1000] = "csound -odac -d -O null ";
        strcat(commandline, csdFileName);
            if(dacorsf == 1){
            char cmd_2[1000] = " && csound -o composed.aif ";
            strcat(cmd_2,csdFileName);
            strcat(commandline, cmd_2);
            }
            system (commandline);
        }
    int flag2;
    printf("\n\n\n\nNow, do you want to listen to a time-stretched version\nof what you just heard?\nor maybe try again?\n");
    printf("\"0\" to stop here, \"1\" for timestretch and \"2\" to try again: ");
    scanf("%d", &flag2);
    
    //NOW WRITING .CSD FILE #2 FOR TIMESTRETCHED VERSION
    if(flag2 == 1){
     float stretchfactor;
     printf("\n\nNow Please enter a time strectch factor\n(1 being the normal speed and 2 stretched twice): ");
     scanf("%f", &stretchfactor);
     FILE* csdpointer2;
     char* csdFileName2;
     
     csdFileName2 = "algo_comp_v3_stretched.csd";
     csdpointer2 = fopen(csdFileName2, "w");
    if(csdpointer2 != NULL)
    {
        fprintf(csdpointer2,"<CsoundSynthesizer>\n");
        
        /* ; ; Instrument. */
        
        fprintf(csdpointer2,"<CsInstruments>\n");
        fprintf(csdpointer2,"sr = 44100\n");
        fprintf(csdpointer2,"ksmps = 32\n");
        fprintf(csdpointer2,"0dbfs = 1\n");
        fprintf(csdpointer2,"nchnls = 2\n\n");

        fprintf(csdpointer2,"garvbL init 0\n");
        fprintf(csdpointer2,"garvbR init 0\n\n");
        
        
        //sndwarp
        fprintf(csdpointer2,"instr 1\n");
        fprintf(csdpointer2,"ktimewarp = %f\n", stretchfactor);	//;length of "fox.wav"
        fprintf(csdpointer2,"kresample init 1\n"); //;do not change pitch
        fprintf(csdpointer2,"ibeg = 0\n"); //;start at beginning
        fprintf(csdpointer2,"iwsize = 4410\n");	//;window size in samples with
        fprintf(csdpointer2,"irandw = 882\n"); //;bandwidth of a random number generator
        fprintf(csdpointer2,"itimemode = 0\n"); //;ktimewarp is "time" pointer
        fprintf(csdpointer2,"ioverlap = p4\n");
        
        fprintf(csdpointer2,"asig sndwarp .5, ktimewarp, kresample, 1, ibeg, iwsize, irandw, ioverlap, 2, itimemode\n");
        fprintf(csdpointer2,"outs (asig*0.3), (asig*0.3)\n");

        

        fprintf(csdPointer,"garvbL = garvbL+(0.05*asig)\n");
        fprintf(csdPointer,"garvbR = garvbR+(0.05*asig)\n");
        fprintf(csdpointer2,"endin\n\n");
        /*I99*/
        fprintf(csdpointer2,"instr 99\n");
        fprintf(csdpointer2,"denorm garvbL\n");
        fprintf(csdpointer2,"denorm garvbR\n");
        fprintf(csdpointer2,"aoutL, aoutR reverbsc garvbL, garvbR, 0.95, 15000, 44100, 0.4\n");
        fprintf(csdpointer2,"outs aoutL, aoutR\n");
        fprintf(csdpointer2,"clear garvbL\n");
        fprintf(csdpointer2,"clear garvbR\n");
        fprintf(csdpointer2,"endin\n\n");
        fprintf(csdpointer2,"</CsInstruments>\n");
        
        fprintf(csdpointer2,"<CsScore>\n\n");
        fprintf(csdpointer2,"f 1 0 %lf 1 \"composed.aif\" 0 0 0\n", (totaltime*44100)); //; audio file
        fprintf(csdpointer2,"f 2 0 1024 9 0.5 1 0\n"); //; half of a sine wave
        
        
        fprintf(csdpointer2,"i 1 0 %f 15\n", (totaltime*stretchfactor));
        fprintf(csdpointer2,"i99 0 %f\n", ((totaltime)*(stretchfactor))+10);
        fprintf(csdpointer2,"</CsScore>\n");
        fprintf(csdpointer2,"</CsoundSynthesizer>\a");
        
        fclose(csdpointer2);

    
    
    
    char commandline2 [1000] = "csound -odac -d -O null ";
    strcat(commandline2, csdFileName2);
    system (commandline2);
    }
    
    }else if(flag2 == 0){
    return 0;
    }else if(flag2 == 2){
        goto retry;
    }
}

