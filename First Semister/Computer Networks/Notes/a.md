# Computer Networks
## Conversion Techniques
Analog to Analog or digital to Analog is modulation. If you convert Anything to digital then it is called encoding
## 1. Analog to Analog Conversion
### A. Amplitude Modulation

We change the amplitude, and keep the frequency and phase constant. The constant frequency is called the carrier frequency. 

1. There is a modulation signal, which is the base analog signal, and there is a carrier frequency. We then combine them, and that produces the final amplitude modulatied signal.
2. There is more noise in these signals.
3. Bandwidth: Bam = 2B 
#### Advantages
1. Its easier
2. Components are very cheap
3. It can be demodulated using a circuit consisting of a very few components

#### Disadvantages
1. Poor performance
2. Inefficient
### B. Frequency Modulation
It is the rocess by which the frequency of a carrier signal which changes with respect to the modulation signal. We just keep the amplitude and the phase constant, and we only change the frequency. 

1. The logic is simple. If the input amplitude of the analog signal is more, then we will increase the frequency in that region. And vice versa. The bandwidth is also calculated in the same manner. 
2. The transmitted signal also has a fixed value. So like when we transmit something, that audio in itself has some value of volume that you can output. Coz to increase the volume, you need to give more audio data. That volume we know is measured in Decibels (db). 
3. The total bandwidth required for FM transmission, is Bm = 10B.

### C. Phase Modulation
Again over here the frequency and amplitude is constant. If the amplitude is high for the base audio signal, then you will shift the signal accordingly. It is costly, and takes more effort. The Bandwidth is again 10 times the bandwidth of the base signal. 
## 2. Digital to Analog Data Conversion
Modulator obviously converts digital to analog. Coz we know that conversion to analog is called modulation. So the thing that does that is the modulator, and then on the receiver side, you will need a demodulator. 

There are different techniques. 
1. Amplitude Shift Keying : Coz we are converting from digital to analog, its rather simple. Coz you just have 2 values. It would be high or 0. So you transmit some wave when there is 1, and if its 0 then dont. 
2. Frequency Shift Keying: Again this is also something similar. you have certain high frequency to transmit the 1, and a low frequency level to represent 0. So we have 2 base carrier waves. So the final wave has the combination of the 2 frequencies. This reduces noise.
3. Phase Shift Keying: To represent 1, you have a certain phase. And to represent 0, you change the phase by 180 degrees. That now generates a final output wave with varing phase. Now we dont require 2 frequencies. And that reduces noise. 
## 3. Digital to Digital Conversion
This is encoding
1. Line coding
2. Block Coding
3. Scrambling
### 1. Line Coding: 

Converting a string of 1s and 0s into a sequency of signals that denote the 1s and 0s. So you would just need an encoder and a decoder. This way you could send a string of digital data to someone.


> #### _Data Rate : It is the number of Bits set per second. Now to just transmit 1 bit, you might need 1 signal or 2 signals, or more. The value of a variable r =  is data element/signal elements_
> #### _Baud Rate: It is related to the signal. You could use 3 signal elements to send like 4 data elements, or 4 bits. So then value of r wouldbe 4/3. To Calculate S = c.N.(1/r)_ 
> #### _NRZ: non return to zero. Whenever the base signal has a change from 1 to 0, we will create a new signal, that doesnt return it to 0, we just flip the voltage. So this makes it such that the signal never has 0, and that makes it easier to key._
Example: A signal is carrying data in which one element is encoded as one signal element. r = 1. If the bit rate is 100 kbps. what is the average value of the baud rate if c is between 0 and 1. Assume that the average value of c is 0.5
### Line Coding Schemes
1. Unipolar - NRZ
2. Polar - NRZ, RZ and biphase
3. Bipolar - AMI and pseudoterary
4. Multilevel - 2b/1Z, 8B/T etc. 
5. Multi Transition - MLT 3
