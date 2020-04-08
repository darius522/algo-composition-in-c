<CsoundSynthesizer>
<CsInstruments>
sr = 44100
ksmps = 32
0dbfs = 1
nchnls = 2

garvbL init 0
garvbR init 0

instr 1
ktimewarp = 2.000000
kresample init 1
ibeg = 0
iwsize = 4410
irandw = 882
itimemode = 0
ioverlap = p4
asig sndwarp .5, ktimewarp, kresample, 1, ibeg, iwsize, irandw, ioverlap, 2, itimemode
outs (asig*0.3), (asig*0.3)
garvbL = garvbL+(0.05*asig)
garvbR = garvbR+(0.05*asig)
endin

instr 99
denorm garvbL
denorm garvbR
aoutL, aoutR reverbsc garvbL, garvbR, 0.95, 15000, 44100, 0.4
outs aoutL, aoutR
clear garvbL
clear garvbR
endin

</CsInstruments>
<CsScore>

f 1 0 1256850.000000 1 "composed.aif" 0 0 0
f 2 0 1024 9 0.5 1 0
i 1 0 57.000000 15
i99 0 67.000000
</CsScore>
</CsoundSynthesizer>